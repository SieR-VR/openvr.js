#ifndef IVRTRACKEDCAMERA_H_JS
#define IVRTRACKEDCAMERA_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRTrackedCamera;
}

class IVRTrackedCamera : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRTrackedCamera *trackedcamera);

private:
    explicit IVRTrackedCamera(vr::IVRTrackedCamera *self);
    ~IVRTrackedCamera() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual const char *GetCameraErrorNameFromEnum( vr::EVRTrackedCameraError eCameraError ) = 0;
    static void GetCameraErrorNameFromEnum(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRTrackedCameraError HasCamera( vr::TrackedDeviceIndex_t nDeviceIndex, bool *pHasCamera ) = 0;
    static void HasCamera(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRTrackedCameraError GetCameraFrameSize( vr::TrackedDeviceIndex_t nDeviceIndex, vr::EVRTrackedCameraFrameType eFrameType, uint32_t *pnWidth, uint32_t *pnHeight, uint32_t *pnFrameBufferSize ) = 0;
    static void GetCameraFrameSize(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRTrackedCameraError GetCameraIntrinsics( vr::TrackedDeviceIndex_t nDeviceIndex, uint32_t nCameraIndex, vr::EVRTrackedCameraFrameType eFrameType, vr::HmdVector2_t *pFocalLength, vr::HmdVector2_t *pCenter ) = 0;
    static void GetCameraIntrinsics(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRTrackedCameraError GetCameraProjection( vr::TrackedDeviceIndex_t nDeviceIndex, uint32_t nCameraIndex, vr::EVRTrackedCameraFrameType eFrameType, float flZNear, float flZFar, vr::HmdMatrix44_t *pProjection ) = 0;
    static void GetCameraProjection(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRTrackedCameraError AcquireVideoStreamingService( vr::TrackedDeviceIndex_t nDeviceIndex, vr::TrackedCameraHandle_t *pHandle ) = 0;
    static void AcquireVideoStreamingService(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRTrackedCameraError ReleaseVideoStreamingService( vr::TrackedCameraHandle_t hTrackedCamera ) = 0;
    static void ReleaseVideoStreamingService(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRTrackedCameraError GetVideoStreamFrameBuffer( vr::TrackedCameraHandle_t hTrackedCamera, vr::EVRTrackedCameraFrameType eFrameType, void *pFrameBuffer, uint32_t nFrameBufferSize, vr::CameraVideoStreamFrameHeader_t *pFrameHeader, uint32_t nFrameHeaderSize ) = 0;
    static void GetVideoStreamFrameBuffer(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRTrackedCameraError GetVideoStreamTextureSize( vr::TrackedDeviceIndex_t nDeviceIndex, vr::EVRTrackedCameraFrameType eFrameType, vr::VRTextureBounds_t *pTextureBounds, uint32_t *pnWidth, uint32_t *pnHeight ) = 0;
    static void GetVideoStreamTextureSize(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRTrackedCameraError GetVideoStreamTextureD3D11( vr::TrackedCameraHandle_t hTrackedCamera, vr::EVRTrackedCameraFrameType eFrameType, void *pD3D11DeviceOrResource, void **ppD3D11ShaderResourceView, vr::CameraVideoStreamFrameHeader_t *pFrameHeader, uint32_t nFrameHeaderSize ) = 0;
    static void GetVideoStreamTextureD3D11(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRTrackedCameraError GetVideoStreamTextureGL( vr::TrackedCameraHandle_t hTrackedCamera, vr::EVRTrackedCameraFrameType eFrameType, vr::glUInt_t *pglTextureId, vr::CameraVideoStreamFrameHeader_t *pFrameHeader, uint32_t nFrameHeaderSize ) = 0;
    static void GetVideoStreamTextureGL(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRTrackedCameraError ReleaseVideoStreamTextureGL( vr::TrackedCameraHandle_t hTrackedCamera, vr::glUInt_t glTextureId ) = 0;
    static void ReleaseVideoStreamTextureGL(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetCameraTrackingSpace( vr::ETrackingUniverseOrigin eUniverse ) = 0;
    static void SetCameraTrackingSpace(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::ETrackingUniverseOrigin GetCameraTrackingSpace( ) = 0;
    static void GetCameraTrackingSpace(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRTrackedCamera *const self_;
};

#endif