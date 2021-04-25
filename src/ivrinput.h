#ifndef IVRINPUT_H_JS
#define IVRINPUT_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRInput;
}

class IVRInput : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRInput *input);

private:
    explicit IVRInput(vr::IVRInput *self);
    ~IVRInput() = default;

    
    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // ---------------  Handle management   --------------- //

    // virtual EVRInputError SetActionManifestPath( const char *pchActionManifestPath ) = 0;
    static void SetActionManifestPath(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetActionSetHandle( const char *pchActionSetName, VRActionSetHandle_t *pHandle ) = 0;
    static void GetActionSetHandle(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetActionHandle( const char *pchActionName, VRActionHandle_t *pHandle ) = 0;
    static void GetActionHandle(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetInputSourceHandle( const char *pchInputSourcePath, VRInputValueHandle_t *pHandle ) = 0;
    static void GetInputSourceHandle(const Nan::FunctionCallbackInfo<Value> &info);

    // --------------- Reading action state ------------------- //

    // virtual EVRInputError UpdateActionState( VR_ARRAY_COUNT( unSetCount ) VRActiveActionSet_t *pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount ) = 0;
    static void UpdateActionState(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetDigitalActionData( VRActionHandle_t action, InputDigitalActionData_t *pActionData, uint32_t unActionDataSize, VRInputValueHandle_t ulRestrictToDevice ) = 0;
    static void GetDigitalActionData(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetAnalogActionData( VRActionHandle_t action, InputAnalogActionData_t *pActionData, uint32_t unActionDataSize, VRInputValueHandle_t ulRestrictToDevice ) = 0;
    static void GetAnalogActionData(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetPoseActionDataRelativeToNow( VRActionHandle_t action, ETrackingUniverseOrigin eOrigin, float fPredictedSecondsFromNow, InputPoseActionData_t *pActionData, uint32_t unActionDataSize, VRInputValueHandle_t ulRestrictToDevice ) = 0;
    static void GetPoseActionDataRelativeToNow(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetPoseActionDataForNextFrame( VRActionHandle_t action, ETrackingUniverseOrigin eOrigin, InputPoseActionData_t *pActionData, uint32_t unActionDataSize, VRInputValueHandle_t ulRestrictToDevice ) = 0;
    static void GetPoseActionDataForNextFrame(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetSkeletalActionData( VRActionHandle_t action, InputSkeletalActionData_t *pActionData, uint32_t unActionDataSize ) = 0;
    static void GetSkeletalActionData(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetDominantHand( ETrackedControllerRole *peDominantHand ) = 0;
    static void GetDominantHand(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError SetDominantHand( ETrackedControllerRole eDominantHand ) = 0;
    static void SetDominantHand(const Nan::FunctionCallbackInfo<Value> &info);

    // ---------------  Static Skeletal Data ------------------- //

    // virtual EVRInputError GetBoneCount( VRActionHandle_t action, uint32_t* pBoneCount ) = 0;
    static void GetBoneCount(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetBoneHierarchy( VRActionHandle_t action, VR_ARRAY_COUNT( unIndexArayCount ) BoneIndex_t* pParentIndices, uint32_t unIndexArayCount ) = 0;
    static void GetBoneHierarchy(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetBoneName( VRActionHandle_t action, BoneIndex_t nBoneIndex, VR_OUT_STRING() char* pchBoneName, uint32_t unNameBufferSize ) = 0;
    static void GetBoneName(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetSkeletalReferenceTransforms( VRActionHandle_t action, EVRSkeletalTransformSpace eTransformSpace, EVRSkeletalReferencePose eReferencePose, VR_ARRAY_COUNT( unTransformArrayCount ) VRBoneTransform_t *pTransformArray, uint32_t unTransformArrayCount ) = 0;
    static void GetSkeletalReferenceTransforms(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetSkeletalTrackingLevel( VRActionHandle_t action, EVRSkeletalTrackingLevel* pSkeletalTrackingLevel ) = 0;
    static void GetSkeletalTrackingLevel(const Nan::FunctionCallbackInfo<Value> &info);

    // ---------------  Dynamic Skeletal Data ------------------- //

    // virtual EVRInputError GetSkeletalBoneData( VRActionHandle_t action, EVRSkeletalTransformSpace eTransformSpace, EVRSkeletalMotionRange eMotionRange, VR_ARRAY_COUNT( unTransformArrayCount ) VRBoneTransform_t *pTransformArray, uint32_t unTransformArrayCount ) = 0;
    static void GetSkeletalBoneData(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetSkeletalSummaryData( VRActionHandle_t action, EVRSummaryType eSummaryType, VRSkeletalSummaryData_t * pSkeletalSummaryData ) = 0;
    static void GetSkeletalSummaryData(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetSkeletalBoneDataCompressed( VRActionHandle_t action, EVRSkeletalMotionRange eMotionRange, VR_OUT_BUFFER_COUNT( unCompressedSize ) void *pvCompressedData, uint32_t unCompressedSize, uint32_t *punRequiredCompressedSize ) = 0;
    static void GetSkeletalBoneDataCompressed(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError DecompressSkeletalBoneData( const void *pvCompressedBuffer, uint32_t unCompressedBufferSize, EVRSkeletalTransformSpace eTransformSpace, VR_ARRAY_COUNT( unTransformArrayCount ) VRBoneTransform_t *pTransformArray, uint32_t unTransformArrayCount ) = 0;
    static void DecompressSkeletalBoneData(const Nan::FunctionCallbackInfo<Value> &info);

    // --------------- Haptics ------------------- //

    // virtual EVRInputError TriggerHapticVibrationAction( VRActionHandle_t action, float fStartSecondsFromNow, float fDurationSeconds, float fFrequency, float fAmplitude, VRInputValueHandle_t ulRestrictToDevice ) = 0;
    static void TriggerHapticVibrationAction(const Nan::FunctionCallbackInfo<Value> &info);
    
    // --------------- Action Origins ---------------- //

    // virtual EVRInputError GetActionOrigins( VRActionSetHandle_t actionSetHandle, VRActionHandle_t digitalActionHandle, VR_ARRAY_COUNT( originOutCount ) VRInputValueHandle_t *originsOut, uint32_t originOutCount ) = 0;
    static void GetActionOrigins(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetOriginLocalizedName( VRInputValueHandle_t origin, VR_OUT_STRING() char *pchNameArray, uint32_t unNameArraySize, int32_t unStringSectionsToInclude ) = 0;
    static void GetOriginLocalizedName(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetOriginTrackedDeviceInfo( VRInputValueHandle_t origin, InputOriginInfo_t *pOriginInfo, uint32_t unOriginInfoSize ) = 0;
    static void GetOriginTrackedDeviceInfo(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetActionBindingInfo( VRActionHandle_t action, InputBindingInfo_t *pOriginInfo, uint32_t unBindingInfoSize, uint32_t unBindingInfoCount, uint32_t *punReturnedBindingInfoCount ) = 0;
    static void GetActionBindingInfo(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError ShowActionOrigins( VRActionSetHandle_t actionSetHandle, VRActionHandle_t ulActionHandle ) = 0;
    static void ShowActionOrigins(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError ShowBindingsForActionSet( VR_ARRAY_COUNT( unSetCount ) VRActiveActionSet_t *pSets, uint32_t unSizeOfVRSelectedActionSet_t, uint32_t unSetCount, VRInputValueHandle_t originToHighlight ) = 0;
    static void ShowBindingsForActionSet(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetComponentStateForBinding( const char *pchRenderModelName, const char *pchComponentName,
	//		const InputBindingInfo_t *pOriginInfo, uint32_t unBindingInfoSize, uint32_t unBindingInfoCount,
	//		vr::RenderModel_ComponentState_t *pComponentState ) = 0;
    static void GetComponentStateForBinding(const Nan::FunctionCallbackInfo<Value> &info);

    // --------------- Legacy Input ------------------- //

    
    // virtual bool IsUsingLegacyInput() = 0;
    static void IsUsingLegacyInput(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError OpenBindingUI( const char* pchAppKey, VRActionSetHandle_t ulActionSetHandle, VRInputValueHandle_t ulDeviceHandle, bool bShowOnDesktop ) = 0;
    static void OpenBindingUI(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRInputError GetBindingVariant( vr::VRInputValueHandle_t ulDevicePath,
	//		VR_OUT_STRING() char *pchVariantArray, uint32_t unVariantArraySize ) = 0;
    static void GetBindingVariant(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRInput *const self_;
};

#endif