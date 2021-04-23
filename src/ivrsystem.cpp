#include "ivrsystem.h"
#include "util.h"

#include <array>
#include <node.h>
#include <openvr.h>

using namespace v8;

using TrackedDevicePoseArray = std::array<vr::TrackedDevicePose_t, vr::k_unMaxTrackedDeviceCount>;
using TrackedDeviceIndexArray = std::array<vr::TrackedDeviceIndex_t, vr::k_unMaxTrackedDeviceCount>;

void IVRSystem::Init(Local<Object> exports)
{
    Local<Context> context = exports->CreationContext();
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("IVRSystem").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "GetRecommendedRenderTargetSize", GetRecommendedRenderTargetSize);
    Nan::SetPrototypeMethod(tpl, "GetProjectionMatrix", GetProjectionMatrix);
    Nan::SetPrototypeMethod(tpl, "GetProjectionRaw", GetProjectionRaw);
    Nan::SetPrototypeMethod(tpl, "ComputeDistortion", ComputeDistortion);
    Nan::SetPrototypeMethod(tpl, "GetEyeToHeadTransform", GetEyeToHeadTransform);
    Nan::SetPrototypeMethod(tpl, "GetTimeSinceLastVsync", GetTimeSinceLastVsync);
    Nan::SetPrototypeMethod(tpl, "GetD3D9AdapterIndex", GetD3D9AdapterIndex);
    Nan::SetPrototypeMethod(tpl, "GetDXGIOutputInfo", GetDXGIOutputInfo);
    Nan::SetPrototypeMethod(tpl, "GetOutputDevice", GetOutputDevice);

    Nan::SetPrototypeMethod(tpl, "IsDisplayOnDesktop", IsDisplayOnDesktop);
    Nan::SetPrototypeMethod(tpl, "SetDisplayVisibility", SetDisplayVisibility);

    Nan::SetPrototypeMethod(tpl, "GetDeviceToAbsoluteTrackingPose", GetDeviceToAbsoluteTrackingPose);
    Nan::SetPrototypeMethod(tpl, "GetSeatedZeroPoseToStandingAbsoluteTrackingPose", GetSeatedZeroPoseToStandingAbsoluteTrackingPose);
    Nan::SetPrototypeMethod(tpl, "GetRawZeroPoseToStandingAbsoluteTrackingPose", GetRawZeroPoseToStandingAbsoluteTrackingPose);
    Nan::SetPrototypeMethod(tpl, "GetSortedTrackedDeviceIndicesOfClass", GetSortedTrackedDeviceIndicesOfClass);
    Nan::SetPrototypeMethod(tpl, "GetTrackedDeviceActivityLevel", GetTrackedDeviceActivityLevel);
    Nan::SetPrototypeMethod(tpl, "ApplyTransform", ApplyTransform);
    Nan::SetPrototypeMethod(tpl, "GetTrackedDeviceIndexForControllerRole", GetTrackedDeviceIndexForControllerRole);
    Nan::SetPrototypeMethod(tpl, "GetControllerRoleForTrackedDeviceIndex", GetControllerRoleForTrackedDeviceIndex);

    Nan::SetPrototypeMethod(tpl, "GetTrackedDeviceClass", GetTrackedDeviceClass);
    Nan::SetPrototypeMethod(tpl, "IsTrackedDeviceConnected", IsTrackedDeviceConnected);
    Nan::SetPrototypeMethod(tpl, "GetBoolTrackedDeviceProperty", GetBoolTrackedDeviceProperty);
    Nan::SetPrototypeMethod(tpl, "GetFloatTrackedDeviceProperty", GetFloatTrackedDeviceProperty);
    Nan::SetPrototypeMethod(tpl, "GetInt32TrackedDeviceProperty", GetInt32TrackedDeviceProperty);
    Nan::SetPrototypeMethod(tpl, "GetUint64TrackedDeviceProperty", GetUint64TrackedDeviceProperty);
    Nan::SetPrototypeMethod(tpl, "GetMatrix34TrackedDeviceProperty", GetMatrix34TrackedDeviceProperty);
    Nan::SetPrototypeMethod(tpl, "GetStringTrackedDeviceProperty", GetStringTrackedDeviceProperty);
    Nan::SetPrototypeMethod(tpl, "GetPropErrorNameFromEnum", GetPropErrorNameFromEnum);

    Nan::SetPrototypeMethod(tpl, "PollNextEvent", PollNextEvent);
    Nan::SetPrototypeMethod(tpl, "PollNextEventWithPose", PollNextEventWithPose);
    Nan::SetPrototypeMethod(tpl, "GetEventTypeNameFromEnum", GetEventTypeNameFromEnum);

    Nan::SetPrototypeMethod(tpl, "GetHiddenAreaMesh", GetHiddenAreaMesh);

    Nan::SetPrototypeMethod(tpl, "GetControllerState", GetControllerState);
    Nan::SetPrototypeMethod(tpl, "GetControllerStateWithPose", GetControllerStateWithPose);
    Nan::SetPrototypeMethod(tpl, "TriggerHapticPulse", TriggerHapticPulse);
    Nan::SetPrototypeMethod(tpl, "GetButtonIdNameFromEnum", GetButtonIdNameFromEnum);
    Nan::SetPrototypeMethod(tpl, "GetControllerAxisTypeNameFromEnum", GetControllerAxisTypeNameFromEnum);
    Nan::SetPrototypeMethod(tpl, "IsInputAvailable", IsInputAvailable);
    Nan::SetPrototypeMethod(tpl, "IsSteamVRDrawingControllers", IsSteamVRDrawingControllers);
    Nan::SetPrototypeMethod(tpl, "ShouldApplicationPause", ShouldApplicationPause);
    Nan::SetPrototypeMethod(tpl, "ShouldApplicationReduceRenderingWork", ShouldApplicationReduceRenderingWork);

    Nan::SetPrototypeMethod(tpl, "PerformFirmwareUpdate", PerformFirmwareUpdate);

    Nan::SetPrototypeMethod(tpl, "AcknowledgeQuit_Exiting", AcknowledgeQuit_Exiting);

    Nan::SetPrototypeMethod(tpl, "GetAppContainerFilePaths", GetAppContainerFilePaths);

    Nan::SetPrototypeMethod(tpl, "GetRuntimeVersion", GetRuntimeVersion);

    constructor.Reset(tpl->GetFunction(context).ToLocalChecked());
    exports->Set(
        context,
        Nan::New("IVRSystem").ToLocalChecked(),
        tpl->GetFunction(context).ToLocalChecked());
}

Local<Object> IVRSystem::NewInstance(vr::IVRSystem *system)
{
    Nan::EscapableHandleScope scope;
    Local<Function> cons = Nan::New(constructor);
    Local<Value> argv[1] = {Nan::New<External>(system)};
    return scope.Escape(Nan::NewInstance(cons, 1, argv).ToLocalChecked());
}

IVRSystem::IVRSystem(vr::IVRSystem *self)
    : self_(self)
{
}

void IVRSystem::New(const Nan::FunctionCallbackInfo<Value> &info)
{
    if (!info.IsConstructCall())
    {
        Nan::ThrowError("Use the `new` keyword when creating a new instance.");
        return;
    }

    if (info.Length() != 1 || !info[0]->IsExternal())
    {
        Nan::ThrowTypeError("Argument[0] must be an `IVRSystem*`.");
        return;
    }

    auto wrapped_instance = static_cast<vr::IVRSystem *>(
        Local<External>::Cast(info[0])->Value());
    IVRSystem *obj = new IVRSystem(wrapped_instance);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

void IVRSystem::GetRecommendedRenderTargetSize(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 0)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    uint32_t nWidth, nHeight;
    obj->self_->GetRecommendedRenderTargetSize(&nWidth, &nHeight);

    Local<Object> result = Nan::New<Object>();
    {
        Local<String> width_prop = Nan::New<String>("width").ToLocalChecked();
        Nan::Set(result, width_prop, Nan::New<Number>(nWidth));

        Local<String> height_prop = Nan::New<String>("height").ToLocalChecked();
        Nan::Set(result, height_prop, Nan::New<Number>(nHeight));
    }

    info.GetReturnValue().Set(result);
}

void IVRSystem::GetProjectionMatrix(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 3)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsNumber())
    {
        Nan::ThrowError("Argument[0] must be a number (EVREye).");
        return;
    }

    uint32_t nEye = info[0]->Uint32Value(context).FromJust();
    if (nEye >= 2)
    {
        Nan::ThrowError("Argument[0] was out of enum range (EVREye).");
        return;
    }

    if (!info[1]->IsNumber())
    {
        Nan::ThrowError("Argument[1] must be a number.");
        return;
    }

    if (!info[2]->IsNumber())
    {
        Nan::ThrowError("Argument[2] must be a number.");
        return;
    }

    vr::EVREye eEye = static_cast<vr::EVREye>(nEye);
    float fNearZ = static_cast<float>(info[1]->NumberValue(context).FromJust());
    float fFarZ = static_cast<float>(info[2]->NumberValue(context).FromJust());
    vr::HmdMatrix44_t matrix = obj->self_->GetProjectionMatrix(eEye, fNearZ, fFarZ);

    info.GetReturnValue().Set(encode(matrix));
}

void IVRSystem::GetProjectionRaw(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 1)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsNumber())
    {
        Nan::ThrowError("Argument[0] must be a number (EVREye).");
        return;
    }

    uint32_t nEye = info[0]->Uint32Value(context).FromJust();
    if (nEye >= 2)
    {
        Nan::ThrowError("Argument[0] was out of enum range (EVREye).");
        return;
    }

    vr::EVREye eEye = static_cast<vr::EVREye>(nEye);
    float pfLeft, pfRight, pfTop, pfBottom;
    obj->self_->GetProjectionRaw(eEye, &pfLeft, &pfRight, &pfTop, &pfBottom);

    Local<Object> result = Nan::New<Object>();
    {
        Local<String> left_prop = Nan::New<String>("left").ToLocalChecked();
        Nan::Set(result, left_prop, Nan::New<Number>(pfLeft));

        Local<String> right_prop = Nan::New<String>("right").ToLocalChecked();
        Nan::Set(result, right_prop, Nan::New<Number>(pfRight));

        Local<String> top_prop = Nan::New<String>("top").ToLocalChecked();
        Nan::Set(result, top_prop, Nan::New<Number>(pfTop));

        Local<String> bottom_prop = Nan::New<String>("bottom").ToLocalChecked();
        Nan::Set(result, bottom_prop, Nan::New<Number>(pfBottom));
    }

    info.GetReturnValue().Set(result);
}

void IVRSystem::ComputeDistortion(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 3)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsNumber())
    {
        Nan::ThrowError("Argument[0] must be a number (EVREye).");
        return;
    }

    uint32_t nEye = info[0]->Uint32Value(context).FromJust();
    if (nEye >= 2)
    {
        Nan::ThrowError("Argument[0] was out of enum range (EVREye).");
        return;
    }

    if (!info[1]->IsNumber())
    {
        Nan::ThrowError("Argument[1] must be a number");
        return;
    }

    if (!info[2]->IsNumber())
    {
        Nan::ThrowError("Argument[2] must be a number");
        return;
    }

    vr::EVREye eEye = static_cast<vr::EVREye>(nEye);
    float fU = static_cast<float>(info[1]->NumberValue(context).FromJust());
    float fV = static_cast<float>(info[2]->NumberValue(context).FromJust());
    vr::DistortionCoordinates_t distortionCoordinates;
    bool success = obj->self_->ComputeDistortion(eEye, fU, fV, &distortionCoordinates);

    if(!success)
    {
        Nan::ThrowError("Distortion coordinates not suitable.");
        return;
    }
    info.GetReturnValue().Set(encode(distortionCoordinates));
}

void IVRSystem::GetEyeToHeadTransform(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 1)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsNumber())
    {
        Nan::ThrowError("Argument[0] must be a number (EVREye).");
        return;
    }

    uint32_t nEye = info[0]->Uint32Value(context).FromJust();
    if (nEye >= 2)
    {
        Nan::ThrowError("Argument[0] was out of enum range (EVREye).");
        return;
    }

    vr::EVREye eEye = static_cast<vr::EVREye>(nEye);
    vr::HmdMatrix34_t matrix = obj->self_->GetEyeToHeadTransform(eEye);

    info.GetReturnValue().Set(encode(matrix));
}

void IVRSystem::GetTimeSinceLastVsync(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if(info.Length() != 0) {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    float fSecondsSinceLastVsync;
    uint64_t ulFrameCounter;
    bool success = obj->self_->GetTimeSinceLastVsync(&fSecondsSinceLastVsync, &ulFrameCounter);

    if(!success)
    {
        Nan::ThrowError("Arguments not suitable.");
        return;
    }

    Local<Object> result = Nan::New<Object>();
    {
        Local<String> seconds_prop = Nan::New<String>("seconds").ToLocalChecked();
        Nan::Set(result, seconds_prop, Nan::New<Number>(fSecondsSinceLastVsync));

        Local<String> frame_prop = Nan::New<String>("frame").ToLocalChecked();
        Nan::Set(result, frame_prop, Nan::New<Number>(static_cast<uint32_t>(ulFrameCounter)));
    }
    info.GetReturnValue().Set(result);
}

void IVRSystem::GetD3D9AdapterIndex(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if(info.Length() != 0) {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    int32_t uIndex = obj->self_->GetD3D9AdapterIndex();
    info.GetReturnValue().Set(Nan::New<Number>(uIndex));
}

void IVRSystem::GetDXGIOutputInfo(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if(info.Length() != 0) {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    int32_t nAdapterIndex;
    obj->self_->GetDXGIOutputInfo(&nAdapterIndex);
    info.GetReturnValue().Set(Nan::New<Number>(nAdapterIndex));
}

void IVRSystem::GetOutputDevice(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if(info.Length() != 1) {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsNumber())
    {
        Nan::ThrowError("Argument[0] must be a number (ETextureType).");
        return;
    }

    uint32_t nTextureType = info[0]->Uint32Value(context).FromJust();
    if (nTextureType >= 7)
    {
        Nan::ThrowError("Argument[0] was out of enum range (ETextureType).");
        return;
    }

    uint64_t nDevice;
    vr::ETextureType textureType = static_cast<vr::ETextureType>(nTextureType);
    obj->self_->GetOutputDevice(&nDevice, textureType);

    info.GetReturnValue().Set(Nan::New<Number>(nDevice));
}

void IVRSystem::IsDisplayOnDesktop(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if(info.Length() != 0) {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    bool bIsDisplayOnDesktop = obj->self_->IsDisplayOnDesktop();
    info.GetReturnValue().Set(Nan::New<Boolean>(bIsDisplayOnDesktop));
}

void IVRSystem::SetDisplayVisibility(const Nan::FunctionCallbackInfo<Value> &info) {
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if(info.Length() != 1) {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsBoolean())
    {
        Nan::ThrowError("Argument[0] must be a number (ETextureType).");
        return;
    }

    bool bIsVisibleOnDesktop = info[0]->BooleanValue(info.GetIsolate());
    bool bSuccess = obj->self_->SetDisplayVisibility(bIsVisibleOnDesktop);
    info.GetReturnValue().Set(Nan::New<Boolean>(bSuccess));
}

