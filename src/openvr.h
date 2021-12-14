#ifndef OPENVR_JS
#define OPENVR_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

/// inline IVRSystem *VR_Init( EVRInitError *peError, EVRApplicationType eApplicationType );
void VR_Init(const Nan::FunctionCallbackInfo<Value>& info);

/// inline void VR_Shutdown();
void VR_Shutdown(const Nan::FunctionCallbackInfo<Value>& info);

/// VR_INTERFACE bool VR_CALLTYPE VR_IsHmdPresent();
void VR_IsHmdPresent(const Nan::FunctionCallbackInfo<Value>& info);

/// VR_INTERFACE bool VR_CALLTYPE VR_IsRuntimeInstalled();
void VR_IsRuntimeInstalled(const Nan::FunctionCallbackInfo<Value>& info);

/// VR_INTERFACE bool VR_GetRuntimePath( VR_OUT_STRING() char *pchPathBuffer, uint32_t unBufferSize, uint32_t *punRequiredBufferSize );
void VR_GetRuntimePath(const Nan::FunctionCallbackInfo<Value>& info);

/// VR_INTERFACE const char *VR_CALLTYPE VR_GetVRInitErrorAsSymbol( EVRInitError error );
void VR_GetVRInitErrorAsSymbol(const Nan::FunctionCallbackInfo<Value>& info);

/// VR_INTERFACE const char *VR_CALLTYPE VR_GetVRInitErrorAsEnglishDescription( EVRInitError error );
void VR_GetVRInitErrorAsEnglishDescription(const Nan::FunctionCallbackInfo<Value>& info);

/// VR_INTERFACE void *VR_CALLTYPE VR_GetGenericInterface( const char *pchInterfaceVersion, EVRInitError *peError );
// void VR_GetGenericInterface(const Nan::FunctionCallbackInfo<Value>& info);

/// VR_INTERFACE bool VR_CALLTYPE VR_IsInterfaceVersionValid( const char *pchInterfaceVersion );
// void VR_IsInterfaceVersionValid(const Nan::FunctionCallbackInfo<Value>& info);

/// VR_INTERFACE uint32_t VR_CALLTYPE VR_GetInitToken();
void VR_GetInitToken(const Nan::FunctionCallbackInfo<Value>& info);

void IVROverlay_Init(const Nan::FunctionCallbackInfo<Value>& info);

void IVRApplications_Init(const Nan::FunctionCallbackInfo<Value>& info);

#endif
