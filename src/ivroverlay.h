#ifndef IVRSETTINGS_H_JS
#define IVRSETTINGS_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVROverlay;
}

class IVROverlay : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVROverlay *overlay);

private:
    explicit IVROverlay(vr::IVROverlay *self);
    ~IVROverlay() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);


    // ---------------------------------------------
	// Overlay management methods
	// ---------------------------------------------

    // virtual EVROverlayError FindOverlay( const char *pchOverlayKey, VROverlayHandle_t * pOverlayHandle ) = 0;
    static void FindOverlay(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError CreateOverlay( const char *pchOverlayKey, const char *pchOverlayName, VROverlayHandle_t * pOverlayHandle ) = 0;
    static void CreateOverlay(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError DestroyOverlay( VROverlayHandle_t ulOverlayHandle ) = 0;
    static void DestroyOverlay(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetOverlayKey( VROverlayHandle_t ulOverlayHandle, VR_OUT_STRING() char *pchValue, uint32_t unBufferSize, EVROverlayError *pError = 0L ) = 0;
    static void GetOverlayKey(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetOverlayName( VROverlayHandle_t ulOverlayHandle, VR_OUT_STRING() char *pchValue, uint32_t unBufferSize, EVROverlayError *pError = 0L ) = 0;
    static void GetOverlayName(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayName( VROverlayHandle_t ulOverlayHandle, const char *pchName ) = 0;
    static void SetOverlayName(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayImageData( VROverlayHandle_t ulOverlayHandle, void *pvBuffer, uint32_t unBufferSize, uint32_t *punWidth, uint32_t *punHeight ) = 0;
    // static void GetOverlayImageData(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual const char *GetOverlayErrorNameFromEnum( EVROverlayError error ) = 0;
    static void GetOverlayErrorNameFromEnum(const Nan::FunctionCallbackInfo<Value> &info);

    // ---------------------------------------------
	// Overlay rendering methods
	// ---------------------------------------------

    // virtual EVROverlayError SetOverlayRenderingPid( VROverlayHandle_t ulOverlayHandle, uint32_t unPID ) = 0;
    static void SetOverlayRenderingPid(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetOverlayRenderingPid( VROverlayHandle_t ulOverlayHandle ) = 0;
    static void GetOverlayRenderingPid(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayFlag( VROverlayHandle_t ulOverlayHandle, VROverlayFlags eOverlayFlag, bool bEnabled ) = 0;
    static void SetOverlayFlag(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayFlag( VROverlayHandle_t ulOverlayHandle, VROverlayFlags eOverlayFlag, bool *pbEnabled ) = 0;
    static void GetOverlayFlag(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayFlags( VROverlayHandle_t ulOverlayHandle, uint32_t *pFlags ) = 0;
    static void GetOverlayFlags(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayColor( VROverlayHandle_t ulOverlayHandle, float fRed, float fGreen, float fBlue ) = 0;
    static void SetOverlayColor(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayColor( VROverlayHandle_t ulOverlayHandle, float *pfRed, float *pfGreen, float *pfBlue ) = 0;
    static void GetOverlayColor(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayAlpha( VROverlayHandle_t ulOverlayHandle, float fAlpha ) = 0;
    static void SetOverlayAlpha(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayAlpha( VROverlayHandle_t ulOverlayHandle, float *pfAlpha ) = 0;
    static void GetOverlayAlpha(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayTexelAspect( VROverlayHandle_t ulOverlayHandle, float fTexelAspect ) = 0;
    static void SetOverlayTexelAspect(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayTexelAspect( VROverlayHandle_t ulOverlayHandle, float *pfTexelAspect ) = 0;
    static void GetOverlayTexelAspect(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlaySortOrder( VROverlayHandle_t ulOverlayHandle, uint32_t unSortOrder ) = 0;
    static void SetOverlaySortOrder(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlaySortOrder( VROverlayHandle_t ulOverlayHandle, uint32_t *punSortOrder ) = 0;
    static void GetOverlaySortOrder(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayWidthInMeters( VROverlayHandle_t ulOverlayHandle, float fWidthInMeters ) = 0;
    static void SetOverlayWidthInMeters(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayWidthInMeters( VROverlayHandle_t ulOverlayHandle, float *pfWidthInMeters ) = 0;
    static void GetOverlayWidthInMeters(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayCurvature( VROverlayHandle_t ulOverlayHandle, float fCurvature ) = 0;
    static void SetOverlayCurvature(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayCurvature( VROverlayHandle_t ulOverlayHandle, float *pfCurvature ) = 0;
    static void GetOverlayCurvature(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayTextureColorSpace( VROverlayHandle_t ulOverlayHandle, EColorSpace eTextureColorSpace ) = 0;
    static void SetOverlayTextureColorSpace(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayTextureColorSpace( VROverlayHandle_t ulOverlayHandle, EColorSpace *peTextureColorSpace ) = 0;
    static void GetOverlayTextureColorSpace(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayTextureBounds( VROverlayHandle_t ulOverlayHandle, const VRTextureBounds_t *pOverlayTextureBounds ) = 0;
    static void SetOverlayTextureBounds(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayTextureBounds( VROverlayHandle_t ulOverlayHandle, VRTextureBounds_t *pOverlayTextureBounds ) = 0;
    static void GetOverlayTextureBounds(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayTransformType( VROverlayHandle_t ulOverlayHandle, VROverlayTransformType *peTransformType ) = 0;
    static void GetOverlayTransformType(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayTransformAbsolute( VROverlayHandle_t ulOverlayHandle, ETrackingUniverseOrigin eTrackingOrigin, const HmdMatrix34_t *pmatTrackingOriginToOverlayTransform ) = 0;
    static void SetOverlayTransformAbsolute(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayTransformAbsolute( VROverlayHandle_t ulOverlayHandle, ETrackingUniverseOrigin *peTrackingOrigin, HmdMatrix34_t *pmatTrackingOriginToOverlayTransform ) = 0;
    static void GetOverlayTransformAbsolute(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayTransformTrackedDeviceRelative( VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t unTrackedDevice, const HmdMatrix34_t *pmatTrackedDeviceToOverlayTransform ) = 0;
    static void SetOverlayTransformTrackedDeviceRelative(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayTransformTrackedDeviceRelative( VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t *punTrackedDevice, HmdMatrix34_t *pmatTrackedDeviceToOverlayTransform ) = 0;
    static void GetOverlayTransformTrackedDeviceRelative(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayTransformTrackedDeviceComponent( VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t unDeviceIndex, const char *pchComponentName ) = 0;
    static void SetOverlayTransformTrackedDeviceComponent(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayTransformTrackedDeviceComponent( VROverlayHandle_t ulOverlayHandle, TrackedDeviceIndex_t *punDeviceIndex, VR_OUT_STRING() char *pchComponentName, uint32_t unComponentNameSize ) = 0;
    static void GetOverlayTransformTrackedDeviceComponent(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVROverlayError GetOverlayTransformOverlayRelative( VROverlayHandle_t ulOverlayHandle, VROverlayHandle_t *ulOverlayHandleParent, HmdMatrix34_t *pmatParentOverlayToOverlayTransform ) = 0;
    static void GetOverlayTransformOverlayRelative(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVROverlayError SetOverlayTransformOverlayRelative( VROverlayHandle_t ulOverlayHandle, VROverlayHandle_t ulOverlayHandleParent, const HmdMatrix34_t *pmatParentOverlayToOverlayTransform ) = 0;
    static void SetOverlayTransformOverlayRelative(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayTransformCursor( VROverlayHandle_t ulCursorOverlayHandle, const HmdVector2_t *pvHotspot ) = 0;
    static void SetOverlayTransformCursor(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVROverlayError GetOverlayTransformCursor( VROverlayHandle_t ulOverlayHandle, HmdVector2_t *pvHotspot ) = 0;
    static void GetOverlayTransformCursor(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVROverlayError SetOverlayTransformProjection( VROverlayHandle_t ulOverlayHandle,
	//		ETrackingUniverseOrigin eTrackingOrigin, const HmdMatrix34_t* pmatTrackingOriginToOverlayTransform,
	//		const VROverlayProjection_t *pProjection, vr::EVREye eEye ) = 0;
    static void SetOverlayTransformProjection(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError ShowOverlay( VROverlayHandle_t ulOverlayHandle ) = 0;
    static void ShowOverlay(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError HideOverlay( VROverlayHandle_t ulOverlayHandle ) = 0;
    static void HideOverlay(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsOverlayVisible( VROverlayHandle_t ulOverlayHandle ) = 0;
    static void IsOverlayVisible(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetTransformForOverlayCoordinates( VROverlayHandle_t ulOverlayHandle, ETrackingUniverseOrigin eTrackingOrigin, HmdVector2_t coordinatesInOverlay, HmdMatrix34_t *pmatTransform ) = 0;
    static void GetTransformForOverlayCoordinates(const Nan::FunctionCallbackInfo<Value> &info);

    // ---------------------------------------------
	// Overlay input methods
	// ---------------------------------------------

    // virtual bool PollNextOverlayEvent( VROverlayHandle_t ulOverlayHandle, VREvent_t *pEvent, uint32_t uncbVREvent ) = 0;
    static void PollNextOverlayEvent(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayInputMethod( VROverlayHandle_t ulOverlayHandle, VROverlayInputMethod *peInputMethod ) = 0;
    static void GetOverlayInputMethod(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayInputMethod( VROverlayHandle_t ulOverlayHandle, VROverlayInputMethod eInputMethod ) = 0;
    static void SetOverlayInputMethod(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayMouseScale( VROverlayHandle_t ulOverlayHandle, HmdVector2_t *pvecMouseScale ) = 0;
    static void GetOverlayMouseScale(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayMouseScale( VROverlayHandle_t ulOverlayHandle, const HmdVector2_t *pvecMouseScale ) = 0;
    static void SetOverlayMouseScale(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool ComputeOverlayIntersection( VROverlayHandle_t ulOverlayHandle, const VROverlayIntersectionParams_t *pParams, VROverlayIntersectionResults_t *pResults ) = 0;
    static void ComputeOverlayIntersection(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsHoverTargetOverlay( VROverlayHandle_t ulOverlayHandle ) = 0;
    static void IsHoverTargetOverlay(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayIntersectionMask( VROverlayHandle_t ulOverlayHandle, VROverlayIntersectionMaskPrimitive_t *pMaskPrimitives, uint32_t unNumMaskPrimitives, uint32_t unPrimitiveSize = sizeof( VROverlayIntersectionMaskPrimitive_t ) ) = 0;
    // static void SetOverlayIntersectionMask(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError TriggerLaserMouseHapticVibration( VROverlayHandle_t ulOverlayHandle, float fDurationSeconds, float fFrequency, float fAmplitude ) = 0;
    static void TriggerLaserMouseHapticVibration(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayCursor( VROverlayHandle_t ulOverlayHandle, VROverlayHandle_t ulCursorHandle ) = 0;
    static void SetOverlayCursor(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayCursorPositionOverride( VROverlayHandle_t ulOverlayHandle, const HmdVector2_t *pvCursor ) = 0;
    static void SetOverlayCursorPositionOverride(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError ClearOverlayCursorPositionOverride( VROverlayHandle_t ulOverlayHandle ) = 0;
    static void ClearOverlayCursorPositionOverride(const Nan::FunctionCallbackInfo<Value> &info);

    // ---------------------------------------------
	// Overlay texture methods
	// ---------------------------------------------

    // virtual EVROverlayError SetOverlayTexture( VROverlayHandle_t ulOverlayHandle, const Texture_t *pTexture ) = 0;
    static void SetOverlayTexture(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError ClearOverlayTexture( VROverlayHandle_t ulOverlayHandle ) = 0;
    static void ClearOverlayTexture(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayRaw( VROverlayHandle_t ulOverlayHandle, void *pvBuffer, uint32_t unWidth, uint32_t unHeight, uint32_t unBytesPerPixel ) = 0;
    static void SetOverlayRaw(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetOverlayFromFile( VROverlayHandle_t ulOverlayHandle, const char *pchFilePath ) = 0;
    static void SetOverlayFromFile(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayTexture( VROverlayHandle_t ulOverlayHandle, void **pNativeTextureHandle, void *pNativeTextureRef, uint32_t *pWidth, uint32_t *pHeight, uint32_t *pNativeFormat, ETextureType *pAPIType, EColorSpace *pColorSpace, VRTextureBounds_t *pTextureBounds ) = 0;
    static void GetOverlayTexture(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError ReleaseNativeOverlayHandle( VROverlayHandle_t ulOverlayHandle, void *pNativeTextureHandle ) = 0;
    static void ReleaseNativeOverlayHandle(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetOverlayTextureSize( VROverlayHandle_t ulOverlayHandle, uint32_t *pWidth, uint32_t *pHeight ) = 0;
    static void GetOverlayTextureSize(const Nan::FunctionCallbackInfo<Value> &info);

    // ----------------------------------------------
	// Dashboard Overlay Methods
	// ----------------------------------------------

    // virtual EVROverlayError CreateDashboardOverlay( const char *pchOverlayKey, const char *pchOverlayFriendlyName, VROverlayHandle_t * pMainHandle, VROverlayHandle_t *pThumbnailHandle ) = 0;
    static void CreateDashboardOverlay(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsDashboardVisible() = 0;
    static void IsDashboardVisible(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsActiveDashboardOverlay( VROverlayHandle_t ulOverlayHandle ) = 0;
    static void IsActiveDashboardOverlay(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError SetDashboardOverlaySceneProcess( VROverlayHandle_t ulOverlayHandle, uint32_t unProcessId ) = 0;
    static void SetDashboardOverlaySceneProcess(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError GetDashboardOverlaySceneProcess( VROverlayHandle_t ulOverlayHandle, uint32_t *punProcessId ) = 0;
    static void GetDashboardOverlaySceneProcess(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void ShowDashboard( const char *pchOverlayToShow ) = 0;
    static void ShowDashboard(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::TrackedDeviceIndex_t GetPrimaryDashboardDevice() = 0;
    static void GetPrimaryDashboardDevice(const Nan::FunctionCallbackInfo<Value> &info);

    // ---------------------------------------------
	// Keyboard methods
	// ---------------------------------------------

    // virtual EVROverlayError ShowKeyboard( EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, uint32_t unFlags,
	//		const char *pchDescription, uint32_t unCharMax, const char *pchExistingText, uint64_t uUserValue ) = 0;
    static void ShowKeyboard(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVROverlayError ShowKeyboardForOverlay( VROverlayHandle_t ulOverlayHandle, EGamepadTextInputMode eInputMode,
	//		EGamepadTextInputLineMode eLineInputMode, uint32_t unFlags, const char *pchDescription, uint32_t unCharMax,
	//		const char *pchExistingText, uint64_t uUserValue ) = 0;
    static void ShowKeyboardForOverlay(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetKeyboardText( VR_OUT_STRING() char *pchText, uint32_t cchText ) = 0;
    static void GetKeyboardText(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void HideKeyboard() = 0;
    static void HideKeyboard(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetKeyboardTransformAbsolute( ETrackingUniverseOrigin eTrackingOrigin, const HmdMatrix34_t *pmatTrackingOriginToKeyboardTransform ) = 0;
    static void SetKeyboardTransformAbsolute(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetKeyboardPositionForOverlay( VROverlayHandle_t ulOverlayHandle, HmdRect2_t avoidRect ) = 0;
    static void SetKeyboardPositionForOverlay(const Nan::FunctionCallbackInfo<Value> &info);

    // ---------------------------------------------
	// Message box methods
	// ---------------------------------------------

    // virtual VRMessageOverlayResponse ShowMessageOverlay( const char* pchText, const char* pchCaption, const char* pchButton0Text, const char* pchButton1Text = nullptr, const char* pchButton2Text = nullptr, const char* pchButton3Text = nullptr ) = 0;
    static void ShowMessageOverlay(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void CloseMessageOverlay() = 0;
    static void CloseMessageOverlay(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVROverlay *const self_;
};

#endif
