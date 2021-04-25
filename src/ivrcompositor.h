#ifndef IVRCOMPOSITOR_H_JS
#define IVRCOMPOSITOR_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRCompositor;
}

class IVRCompositor : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRCompositor *compositor);

private:
    explicit IVRCompositor(vr::IVRCompositor *self);
    ~IVRCompositor() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual void SetTrackingSpace( ETrackingUniverseOrigin eOrigin ) = 0;
    static void SetTrackingSpace(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual ETrackingUniverseOrigin GetTrackingSpace() = 0;
    static void GetTrackingSpace(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRCompositorError WaitGetPoses( VR_ARRAY_COUNT( unRenderPoseArrayCount ) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount,
	// 	VR_ARRAY_COUNT( unGamePoseArrayCount ) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount ) = 0;
    static void WaitGetPoses(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRCompositorError GetLastPoses( VR_ARRAY_COUNT( unRenderPoseArrayCount ) TrackedDevicePose_t* pRenderPoseArray, uint32_t unRenderPoseArrayCount,
	//	VR_ARRAY_COUNT( unGamePoseArrayCount ) TrackedDevicePose_t* pGamePoseArray, uint32_t unGamePoseArrayCount ) = 0;
    static void GetLastPoses(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRCompositorError GetLastPoseForTrackedDeviceIndex( TrackedDeviceIndex_t unDeviceIndex, TrackedDevicePose_t *pOutputPose, TrackedDevicePose_t *pOutputGamePose ) = 0;
    static void GetLastPoseForTrackedDeviceIndex(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRCompositorError Submit( EVREye eEye, const Texture_t *pTexture, const VRTextureBounds_t* pBounds = 0, EVRSubmitFlags nSubmitFlags = Submit_Default ) = 0;
    static void Submit(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ClearLastSubmittedFrame() = 0;
    static void ClearLastSubmittedFrame(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void PostPresentHandoff() = 0;
    static void PostPresentHandoff(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetFrameTiming( Compositor_FrameTiming *pTiming, uint32_t unFramesAgo = 0 ) = 0;
    static void GetFrameTiming(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetFrameTimings( VR_ARRAY_COUNT( nFrames ) Compositor_FrameTiming *pTiming, uint32_t nFrames ) = 0;
    static void GetFrameTimings(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual float GetFrameTimeRemaining() = 0;
    static void GetFrameTimeRemaining(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void GetCumulativeStats( Compositor_CumulativeStats *pStats, uint32_t nStatsSizeInBytes ) = 0;
    static void GetCumulativeStats(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void FadeToColor( float fSeconds, float fRed, float fGreen, float fBlue, float fAlpha, bool bBackground = false ) = 0;
    static void FadeToColor(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual HmdColor_t GetCurrentFadeColor( bool bBackground = false ) = 0;
    static void GetCurrentFadeColor(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void FadeGrid( float fSeconds, bool bFadeGridIn ) = 0;
    static void FadeGrid(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual float GetCurrentGridAlpha() = 0;
    static void GetCurrentGridAlpha(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRCompositorError SetSkyboxOverride( VR_ARRAY_COUNT( unTextureCount ) const Texture_t *pTextures, uint32_t unTextureCount ) = 0;
    static void SetSkyboxOverride(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ClearSkyboxOverride() = 0;
    static void ClearSkyboxOverride(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void CompositorBringToFront() = 0;
    static void CompositorBringToFront(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void CompositorGoToBack() = 0;
    static void CompositorGoToBack(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void CompositorQuit() = 0;
    static void CompositorQuit(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsFullscreen() = 0;
    static void IsFullscreen(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetCurrentSceneFocusProcess() = 0;
    static void GetCurrentSceneFocusProcess(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetLastFrameRenderer() = 0;
    static void GetLastFrameRenderer(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool CanRenderScene() = 0;
    static void CanRenderScene(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ShowMirrorWindow() = 0;
    static void ShowMirrorWindow(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void HideMirrorWindow() = 0;
    static void HideMirrorWindow(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsMirrorWindowVisible() = 0;
    static void IsMirrorWindowVisible(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void CompositorDumpImages() = 0;
    static void CompositorDumpImages(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool ShouldAppRenderWithLowResources() = 0;
    static void ShouldAppRenderWithLowResources(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ForceInterleavedReprojectionOn( bool bOverride ) = 0;
    static void ForceInterleavedReprojectionOn(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ForceReconnectProcess() = 0;
    static void ForceReconnectProcess(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SuspendRendering( bool bSuspend ) = 0;
    static void SuspendRendering(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRCompositorError GetMirrorTextureD3D11( vr::EVREye eEye, void *pD3D11DeviceOrResource, void **ppD3D11ShaderResourceView ) = 0;
    static void GetMirrorTextureD3D11(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ReleaseMirrorTextureD3D11( void *pD3D11ShaderResourceView ) = 0;
    static void ReleaseMirrorTextureD3D11(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRCompositorError GetMirrorTextureGL( vr::EVREye eEye, vr::glUInt_t *pglTextureId, vr::glSharedTextureHandle_t *pglSharedTextureHandle ) = 0;
    static void GetMirrorTextureGL(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool ReleaseSharedGLTexture( vr::glUInt_t glTextureId, vr::glSharedTextureHandle_t glSharedTextureHandle ) = 0;
    static void ReleaseSharedGLTexture(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void LockGLSharedTextureForAccess( vr::glSharedTextureHandle_t glSharedTextureHandle ) = 0;
    static void LockGLSharedTextureForAccess(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void UnlockGLSharedTextureForAccess( vr::glSharedTextureHandle_t glSharedTextureHandle ) = 0;
    static void UnlockGLSharedTextureForAccess(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetVulkanInstanceExtensionsRequired( VR_OUT_STRING() char *pchValue, uint32_t unBufferSize ) = 0;
    static void GetVulkanInstanceExtensionsRequired(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetVulkanDeviceExtensionsRequired( VkPhysicalDevice_T *pPhysicalDevice, VR_OUT_STRING() char *pchValue, uint32_t unBufferSize ) = 0;
    static void GetVulkanDeviceExtensionsRequired(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetExplicitTimingMode( EVRCompositorTimingMode eTimingMode ) = 0;
    static void SetExplicitTimingMode(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRCompositorError SubmitExplicitTimingData() = 0;
    static void SubmitExplicitTimingData(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsMotionSmoothingEnabled() = 0;
    static void IsMotionSmoothingEnabled(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsMotionSmoothingSupported() = 0;
    static void IsMotionSmoothingSupported(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsCurrentSceneFocusAppLoading() = 0;
    static void IsCurrentSceneFocusAppLoading(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRCompositorError SetStageOverride_Async( const char *pchRenderModelPath, const HmdMatrix34_t *pTransform = 0,
	//	const Compositor_StageRenderSettings *pRenderSettings = 0, uint32_t nSizeOfRenderSettings = 0 ) = 0;
    static void SetStageOverride_Async(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ClearStageOverride() = 0;
    static void ClearStageOverride(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetCompositorBenchmarkResults( Compositor_BenchmarkResults *pBenchmarkResults, uint32_t nSizeOfBenchmarkResults ) = 0;
    static void GetCompositorBenchmarkResults(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRCompositorError GetLastPosePredictionIDs( uint32_t *pRenderPosePredictionID, uint32_t *pGamePosePredictionID ) = 0;
    static void GetLastPosePredictionIDs(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRCompositorError GetPosesForFrame( uint32_t unPosePredictionID, VR_ARRAY_COUNT( unPoseArrayCount ) TrackedDevicePose_t* pPoseArray, uint32_t unPoseArrayCount ) = 0;
    static void GetPosesForFrame(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRCompositor *const self_;
};

#endif