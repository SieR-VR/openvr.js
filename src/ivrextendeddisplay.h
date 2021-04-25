#ifndef IVREXTENDEDDISPLAY_H_JS
#define IVREXTENDEDDISPLAY_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRExtendedDisplay;
}

class IVRExtendedDisplay : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRExtendedDisplay *extendeddisplay);

private:
    explicit IVRExtendedDisplay(vr::IVRExtendedDisplay *self);
    ~IVRExtendedDisplay() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual void GetWindowBounds( int32_t *pnX, int32_t *pnY, uint32_t *pnWidth, uint32_t *pnHeight ) = 0;
    static void GetWindowBounds(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void GetEyeOutputViewport( EVREye eEye, uint32_t *pnX, uint32_t *pnY, uint32_t *pnWidth, uint32_t *pnHeight ) = 0;
    static void GetEyeOutputViewport(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void GetDXGIOutputInfo( int32_t *pnAdapterIndex, int32_t *pnAdapterOutputIndex ) = 0;
    static void GetDXGIOutputInfo(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRExtendedDisplay *const self_;
};

#endif