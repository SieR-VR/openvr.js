#ifndef IVRSPATIALANCHORS_H_JS
#define IVRSPATIALANCHORS_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRSpatialAnchors;
}

class IVRSpatialAnchors : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRSpatialAnchors *spatialanchors);

private:
    explicit IVRSpatialAnchors(vr::IVRSpatialAnchors *self);
    ~IVRSpatialAnchors() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual EVRSpatialAnchorError CreateSpatialAnchorFromDescriptor( const char *pchDescriptor, SpatialAnchorHandle_t *pHandleOut ) = 0;
    static void CreateSpatialAnchorFromDescriptor(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRSpatialAnchorError CreateSpatialAnchorFromPose( TrackedDeviceIndex_t unDeviceIndex, ETrackingUniverseOrigin eOrigin, SpatialAnchorPose_t *pPose, SpatialAnchorHandle_t *pHandleOut ) = 0;
    static void CreateSpatialAnchorFromPose(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRSpatialAnchorError GetSpatialAnchorPose( SpatialAnchorHandle_t unHandle, ETrackingUniverseOrigin eOrigin, SpatialAnchorPose_t *pPoseOut ) = 0;
    static void GetSpatialAnchorPose(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRSpatialAnchorError GetSpatialAnchorDescriptor( SpatialAnchorHandle_t unHandle, VR_OUT_STRING() char *pchDescriptorOut, uint32_t *punDescriptorBufferLenInOut ) = 0;
    static void GetSpatialAnchorDescriptor(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRSpatialAnchors *const self_;
};

#endif