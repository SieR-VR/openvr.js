#include "ivrsystem.h"
#include "util.h"

#include <array>
#include <node.h>
#include <openvr.h>

using namespace v8;

using TrackedDevicePoseArray = std::array<vr::TrackedDevicePose_t, vr::k_unMaxTrackedDeviceCount>;
using TrackedDeviceIndexArray = std::array<vr::TrackedDeviceIndex_t, vr::k_unMaxTrackedDeviceCount>;

using VREventArray = std::array<vr::VREvent_t, vr::k_unMaxTrackedDeviceCount>;

Nan::Persistent<Function> IVRSystem::constructor;

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
    // Nan::SetPrototypeMethod(tpl, "GetControllerRoleForTrackedDeviceIndex", GetControllerRoleForTrackedDeviceIndex);

    Nan::SetPrototypeMethod(tpl, "GetTrackedDeviceClass", GetTrackedDeviceClass);
    Nan::SetPrototypeMethod(tpl, "IsTrackedDeviceConnected", IsTrackedDeviceConnected);
    Nan::SetPrototypeMethod(tpl, "GetBoolTrackedDeviceProperty", GetBoolTrackedDeviceProperty);
    Nan::SetPrototypeMethod(tpl, "GetFloatTrackedDeviceProperty", GetFloatTrackedDeviceProperty);
    Nan::SetPrototypeMethod(tpl, "GetInt32TrackedDeviceProperty", GetInt32TrackedDeviceProperty);
    Nan::SetPrototypeMethod(tpl, "GetUint64TrackedDeviceProperty", GetUint64TrackedDeviceProperty);
    Nan::SetPrototypeMethod(tpl, "GetMatrix34TrackedDeviceProperty", GetMatrix34TrackedDeviceProperty);
    // Nan::SetPrototypeMethod(tpl, "GetArrayTrackedDeviceProperty", GetArrayTrackedDeviceProperty);
    // Nan::SetPrototypeMethod(tpl, "GetStringTrackedDeviceProperty", GetStringTrackedDeviceProperty);
    // Nan::SetPrototypeMethod(tpl, "GetPropErrorNameFromEnum", GetPropErrorNameFromEnum);

    // Nan::SetPrototypeMethod(tpl, "PollNextEvent", PollNextEvent);
    // Nan::SetPrototypeMethod(tpl, "PollNextEventWithPose", PollNextEventWithPose);
    // Nan::SetPrototypeMethod(tpl, "GetEventTypeNameFromEnum", GetEventTypeNameFromEnum);

    // Nan::SetPrototypeMethod(tpl, "GetHiddenAreaMesh", GetHiddenAreaMesh);

    // Nan::SetPrototypeMethod(tpl, "GetControllerState", GetControllerState);
    // Nan::SetPrototypeMethod(tpl, "GetControllerStateWithPose", GetControllerStateWithPose);
    // Nan::SetPrototypeMethod(tpl, "TriggerHapticPulse", TriggerHapticPulse);
    // Nan::SetPrototypeMethod(tpl, "GetButtonIdNameFromEnum", GetButtonIdNameFromEnum);
    // Nan::SetPrototypeMethod(tpl, "GetControllerAxisTypeNameFromEnum", GetControllerAxisTypeNameFromEnum);
    Nan::SetPrototypeMethod(tpl, "IsInputAvailable", IsInputAvailable);
    Nan::SetPrototypeMethod(tpl, "IsSteamVRDrawingControllers", IsSteamVRDrawingControllers);
    Nan::SetPrototypeMethod(tpl, "ShouldApplicationPause", ShouldApplicationPause);
    Nan::SetPrototypeMethod(tpl, "ShouldApplicationReduceRenderingWork", ShouldApplicationReduceRenderingWork);

    Nan::SetPrototypeMethod(tpl, "PerformFirmwareUpdate", PerformFirmwareUpdate);

    Nan::SetPrototypeMethod(tpl, "AcknowledgeQuit_Exiting", AcknowledgeQuit_Exiting);

    // Nan::SetPrototypeMethod(tpl, "GetAppContainerFilePaths", GetAppContainerFilePaths);

    // Nan::SetPrototypeMethod(tpl, "GetRuntimeVersion", GetRuntimeVersion);

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

    auto wrapped_instance = static_cast<vr::IVRSystem *>(
        Local<External>::Cast(info[0])->Value());
    IVRSystem *obj = new IVRSystem(wrapped_instance);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

// ------------------------------------
// Display Methods
// ------------------------------------

void IVRSystem::GetRecommendedRenderTargetSize(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

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

    vr::EVREye eEye = static_cast<vr::EVREye>(info[0]->Uint32Value(context).FromJust());
    float fNearZ = static_cast<float>(info[1]->NumberValue(context).FromJust());
    float fFarZ = static_cast<float>(info[2]->NumberValue(context).FromJust());
    vr::HmdMatrix44_t matrix = obj->self_->GetProjectionMatrix(eEye, fNearZ, fFarZ);

    info.GetReturnValue().Set(encode(matrix));
}

void IVRSystem::GetProjectionRaw(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    vr::EVREye eEye = static_cast<vr::EVREye>(info[0]->Uint32Value(context).FromJust());
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

    vr::EVREye eEye = static_cast<vr::EVREye>(info[0]->Uint32Value(context).FromJust());
    float fU = static_cast<float>(info[1]->NumberValue(context).FromJust());
    float fV = static_cast<float>(info[2]->NumberValue(context).FromJust());
    vr::DistortionCoordinates_t distortionCoordinates;
    bool success = obj->self_->ComputeDistortion(eEye, fU, fV, &distortionCoordinates);

    if (!success)
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

    vr::EVREye eEye = static_cast<vr::EVREye>(info[0]->Uint32Value(context).FromJust());
    vr::HmdMatrix34_t matrix = obj->self_->GetEyeToHeadTransform(eEye);
    info.GetReturnValue().Set(encode(matrix));
}

void IVRSystem::GetTimeSinceLastVsync(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    float fSecondsSinceLastVsync;
    uint64_t ulFrameCounter;
    bool success = obj->self_->GetTimeSinceLastVsync(&fSecondsSinceLastVsync, &ulFrameCounter);

    if (!success)
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

    int32_t uIndex = obj->self_->GetD3D9AdapterIndex();
    info.GetReturnValue().Set(Nan::New<Number>(uIndex));
}

void IVRSystem::GetDXGIOutputInfo(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    int32_t nAdapterIndex;
    obj->self_->GetDXGIOutputInfo(&nAdapterIndex);
    info.GetReturnValue().Set(Nan::New<Number>(nAdapterIndex));
}

void IVRSystem::GetOutputDevice(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    uint64_t nDevice;
    vr::ETextureType textureType = static_cast<vr::ETextureType>(info[0]->Uint32Value(context).FromJust());
    obj->self_->GetOutputDevice(&nDevice, textureType);

    info.GetReturnValue().Set(Nan::New<Number>(nDevice));
}

// ------------------------------------
// Display Mode methods
// ------------------------------------

void IVRSystem::IsDisplayOnDesktop(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    bool bIsDisplayOnDesktop = obj->self_->IsDisplayOnDesktop();
    info.GetReturnValue().Set(Nan::New<Boolean>(bIsDisplayOnDesktop));
}

void IVRSystem::SetDisplayVisibility(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    bool bIsVisibleOnDesktop = info[0]->BooleanValue(info.GetIsolate());
    bool bSuccess = obj->self_->SetDisplayVisibility(bIsVisibleOnDesktop);
    info.GetReturnValue().Set(Nan::New<Boolean>(bSuccess));
}

// ------------------------------------
// Tracking Methods
// ------------------------------------

void IVRSystem::GetDeviceToAbsoluteTrackingPose(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    vr::ETrackingUniverseOrigin eOrigin = static_cast<vr::ETrackingUniverseOrigin>(info[0]->Uint32Value(context).FromJust());
    float fPredictedSecondsToPhotonsFromNow = static_cast<float>(info[1]->NumberValue(context).FromJust());
    TrackedDevicePoseArray trackedDevicePoseArray;
    obj->self_->GetDeviceToAbsoluteTrackingPose(
        eOrigin, fPredictedSecondsToPhotonsFromNow, trackedDevicePoseArray.data(),
        static_cast<uint32_t>(trackedDevicePoseArray.size()));

    info.GetReturnValue().Set(encode(trackedDevicePoseArray));
}

void IVRSystem::GetSeatedZeroPoseToStandingAbsoluteTrackingPose(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    vr::HmdMatrix34_t matrix = obj->self_->GetSeatedZeroPoseToStandingAbsoluteTrackingPose();
    info.GetReturnValue().Set(encode(matrix));
}

void IVRSystem::GetRawZeroPoseToStandingAbsoluteTrackingPose(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    vr::HmdMatrix34_t matrix = obj->self_->GetRawZeroPoseToStandingAbsoluteTrackingPose();
    info.GetReturnValue().Set(encode(matrix));
}

void IVRSystem::GetSortedTrackedDeviceIndicesOfClass(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() < 1 || info.Length() > 2)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsNumber())
    {
        Nan::ThrowTypeError("Argument[0] must be a number (ETrackedDeviceClass).");
        return;
    }

    uint32_t nTrackedDeviceClass = info[0]->Uint32Value(context).FromJust();
    if (nTrackedDeviceClass >= 6)
    {
        Nan::ThrowTypeError("Argument[0] was out of enum range (ETrackedDeviceClass).");
        return;
    }

    vr::TrackedDeviceIndex_t unRelativeToTrackedDeviceIndex = 0;
    if (!info[1]->IsUndefined())
    {
        if (!info[1]->IsNumber())
        {
            Nan::ThrowTypeError("Argument[1] must be a number.");
            return;
        }
        else
        {
            unRelativeToTrackedDeviceIndex = info[1]->Uint32Value(context).FromJust();
        }
    }

    vr::ETrackedDeviceClass eTrackedDeviceClass =
        static_cast<vr::ETrackedDeviceClass>(nTrackedDeviceClass);
    TrackedDeviceIndexArray trackedDeviceIndexArray;
    uint32_t nDeviceIndices = obj->self_->GetSortedTrackedDeviceIndicesOfClass(
        eTrackedDeviceClass, trackedDeviceIndexArray.data(),
        static_cast<uint32_t>(trackedDeviceIndexArray.size()),
        unRelativeToTrackedDeviceIndex);

    info.GetReturnValue().Set(encode(trackedDeviceIndexArray, nDeviceIndices));
}

void IVRSystem::GetTrackedDeviceActivityLevel(const Nan::FunctionCallbackInfo<Value> &info)
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
        Nan::ThrowTypeError("Argument[0] must be a number.");
        return;
    }

    uint32_t unDeviceId = info[0]->Uint32Value(context).FromJust();
    vr::EDeviceActivityLevel deviceActivityLevel =
        obj->self_->GetTrackedDeviceActivityLevel(unDeviceId);
    info.GetReturnValue().Set(Nan::New<Number>(
        static_cast<uint32_t>(deviceActivityLevel)));
}

void IVRSystem::ApplyTransform(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 2)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsObject())
    {
        Nan::ThrowTypeError("Argument[0] must be a tracked device pose.");
        return;
    }

    if (!info[1]->IsArray())
    {
        Nan::ThrowTypeError("Argument[1] must be a 3x4 matrix.");
        return;
    }

    const auto trackedDevicePose = decode<vr::TrackedDevicePose_t>(info[0], info.GetIsolate());
    const auto transform = decode<vr::HmdMatrix34_t>(info[1], info.GetIsolate());
    vr::TrackedDevicePose_t outputPose;
    obj->self_->ApplyTransform(&outputPose, &trackedDevicePose, &transform);
    info.GetReturnValue().Set(encode(outputPose));
}

void IVRSystem::GetTrackedDeviceIndexForControllerRole(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 1)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[0] must be a tracked controller role.");
        return;
    }

    uint32_t nDeviceType = info[0]->Uint32Value(context).FromJust();
    if (nDeviceType > vr::TrackedControllerRole_Max)
    {
        Nan::ThrowTypeError("Argument[0] was out of enum range (ETrackedControllerRole).");
        return;
    }

    vr::TrackedDeviceIndex_t nDeviceIndex = obj->self_->GetTrackedDeviceIndexForControllerRole(static_cast<vr::ETrackedControllerRole>(nDeviceType));
    info.GetReturnValue().Set(Nan::New<Number>(nDeviceIndex));
}

// ------------------------------------
// Property methods
// ------------------------------------

void IVRSystem::GetTrackedDeviceClass(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 1)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[0] must be a tracked device index.");
        return;
    }

    vr::TrackedDeviceIndex_t nDeviceIndex = static_cast<vr::TrackedDeviceIndex_t>(info[0]->Uint32Value(context).FromJust());

    vr::ETrackedDeviceClass nDeviceClass = obj->self_->GetTrackedDeviceClass(nDeviceIndex);
    info.GetReturnValue().Set(Nan::New<Number>(nDeviceClass));
}

void IVRSystem::IsTrackedDeviceConnected(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 1)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[0] must be a tracked device index.");
        return;
    }

    vr::TrackedDeviceIndex_t nDeviceIndex = static_cast<vr::TrackedDeviceIndex_t>(info[0]->Uint32Value(context).FromJust());

    bool bIsDeviceConnected = obj->self_->IsTrackedDeviceConnected(nDeviceIndex);
    info.GetReturnValue().Set(Nan::New<Boolean>(bIsDeviceConnected));
}

void IVRSystem::GetBoolTrackedDeviceProperty(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 2)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[0] must be a tracked device index.");
        return;
    }
    vr::TrackedDeviceIndex_t nDeviceIndex = static_cast<vr::TrackedDeviceIndex_t>(info[0]->Uint32Value(context).FromJust());

    if (!info[1]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[1] must be a tracked device property.");
        return;
    }
    vr::ETrackedDeviceProperty nDeviceProp = static_cast<vr::ETrackedDeviceProperty>(info[1]->Uint32Value(context).FromJust());

    bool bProp = obj->self_->GetBoolTrackedDeviceProperty(nDeviceIndex, nDeviceProp);
    info.GetReturnValue().Set(Nan::New<Boolean>(bProp));
}

void IVRSystem::GetFloatTrackedDeviceProperty(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 2)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[0] must be a tracked device index.");
        return;
    }
    vr::TrackedDeviceIndex_t nDeviceIndex = static_cast<vr::TrackedDeviceIndex_t>(info[0]->Uint32Value(context).FromJust());

    if (!info[1]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[1] must be a tracked device property.");
        return;
    }
    vr::ETrackedDeviceProperty nDeviceProp = static_cast<vr::ETrackedDeviceProperty>(info[1]->Uint32Value(context).FromJust());

    float fProp = obj->self_->GetFloatTrackedDeviceProperty(nDeviceIndex, nDeviceProp);
    info.GetReturnValue().Set(Nan::New<Number>(fProp));
}

void IVRSystem::GetInt32TrackedDeviceProperty(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 2)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[0] must be a tracked device index.");
        return;
    }
    vr::TrackedDeviceIndex_t nDeviceIndex = static_cast<vr::TrackedDeviceIndex_t>(info[0]->Uint32Value(context).FromJust());

    if (!info[1]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[1] must be a tracked device property.");
        return;
    }
    vr::ETrackedDeviceProperty nDeviceProp = static_cast<vr::ETrackedDeviceProperty>(info[1]->Uint32Value(context).FromJust());

    int32_t iProp = obj->self_->GetInt32TrackedDeviceProperty(nDeviceIndex, nDeviceProp);
    info.GetReturnValue().Set(Nan::New<Number>(iProp));
}

void IVRSystem::GetUint64TrackedDeviceProperty(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 2)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[0] must be a tracked device index.");
        return;
    }
    vr::TrackedDeviceIndex_t nDeviceIndex = static_cast<vr::TrackedDeviceIndex_t>(info[0]->Uint32Value(context).FromJust());

    if (!info[1]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[1] must be a tracked device property.");
        return;
    }
    vr::ETrackedDeviceProperty nDeviceProp = static_cast<vr::ETrackedDeviceProperty>(info[1]->Uint32Value(context).FromJust());

    uint64_t uiProp = obj->self_->GetUint64TrackedDeviceProperty(nDeviceIndex, nDeviceProp);
    info.GetReturnValue().Set(Nan::New<Number>(uiProp));
}

void IVRSystem::GetMatrix34TrackedDeviceProperty(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 2)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[0] must be a tracked device index.");
        return;
    }
    vr::TrackedDeviceIndex_t nDeviceIndex = static_cast<vr::TrackedDeviceIndex_t>(info[0]->Uint32Value(context).FromJust());

    if (!info[1]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[1] must be a tracked device property.");
        return;
    }
    vr::ETrackedDeviceProperty nDeviceProp = static_cast<vr::ETrackedDeviceProperty>(info[1]->Uint32Value(context).FromJust());

    vr::HmdMatrix34_t matrixProp = obj->self_->GetMatrix34TrackedDeviceProperty(nDeviceIndex, nDeviceProp);
    info.GetReturnValue().Set(encode(matrixProp));
}

void IVRSystem::IsInputAvailable(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 0)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    bool bIsInputAvailable = obj->self_->IsInputAvailable();
    info.GetReturnValue().Set(Nan::New<Boolean>(bIsInputAvailable));
}

void IVRSystem::IsSteamVRDrawingControllers(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 0)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    bool bIsSteamVRDrawingControllers = obj->self_->IsSteamVRDrawingControllers();
    info.GetReturnValue().Set(Nan::New<Boolean>(bIsSteamVRDrawingControllers));
}

void IVRSystem::ShouldApplicationPause(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 0)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    bool bShouldApplicationPause = obj->self_->ShouldApplicationPause();
    info.GetReturnValue().Set(Nan::New<Boolean>(bShouldApplicationPause));
}

void IVRSystem::ShouldApplicationReduceRenderingWork(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 0)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    bool bShouldApplicationReduceRenderingWork = obj->self_->ShouldApplicationReduceRenderingWork();
    info.GetReturnValue().Set(Nan::New<Boolean>(bShouldApplicationReduceRenderingWork));
}

void IVRSystem::PerformFirmwareUpdate(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 1)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if(!info[0]->IsUint32())
    {
        Nan::ThrowTypeError("Argument[0] must be a tracked device index");
        return;
    }
    vr::TrackedDeviceIndex_t uiTrackedDeviceIndex = info[0]->Uint32Value(context).FromJust();

    vr::EVRFirmwareError unVRFirmwareError = obj->self_->PerformFirmwareUpdate(uiTrackedDeviceIndex);
    info.GetReturnValue().Set(Nan::New<Number>(static_cast<uint32_t>(unVRFirmwareError)));
}

void IVRSystem::AcknowledgeQuit_Exiting(const Nan::FunctionCallbackInfo<Value> &info)
{
    IVRSystem *obj = Nan::ObjectWrap::Unwrap<IVRSystem>(info.Holder());

    if (info.Length() != 0)
    {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    obj->self_->AcknowledgeQuit_Exiting();
}

