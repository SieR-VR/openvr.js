#include "ivrapplications.h"
#include "util.h"

#include <array>
#include <node.h>
#include <openvr.h>

void IVRApplications::Init(Local<Object> exports)
{
    Local<Context> context = exports->CreationContext();
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("IVRApplications").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "AddApplicationManifest", AddApplicationManifest);
    Nan::SetPrototypeMethod(tpl, "RemoveApplicationManifest", RemoveApplicationManifest);
    Nan::SetPrototypeMethod(tpl, "IsApplicationInstalled", IsApplicationInstalled);

    constructor.Reset(tpl->GetFunction(context).ToLocalChecked());
    exports->Set(
        context,
        Nan::New("IVRApplications").ToLocalChecked(),
        tpl->GetFunction(context).ToLocalChecked());
}

Local<Object> IVRApplications::NewInstance(vr::IVRApplications *applications)
{
    Nan::EscapableHandleScope scope;
    Local<Function> cons = Nan::New(constructor);
    Local<Value> argv[1] = {Nan::New<External>(system)};
    return scope.Escape(Nan::NewInstance(cons, 1, argv).ToLocalChecked());
}

IVRApplications::IVRApplications(vr::IVRApplications *self)
    : self_(self)
{
}

void IVRApplications::New(const Nan::FunctionCallbackInfo<Value> &info)
{
    if (!info.IsConstructCall())
    {
        Nan::ThrowError("Use the `new` keyword when creating a new instance.");
        return;
    }

    auto wrapped_instance = static_cast<vr::IVRApplications *>(
        Local<External>::Cast(info[0])->Value());
    IVRApplications *obj = new IVRApplications(wrapped_instance);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

// ------------------------------------
// Application management
// ------------------------------------

// virtual EVRApplicationError AddApplicationManifest( const char *pchApplicationManifestFullPath, bool bTemporary = false )
void IVRApplications::AddApplicationManifest(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRApplications *obj = Nan::ObjectWrap::Unwrap<IVRApplications>(info.Holder());

    const char *pchApplicationManifestFullPath = *(Nan::Utf8String(info[0]));
    bool bTemporary = info[1]->BooleanValue(info.GetIsolate());

    vr::EVRApplicationError error = obj->self_->AddApplicationManifest(pchApplicationManifestFullPath, bTemporary);

    if (error != vr::EVRApplicationError_None)
    {
        Nan::ThrowError(obj->self_->GetApplicationsErrorNameFromEnum(error));
        return;
    }
}

// virtual EVRApplicationError RemoveApplicationManifest( const char *pchApplicationManifestFullPath )
void IVRApplications::RemoveApplicationManifest(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRApplications *obj = Nan::ObjectWrap::Unwrap<IVRApplications>(info.Holder());

    const char *pchApplicationManifestFullPath = *(Nan::Utf8String(info[0]));

    vr::EVRApplicationError error = obj->self_->RemoveApplicationManifest(pchApplicationManifestFullPath);

    if (error != vr::EVRApplicationError_None)
    {
        Nan::ThrowError(obj->self_->GetApplicationsErrorNameFromEnum(error));
        return;
    }
}

// virtual bool IsApplicationInstalled( const char *pchAppKey )
void IVRApplications::IsApplicationInstalled(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRApplications *obj = Nan::ObjectWrap::Unwrap<IVRApplications>(info.Holder());

    const char *pchAppKey = *(Nan::Utf8String(info[0]));

    bool isApplicationInstalled = obj->self_->IsApplicationInstalled(pchAppKey);
    info.GetReturnValue().Set(Nan::New<Boolean>(isApplicationInstalled));
}
