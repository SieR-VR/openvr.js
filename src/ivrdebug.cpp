#include <node.h>
#include <openvr.h>

#include "ivrdebug.h"
#include "util.h"

using namespace v8;

Nan::Persistent<Function> IVRDebug::constructor;

void IVRDebug::Init(Local<Object> exports)
{
    Local<Context> context = exports->CreationContext();
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("IVRDebug").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "EmitVrProfilerEvent", EmitVrProfilerEvent);
    Nan::SetPrototypeMethod(tpl, "BeginVrProfilerEvent", BeginVrProfilerEvent);
    Nan::SetPrototypeMethod(tpl, "FinishVrProfilerEvent", FinishVrProfilerEvent);
    Nan::SetPrototypeMethod(tpl, "DriverDebugRequest", DriverDebugRequest);

    constructor.Reset(tpl->GetFunction(context).ToLocalChecked());
    exports->Set(
               context,
               Nan::New("IVRDebug").ToLocalChecked(),
               tpl->GetFunction(context).ToLocalChecked())
        .FromJust();
}

Local<Object> IVRDebug::NewInstance(vr::IVRDebug *debug)
{
    Nan::EscapableHandleScope scope;
    Local<Function> cons = Nan::New(constructor);
    Local<Value> argv[1] = {Nan::New<External>(debug)};
    return scope.Escape(Nan::NewInstance(cons, 1, argv).ToLocalChecked());
}

IVRDebug::IVRDebug(vr::IVRDebug *self)
    : self_(self)
{
}

void IVRDebug::New(const Nan::FunctionCallbackInfo<Value> &info)
{
    if (!info.IsConstructCall())
    {
        Nan::ThrowError("Use the `new` keyword when creating a new instance.");
        return;
    }

    auto wrapped_instance = static_cast<vr::IVRDebug *>(
        Local<External>::Cast(info[0])->Value());
    IVRDebug *obj = new IVRDebug(wrapped_instance);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

// virtual EVRDebugError EmitVrProfilerEvent( const char *pchMessage ) = 0;
void IVRDebug::EmitVrProfilerEvent(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRDebug *obj = ObjectWrap::Unwrap<IVRDebug>(info.Holder());

    const char *pchMessage = *Nan::Utf8String(info[0]);
    vr::EVRDebugError result = obj->self_->EmitVrProfilerEvent(pchMessage);
    info.GetReturnValue().Set(Nan::New<Number>(static_cast<uint32_t>(result)));
}

// virtual EVRDebugError BeginVrProfilerEvent( VrProfilerEventHandle_t *pHandleOut ) = 0;
void IVRDebug::BeginVrProfilerEvent(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRDebug *obj = ObjectWrap::Unwrap<IVRDebug>(info.Holder());

    vr::VrProfilerEventHandle_t handleOut;
    vr::EVRDebugError result = obj->self_->BeginVrProfilerEvent(&handleOut);
    info.GetReturnValue().Set(Nan::New<Number>(static_cast<uint32_t>(result)));
}

// virtual EVRDebugError FinishVrProfilerEvent( VrProfilerEventHandle_t hHandle, const char *pchMessage ) = 0;
void IVRDebug::FinishVrProfilerEvent(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRDebug *obj = ObjectWrap::Unwrap<IVRDebug>(info.Holder());

    vr::VrProfilerEventHandle_t hHandle = static_cast<vr::VrProfilerEventHandle_t>(
        Nan::To<int32_t>(info[0]).FromJust());
    const char *pchMessage = *Nan::Utf8String(info[1]);
    vr::EVRDebugError result = obj->self_->FinishVrProfilerEvent(hHandle, pchMessage);
    info.GetReturnValue().Set(Nan::New<Number>(static_cast<uint32_t>(result)));
}

// virtual uint32_t DriverDebugRequest( vr::TrackedDeviceIndex_t unDeviceIndex, const char *pchRequest, VR_OUT_STRING() char *pchResponseBuffer, uint32_t unResponseBufferSize ) = 0;
void IVRDebug::DriverDebugRequest(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRDebug *obj = ObjectWrap::Unwrap<IVRDebug>(info.Holder());

    vr::TrackedDeviceIndex_t unDeviceIndex = static_cast<vr::TrackedDeviceIndex_t>(
        Nan::To<int32_t>(info[0]).FromJust());
    
    const char *pchRequest = *Nan::Utf8String(info[1]);
    uint32_t unResponseBufferSize = Nan::To<uint32_t>(info[2]).FromJust();
    char *pchResponseBuffer = new char[unResponseBufferSize];

    uint32_t result = obj->self_->DriverDebugRequest(
        unDeviceIndex,
        pchRequest,
        pchResponseBuffer,
        unResponseBufferSize);
    info.GetReturnValue().Set(Nan::New<String>(pchResponseBuffer).ToLocalChecked());
}
