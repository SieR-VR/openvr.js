#include "openvr.h"
#include "ivrsystem.h"

#include <node.h>
#include <openvr.h>
#include <v8.h>

using namespace v8;

void VR_Init(const Nan::FunctionCallbackInfo<Value>& info) {
    Local<Context> context = info.GetIsolate()->GetCurrentContext();

    if (info.Length() != 1) {
        Nan::ThrowError("Wrong number of arguments.");
        return;
    }

    if (!info[0]->IsNumber()) {
        Nan::ThrowTypeError("Argument[0] must be a number (EVRApplicationType).");
        return;
    }

    uint32_t applicationType = info[0]->NumberValue(context).FromJust();
    constexpr uint32_t applicationTypeMax = vr::VRApplication_Max;

    if(applicationType >= applicationTypeMax) {
        Nan::ThrowTypeError("Argument[0] was out of enum range (EVRApplicationType).");
        return;
    }

    vr::EVRInitError error;
    vr::IVRSystem *system = vr::VR_Init(&error, static_cast<vr::EVRApplicationType>(applicationType));

    if(!system) {
        Nan::ThrowError(vr::VR_GetVRInitErrorAsEnglishDescription(error));
        return;
    }
}