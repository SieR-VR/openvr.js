#ifndef IVRCHAPERONESETUP_H_JS
#define IVRCHAPERONESETUP_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRChaperoneSetup;
}

class IVRChaperoneSetup : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRChaperoneSetup *system);

private:
    explicit IVRChaperoneSetup(vr::IVRChaperoneSetup *self);
    ~IVRChaperoneSetup() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual bool CommitWorkingCopy( EChaperoneConfigFile configFile ) = 0;
    static void CommitWorkingCopy(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void RevertWorkingCopy() = 0;
    static void RevertWorkingCopy(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetWorkingPlayAreaSize( float *pSizeX, float *pSizeZ ) = 0;
    static void GetWorkingPlayAreaSize(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetWorkingPlayAreaRect( HmdQuad_t *rect ) = 0;
    static void GetWorkingPlayAreaRect(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetWorkingCollisionBoundsInfo( VR_OUT_ARRAY_COUNT(punQuadsCount) HmdQuad_t *pQuadsBuffer, uint32_t* punQuadsCount ) = 0;
    static void GetWorkingCollisionBoundsInfo(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetLiveCollisionBoundsInfo( VR_OUT_ARRAY_COUNT(punQuadsCount) HmdQuad_t *pQuadsBuffer, uint32_t* punQuadsCount ) = 0;
    static void GetLiveCollisionBoundsInfo(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetWorkingSeatedZeroPoseToRawTrackingPose( HmdMatrix34_t *pmatSeatedZeroPoseToRawTrackingPose ) = 0;
    static void GetWorkingSeatedZeroPoseToRawTrackingPose(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetWorkingStandingZeroPoseToRawTrackingPose( HmdMatrix34_t *pmatStandingZeroPoseToRawTrackingPose ) = 0;
    static void GetWorkingStandingZeroPoseToRawTrackingPose(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetWorkingPlayAreaSize( float sizeX, float sizeZ ) = 0;
    static void SetWorkingPlayAreaSize(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetWorkingCollisionBoundsInfo( VR_ARRAY_COUNT(unQuadsCount) HmdQuad_t *pQuadsBuffer, uint32_t unQuadsCount ) = 0;
    static void SetWorkingCollisionBoundsInfo(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetWorkingPerimeter( VR_ARRAY_COUNT( unPointCount ) HmdVector2_t *pPointBuffer, uint32_t unPointCount ) = 0;
    static void SetWorkingPerimeter(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetWorkingSeatedZeroPoseToRawTrackingPose( const HmdMatrix34_t *pMatSeatedZeroPoseToRawTrackingPose ) = 0;
    static void SetWorkingSeatedZeroPoseToRawTrackingPose(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetWorkingStandingZeroPoseToRawTrackingPose( const HmdMatrix34_t *pMatStandingZeroPoseToRawTrackingPose ) = 0;
    static void SetWorkingStandingZeroPoseToRawTrackingPose(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ReloadFromDisk( EChaperoneConfigFile configFile ) = 0;
    static void ReloadFromDisk(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetLiveSeatedZeroPoseToRawTrackingPose( HmdMatrix34_t *pmatSeatedZeroPoseToRawTrackingPose ) = 0;
    static void GetLiveSeatedZeroPoseToRawTrackingPose(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool ExportLiveToBuffer( VR_OUT_STRING() char *pBuffer, uint32_t *pnBufferLength ) = 0;
    static void ExportLiveToBuffer(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool ImportFromBufferToWorking( const char *pBuffer, uint32_t nImportFlags ) = 0;
    static void ImportFromBufferToWorking(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ShowWorkingSetPreview() = 0;
    static void ShowWorkingSetPreview(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void HideWorkingSetPreview() = 0;
    static void HideWorkingSetPreview(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void RoomSetupStarting() = 0;
    static void RoomSetupStarting(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRChaperoneSetup *const self_;
};

#endif