#ifndef IVROVERLAYVIEW_H_JS
#define IVROVERLAYVIEW_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVROverlayView;
}

class IVROverlayView : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVROverlayView *overlayview);

private:
    explicit IVROverlayView(vr::IVROverlayView *self);
    ~IVROverlayView() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual EVROverlayError AcquireOverlayView(VROverlayHandle_t ulOverlayHandle, VRNativeDevice_t *pNativeDevice, VROverlayView_t *pOverlayView, uint32_t unOverlayViewSize ) = 0;
    static void AcquireOverlayView(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError ReleaseOverlayView(VROverlayView_t *pOverlayView) = 0;
    static void ReleaseOverlayView(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void PostOverlayEvent(VROverlayHandle_t ulOverlayHandle, const VREvent_t *pvrEvent) = 0;
    static void PostOverlayEvent(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsViewingPermitted( VROverlayHandle_t ulOverlayHandle ) = 0;
    static void IsViewingPermitted(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVROverlayView *const self_;
};

#endif