#ifndef IVRSYSTEM_H_JS
#define IVRSYSTEM_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRSystem;
}

class IVRSystem : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRSystem *system);

private:
    explicit IVRSystem(vr::IVRSystem *self);
    ~IVRSystem() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // ------------------------------------
    // Display Methods
    // ------------------------------------

    // virtual void GetRecommendedRenderTargetSize( uint32_t *pnWidth, uint32_t *pnHeight )
    static void GetRecommendedRenderTargetSize(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual HmdMatrix44_t GetProjectionMatrix( EVREye eEye, float fNearZ, float fFarZ )
    static void GetProjectionMatrix(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void GetProjectionRaw( EVREye eEye, float *pfLeft, float *pfRight, float *pfTop, float *pfBottom )
    static void GetProjectionRaw(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool ComputeDistortion( EVREye eEye, float fU, float fV, DistortionCoordinates_t *pDistortionCoordinates )
    static void ComputeDistortion(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual HmdMatrix34_t GetEyeToHeadTransform( EVREye eEye )
    static void GetEyeToHeadTransform(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetTimeSinceLastVsync( float *pfSecondsSinceLastVsync, uint64_t *pulFrameCounter )
    static void GetTimeSinceLastVsync(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual int32_t GetD3D9AdapterIndex()
    static void GetD3D9AdapterIndex(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void GetDXGIOutputInfo( int32_t *pnAdapterIndex )
    static void GetDXGIOutputInfo(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void GetOutputDevice( uint64_t *pnDevice, ETextureType textureType, VkInstance_T *pInstance = nullptr )
    static void GetOutputDevice(const Nan::FunctionCallbackInfo<Value> &info);

    // ------------------------------------
    // Display Mode methods
    // ------------------------------------

    // virtual bool IsDisplayOnDesktop()
    static void IsDisplayOnDesktop(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool SetDisplayVisibility( bool bIsVisibleOnDesktop )
    static void SetDisplayVisibility(const Nan::FunctionCallbackInfo<Value> &info);

    // ------------------------------------
    // Tracking Methods
    // ------------------------------------

    // virtual void GetDeviceToAbsoluteTrackingPose( ETrackingUniverseOrigin eOrigin, float fPredictedSecondsToPhotonsFromNow, VR_ARRAY_COUNT(unTrackedDevicePoseArrayCount) TrackedDevicePose_t *pTrackedDevicePoseArray, uint32_t unTrackedDevicePoseArrayCount )
    static void GetDeviceToAbsoluteTrackingPose(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual HmdMatrix34_t GetSeatedZeroPoseToStandingAbsoluteTrackingPose()
    static void GetSeatedZeroPoseToStandingAbsoluteTrackingPose(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual HmdMatrix34_t GetRawZeroPoseToStandingAbsoluteTrackingPose()
    static void GetRawZeroPoseToStandingAbsoluteTrackingPose(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetSortedTrackedDeviceIndicesOfClass( ETrackedDeviceClass eTrackedDeviceClass, VR_ARRAY_COUNT(unTrackedDeviceIndexArrayCount) vr::TrackedDeviceIndex_t *punTrackedDeviceIndexArray, uint32_t unTrackedDeviceIndexArrayCount, vr::TrackedDeviceIndex_t unRelativeToTrackedDeviceIndex = k_unTrackedDeviceIndex_Hmd )
    static void GetSortedTrackedDeviceIndicesOfClass(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EDeviceActivityLevel GetTrackedDeviceActivityLevel( vr::TrackedDeviceIndex_t unDeviceId )
    static void GetTrackedDeviceActivityLevel(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ApplyTransform( TrackedDevicePose_t *pOutputPose, const TrackedDevicePose_t *pTrackedDevicePose, const HmdMatrix34_t *pTransform )
    static void ApplyTransform(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::TrackedDeviceIndex_t GetTrackedDeviceIndexForControllerRole( vr::ETrackedControllerRole unDeviceType )
    static void GetTrackedDeviceIndexForControllerRole(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::ETrackedControllerRole GetControllerRoleForTrackedDeviceIndex( vr::TrackedDeviceIndex_t unDeviceIndex )
    static void GetControllerRoleForTrackedDeviceIndex(const Nan::FunctionCallbackInfo<Value> &info);

    // ------------------------------------
    // Property methods
    // ------------------------------------

    // virtual ETrackedDeviceClass GetTrackedDeviceClass( vr::TrackedDeviceIndex_t unDeviceIndex )
    static void GetTrackedDeviceClass(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsTrackedDeviceConnected( vr::TrackedDeviceIndex_t unDeviceIndex )
    static void IsTrackedDeviceConnected(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetBoolTrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError *pError = 0L )
    static void GetBoolTrackedDeviceProperty(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual float GetFloatTrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError *pError = 0L )
    static void GetFloatTrackedDeviceProperty(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual int32_t GetInt32TrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError *pError = 0L )
    static void GetInt32TrackedDeviceProperty(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint64_t GetUint64TrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError *pError = 0L )
    static void GetUint64TrackedDeviceProperty(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual HmdMatrix34_t GetMatrix34TrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError *pError = 0L )
    static void GetMatrix34TrackedDeviceProperty(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetArrayTrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, PropertyTypeTag_t propType, void *pBuffer, uint32_t unBufferSize, ETrackedPropertyError *pError = 0L )
    static void GetArrayTrackedDeviceProperty(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetStringTrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, VR_OUT_STRING() char *pchValue, uint32_t unBufferSize, ETrackedPropertyError *pError = 0L )
    static void GetStringTrackedDeviceProperty(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual const char *GetPropErrorNameFromEnum( ETrackedPropertyError error )
    static void GetPropErrorNameFromEnum(const Nan::FunctionCallbackInfo<Value> &info);

    // ------------------------------------
    // Event methods
    // ------------------------------------

    // virtual bool PollNextEvent( VREvent_t *pEvent, uint32_t uncbVREvent )
    static void PollNextEvent(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool PollNextEventWithPose( ETrackingUniverseOrigin eOrigin, VREvent_t *pEvent, uint32_t uncbVREvent, vr::TrackedDevicePose_t *pTrackedDevicePose )
    static void PollNextEventWithPose(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual const char *GetEventTypeNameFromEnum( EVREventType eType )
    static void GetEventTypeNameFromEnum(const Nan::FunctionCallbackInfo<Value> &info);

    // ------------------------------------
    // Rendering helper methods
    // ------------------------------------

    // virtual HiddenAreaMesh_t GetHiddenAreaMesh( EVREye eEye, EHiddenAreaMeshType type = k_eHiddenAreaMesh_Standard )
    static void GetHiddenAreaMesh(const Nan::FunctionCallbackInfo<Value> &info);

    // ------------------------------------
    // Controller methods
    // ------------------------------------

    // virtual bool GetControllerState( vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t *pControllerState, uint32_t unControllerStateSize )
    static void GetControllerState(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetControllerStateWithPose( ETrackingUniverseOrigin eOrigin, vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t *pControllerState, uint32_t unControllerStateSize, TrackedDevicePose_t *pTrackedDevicePose )
    static void GetControllerStateWithPose(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void TriggerHapticPulse( vr::TrackedDeviceIndex_t unControllerDeviceIndex, uint32_t unAxisId, unsigned short usDurationMicroSec )
    static void TriggerHapticPulse(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual const char *GetButtonIdNameFromEnum( EVRButtonId eButtonId )
    static void GetButtonIdNameFromEnum(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual const char *GetControllerAxisTypeNameFromEnum( EVRControllerAxisType eAxisType )
    static void GetControllerAxisTypeNameFromEnum(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsInputAvailable()
    static void IsInputAvailable(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsSteamVRDrawingControllers()
    static void IsSteamVRDrawingControllers(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool ShouldApplicationPause()
    static void ShouldApplicationPause(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool ShouldApplicationReduceRenderingWork()
    static void ShouldApplicationReduceRenderingWork(const Nan::FunctionCallbackInfo<Value> &info);

    // ------------------------------------
    // Firmware methods
    // ------------------------------------

    // virtual vr::EVRFirmwareError PerformFirmwareUpdate( vr::TrackedDeviceIndex_t unDeviceIndex )
    static void PerformFirmwareUpdate(const Nan::FunctionCallbackInfo<Value> &info);

    // ------------------------------------
    // Application life cycle methods
    // ------------------------------------

    // virtual void AcknowledgeQuit_Exiting()
    static void AcknowledgeQuit_Exiting(const Nan::FunctionCallbackInfo<Value> &info);

    // -------------------------------------
    // App container sandbox methods
    // -------------------------------------

    // virtual uint32_t GetAppContainerFilePaths( VR_OUT_STRING() char *pchBuffer, uint32_t unBufferSize )
    static void GetAppContainerFilePaths(const Nan::FunctionCallbackInfo<Value> &info);

    // -------------------------------------
    // System methods
    // -------------------------------------

    // virtual const char *GetRuntimeVersion()
    static void GetRuntimeVersion(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRSystem * const self_;
};

#endif