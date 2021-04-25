#ifndef IVRHEADSETVIEW_H_JS
#define IVRHEADSETVIEW_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRHeadsetView;
}

class IVRHeadsetView : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRHeadsetView *headsetview);

private:
    explicit IVRHeadsetView(vr::IVRHeadsetView *self);
    ~IVRHeadsetView() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual void SetHeadsetViewSize( uint32_t nWidth, uint32_t nHeight ) = 0;
    static void SetHeadsetViewSize(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void GetHeadsetViewSize( uint32_t *pnWidth, uint32_t *pnHeight ) = 0;
    static void GetHeadsetViewSize(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetHeadsetViewMode( HeadsetViewMode_t eHeadsetViewMode ) = 0;
    static void SetHeadsetViewMode(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual HeadsetViewMode_t GetHeadsetViewMode() = 0;
    static void GetHeadsetViewMode(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetHeadsetViewCropped( bool bCropped ) = 0;
    static void SetHeadsetViewCropped(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetHeadsetViewCropped() = 0;
    static void GetHeadsetViewCropped(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual float GetHeadsetViewAspectRatio() = 0;
    static void GetHeadsetViewAspectRatio(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetHeadsetViewBlendRange( float flStartPct, float flEndPct ) = 0;
    static void SetHeadsetViewBlendRange(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void GetHeadsetViewBlendRange( float *pStartPct, float *pEndPct ) = 0;
    static void GetHeadsetViewBlendRange(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRHeadsetView *const self_;
};

#endif