#ifndef IVRCHAPERONE_H_JS
#define IVRCHAPERONE_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRChaperone;
}

class IVRChaperone : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRChaperone *chaperone);

private:
    explicit IVRChaperone(vr::IVRChaperone *self);
    ~IVRChaperone() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual ChaperoneCalibrationState GetCalibrationState() = 0;
    static void GetCalibrationState(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetPlayAreaSize( float *pSizeX, float *pSizeZ ) = 0;
    static void GetPlayAreaSize(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetPlayAreaRect( HmdQuad_t *rect ) = 0;
    static void GetPlayAreaRect(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ReloadInfo( void ) = 0;
    static void ReloadInfo(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetSceneColor( HmdColor_t color ) = 0;
    static void SetSceneColor(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void GetBoundsColor( HmdColor_t *pOutputColorArray, int nNumOutputColors, float flCollisionBoundsFadeDistance, HmdColor_t *pOutputCameraColor ) = 0;
    static void GetBoundsColor(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool AreBoundsVisible() = 0;
    static void AreBoundsVisible(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ForceBoundsVisible( bool bForce ) = 0;
    static void ForceBoundsVisible(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ResetZeroPose( ETrackingUniverseOrigin eTrackingUniverseOrigin ) = 0;
    static void ResetZeroPose(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRChaperone *const self_;
};

#endif