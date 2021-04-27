#include "ivroverlay.h"
#include "util.h"

#include <array>
#include <node.h>
#include <openvr.h>

using namespace v8;

Nan::Persistent<Function> IVROverlay::constructor;

void IVROverlay::Init(Local<Object> exports)
{
    Local<Context> context = exports->CreationContext();
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("IVROverlay").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "FindOverlay", FindOverlay);
    Nan::SetPrototypeMethod(tpl, "CreateOverlay", CreateOverlay);
    Nan::SetPrototypeMethod(tpl, "DestroyOverlay", DestroyOverlay);
    Nan::SetPrototypeMethod(tpl, "GetOverlayKey", GetOverlayKey);
    Nan::SetPrototypeMethod(tpl, "GetOverlayName", GetOverlayName);
    Nan::SetPrototypeMethod(tpl, "SetOverlayName", SetOverlayName);
    // Nan::SetPrototypeMethod(tpl, "GetOverlayImageData", GetOverlayImageData);
    Nan::SetPrototypeMethod(tpl, "GetOverlayErrorNameFromEnum", GetOverlayErrorNameFromEnum);

    Nan::SetPrototypeMethod(tpl, "SetOverlayRenderingPid", SetOverlayRenderingPid);
    Nan::SetPrototypeMethod(tpl, "GetOverlayRenderingPid", GetOverlayRenderingPid);
    Nan::SetPrototypeMethod(tpl, "SetOverlayFlag", SetOverlayFlag);
    Nan::SetPrototypeMethod(tpl, "GetOverlayFlag", GetOverlayFlag);
    Nan::SetPrototypeMethod(tpl, "GetOverlayFlags", GetOverlayFlags);
    Nan::SetPrototypeMethod(tpl, "SetOverlayName", SetOverlayName);
    Nan::SetPrototypeMethod(tpl, "SetOverlayColor", SetOverlayColor);
    Nan::SetPrototypeMethod(tpl, "GetOverlayColor", GetOverlayColor);
    Nan::SetPrototypeMethod(tpl, "SetOverlayAlpha", SetOverlayAlpha);
    Nan::SetPrototypeMethod(tpl, "GetOverlayAlpha", GetOverlayAlpha);
    Nan::SetPrototypeMethod(tpl, "SetOverlayTexelAspect", SetOverlayTexelAspect);
    Nan::SetPrototypeMethod(tpl, "GetOverlayTexelAspect", GetOverlayTexelAspect);
    Nan::SetPrototypeMethod(tpl, "SetOverlaySortOrder", SetOverlaySortOrder);
    Nan::SetPrototypeMethod(tpl, "SetOverlayName", SetOverlayName);
    Nan::SetPrototypeMethod(tpl, "GetOverlaySortOrder", GetOverlaySortOrder);
    Nan::SetPrototypeMethod(tpl, "SetOverlayWidthInMeters", SetOverlayWidthInMeters);
    Nan::SetPrototypeMethod(tpl, "GetOverlayWidthInMeters", GetOverlayWidthInMeters);
    Nan::SetPrototypeMethod(tpl, "SetOverlayCurvature", SetOverlayCurvature);
    Nan::SetPrototypeMethod(tpl, "GetOverlayCurvature", GetOverlayCurvature);
    Nan::SetPrototypeMethod(tpl, "GetOverlayKey", GetOverlayKey);
    Nan::SetPrototypeMethod(tpl, "SetOverlayTextureColorSpace", SetOverlayTextureColorSpace);
    Nan::SetPrototypeMethod(tpl, "GetOverlayTextureColorSpace", GetOverlayTextureColorSpace);
    Nan::SetPrototypeMethod(tpl, "SetOverlayTextureBounds", SetOverlayTextureBounds);
    Nan::SetPrototypeMethod(tpl, "GetOverlayTextureBounds", GetOverlayTextureBounds);
    Nan::SetPrototypeMethod(tpl, "GetOverlayTransformType", GetOverlayTransformType);
    Nan::SetPrototypeMethod(tpl, "SetOverlayTransformAbsolute", SetOverlayTransformAbsolute);
    Nan::SetPrototypeMethod(tpl, "GetOverlayTransformAbsolute", GetOverlayTransformAbsolute);
    Nan::SetPrototypeMethod(tpl, "SetOverlayTransformTrackedDeviceRelative", SetOverlayTransformTrackedDeviceRelative);
    Nan::SetPrototypeMethod(tpl, "GetOverlayTransformTrackedDeviceRelative", GetOverlayTransformTrackedDeviceRelative);
    Nan::SetPrototypeMethod(tpl, "SetOverlayTransformTrackedDeviceComponent", SetOverlayTransformTrackedDeviceComponent);
    Nan::SetPrototypeMethod(tpl, "GetOverlayTransformTrackedDeviceComponent", GetOverlayTransformTrackedDeviceComponent);
    Nan::SetPrototypeMethod(tpl, "GetOverlayTransformOverlayRelative", GetOverlayTransformOverlayRelative);
    Nan::SetPrototypeMethod(tpl, "SetOverlayTransformOverlayRelative", SetOverlayTransformOverlayRelative);
    Nan::SetPrototypeMethod(tpl, "SetOverlayTransformCursor", SetOverlayTransformCursor);
    Nan::SetPrototypeMethod(tpl, "GetOverlayTransformCursor", GetOverlayTransformCursor);
    Nan::SetPrototypeMethod(tpl, "SetOverlayTransformProjection", SetOverlayTransformProjection);
    Nan::SetPrototypeMethod(tpl, "ShowOverlay", ShowOverlay);
    Nan::SetPrototypeMethod(tpl, "HideOverlay", HideOverlay);
    Nan::SetPrototypeMethod(tpl, "IsOverlayVisible", IsOverlayVisible);
    Nan::SetPrototypeMethod(tpl, "GetTransformForOverlayCoordinates", GetTransformForOverlayCoordinates);

    Nan::SetPrototypeMethod(tpl, "PollNextOverlayEvent", PollNextOverlayEvent);
    Nan::SetPrototypeMethod(tpl, "GetOverlayInputMethod", GetOverlayInputMethod);
    Nan::SetPrototypeMethod(tpl, "SetOverlayInputMethod", SetOverlayInputMethod);
    Nan::SetPrototypeMethod(tpl, "GetOverlayMouseScale", GetOverlayMouseScale);
    Nan::SetPrototypeMethod(tpl, "SetOverlayMouseScale", SetOverlayMouseScale);
    Nan::SetPrototypeMethod(tpl, "ComputeOverlayIntersection", ComputeOverlayIntersection);
    Nan::SetPrototypeMethod(tpl, "IsHoverTargetOverlay", IsHoverTargetOverlay);
    Nan::SetPrototypeMethod(tpl, "SetOverlayIntersectionMask", SetOverlayIntersectionMask);
    Nan::SetPrototypeMethod(tpl, "TriggerLaserMouseHapticVibration", TriggerLaserMouseHapticVibration);
    Nan::SetPrototypeMethod(tpl, "SetOverlayCursor", SetOverlayCursor);
    Nan::SetPrototypeMethod(tpl, "SetOverlayCursorPositionOverride", SetOverlayCursorPositionOverride);
    Nan::SetPrototypeMethod(tpl, "ClearOverlayCursorPositionOverride", ClearOverlayCursorPositionOverride);

    Nan::SetPrototypeMethod(tpl, "SetOverlayTexture", SetOverlayTexture);
    Nan::SetPrototypeMethod(tpl, "ClearOverlayTexture", ClearOverlayTexture);
    Nan::SetPrototypeMethod(tpl, "SetOverlayRaw", SetOverlayRaw);
    Nan::SetPrototypeMethod(tpl, "SetOverlayFromFile", SetOverlayFromFile);
    Nan::SetPrototypeMethod(tpl, "GetOverlayTexture", GetOverlayTexture);
    Nan::SetPrototypeMethod(tpl, "ReleaseNativeOverlayHandle", ReleaseNativeOverlayHandle);
    Nan::SetPrototypeMethod(tpl, "GetOverlayTextureSize", GetOverlayTextureSize);

    Nan::SetPrototypeMethod(tpl, "CreateDashboardOverlay", CreateDashboardOverlay);
    Nan::SetPrototypeMethod(tpl, "IsDashboardVisible", IsDashboardVisible);
    Nan::SetPrototypeMethod(tpl, "IsActiveDashboardOverlay", IsActiveDashboardOverlay);
    Nan::SetPrototypeMethod(tpl, "SetDashboardOverlaySceneProcess", SetDashboardOverlaySceneProcess);
    Nan::SetPrototypeMethod(tpl, "GetDashboardOverlaySceneProcess", GetDashboardOverlaySceneProcess);
    Nan::SetPrototypeMethod(tpl, "ShowDashboard", ShowDashboard);
    Nan::SetPrototypeMethod(tpl, "GetPrimaryDashboardDevice", GetPrimaryDashboardDevice);

    Nan::SetPrototypeMethod(tpl, "ShowKeyboard", ShowKeyboard);
    Nan::SetPrototypeMethod(tpl, "ShowKeyboardForOverlay", ShowKeyboardForOverlay);
    Nan::SetPrototypeMethod(tpl, "GetKeyboardText", GetKeyboardText);
    Nan::SetPrototypeMethod(tpl, "HideKeyboard", HideKeyboard);
    Nan::SetPrototypeMethod(tpl, "SetKeyboardTransformAbsolute", SetKeyboardTransformAbsolute);
    Nan::SetPrototypeMethod(tpl, "SetKeyboardPositionForOverlay", SetKeyboardPositionForOverlay);

    Nan::SetPrototypeMethod(tpl, "ShowMessageOverlay", ShowMessageOverlay);
    Nan::SetPrototypeMethod(tpl, "CloseMessageOverlay", CloseMessageOverlay);

    constructor.Reset(tpl->GetFunction(context).ToLocalChecked());
    exports->Set(
        context,
        Nan::New("IVROverlay").ToLocalChecked(),
        tpl->GetFunction(context).ToLocalChecked());
}

Local<Object> IVROverlay::NewInstance(vr::IVROverlay *overlay)
{
    Nan::EscapableHandleScope scope;
    Local<Function> cons = Nan::New(constructor);
    Local<Value> argv[1] = {Nan::New<External>(overlay)};
    return scope.Escape(Nan::NewInstance(cons, 1, argv).ToLocalChecked());
}

IVROverlay::IVROverlay(vr::IVROverlay *self)
    : self_(self)
{
}

void IVROverlay::New(const Nan::FunctionCallbackInfo<Value> &info)
{
    if(!info.IsConstructCall())
    {
        Nan::ThrowError("Use the `new` keyword when creating a new instance.");
        return;
    }

    auto wrapped_instance = static_cast<vr::IVROverlay *>(
        Local<External>::Cast(info[0])->Value());
    IVROverlay *obj = new IVROverlay(wrapped_instance);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

// ---------------------------------------------
// Overlay management methods
// ---------------------------------------------

// virtual EVROverlayError FindOverlay( const char *pchOverlayKey, VROverlayHandle_t * pOverlayHandle ) = 0;
void IVROverlay::FindOverlay(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    const char *pchOverlayKey = *Nan::Utf8String(info[0]);
    vr::VROverlayHandle_t OverlayHandle;
    obj->self_->FindOverlay(pchOverlayKey, &OverlayHandle);
    info.GetReturnValue().Set(Nan::New<Number>(static_cast<uint64_t>(OverlayHandle)));
}
// virtual EVROverlayError CreateOverlay( const char *pchOverlayKey, const char *pchOverlayName, VROverlayHandle_t * pOverlayHandle ) = 0;
void IVROverlay::CreateOverlay(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    const char *pchOverlayKey = *Nan::Utf8String(info[0]);
    const char *pchOverlayName = *Nan::Utf8String(info[1]);
    vr::VROverlayHandle_t OverlayHandle;
    obj->self_->CreateOverlay(pchOverlayKey, pchOverlayName, &OverlayHandle);
    info.GetReturnValue().Set(Nan::New<Number>(static_cast<uint64_t>(OverlayHandle)));
}
// virtual EVROverlayError DestroyOverlay( VROverlayHandle_t ulOverlayHandle ) = 0;
void IVROverlay::DestroyOverlay(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    vr::EVROverlayError overlayError = obj->self_->DestroyOverlay(ulOverlayHandle);
    info.GetReturnValue().Set(Nan::New<Number>(static_cast<uint64_t>(overlayError)));
}
// virtual uint32_t GetOverlayKey( VROverlayHandle_t ulOverlayHandle, VR_OUT_STRING() char *pchValue, uint32_t unBufferSize, EVROverlayError *pError = 0L ) = 0;
void IVROverlay::GetOverlayKey(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    char * pchValue;
    obj->self_->GetOverlayKey(ulOverlayHandle, pchValue, vr::k_unVROverlayMaxKeyLength);
    info.GetReturnValue().Set(Nan::New<String>(pchValue).ToLocalChecked());
}
// virtual uint32_t GetOverlayName( VROverlayHandle_t ulOverlayHandle, VR_OUT_STRING() char *pchValue, uint32_t unBufferSize, EVROverlayError *pError = 0L ) = 0;
void IVROverlay::GetOverlayName(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    char * pchValue;
    obj->self_->GetOverlayKey(ulOverlayHandle, pchValue, vr::k_unVROverlayMaxNameLength);
    info.GetReturnValue().Set(Nan::New<String>(pchValue).ToLocalChecked());
}
// virtual EVROverlayError SetOverlayName( VROverlayHandle_t ulOverlayHandle, const char *pchName ) = 0;
void IVROverlay::SetOverlayName(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    const char *pchName = *Nan::Utf8String(info[1]);
    vr::EVROverlayError error = obj->self_->SetOverlayName(ulOverlayHandle, pchName);
    
    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }
}
// virtual EVROverlayError GetOverlayImageData( VROverlayHandle_t ulOverlayHandle, void *pvBuffer, uint32_t unBufferSize, uint32_t *punWidth, uint32_t *punHeight ) = 0;
// void IVROverlay::GetOverlayImageData(const Nan::FunctionCallbackInfo<Value> &info);
// virtual const char *GetOverlayErrorNameFromEnum( EVROverlayError error ) = 0;
void IVROverlay::GetOverlayErrorNameFromEnum(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::EVROverlayError error = static_cast<vr::EVROverlayError>(info[0]->Uint32Value(context).FromJust());
    const char * pchName = obj->self_->GetOverlayErrorNameFromEnum(error);
    info.GetReturnValue().Set(Nan::New<String>(pchName).ToLocalChecked());
}

// ---------------------------------------------
// Overlay rendering methods
// ---------------------------------------------

// virtual EVROverlayError SetOverlayRenderingPid( VROverlayHandle_t ulOverlayHandle, uint32_t unPID ) = 0;
void IVROverlay::SetOverlayRenderingPid(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    uint32_t unPID = info[1]->Uint32Value(context).FromJust();
    vr::EVROverlayError error = obj->self_->SetOverlayRenderingPid(ulOverlayHandle, unPID);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }
}
// virtual uint32_t GetOverlayRenderingPid( VROverlayHandle_t ulOverlayHandle ) = 0;
void IVROverlay::GetOverlayRenderingPid(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    uint32_t unPID = obj->self_->SetOverlayRenderingPid(ulOverlayHandle, unPID);
    info.GetReturnValue().Set(Nan::New<Number>(unPID));
}
// virtual EVROverlayError SetOverlayFlag( VROverlayHandle_t ulOverlayHandle, VROverlayFlags eOverlayFlag, bool bEnabled ) = 0;
void IVROverlay::SetOverlayFlag(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    vr::VROverlayFlags eOverlayFlag = static_cast<vr::VROverlayFlags>(info[1]->Uint32Value(context).FromJust());
    bool bEnabled = info[2]->BooleanValue(info.GetIsolate());
    vr::EVROverlayError error = obj->self_->SetOverlayFlag(ulOverlayHandle, eOverlayFlag, bEnabled);
        
    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }
}
// virtual EVROverlayError GetOverlayFlag( VROverlayHandle_t ulOverlayHandle, VROverlayFlags eOverlayFlag, bool *pbEnabled ) = 0;
void IVROverlay::GetOverlayFlag(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    vr::VROverlayFlags eOverlayFlag = static_cast<vr::VROverlayFlags>(info[1]->Uint32Value(context).FromJust());
    bool bEnabled;
    vr::EVROverlayError error = obj->self_->GetOverlayFlag(ulOverlayHandle, eOverlayFlag, &bEnabled);
        
    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }

    info.GetReturnValue().Set(Nan::New<Boolean>(bEnabled));
}
// virtual EVROverlayError GetOverlayFlags( VROverlayHandle_t ulOverlayHandle, uint32_t *pFlags ) = 0;
void IVROverlay::GetOverlayFlags(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    uint32_t flags;
    vr::EVROverlayError error = obj->self_->GetOverlayFlags(ulOverlayHandle, &flags);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }

    info.GetReturnValue().Set(Nan::New<Number>(flags));
}
// virtual EVROverlayError SetOverlayColor( VROverlayHandle_t ulOverlayHandle, float fRed, float fGreen, float fBlue ) = 0;
void IVROverlay::SetOverlayColor(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    float fRed = info[1]->NumberValue(context).FromJust();
    float fGreen = info[2]->NumberValue(context).FromJust();
    float fBlue = info[3]->NumberValue(context).FromJust();
    vr::EVROverlayError error = obj->self_->SetOverlayColor(ulOverlayHandle, fRed, fGreen, fBlue);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }
}
// virtual EVROverlayError GetOverlayColor( VROverlayHandle_t ulOverlayHandle, float *pfRed, float *pfGreen, float *pfBlue ) = 0;
void IVROverlay::GetOverlayColor(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    float fRed, fGreen, fBlue;
    vr::EVROverlayError error = obj->self_->GetOverlayColor(ulOverlayHandle, &fRed, &fGreen, &fBlue);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }

    Local<Object> result = Nan::New<Object>();
    {
        Local<String> left_prop = Nan::New<String>("red").ToLocalChecked();
        Nan::Set(result, left_prop, Nan::New<Number>(fRed));

        Local<String> right_prop = Nan::New<String>("green").ToLocalChecked();
        Nan::Set(result, right_prop, Nan::New<Number>(fGreen));

        Local<String> top_prop = Nan::New<String>("blue").ToLocalChecked();
        Nan::Set(result, top_prop, Nan::New<Number>(fBlue));
    }

    info.GetReturnValue().Set(result);
}
// virtual EVROverlayError SetOverlayAlpha( VROverlayHandle_t ulOverlayHandle, float fAlpha ) = 0;
void IVROverlay::SetOverlayAlpha(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    float fAlpha = info[1]->NumberValue(context).FromJust();
    vr::EVROverlayError error = obj->self_->SetOverlayAlpha(ulOverlayHandle, fAlpha);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }
}
// virtual EVROverlayError GetOverlayAlpha( VROverlayHandle_t ulOverlayHandle, float *pfAlpha ) = 0;
void IVROverlay::GetOverlayAlpha(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    float fAlpha;
    vr::EVROverlayError error = obj->self_->GetOverlayAlpha(ulOverlayHandle, &fAlpha);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }

    info.GetReturnValue().Set(Nan::New<Number>(fAlpha));
}
// virtual EVROverlayError SetOverlayTexelAspect( VROverlayHandle_t ulOverlayHandle, float fTexelAspect ) = 0;
void IVROverlay::SetOverlayTexelAspect(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    float fTexelAspect = info[1]->NumberValue(context).FromJust();
    vr::EVROverlayError error = obj->self_->SetOverlayTexelAspect(ulOverlayHandle, fTexelAspect);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }
}
// virtual EVROverlayError GetOverlayTexelAspect( VROverlayHandle_t ulOverlayHandle, float *pfTexelAspect ) = 0;
void IVROverlay::GetOverlayTexelAspect(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    float pfTexelAspect;
    vr::EVROverlayError error = obj->self_->GetOverlayTexelAspect(ulOverlayHandle, &pfTexelAspect);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }

    info.GetReturnValue().Set(Nan::New<Number>(pfTexelAspect));
}
// virtual EVROverlayError SetOverlaySortOrder( VROverlayHandle_t ulOverlayHandle, uint32_t unSortOrder ) = 0;
void IVROverlay::SetOverlaySortOrder(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    uint32_t unSortOrder = info[1]->NumberValue(context).FromJust();
    vr::EVROverlayError error = obj->self_->SetOverlaySortOrder(ulOverlayHandle, unSortOrder);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }
}
// virtual EVROverlayError GetOverlaySortOrder( VROverlayHandle_t ulOverlayHandle, uint32_t *punSortOrder ) = 0;
void IVROverlay::GetOverlaySortOrder(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    uint32_t punSortOrder;
    vr::EVROverlayError error = obj->self_->GetOverlaySortOrder(ulOverlayHandle, &punSortOrder);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }

    info.GetReturnValue().Set(Nan::New<Number>(punSortOrder));
}
// virtual EVROverlayError SetOverlayWidthInMeters( VROverlayHandle_t ulOverlayHandle, float fWidthInMeters ) = 0;
void IVROverlay::SetOverlayWidthInMeters(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    float fWidthInMeters = info[1]->NumberValue(context).FromJust();
    vr::EVROverlayError error = obj->self_->SetOverlayWidthInMeters(ulOverlayHandle, fWidthInMeters);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }
}
// virtual EVROverlayError GetOverlayWidthInMeters( VROverlayHandle_t ulOverlayHandle, float *pfWidthInMeters ) = 0;
void IVROverlay::GetOverlayWidthInMeters(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    float fWidthInMeters;
    vr::EVROverlayError error = obj->self_->GetOverlayWidthInMeters(ulOverlayHandle, &fWidthInMeters);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }

    info.GetReturnValue().Set(Nan::New<Number>(fWidthInMeters));
}
// virtual EVROverlayError SetOverlayCurvature( VROverlayHandle_t ulOverlayHandle, float fCurvature ) = 0;
void IVROverlay::SetOverlayCurvature(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    float fCurvature = info[1]->NumberValue(context).FromJust();
    vr::EVROverlayError error = obj->self_->SetOverlayCurvature(ulOverlayHandle, fCurvature);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }
}
// virtual EVROverlayError GetOverlayCurvature( VROverlayHandle_t ulOverlayHandle, float *pfCurvature ) = 0;
void IVROverlay::GetOverlayCurvature(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVROverlay *obj = Nan::ObjectWrap::Unwrap<IVROverlay>(info.Holder());

    vr::VROverlayHandle_t ulOverlayHandle = static_cast<vr::VROverlayHandle_t>(info[0]->Uint32Value(context).FromJust());
    float pfCurvature;
    vr::EVROverlayError error = obj->self_->GetOverlayCurvature(ulOverlayHandle, &pfCurvature);

    if(error != vr::VROverlayError_None)
    {
        Nan::ThrowError(obj->self_->GetOverlayErrorNameFromEnum(error));
        return;
    }

    info.GetReturnValue().Set(Nan::New<Number>(pfCurvature));
}
// virtual EVROverlayError SetOverlayTextureColorSpace( VROverlayHandle_t ulOverlayHandle, EColorSpace eTextureColorSpace ) = 0;
void SetOverlayTextureColorSpace(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError GetOverlayTextureColorSpace( VROverlayHandle_t ulOverlayHandle, EColorSpace *peTextureColorSpace ) = 0;
void GetOverlayTextureColorSpace(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetOverlayTextureBounds( VROverlayHandle_t ulOverlayHandle, const VRTextureBounds_t *pOverlayTextureBounds ) = 0;
void SetOverlayTextureBounds(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError GetOverlayTextureBounds( VROverlayHandle_t ulOverlayHandle, VRTextureBounds_t *pOverlayTextureBounds ) = 0;
void GetOverlayTextureBounds(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError GetOverlayTransformType( VROverlayHandle_t ulOverlayHandle, VROverlayTransformType *peTransformType ) = 0;
void GetOverlayTransformType(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetOverlayTransformAbsolute( VROverlayHandle_t ulOverlayHandle, ETrackingUniverseOrigin eTrackingOrigin, const HmdMatrix34_t *pmatTrackingOriginToOverlayTransform ) = 0;
void SetOverlayTransformAbsolute(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError GetOverlayTransformAbsolute( VROverlayHandle_t ulOverlayHandle, ETrackingUniverseOrigin *peTrackingOrigin, HmdMatrix34_t *pmatTrackingOriginToOverlayTransform ) = 0;
void GetOverlayTransformAbsolute(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetOverlayTransformTrackedDeviceRelative( VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t unTrackedDevice, const HmdMatrix34_t *pmatTrackedDeviceToOverlayTransform ) = 0;
void SetOverlayTransformTrackedDeviceRelative(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError GetOverlayTransformTrackedDeviceRelative( VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t *punTrackedDevice, HmdMatrix34_t *pmatTrackedDeviceToOverlayTransform ) = 0;
void GetOverlayTransformTrackedDeviceRelative(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetOverlayTransformTrackedDeviceComponent( VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t unDeviceIndex, const char *pchComponentName ) = 0;
void SetOverlayTransformTrackedDeviceComponent(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError GetOverlayTransformTrackedDeviceComponent( VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t *punDeviceIndex, VR_OUT_STRING() char *pchComponentName, uint32_t unComponentNameSize ) = 0;
void GetOverlayTransformTrackedDeviceComponent(const Nan::FunctionCallbackInfo<Value> &info);
// virtual vr::EVROverlayError GetOverlayTransformOverlayRelative( VROverlayHandle_t ulOverlayHandle, VROverlayHandle_t *ulOverlayHandleParent, HmdMatrix34_t *pmatParentOverlayToOverlayTransform ) = 0;
void GetOverlayTransformOverlayRelative(const Nan::FunctionCallbackInfo<Value> &info);
// virtual vr::EVROverlayError SetOverlayTransformOverlayRelative( VROverlayHandle_t ulOverlayHandle, VROverlayHandle_t ulOverlayHandleParent, const HmdMatrix34_t *pmatParentOverlayToOverlayTransform ) = 0;
void SetOverlayTransformOverlayRelative(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetOverlayTransformCursor( VROverlayHandle_t ulCursorOverlayHandle, const HmdVector2_t *pvHotspot ) = 0;
void SetOverlayTransformCursor(const Nan::FunctionCallbackInfo<Value> &info);
// virtual vr::EVROverlayError GetOverlayTransformCursor( VROverlayHandle_t ulOverlayHandle, HmdVector2_t *pvHotspot ) = 0;
void GetOverlayTransformCursor(const Nan::FunctionCallbackInfo<Value> &info);
// virtual vr::EVROverlayError SetOverlayTransformProjection( VROverlayHandle_t ulOverlayHandle,
//		ETrackingUniverseOrigin eTrackingOrigin, const HmdMatrix34_t* pmatTrackingOriginToOverlayTransform,
//		const VROverlayProjection_t *pProjection, vr::EVREye eEye ) = 0;
void SetOverlayTransformProjection(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError ShowOverlay( VROverlayHandle_t ulOverlayHandle ) = 0;
void ShowOverlay(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError HideOverlay( VROverlayHandle_t ulOverlayHandle ) = 0;
void HideOverlay(const Nan::FunctionCallbackInfo<Value> &info);
// virtual bool IsOverlayVisible( VROverlayHandle_t ulOverlayHandle ) = 0;
void IsOverlayVisible(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError GetTransformForOverlayCoordinates( VROverlayHandle_t ulOverlayHandle, ETrackingUniverseOrigin eTrackingOrigin, HmdVector2_t coordinatesInOverlay, HmdMatrix34_t *pmatTransform ) = 0;
void GetTransformForOverlayCoordinates(const Nan::FunctionCallbackInfo<Value> &info);

// ---------------------------------------------
// Overlay input methods
// ---------------------------------------------

// virtual bool PollNextOverlayEvent( VROverlayHandle_t ulOverlayHandle, VREvent_t *pEvent, uint32_t uncbVREvent ) = 0;
void PollNextOverlayEvent(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError GetOverlayInputMethod( VROverlayHandle_t ulOverlayHandle, VROverlayInputMethod *peInputMethod ) = 0;
void GetOverlayInputMethod(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetOverlayInputMethod( VROverlayHandle_t ulOverlayHandle, VROverlayInputMethod eInputMethod ) = 0;
void SetOverlayInputMethod(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError GetOverlayMouseScale( VROverlayHandle_t ulOverlayHandle, HmdVector2_t *pvecMouseScale ) = 0;
void GetOverlayMouseScale(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetOverlayMouseScale( VROverlayHandle_t ulOverlayHandle, const HmdVector2_t *pvecMouseScale ) = 0;
void SetOverlayMouseScale(const Nan::FunctionCallbackInfo<Value> &info);
// virtual bool ComputeOverlayIntersection( VROverlayHandle_t ulOverlayHandle, const VROverlayIntersectionParams_t *pParams, VROverlayIntersectionResults_t *pResults ) = 0;
void ComputeOverlayIntersection(const Nan::FunctionCallbackInfo<Value> &info);
// virtual bool IsHoverTargetOverlay( VROverlayHandle_t ulOverlayHandle ) = 0;
void IsHoverTargetOverlay(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetOverlayIntersectionMask( VROverlayHandle_t ulOverlayHandle, VROverlayIntersectionMaskPrimitive_t *pMaskPrimitives, uint32_t unNumMaskPrimitives, uint32_t unPrimitiveSize = sizeof( VROverlayIntersectionMaskPrimitive_t ) ) = 0;
void SetOverlayIntersectionMask(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError TriggerLaserMouseHapticVibration( VROverlayHandle_t ulOverlayHandle, float fDurationSeconds, float fFrequency, float fAmplitude ) = 0;
void TriggerLaserMouseHapticVibration(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetOverlayCursor( VROverlayHandle_t ulOverlayHandle, VROverlayHandle_t ulCursorHandle ) = 0;
void SetOverlayCursor(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetOverlayCursorPositionOverride( VROverlayHandle_t ulOverlayHandle, const HmdVector2_t *pvCursor ) = 0;
void SetOverlayCursorPositionOverride(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError ClearOverlayCursorPositionOverride( VROverlayHandle_t ulOverlayHandle ) = 0;
void ClearOverlayCursorPositionOverride(const Nan::FunctionCallbackInfo<Value> &info);

// ---------------------------------------------
// Overlay texture methods
// ---------------------------------------------

// virtual EVROverlayError SetOverlayTexture( VROverlayHandle_t ulOverlayHandle, const Texture_t *pTexture ) = 0;
void SetOverlayTexture(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError ClearOverlayTexture( VROverlayHandle_t ulOverlayHandle ) = 0;
void ClearOverlayTexture(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetOverlayRaw( VROverlayHandle_t ulOverlayHandle, void *pvBuffer, uint32_t unWidth, uint32_t unHeight, uint32_t unBytesPerPixel ) = 0;
void SetOverlayRaw(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetOverlayFromFile( VROverlayHandle_t ulOverlayHandle, const char *pchFilePath ) = 0;
void SetOverlayFromFile(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError GetOverlayTexture( VROverlayHandle_t ulOverlayHandle, void **pNativeTextureHandle, void *pNativeTextureRef, uint32_t *pWidth, uint32_t *pHeight, uint32_t *pNativeFormat, ETextureType *pAPIType, EColorSpace *pColorSpace, VRTextureBounds_t *pTextureBounds ) = 0;
void GetOverlayTexture(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError ReleaseNativeOverlayHandle( VROverlayHandle_t ulOverlayHandle, void *pNativeTextureHandle ) = 0;
void ReleaseNativeOverlayHandle(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError GetOverlayTextureSize( VROverlayHandle_t ulOverlayHandle, uint32_t *pWidth, uint32_t *pHeight ) = 0;
void GetOverlayTextureSize(const Nan::FunctionCallbackInfo<Value> &info);

// ----------------------------------------------
// Dashboard Overlay Methods
// ----------------------------------------------

// virtual EVROverlayError CreateDashboardOverlay( const char *pchOverlayKey, const char *pchOverlayFriendlyName, VROverlayHandle_t * pMainHandle, VROverlayHandle_t *pThumbnailHandle ) = 0;
void CreateDashboardOverlay(const Nan::FunctionCallbackInfo<Value> &info);
// virtual bool IsDashboardVisible() = 0;
void IsDashboardVisible(const Nan::FunctionCallbackInfo<Value> &info);
// virtual bool IsActiveDashboardOverlay( VROverlayHandle_t ulOverlayHandle ) = 0;
void IsActiveDashboardOverlay(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError SetDashboardOverlaySceneProcess( VROverlayHandle_t ulOverlayHandle, uint32_t unProcessId ) = 0;
void SetDashboardOverlaySceneProcess(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError GetDashboardOverlaySceneProcess( VROverlayHandle_t ulOverlayHandle, uint32_t *punProcessId ) = 0;
void GetDashboardOverlaySceneProcess(const Nan::FunctionCallbackInfo<Value> &info);
// virtual void ShowDashboard( const char *pchOverlayToShow ) = 0;
void ShowDashboard(const Nan::FunctionCallbackInfo<Value> &info);
// virtual vr::TrackedDeviceIndex_t GetPrimaryDashboardDevice() = 0;
void GetPrimaryDashboardDevice(const Nan::FunctionCallbackInfo<Value> &info);

// ---------------------------------------------
// Keyboard methods
// ---------------------------------------------

// virtual EVROverlayError ShowKeyboard( EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, uint32_t unFlags,
//		const char *pchDescription, uint32_t unCharMax, const char *pchExistingText, uint64_t uUserValue ) = 0;
void ShowKeyboard(const Nan::FunctionCallbackInfo<Value> &info);
// virtual EVROverlayError ShowKeyboardForOverlay( VROverlayHandle_t ulOverlayHandle, EGamepadTextInputMode eInputMode,
//		EGamepadTextInputLineMode eLineInputMode, uint32_t unFlags, const char *pchDescription, uint32_t unCharMax,
//		const char *pchExistingText, uint64_t uUserValue ) = 0;
void ShowKeyboardForOverlay(const Nan::FunctionCallbackInfo<Value> &info);
// virtual uint32_t GetKeyboardText( VR_OUT_STRING() char *pchText, uint32_t cchText ) = 0;
void GetKeyboardText(const Nan::FunctionCallbackInfo<Value> &info);
// virtual void HideKeyboard() = 0;
void HideKeyboard(const Nan::FunctionCallbackInfo<Value> &info);
// virtual void SetKeyboardTransformAbsolute( ETrackingUniverseOrigin eTrackingOrigin, const HmdMatrix34_t *pmatTrackingOriginToKeyboardTransform ) = 0;
void SetKeyboardTransformAbsolute(const Nan::FunctionCallbackInfo<Value> &info);
// virtual void SetKeyboardPositionForOverlay( VROverlayHandle_t ulOverlayHandle, HmdRect2_t avoidRect ) = 0;
void SetKeyboardPositionForOverlay(const Nan::FunctionCallbackInfo<Value> &info);

// ---------------------------------------------
// Message box methods
// ---------------------------------------------

// virtual VRMessageOverlayResponse ShowMessageOverlay( const char* pchText, const char* pchCaption, const char* pchButton0Text, const char* pchButton1Text = nullptr, const char* pchButton2Text = nullptr, const char* pchButton3Text = nullptr ) = 0;
void ShowMessageOverlay(const Nan::FunctionCallbackInfo<Value> &info);
// virtual void CloseMessageOverlay() = 0;
void CloseMessageOverlay(const Nan::FunctionCallbackInfo<Value> &info);