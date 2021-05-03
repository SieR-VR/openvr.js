#include "ivrsystem.h"
#include "ivroverlay.h"
#include "openvr.h"

#include <nan.h>

void Initialize(v8::Local<v8::Object> exports)
{
    v8::Local<v8::Context> context = exports->CreationContext();

    exports->Set(context, 
                 Nan::New("VR_Init").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(VR_Init)->GetFunction(context).ToLocalChecked());
    exports->Set(context,
                 Nan::New("VR_Shutdown").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(VR_Shutdown)->GetFunction(context).ToLocalChecked());
    exports->Set(context,
                 Nan::New("VR_IsHmdPresent").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(VR_IsHmdPresent)->GetFunction(context).ToLocalChecked());
    exports->Set(context,
                 Nan::New("VR_IsRuntimeInstalled").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(VR_IsRuntimeInstalled)->GetFunction(context).ToLocalChecked());
    exports->Set(context,
                 Nan::New("VR_GetRuntimePath").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(VR_GetRuntimePath)->GetFunction(context).ToLocalChecked());
    exports->Set(context,
                 Nan::New("VR_GetVRInitErrorAsSymbol").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(VR_GetVRInitErrorAsSymbol)->GetFunction(context).ToLocalChecked());
    exports->Set(context,
                 Nan::New("VR_GetVRInitErrorAsEnglishDescription").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(VR_GetVRInitErrorAsEnglishDescription)->GetFunction(context).ToLocalChecked());
    exports->Set(context,
                 Nan::New("VR_GetInitToken").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(VR_GetInitToken)->GetFunction(context).ToLocalChecked());
     exports->Set(context,
                 Nan::New("IVROverlay_Init").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(IVROverlay_Init)->GetFunction(context).ToLocalChecked());
                 
    IVRSystem::Init(exports);
    IVROverlay::Init(exports);
}

NODE_MODULE(openvr, Initialize);