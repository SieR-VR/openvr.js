#ifndef IVRDEBUG_H_JS
#define IVRDEBUG_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRDebug;
}

class IVRDebug : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRDebug *debug);

private:
    explicit IVRDebug(vr::IVRDebug *self);
    ~IVRDebug() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual EVRDebugError EmitVrProfilerEvent( const char *pchMessage ) = 0;
    static void EmitVrProfilerEvent(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRDebugError BeginVrProfilerEvent( VrProfilerEventHandle_t *pHandleOut ) = 0;
    static void BeginVrProfilerEvent(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRDebugError FinishVrProfilerEvent( VrProfilerEventHandle_t hHandle, const char *pchMessage ) = 0;
    static void FinishVrProfilerEvent(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t DriverDebugRequest( vr::TrackedDeviceIndex_t unDeviceIndex, const char *pchRequest, VR_OUT_STRING() char *pchResponseBuffer, uint32_t unResponseBufferSize ) = 0;
    static void DriverDebugRequest(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRDebug *const self_;
};

#endif