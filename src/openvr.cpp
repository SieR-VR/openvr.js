#include "openvr.h"
#include "ivrsystem.h"
#include "ivroverlay.h"
#include "ivrapplications.h"

#include <node.h>
#include <openvr.h>
#include <v8.h>

using namespace v8;

void VR_Init(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();

    uint32_t applicationType = info[0]->NumberValue(context).FromJust();
    constexpr uint32_t applicationTypeMax = vr::VRApplication_Max;

    vr::EVRInitError error;
    vr::IVRSystem *system = vr::VR_Init(&error, static_cast<vr::EVRApplicationType>(applicationType));

    if (!system)
    {
        Nan::ThrowError(vr::VR_GetVRInitErrorAsEnglishDescription(error));
        return;
    }

    auto result = IVRSystem::NewInstance(system);
    info.GetReturnValue().Set(result);
}

void VR_Shutdown(const Nan::FunctionCallbackInfo<Value> &info)
{
    vr::VR_Shutdown();
}

void VR_IsHmdPresent(const Nan::FunctionCallbackInfo<Value> &info)
{
    const bool result = vr::VR_IsHmdPresent();
    info.GetReturnValue().Set(Nan::New<Boolean>(result));
}

void VR_IsRuntimeInstalled(const Nan::FunctionCallbackInfo<Value> &info)
{
    const bool result = vr::VR_IsRuntimeInstalled();
    info.GetReturnValue().Set(Nan::New<Boolean>(result));
}

void VR_GetRuntimePath(const Nan::FunctionCallbackInfo<Value> &info)
{
    char *pchVRRuntimePath;
    uint32_t *punRequiredBufferSize;

    const bool bIsVRRuntimeExist = vr::VR_GetRuntimePath(pchVRRuntimePath, 0, punRequiredBufferSize);
    if (!bIsVRRuntimeExist)
    {
        Nan::ThrowError("VR Runtime is not exist.");
        return;
    }

    uint32_t *fpunRequiredBufferSize;
    const bool fbIsVRRuntimeExist = vr::VR_GetRuntimePath(pchVRRuntimePath, *punRequiredBufferSize, fpunRequiredBufferSize);

    info.GetReturnValue().Set(Nan::New<String>(pchVRRuntimePath).ToLocalChecked());
}

void VR_GetVRInitErrorAsSymbol(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    uint32_t nError = info[0]->Uint32Value(context).FromJust();
    vr::EVRInitError eError = static_cast<vr::EVRInitError>(nError);
    const char *result = vr::VR_GetVRInitErrorAsSymbol(eError);
    info.GetReturnValue().Set(Nan::New<String>(result).ToLocalChecked());
}

void VR_GetVRInitErrorAsEnglishDescription(const Nan::FunctionCallbackInfo<Value> &info)
{
    Local<Context> context = info.GetIsolate()->GetCurrentContext();
    uint32_t nError = info[0]->Uint32Value(context).FromJust();
    vr::EVRInitError eError = static_cast<vr::EVRInitError>(nError);
    const auto result = vr::VR_GetVRInitErrorAsEnglishDescription(eError);
    info.GetReturnValue().Set(Nan::New<String>(result).ToLocalChecked());
}

void VR_GetInitToken(const Nan::FunctionCallbackInfo<Value> &info)
{
    const auto result = vr::VR_GetInitToken();
    info.GetReturnValue().Set(Nan::New<Number>(result));
}

void IVROverlay_Init(const Nan::FunctionCallbackInfo<Value>& info)
{
    auto result = IVROverlay::NewInstance(vr::VROverlay());
    info.GetReturnValue().Set(result);
}

void IVRApplications_Init(const Nan::FunctionCallbackInfo<Value>& info)
{
    auto result = IVRApplications::NewInstance(vr::VRApplications());
    info.GetReturnValue().Set(result);
}
