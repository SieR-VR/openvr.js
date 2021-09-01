const openvr = require('bindings')('openvr')

// version.h
export const k_nSteamVRVersionMajor: number = 1;
export const k_nSteamVRVersionMinor: number = 16;
export const k_nSteamVRVersionBuild: number = 8;

//public_vrtypes.h
export type HmdMatrix34_t = number[][];
export type HmdMatrix33_t = number[][];
export type HmdMatrix44_t = number[][];

export type HmdVector2_t = number[];
export type HmdVector3_t = number[];
export type HmdVector4_t = number[];

export type HmdQuaternion_t = { w: number; x: number; y: number; z: number };
export type HmdColor_t = { r: number; g: number; b: number; a: number };
export type HmdQuad_t = HmdVector3_t[];
export type HmdRect2_t = { vTopLeft: HmdVector2_t; vBottomRight: HmdVector2_t; };
export type VRBoneTransform_t = { position: HmdVector4_t; orientation: HmdQuaternion_t; };

// vrtypes.h
export type SpatialAnchorHandle_t = number;
export type glSharedTextureHandle_t = number;
export type glInt_t = number;
export type glUInt_t = number;

export type DistortionCoordinates_t = { rfRed: number[]; rfGreen: number[]; rfBlue: number[]; };
export enum EVREye { Eye_Left = 0, Eye_Right = 1, };
export enum ETextureType {
    TextureType_Invalid = -1,
    TextureType_DirectX = 0,
    TextureType_OpenGL = 1,
    TextureType_Vulkan = 2,
    TextureType_IOSurface = 3,
    TextureType_DirectX12 = 4,
    TextureType_DXGISharedHandle = 5,
    TextureType_Metal = 6,
};
export enum EColorSpace {
    ColorSpace_Auto = 0,
    ColorSpace_Gamma = 1,
    ColorSpace_Linear = 2,
};
export type Texture_t = { handle: number; eType: ETextureType; eColorSpace: EColorSpace };
export type SharedTextureHandle_t = number;
export enum ETrackingResult {
    TrackingResult_Uninitialized = 1,

    TrackingResult_Calibrating_InProgress = 100,
    TrackingResult_Calibrating_OutOfRange = 101,

    TrackingResult_Running_OK = 200,
    TrackingResult_Running_OutOfRange = 201,

    TrackingResult_Fallback_RotationOnly = 300,
}
export type DriverId_t = number;
export const k_nDriverNone: number = 0xFFFFFFFF;
export const k_unMaxDriverDebugResponseSize = 32768;
export type TrackedDeviceIndex_t = number;
export const k_unTrackedDeviceIndex_Hmd: number = 0;
export const k_unMaxTrackedDeviceCount: number = 64;
export const k_unTrackedDeviceIndexOther: number = 0xFFFFFFFE;
export const k_unTrackedDeviceIndexInvalid: number = 0xFFFFFFFF;
export enum ETrackedDeviceClass {
    TrackedDeviceClass_Invalid = 0,
    TrackedDeviceClass_HMD = 1,
    TrackedDeviceClass_Controller = 2,
    TrackedDeviceClass_GenericTracker = 3,
    TrackedDeviceClass_TrackingReference = 4,
    TrackedDeviceClass_DisplayRedirect = 5,

    TrackedDeviceClass_Max
}
export enum ETrackedControllerRole {
    TrackedControllerRole_Invalid = 0,
    TrackedControllerRole_LeftHand = 1,
    TrackedControllerRole_RightHand = 2,
    TrackedControllerRole_OptOut = 3,
    TrackedControllerRole_Treadmill = 4,
    TrackedControllerRole_Stylus = 5,
    TrackedControllerRole_Max = 5
}
export const IsRoleAllowedAsHand = function (eRole: ETrackedControllerRole): boolean {
    switch (eRole) {
        case ETrackedControllerRole.TrackedControllerRole_Invalid:
        case ETrackedControllerRole.TrackedControllerRole_LeftHand:
        case ETrackedControllerRole.TrackedControllerRole_RightHand:
            return true;
        default:
            return false;
    }
}
export type TrackedDevicePose_t = {
    mDeviceToAbsoluteTracking: HmdMatrix34_t;
    vVelocity: HmdVector3_t;
    VAngularVelocity: HmdVector3_t;
    eTrackingResult: ETrackingResult;
    bPoseIsValid: boolean;

    bDeviceIsConnected: boolean;
}
export enum ETrackingUniverseOrigin {
    TrackingUniverseSeated = 0,
    TrackingUniverseStanding = 1,
    TrackingUniverseRawAndUncalibrated = 2,
}
export enum EAdditionalRadioFeatures {
    AdditionalRadioFeatures_None = 0x00000000,
    AdditionalRadioFeatures_HTCLinkBox = 0x00000001,
    AdditionalRadioFeatures_InternalDongle = 0x00000002,
    AdditionalRadioFeatures_ExternalDongle = 0x00000004,
}
export type WebConsoleHandle_t = number;
export type PropertyContainerHandle_t = number;
export type PropertyTypeTag_t = number;
export const k_unInvalidPropertyContainer: PropertyContainerHandle_t = 0;
export const k_unInvalidPropertyTag: PropertyTypeTag_t = 0;
export type DriverHandle_t = PropertyContainerHandle_t;
export const k_unInvalidDriverHandle: PropertyContainerHandle_t = 0;

export const k_unFloatPropertyTag: PropertyTypeTag_t = 1;
export const k_unInt32PropertyTag: PropertyTypeTag_t = 2;
export const k_unUint64PropertyTag: PropertyTypeTag_t = 3;
export const k_unBoolPropertyTag: PropertyTypeTag_t = 4;
export const k_unStringPropertyTag: PropertyTypeTag_t = 5;
export const k_unErrorPropertyTag: PropertyTypeTag_t = 6;
export const k_unDoublePropertyTag: PropertyTypeTag_t = 7;

export const k_unHmdMatrix34PropertyTag: PropertyTypeTag_t = 20;
export const k_unHmdMatrix44PropertyTag: PropertyTypeTag_t = 21;
export const k_unHmdVector3PropertyTag: PropertyTypeTag_t = 22;
export const k_unHmdVector4PropertyTag: PropertyTypeTag_t = 23;
export const k_unHmdVector2PropertyTag: PropertyTypeTag_t = 24;
export const k_unHmdQuadPropertyTag: PropertyTypeTag_t = 25;

export const k_unHiddenAreaPropertyTag: PropertyTypeTag_t = 30;
export const k_unPathHandleInfoTag: PropertyTypeTag_t = 31;
export const k_unActionPropertyTag: PropertyTypeTag_t = 32;
export const k_unInputValuePropertyTag: PropertyTypeTag_t = 33;
export const k_unWildcardPropertyTag: PropertyTypeTag_t = 34;
export const k_unHapticVibrationPropertyTag: PropertyTypeTag_t = 35;
export const k_unSkeletonPropertyTag: PropertyTypeTag_t = 36;

export const k_unSpatialAnchorPosePropertyTag: PropertyTypeTag_t = 40;
export const k_unJsonPropertyTag: PropertyTypeTag_t = 41;
export const k_unActiveActionSetPropertyTag: PropertyTypeTag_t = 42;

export const k_unOpenVRInternalReserved_Start: PropertyTypeTag_t = 1000;
export const k_unOpenVRInternalReserved_End: PropertyTypeTag_t = 10000;

export enum ETrackedDeviceProperty {
    Prop_Invalid = 0,

    // general properties that apply to all device classes
    Prop_TrackingSystemName_String = 1000,
    Prop_ModelNumber_String = 1001,
    Prop_SerialNumber_String = 1002,
    Prop_RenderModelName_String = 1003,
    Prop_WillDriftInYaw_Bool = 1004,
    Prop_ManufacturerName_String = 1005,
    Prop_TrackingFirmwareVersion_String = 1006,
    Prop_HardwareRevision_String = 1007,
    Prop_AllWirelessDongleDescriptions_String = 1008,
    Prop_ConnectedWirelessDongle_String = 1009,
    Prop_DeviceIsWireless_Bool = 1010,
    Prop_DeviceIsCharging_Bool = 1011,
    Prop_DeviceBatteryPercentage_Float = 1012, // 0 is empty, 1 is full
    Prop_StatusDisplayTransform_Matrix34 = 1013,
    Prop_Firmware_UpdateAvailable_Bool = 1014,
    Prop_Firmware_ManualUpdate_Bool = 1015,
    Prop_Firmware_ManualUpdateURL_String = 1016,
    Prop_HardwareRevision_Uint64 = 1017,
    Prop_FirmwareVersion_Uint64 = 1018,
    Prop_FPGAVersion_Uint64 = 1019,
    Prop_VRCVersion_Uint64 = 1020,
    Prop_RadioVersion_Uint64 = 1021,
    Prop_DongleVersion_Uint64 = 1022,
    Prop_BlockServerShutdown_Bool = 1023,
    Prop_CanUnifyCoordinateSystemWithHmd_Bool = 1024,
    Prop_ContainsProximitySensor_Bool = 1025,
    Prop_DeviceProvidesBatteryStatus_Bool = 1026,
    Prop_DeviceCanPowerOff_Bool = 1027,
    Prop_Firmware_ProgrammingTarget_String = 1028,
    Prop_DeviceClass_Int32 = 1029,
    Prop_HasCamera_Bool = 1030,
    Prop_DriverVersion_String = 1031,
    Prop_Firmware_ForceUpdateRequired_Bool = 1032,
    Prop_ViveSystemButtonFixRequired_Bool = 1033,
    Prop_ParentDriver_Uint64 = 1034,
    Prop_ResourceRoot_String = 1035,
    Prop_RegisteredDeviceType_String = 1036,
    Prop_InputProfilePath_String = 1037, // input profile to use for this device in the input system. Will default to tracking system name if this isn't provided
    Prop_NeverTracked_Bool = 1038, // Used for devices that will never have a valid pose by design
    Prop_NumCameras_Int32 = 1039,
    Prop_CameraFrameLayout_Int32 = 1040, // EVRTrackedCameraFrameLayout value
    Prop_CameraStreamFormat_Int32 = 1041, // ECameraVideoStreamFormat value
    Prop_AdditionalDeviceSettingsPath_String = 1042, // driver-relative path to additional device and global configuration settings
    Prop_Identifiable_Bool = 1043, // Whether device supports being identified from vrmonitor (e.g. blink LED, vibrate haptics, etc)
    Prop_BootloaderVersion_Uint64 = 1044,
    Prop_AdditionalSystemReportData_String = 1045, // additional string to include in system reports about a tracked device
    Prop_CompositeFirmwareVersion_String = 1046, // additional FW components from a device that gets propagated into reports
    Prop_Firmware_RemindUpdate_Bool = 1047,
    Prop_PeripheralApplicationVersion_Uint64 = 1048,
    Prop_ManufacturerSerialNumber_String = 1049,
    Prop_ComputedSerialNumber_String = 1050,
    Prop_EstimatedDeviceFirstUseTime_Int32 = 1051,

    // Properties that are unique to TrackedDeviceClass_HMD
    Prop_ReportsTimeSinceVSync_Bool = 2000,
    Prop_SecondsFromVsyncToPhotons_Float = 2001,
    Prop_DisplayFrequency_Float = 2002,
    Prop_UserIpdMeters_Float = 2003,
    Prop_CurrentUniverseId_Uint64 = 2004,
    Prop_PreviousUniverseId_Uint64 = 2005,
    Prop_DisplayFirmwareVersion_Uint64 = 2006,
    Prop_IsOnDesktop_Bool = 2007,
    Prop_DisplayMCType_Int32 = 2008,
    Prop_DisplayMCOffset_Float = 2009,
    Prop_DisplayMCScale_Float = 2010,
    Prop_EdidVendorID_Int32 = 2011,
    Prop_DisplayMCImageLeft_String = 2012,
    Prop_DisplayMCImageRight_String = 2013,
    Prop_DisplayGCBlackClamp_Float = 2014,
    Prop_EdidProductID_Int32 = 2015,
    Prop_CameraToHeadTransform_Matrix34 = 2016,
    Prop_DisplayGCType_Int32 = 2017,
    Prop_DisplayGCOffset_Float = 2018,
    Prop_DisplayGCScale_Float = 2019,
    Prop_DisplayGCPrescale_Float = 2020,
    Prop_DisplayGCImage_String = 2021,
    Prop_LensCenterLeftU_Float = 2022,
    Prop_LensCenterLeftV_Float = 2023,
    Prop_LensCenterRightU_Float = 2024,
    Prop_LensCenterRightV_Float = 2025,
    Prop_UserHeadToEyeDepthMeters_Float = 2026,
    Prop_CameraFirmwareVersion_Uint64 = 2027,
    Prop_CameraFirmwareDescription_String = 2028,
    Prop_DisplayFPGAVersion_Uint64 = 2029,
    Prop_DisplayBootloaderVersion_Uint64 = 2030,
    Prop_DisplayHardwareVersion_Uint64 = 2031,
    Prop_AudioFirmwareVersion_Uint64 = 2032,
    Prop_CameraCompatibilityMode_Int32 = 2033,
    Prop_ScreenshotHorizontalFieldOfViewDegrees_Float = 2034,
    Prop_ScreenshotVerticalFieldOfViewDegrees_Float = 2035,
    Prop_DisplaySuppressed_Bool = 2036,
    Prop_DisplayAllowNightMode_Bool = 2037,
    Prop_DisplayMCImageWidth_Int32 = 2038,
    Prop_DisplayMCImageHeight_Int32 = 2039,
    Prop_DisplayMCImageNumChannels_Int32 = 2040,
    Prop_DisplayMCImageData_Binary = 2041,
    Prop_SecondsFromPhotonsToVblank_Float = 2042,
    Prop_DriverDirectModeSendsVsyncEvents_Bool = 2043,
    Prop_DisplayDebugMode_Bool = 2044,
    Prop_GraphicsAdapterLuid_Uint64 = 2045,
    Prop_DriverProvidedChaperonePath_String = 2048,
    Prop_ExpectedTrackingReferenceCount_Int32 = 2049, // expected number of sensors or basestations to reserve UI space for
    Prop_ExpectedControllerCount_Int32 = 2050, // expected number of tracked controllers to reserve UI space for
    Prop_NamedIconPathControllerLeftDeviceOff_String = 2051, // placeholder icon for "left" controller if not yet detected/loaded
    Prop_NamedIconPathControllerRightDeviceOff_String = 2052, // placeholder icon for "right" controller if not yet detected/loaded
    Prop_NamedIconPathTrackingReferenceDeviceOff_String = 2053, // placeholder icon for sensor/base if not yet detected/loaded
    Prop_DoNotApplyPrediction_Bool = 2054, // currently no effect. was used to disable HMD pose prediction on MR, which is now done by MR driver setting velocity=0
    Prop_CameraToHeadTransforms_Matrix34_Array = 2055,
    Prop_DistortionMeshResolution_Int32 = 2056, // custom resolution of compositor calls to IVRSystem::ComputeDistortion
    Prop_DriverIsDrawingControllers_Bool = 2057,
    Prop_DriverRequestsApplicationPause_Bool = 2058,
    Prop_DriverRequestsReducedRendering_Bool = 2059,
    Prop_MinimumIpdStepMeters_Float = 2060,
    Prop_AudioBridgeFirmwareVersion_Uint64 = 2061,
    Prop_ImageBridgeFirmwareVersion_Uint64 = 2062,
    Prop_ImuToHeadTransform_Matrix34 = 2063,
    Prop_ImuFactoryGyroBias_Vector3 = 2064,
    Prop_ImuFactoryGyroScale_Vector3 = 2065,
    Prop_ImuFactoryAccelerometerBias_Vector3 = 2066,
    Prop_ImuFactoryAccelerometerScale_Vector3 = 2067,
    // reserved 2068
    Prop_ConfigurationIncludesLighthouse20Features_Bool = 2069,
    Prop_AdditionalRadioFeatures_Uint64 = 2070,
    Prop_CameraWhiteBalance_Vector4_Array = 2071, // Prop_NumCameras_Int32-sized array of float[4] RGBG white balance calibration data (max size is vr::k_unMaxCameras)
    Prop_CameraDistortionFunction_Int32_Array = 2072, // Prop_NumCameras_Int32-sized array of vr::EVRDistortionFunctionType values (max size is vr::k_unMaxCameras)
    Prop_CameraDistortionCoefficients_Float_Array = 2073, // Prop_NumCameras_Int32-sized array of double[vr::k_unMaxDistortionFunctionParameters] (max size is vr::k_unMaxCameras)
    Prop_ExpectedControllerType_String = 2074,
    Prop_HmdTrackingStyle_Int32 = 2075, // one of EHmdTrackingStyle
    Prop_DriverProvidedChaperoneVisibility_Bool = 2076,
    Prop_HmdColumnCorrectionSettingPrefix_String = 2077,
    Prop_CameraSupportsCompatibilityModes_Bool = 2078,
    Prop_SupportsRoomViewDepthProjection_Bool = 2079,
    Prop_DisplayAvailableFrameRates_Float_Array = 2080, // populated by compositor from actual EDID list when available from GPU driver
    Prop_DisplaySupportsMultipleFramerates_Bool = 2081, // if this is true but Prop_DisplayAvailableFrameRates_Float_Array is empty, explain to user
    Prop_DisplayColorMultLeft_Vector3 = 2082,
    Prop_DisplayColorMultRight_Vector3 = 2083,
    Prop_DisplaySupportsRuntimeFramerateChange_Bool = 2084,
    Prop_DisplaySupportsAnalogGain_Bool = 2085,
    Prop_DisplayMinAnalogGain_Float = 2086,
    Prop_DisplayMaxAnalogGain_Float = 2087,
    Prop_CameraExposureTime_Float = 2088,
    Prop_CameraGlobalGain_Float = 2089,
    // Prop_DashboardLayoutPathName_String 		= 2090, // DELETED
    Prop_DashboardScale_Float = 2091,
    Prop_IpdUIRangeMinMeters_Float = 2100,
    Prop_IpdUIRangeMaxMeters_Float = 2101,
    Prop_Hmd_SupportsHDCP14LegacyCompat_Bool = 2102,
    Prop_Hmd_SupportsMicMonitoring_Bool = 2103,

    // Driver requested mura correction properties
    Prop_DriverRequestedMuraCorrectionMode_Int32 = 2200,
    Prop_DriverRequestedMuraFeather_InnerLeft_Int32 = 2201,
    Prop_DriverRequestedMuraFeather_InnerRight_Int32 = 2202,
    Prop_DriverRequestedMuraFeather_InnerTop_Int32 = 2203,
    Prop_DriverRequestedMuraFeather_InnerBottom_Int32 = 2204,
    Prop_DriverRequestedMuraFeather_OuterLeft_Int32 = 2205,
    Prop_DriverRequestedMuraFeather_OuterRight_Int32 = 2206,
    Prop_DriverRequestedMuraFeather_OuterTop_Int32 = 2207,
    Prop_DriverRequestedMuraFeather_OuterBottom_Int32 = 2208,

    Prop_Audio_DefaultPlaybackDeviceId_String = 2300,
    Prop_Audio_DefaultRecordingDeviceId_String = 2301,
    Prop_Audio_DefaultPlaybackDeviceVolume_Float = 2302,
    Prop_Audio_SupportsDualSpeakerAndJackOutput_Bool = 2303,

    // Properties that are unique to TrackedDeviceClass_Controller
    Prop_AttachedDeviceId_String = 3000,
    Prop_SupportedButtons_Uint64 = 3001,
    Prop_Axis0Type_Int32 = 3002, // Return value is of type EVRControllerAxisType
    Prop_Axis1Type_Int32 = 3003, // Return value is of type EVRControllerAxisType
    Prop_Axis2Type_Int32 = 3004, // Return value is of type EVRControllerAxisType
    Prop_Axis3Type_Int32 = 3005, // Return value is of type EVRControllerAxisType
    Prop_Axis4Type_Int32 = 3006, // Return value is of type EVRControllerAxisType
    Prop_ControllerRoleHint_Int32 = 3007, // Return value is of type ETrackedControllerRole

    // Properties that are unique to TrackedDeviceClass_TrackingReference
    Prop_FieldOfViewLeftDegrees_Float = 4000,
    Prop_FieldOfViewRightDegrees_Float = 4001,
    Prop_FieldOfViewTopDegrees_Float = 4002,
    Prop_FieldOfViewBottomDegrees_Float = 4003,
    Prop_TrackingRangeMinimumMeters_Float = 4004,
    Prop_TrackingRangeMaximumMeters_Float = 4005,
    Prop_ModeLabel_String = 4006,
    Prop_CanWirelessIdentify_Bool = 4007, // volatile, based on radio presence and fw discovery
    Prop_Nonce_Int32 = 4008,

    // Properties that are used for user interface like icons names
    Prop_IconPathName_String = 5000, // DEPRECATED. Value not referenced. Now expected to be part of icon path properties.
    Prop_NamedIconPathDeviceOff_String = 5001, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
    Prop_NamedIconPathDeviceSearching_String = 5002, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
    Prop_NamedIconPathDeviceSearchingAlert_String = 5003, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
    Prop_NamedIconPathDeviceReady_String = 5004, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
    Prop_NamedIconPathDeviceReadyAlert_String = 5005, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
    Prop_NamedIconPathDeviceNotReady_String = 5006, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
    Prop_NamedIconPathDeviceStandby_String = 5007, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
    Prop_NamedIconPathDeviceAlertLow_String = 5008, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others
    Prop_NamedIconPathDeviceStandbyAlert_String = 5009, // {driver}/icons/icon_filename - PNG for static icon, or GIF for animation, 50x32 for headsets and 32x32 for others

    // Properties that are used by helpers, but are opaque to applications
    Prop_DisplayHiddenArea_Binary_Start = 5100,
    Prop_DisplayHiddenArea_Binary_End = 5150,
    Prop_ParentContainer = 5151,
    Prop_OverrideContainer_Uint64 = 5152,

    // Properties that are unique to drivers
    Prop_UserConfigPath_String = 6000,
    Prop_InstallPath_String = 6001,
    Prop_HasDisplayComponent_Bool = 6002,
    Prop_HasControllerComponent_Bool = 6003,
    Prop_HasCameraComponent_Bool = 6004,
    Prop_HasDriverDirectModeComponent_Bool = 6005,
    Prop_HasVirtualDisplayComponent_Bool = 6006,
    Prop_HasSpatialAnchorsSupport_Bool = 6007,

    // Properties that are set internally based on other information provided by drivers
    Prop_ControllerType_String = 7000,
    //Prop_LegacyInputProfile_String				= 7001, // This is no longer used. See "legacy_binding" in the input profile instead.
    Prop_ControllerHandSelectionPriority_Int32 = 7002, // Allows hand assignments to prefer some controllers over others. High numbers are selected over low numbers

    // Vendors are free to expose private debug data in this reserved region
    Prop_VendorSpecific_Reserved_Start = 10000,
    Prop_VendorSpecific_Reserved_End = 10999,

    Prop_TrackedDeviceProperty_Max = 1000000,
};

export const k_unMaxPropertyStringSize: number = 32 * 1024;
export enum ETrackedPropertyError {
    TrackedProp_Success = 0,
    TrackedProp_WrongDataType = 1,
    TrackedProp_WrongDeviceClass = 2,
    TrackedProp_BufferTooSmall = 3,
    TrackedProp_UnknownProperty = 4, // Driver has not set the property (and may not ever).
    TrackedProp_InvalidDevice = 5,
    TrackedProp_CouldNotContactServer = 6,
    TrackedProp_ValueNotProvidedByDevice = 7,
    TrackedProp_StringExceedsMaximumLength = 8,
    TrackedProp_NotYetAvailable = 9, // The property value isn't known yet, but is expected soon. Call again later.
    TrackedProp_PermissionDenied = 10,
    TrackedProp_InvalidOperation = 11,
    TrackedProp_CannotWriteToWildcards = 12,
    TrackedProp_IPCReadFailure = 13,
    TrackedProp_OutOfMemory = 14,
    TrackedProp_InvalidContainer = 15,
};
export enum EHmdTrackingStyle {
    HmdTrackingStyle_Unknown = 0,

    HmdTrackingStyle_Lighthouse = 1, // base stations and lasers
    HmdTrackingStyle_OutsideInCameras = 2, // Cameras and LED, Rift 1 style
    HmdTrackingStyle_InsideOutCameras = 3, // Cameras on HMD looking at the world
};
export type VRActionHandle_t = number;
export type VRActionSetHandle_t = number;
export type VRInputValueHandle_t = number;

export const k_ulInvalidActionHandle: VRActionHandle_t = 0;
export const k_ulInvalidActionSetHandle: VRActionSetHandle_t = 0;
export const k_ulInvalidInputValueHandle: VRInputValueHandle_t = 0;

export type VRTextureBounds_t = { uMin: number; vMin: number; uMax: number; vMax: number; };
export type VRTextureWithPose_t = Texture_t & { mDeviceToAbsoluteTracking: HmdMatrix34_t };
export type VRTextureDepthInfo_t = { handle: number; mProjection: HmdMatrix44_t; vRange: HmdVector2_t };
export type VRTextureWithDepth_t = Texture_t & { depth: VRTextureDepthInfo_t };
export type VRTextureWithPoseAndDepth_t = VRTextureWithPose_t & { depth: VRTextureDepthInfo_t };

export enum EVRSubmitFlags {
    // Simple render path. App submits rendered left and right eye images with no lens distortion correction applied.
    Submit_Default = 0x00,

    // App submits final left and right eye images with lens distortion already applied (lens distortion makes the images appear
    // barrel distorted with chromatic aberration correction applied). The app would have used the data returned by
    // vr::IVRSystem::ComputeDistortion() to apply the correct distortion to the rendered images before calling Submit().
    Submit_LensDistortionAlreadyApplied = 0x01,

    // If the texture pointer passed in is actually a renderbuffer (e.g. for MSAA in OpenGL) then set this flag.
    Submit_GlRenderBuffer = 0x02,

    // Do not use
    Submit_Reserved = 0x04,

    // Set to indicate that pTexture is a pointer to a VRTextureWithPose_t.
    // This flag can be combined with Submit_TextureWithDepth to pass a VRTextureWithPoseAndDepth_t.
    Submit_TextureWithPose = 0x08,

    // Set to indicate that pTexture is a pointer to a VRTextureWithDepth_t.
    // This flag can be combined with Submit_TextureWithPose to pass a VRTextureWithPoseAndDepth_t.
    Submit_TextureWithDepth = 0x10,

    // Set to indicate a discontinuity between this and the last frame.
    // This will prevent motion smoothing from attempting to extrapolate using the pair.
    Submit_FrameDiscontinuty = 0x20,

    // Set to indicate that pTexture->handle is a contains VRVulkanTextureArrayData_t
    Submit_VulkanTextureWithArrayData = 0x40,

    // If the texture pointer passed in is an OpenGL Array texture, set this flag
    Submit_GlArrayTexture = 0x80,

    // Do not use
    Submit_Reserved2 = 0x8000,
};

export enum EVRState {
    VRState_Undefined = -1,
    VRState_Off = 0,
    VRState_Searching = 1,
    VRState_Searching_Alert = 2,
    VRState_Ready = 3,
    VRState_Ready_Alert = 4,
    VRState_NotReady = 5,
    VRState_Standby = 6,
    VRState_Ready_Alert_Low = 7,
};

export enum EVREventType {
    VREvent_None = 0,

    VREvent_TrackedDeviceActivated = 100,
    VREvent_TrackedDeviceDeactivated = 101,
    VREvent_TrackedDeviceUpdated = 102,
    VREvent_TrackedDeviceUserInteractionStarted = 103,
    VREvent_TrackedDeviceUserInteractionEnded = 104,
    VREvent_IpdChanged = 105,
    VREvent_EnterStandbyMode = 106,
    VREvent_LeaveStandbyMode = 107,
    VREvent_TrackedDeviceRoleChanged = 108,
    VREvent_WatchdogWakeUpRequested = 109,
    VREvent_LensDistortionChanged = 110,
    VREvent_PropertyChanged = 111,
    VREvent_WirelessDisconnect = 112,
    VREvent_WirelessReconnect = 113,

    VREvent_ButtonPress = 200, // data is controller
    VREvent_ButtonUnpress = 201, // data is controller
    VREvent_ButtonTouch = 202, // data is controller
    VREvent_ButtonUntouch = 203, // data is controller

    // VREvent_DualAnalog_Press			= 250, // No longer sent
    // VREvent_DualAnalog_Unpress		= 251, // No longer sent
    // VREvent_DualAnalog_Touch			= 252, // No longer sent
    // VREvent_DualAnalog_Untouch		= 253, // No longer sent
    // VREvent_DualAnalog_Move			= 254, // No longer sent
    // VREvent_DualAnalog_ModeSwitch1	= 255, // No longer sent
    // VREvent_DualAnalog_ModeSwitch2	= 256, // No longer sent
    VREvent_Modal_Cancel = 257, // Sent to overlays with the

    VREvent_MouseMove = 300, // data is mouse
    VREvent_MouseButtonDown = 301, // data is mouse
    VREvent_MouseButtonUp = 302, // data is mouse
    VREvent_FocusEnter = 303, // data is overlay
    VREvent_FocusLeave = 304, // data is overlay
    VREvent_ScrollDiscrete = 305, // data is scroll
    VREvent_TouchPadMove = 306, // data is mouse
    VREvent_OverlayFocusChanged = 307, // data is overlay, global event
    VREvent_ReloadOverlays = 308,
    VREvent_ScrollSmooth = 309, // data is scroll
    VREvent_LockMousePosition = 310,
    VREvent_UnlockMousePosition = 311,

    VREvent_InputFocusCaptured = 400, // data is process DEPRECATED
    VREvent_InputFocusReleased = 401, // data is process DEPRECATED
    // VREvent_SceneFocusLost			= 402, // data is process
    // VREvent_SceneFocusGained			= 403, // data is process
    VREvent_SceneApplicationChanged = 404, // data is process - The App actually drawing the scene changed (usually to or from the compositor)
    VREvent_SceneFocusChanged = 405, // data is process - New app got access to draw the scene
    VREvent_InputFocusChanged = 406, // data is process
    // VREvent_SceneApplicationSecondaryRenderingStarted = 407,
    VREvent_SceneApplicationUsingWrongGraphicsAdapter = 408, // data is process
    VREvent_ActionBindingReloaded = 409, // data is process - The App that action binds reloaded for

    VREvent_HideRenderModels = 410, // Sent to the scene application to request hiding render models temporarily
    VREvent_ShowRenderModels = 411, // Sent to the scene application to request restoring render model visibility

    VREvent_SceneApplicationStateChanged = 412, // No data; but query VRApplications()->GetSceneApplicationState();

    VREvent_ConsoleOpened = 420,
    VREvent_ConsoleClosed = 421,

    VREvent_OverlayShown = 500,
    VREvent_OverlayHidden = 501,
    VREvent_DashboardActivated = 502,
    VREvent_DashboardDeactivated = 503,
    //VREvent_DashboardThumbSelected		= 504, // Sent to the overlay manager - data is overlay - No longer sent
    VREvent_DashboardRequested = 505, // Sent to the overlay manager - data is overlay
    VREvent_ResetDashboard = 506, // Send to the overlay manager
    //VREvent_RenderToast					= 507, // Send to the dashboard to render a toast - data is the notification ID -- no longer sent
    VREvent_ImageLoaded = 508, // Sent to overlays when a SetOverlayRaw or SetOverlayFromFile call finishes loading
    VREvent_ShowKeyboard = 509, // Sent to keyboard renderer in the dashboard to invoke it
    VREvent_HideKeyboard = 510, // Sent to keyboard renderer in the dashboard to hide it
    VREvent_OverlayGamepadFocusGained = 511, // Sent to an overlay when IVROverlay::SetFocusOverlay is called on it
    VREvent_OverlayGamepadFocusLost = 512, // Send to an overlay when it previously had focus and IVROverlay::SetFocusOverlay is called on something else
    VREvent_OverlaySharedTextureChanged = 513,
    //VREvent_DashboardGuideButtonDown	= 514, // These are no longer sent
    //VREvent_DashboardGuideButtonUp		= 515,
    VREvent_ScreenshotTriggered = 516, // Screenshot button combo was pressed, Dashboard should request a screenshot
    VREvent_ImageFailed = 517, // Sent to overlays when a SetOverlayRaw or SetOverlayfromFail fails to load
    VREvent_DashboardOverlayCreated = 518,
    VREvent_SwitchGamepadFocus = 519,

    // Screenshot API
    VREvent_RequestScreenshot = 520, // Sent by vrclient application to compositor to take a screenshot
    VREvent_ScreenshotTaken = 521, // Sent by compositor to the application that the screenshot has been taken
    VREvent_ScreenshotFailed = 522, // Sent by compositor to the application that the screenshot failed to be taken
    VREvent_SubmitScreenshotToDashboard = 523, // Sent by compositor to the dashboard that a completed screenshot was submitted
    VREvent_ScreenshotProgressToDashboard = 524, // Sent by compositor to the dashboard that a completed screenshot was submitted

    VREvent_PrimaryDashboardDeviceChanged = 525,
    VREvent_RoomViewShown = 526, // Sent by compositor whenever room-view is enabled
    VREvent_RoomViewHidden = 527, // Sent by compositor whenever room-view is disabled
    VREvent_ShowUI = 528, // data is showUi
    VREvent_ShowDevTools = 529, // data is showDevTools
    VREvent_DesktopViewUpdating = 530,
    VREvent_DesktopViewReady = 531,

    VREvent_Notification_Shown = 600,
    VREvent_Notification_Hidden = 601,
    VREvent_Notification_BeginInteraction = 602,
    VREvent_Notification_Destroyed = 603,

    VREvent_Quit = 700, // data is process
    VREvent_ProcessQuit = 701, // data is process
    //VREvent_QuitAborted_UserPrompt			= 702, // data is process
    VREvent_QuitAcknowledged = 703, // data is process
    VREvent_DriverRequestedQuit = 704, // The driver has requested that SteamVR shut down
    VREvent_RestartRequested = 705, // A driver or other component wants the user to restart SteamVR

    VREvent_ChaperoneDataHasChanged = 800, // this will never happen with the new chaperone system
    VREvent_ChaperoneUniverseHasChanged = 801,
    VREvent_ChaperoneTempDataHasChanged = 802, // this will never happen with the new chaperone system
    VREvent_ChaperoneSettingsHaveChanged = 803,
    VREvent_SeatedZeroPoseReset = 804,
    VREvent_ChaperoneFlushCache = 805, // Sent when the process needs to reload any cached data it retrieved from VRChaperone()
    VREvent_ChaperoneRoomSetupStarting = 806, // Triggered by CVRChaperoneClient::RoomSetupStarting
    VREvent_ChaperoneRoomSetupFinished = 807, // Triggered by CVRChaperoneClient::CommitWorkingCopy
    VREvent_StandingZeroPoseReset = 808,

    VREvent_AudioSettingsHaveChanged = 820,

    VREvent_BackgroundSettingHasChanged = 850,
    VREvent_CameraSettingsHaveChanged = 851,
    VREvent_ReprojectionSettingHasChanged = 852,
    VREvent_ModelSkinSettingsHaveChanged = 853,
    VREvent_EnvironmentSettingsHaveChanged = 854,
    VREvent_PowerSettingsHaveChanged = 855,
    VREvent_EnableHomeAppSettingsHaveChanged = 856,
    VREvent_SteamVRSectionSettingChanged = 857,
    VREvent_LighthouseSectionSettingChanged = 858,
    VREvent_NullSectionSettingChanged = 859,
    VREvent_UserInterfaceSectionSettingChanged = 860,
    VREvent_NotificationsSectionSettingChanged = 861,
    VREvent_KeyboardSectionSettingChanged = 862,
    VREvent_PerfSectionSettingChanged = 863,
    VREvent_DashboardSectionSettingChanged = 864,
    VREvent_WebInterfaceSectionSettingChanged = 865,
    VREvent_TrackersSectionSettingChanged = 866,
    VREvent_LastKnownSectionSettingChanged = 867,
    VREvent_DismissedWarningsSectionSettingChanged = 868,
    VREvent_GpuSpeedSectionSettingChanged = 869,
    VREvent_WindowsMRSectionSettingChanged = 870,
    VREvent_OtherSectionSettingChanged = 871,

    VREvent_StatusUpdate = 900,

    VREvent_WebInterface_InstallDriverCompleted = 950,

    VREvent_MCImageUpdated = 1000,

    VREvent_FirmwareUpdateStarted = 1100,
    VREvent_FirmwareUpdateFinished = 1101,

    VREvent_KeyboardClosed = 1200,
    VREvent_KeyboardCharInput = 1201,
    VREvent_KeyboardDone = 1202, // Sent when DONE button clicked on keyboard

    //VREvent_ApplicationTransitionStarted		= 1300,
    //VREvent_ApplicationTransitionAborted		= 1301,
    //VREvent_ApplicationTransitionNewAppStarted	= 1302,
    VREvent_ApplicationListUpdated = 1303,
    VREvent_ApplicationMimeTypeLoad = 1304,
    // VREvent_ApplicationTransitionNewAppLaunchComplete = 1305,
    VREvent_ProcessConnected = 1306,
    VREvent_ProcessDisconnected = 1307,

    //VREvent_Compositor_MirrorWindowShown		= 1400, // DEPRECATED
    //VREvent_Compositor_MirrorWindowHidden		= 1401, // DEPRECATED
    VREvent_Compositor_ChaperoneBoundsShown = 1410,
    VREvent_Compositor_ChaperoneBoundsHidden = 1411,
    VREvent_Compositor_DisplayDisconnected = 1412,
    VREvent_Compositor_DisplayReconnected = 1413,
    VREvent_Compositor_HDCPError = 1414, // data is hdcpError
    VREvent_Compositor_ApplicationNotResponding = 1415,
    VREvent_Compositor_ApplicationResumed = 1416,
    VREvent_Compositor_OutOfVideoMemory = 1417,
    VREvent_Compositor_DisplayModeNotSupported = 1418, // k_pch_SteamVR_PreferredRefreshRate
    VREvent_Compositor_StageOverrideReady = 1419,

    VREvent_TrackedCamera_StartVideoStream = 1500,
    VREvent_TrackedCamera_StopVideoStream = 1501,
    VREvent_TrackedCamera_PauseVideoStream = 1502,
    VREvent_TrackedCamera_ResumeVideoStream = 1503,
    VREvent_TrackedCamera_EditingSurface = 1550,

    VREvent_PerformanceTest_EnableCapture = 1600,
    VREvent_PerformanceTest_DisableCapture = 1601,
    VREvent_PerformanceTest_FidelityLevel = 1602,

    VREvent_MessageOverlay_Closed = 1650,
    VREvent_MessageOverlayCloseRequested = 1651,

    VREvent_Input_HapticVibration = 1700, // data is hapticVibration
    VREvent_Input_BindingLoadFailed = 1701, // data is inputBinding
    VREvent_Input_BindingLoadSuccessful = 1702, // data is inputBinding
    VREvent_Input_ActionManifestReloaded = 1703, // no data
    VREvent_Input_ActionManifestLoadFailed = 1704, // data is actionManifest
    VREvent_Input_ProgressUpdate = 1705, // data is progressUpdate
    VREvent_Input_TrackerActivated = 1706,
    VREvent_Input_BindingsUpdated = 1707,
    VREvent_Input_BindingSubscriptionChanged = 1708,

    VREvent_SpatialAnchors_PoseUpdated = 1800,        // data is spatialAnchor. broadcast
    VREvent_SpatialAnchors_DescriptorUpdated = 1801,       // data is spatialAnchor. broadcast
    VREvent_SpatialAnchors_RequestPoseUpdate = 1802,       // data is spatialAnchor. sent to specific driver
    VREvent_SpatialAnchors_RequestDescriptorUpdate = 1803, // data is spatialAnchor. sent to specific driver

    VREvent_SystemReport_Started = 1900, // user or system initiated generation of a system report. broadcast

    VREvent_Monitor_ShowHeadsetView = 2000, // data is process
    VREvent_Monitor_HideHeadsetView = 2001, // data is process

    // Vendors are free to expose private events in this reserved region
    VREvent_VendorSpecific_Reserved_Start = 10000,
    VREvent_VendorSpecific_Reserved_End = 19999,
};

export enum EDeviceActivityLevel {
    k_EDeviceActivityLevel_Unknown = -1,
    k_EDeviceActivityLevel_Idle = 0,						// No activity for the last 10 seconds
    k_EDeviceActivityLevel_UserInteraction = 1,				// Activity (movement or prox sensor) is happening now
    k_EDeviceActivityLevel_UserInteraction_Timeout = 2,		// No activity for the last 0.5 seconds
    k_EDeviceActivityLevel_Standby = 3,						// Idle for at least 5 seconds (configurable in Settings -> Power Management)
    k_EDeviceActivityLevel_Idle_Timeout = 4,
};

export enum EVRButtonId {
    k_EButton_System = 0,
    k_EButton_ApplicationMenu = 1,
    k_EButton_Grip = 2,
    k_EButton_DPad_Left = 3,
    k_EButton_DPad_Up = 4,
    k_EButton_DPad_Right = 5,
    k_EButton_DPad_Down = 6,
    k_EButton_A = 7,

    k_EButton_ProximitySensor = 31,

    k_EButton_Axis0 = 32,
    k_EButton_Axis1 = 33,
    k_EButton_Axis2 = 34,
    k_EButton_Axis3 = 35,
    k_EButton_Axis4 = 36,

    // aliases for well known controllers
    k_EButton_SteamVR_Touchpad = k_EButton_Axis0,
    k_EButton_SteamVR_Trigger = k_EButton_Axis1,

    k_EButton_Dashboard_Back = k_EButton_Grip,

    k_EButton_IndexController_A = k_EButton_Grip,
    k_EButton_IndexController_B = k_EButton_ApplicationMenu,
    k_EButton_IndexController_JoyStick = k_EButton_Axis3,

    k_EButton_Max = 64
}

export const ButtonMaskFromId = function (id: EVRButtonId): number { return 1 << id };
export type VREvent_Controller_t = { button: EVRButtonId };
export enum EVRMouseButton {
    VRMouseButton_Left = 0x0001,
    VRMouseButton_Right = 0x0002,
    VRMouseButton_Middle = 0x0004,
};
export type VREvent_Mouse_t = { x: number; y: number; button: number; };
export type VREvent_Scroll_t = {
    xdelta: number;
    ydelta: number;
    unused: number;
    viewportscale: number;
};
export type VREvent_TouchPadMove_t = {
    bFingerDown: boolean;
    fSecondsFingerDown: number;

    fValueXFirst: number;
    fValueYFirst: number;

    fValueXRaw: number;
    fValueYRaw: number;
};
export type VREvent_Notification_t = { ulUserValue: number; notificationId: number; };
export type VREvent_Process_t = { pid: number; oldPid: number; bForced: boolean; bConnectionLost: boolean; };
export type VREvent_Overlay_t = { overlayHandle: number; devicePath: number; memoryBlockId: number; };
export type VREvent_Status_t = { statusState: number; };
export type VREvent_Keyboard_t = { cNewInput: string; uUserValue: number; };
export type VREvent_Ipd_t = { ipdMeters: number; };
export type VREvent_Chaperone_t = { m_nPreviousUniverse: number; m_nCurrentUniverse: number; };
export type VREvent_Reserved_t = {
    reserved0: number;
    reserved1: number;
    reserved2: number;
    reserved3: number;
    reserved4: number;
    reserved5: number;
};
export type VREvent_PerformanceTest_t = { m_bFidelityLevel: number; };
export type VREvent_SeatedZeroPoseReset_t = { bResetBySystemMenu: number; };
export type VREvent_Screenshot_t = { handle: number; type: number; };
export type VREvent_ScreenshotProgress_t = { progress: number; };
export type VREvent_ApplicationLaunch_t = { pid: number; unArgsHandle: number; };
export type VREvent_EditingCameraSurface_t = { overlayHandle: number; nVisualMode: number; };
export type VREvent_MessageOverlay_t = { unVRMessageOverlayResponse: number; };
export type VREvent_Property_t = { container: PropertyContainerHandle_t; prop: ETrackedDeviceProperty; };
export type VREvent_HapticVibration_t = {
    containerHandle: number; // property container handle of the device with the haptic component
    componentHandle: number;
    fDurationSeconds: number;
    fFrequency: number;
    fAmplitude: number;
};
export type VREvent_WebConsole_t = { webConsoleHandle: WebConsoleHandle_t; };
export type VREvent_InputBindingLoad_t = {
    ulAppContainer: PropertyContainerHandle_t;
    pathMessage: number;
    pathUrl: number;
    pathControllerType: number;
};
export type VREvent_InputActionManifestLoad_t = { pathAppKey: number; pathMessage: number; pathMessageParam: number; pathManifestPath: number; };
export type VREvent_SpatialAnchor_t = { unHandle: SpatialAnchorHandle_t };
export type VREvent_ProgressUpdate_t = {
    ulApplicationPropertyContainer: number;
    pathDevice: number;
    pathInputSource: number;
    pathProgressAction: number;
    pathIcon: number;
    fProgress: number;
};
export enum EShowUIType {
    ShowUI_ControllerBinding = 0,
    ShowUI_ManageTrackers = 1,
    // ShowUI_QuickStart = 2, // Deprecated
    ShowUI_Pairing = 3,
    ShowUI_Settings = 4,
    ShowUI_DebugCommands = 5,
    ShowUI_FullControllerBinding = 6,
    ShowUI_ManageDrivers = 7,
};
export type VREvent_ShowUI_t = { eType: EShowUIType; };
export type VREvent_ShowDevTools_t = { nBrowserIdentifier: number; };
export enum EHDCPError {
    HDCPError_None = 0,
    HDCPError_LinkLost = 1,
    HDCPError_Tampered = 2,
    HDCPError_DeviceRevoked = 3,
    HDCPError_Unknown = 4
};
export type VREvent_HDCPError_t = { eCode: EHDCPError };
export type VREvent_Data_t = {
    reserved: VREvent_Reserved_t;
    controller: VREvent_Controller_t;
    mouse: VREvent_Mouse_t;
    scroll: VREvent_Scroll_t;
    process: VREvent_Process_t;
    notification: VREvent_Notification_t;
    overlay: VREvent_Overlay_t;
    status: VREvent_Status_t;
    keyboard: VREvent_Keyboard_t;
    ipd: VREvent_Ipd_t;
    chaperone: VREvent_Chaperone_t;
    performanceTest: VREvent_PerformanceTest_t;
    touchPadMove: VREvent_TouchPadMove_t;
    seatedZeroPoseReset: VREvent_SeatedZeroPoseReset_t;
    screenshot: VREvent_Screenshot_t;
    screenshotProgress: VREvent_ScreenshotProgress_t;
    applicationLaunch: VREvent_ApplicationLaunch_t;
    cameraSurface: VREvent_EditingCameraSurface_t;
    messageOverlay: VREvent_MessageOverlay_t;
    property: VREvent_Property_t;
    hapticVibration: VREvent_HapticVibration_t;
    webConsole: VREvent_WebConsole_t;
    inputBinding: VREvent_InputBindingLoad_t;
    actionManifest: VREvent_InputActionManifestLoad_t;
    spatialAnchor: VREvent_SpatialAnchor_t;
    progressUpdate: VREvent_ProgressUpdate_t;
    showUi: VREvent_ShowUI_t;
    showDevTools: VREvent_ShowDevTools_t;
    hdcpError: VREvent_HDCPError_t;
}
export type VREvent_t = {
    eventType: EVREventType;
    trackedDeviceIndex: TrackedDeviceIndex_t;
    eventAgeSeconds: number;
    data: VREvent_Data_t;
}
export type VRComponentProperties = number;
export enum EVRComponentProperty {
    VRComponentProperty_IsStatic = (1 << 0),
    VRComponentProperty_IsVisible = (1 << 1),
    VRComponentProperty_IsTouched = (1 << 2),
    VRComponentProperty_IsPressed = (1 << 3),
    VRComponentProperty_IsScrolled = (1 << 4),
    VRComponentProperty_IsHighlighted = (1 << 5),
};
export type RenderModel_ComponentState_t = {
    mTrackingToComponentRenderModel: HmdMatrix34_t;
    mTrackingToComponentLocal: HmdMatrix34_t;
    uProperties: VRComponentProperties;
};
export enum EVRInputError {
    VRInputError_None = 0,
    VRInputError_NameNotFound = 1,
    VRInputError_WrongType = 2,
    VRInputError_InvalidHandle = 3,
    VRInputError_InvalidParam = 4,
    VRInputError_NoSteam = 5,
    VRInputError_MaxCapacityReached = 6,
    VRInputError_IPCError = 7,
    VRInputError_NoActiveActionSet = 8,
    VRInputError_InvalidDevice = 9,
    VRInputError_InvalidSkeleton = 10,
    VRInputError_InvalidBoneCount = 11,
    VRInputError_InvalidCompressedData = 12,
    VRInputError_NoData = 13,
    VRInputError_BufferTooSmall = 14,
    VRInputError_MismatchedActionManifest = 15,
    VRInputError_MissingSkeletonData = 16,
    VRInputError_InvalidBoneIndex = 17,
    VRInputError_InvalidPriority = 18,
    VRInputError_PermissionDenied = 19,
    VRInputError_InvalidRenderModel = 20,
};
export enum EVRSpatialAnchorError {
    VRSpatialAnchorError_Success = 0,
    VRSpatialAnchorError_Internal = 1,
    VRSpatialAnchorError_UnknownHandle = 2,
    VRSpatialAnchorError_ArrayTooSmall = 3,
    VRSpatialAnchorError_InvalidDescriptorChar = 4,
    VRSpatialAnchorError_NotYetAvailable = 5,
    VRSpatialAnchorError_NotAvailableInThisUniverse = 6,
    VRSpatialAnchorError_PermanentlyUnavailable = 7,
    VRSpatialAnchorError_WrongDriver = 8,
    VRSpatialAnchorError_DescriptorTooLong = 9,
    VRSpatialAnchorError_Unknown = 10,
    VRSpatialAnchorError_NoRoomCalibration = 11,
    VRSpatialAnchorError_InvalidArgument = 12,
    VRSpatialAnchorError_UnknownDriver = 13,
};
export type HiddenAreaMesh_t = {
    pVertexData: HmdVector2_t[];
    unTriangleCount: number;
}
export enum EHiddenAreaMeshType {
    k_eHiddenAreaMesh_Standard = 0,
    k_eHiddenAreaMesh_Inverse = 1,
    k_eHiddenAreaMesh_LineLoop = 2,

    k_eHiddenAreaMesh_Max = 3,
};
export enum EVRControllerAxisType {
    k_eControllerAxis_None = 0,
    k_eControllerAxis_TrackPad = 1,
    k_eControllerAxis_Joystick = 2,
    k_eControllerAxis_Trigger = 3, // Analog trigger data is in the X axis
};
export type VRControllerAxis_t = { x: number; y: number; };
export const k_unControllerStateAxisCount: number = 5;
export type VRControllerState001_t = {
    unPacketNum: number;
    ulButtonPressed: number;
    ulButtonTouched: number;

    rAxis: VRControllerAxis_t[];
};
export type VRControllerState_t = VRControllerState001_t;
export enum EVRControllerEventOutputType {
    ControllerEventOutput_OSEvents = 0,
    ControllerEventOutput_VREvents = 1,
};
export enum ECollisionBoundsStyle {
    COLLISION_BOUNDS_STYLE_BEGINNER = 0,
    COLLISION_BOUNDS_STYLE_INTERMEDIATE,
    COLLISION_BOUNDS_STYLE_SQUARES,
    COLLISION_BOUNDS_STYLE_ADVANCED,
    COLLISION_BOUNDS_STYLE_NONE,

    COLLISION_BOUNDS_STYLE_COUNT
};
export type VROverlayHandle_t = {
    DownBits: number,
    UpBits: number
};
export const k_ulOverlayHandleInvalid: VROverlayHandle_t = { DownBits: 0, UpBits: 0 };
export enum EVROverlayError {
    VROverlayError_None = 0,

    VROverlayError_UnknownOverlay = 10,
    VROverlayError_InvalidHandle = 11,
    VROverlayError_PermissionDenied = 12,
    VROverlayError_OverlayLimitExceeded = 13, // No more overlays could be created because the maximum number already exist
    VROverlayError_WrongVisibilityType = 14,
    VROverlayError_KeyTooLong = 15,
    VROverlayError_NameTooLong = 16,
    VROverlayError_KeyInUse = 17,
    VROverlayError_WrongTransformType = 18,
    VROverlayError_InvalidTrackedDevice = 19,
    VROverlayError_InvalidParameter = 20,
    VROverlayError_ThumbnailCantBeDestroyed = 21,
    VROverlayError_ArrayTooSmall = 22,
    VROverlayError_RequestFailed = 23,
    VROverlayError_InvalidTexture = 24,
    VROverlayError_UnableToLoadFile = 25,
    VROverlayError_KeyboardAlreadyInUse = 26,
    VROverlayError_NoNeighbor = 27,
    VROverlayError_TooManyMaskPrimitives = 29,
    VROverlayError_BadMaskPrimitive = 30,
    VROverlayError_TextureAlreadyLocked = 31,
    VROverlayError_TextureLockCapacityReached = 32,
    VROverlayError_TextureNotLocked = 33,
};
export enum EVRApplicationType {
    VRApplication_Other = 0,		// Some other kind of application that isn't covered by the other entries
    VRApplication_Scene = 1,		// Application will submit 3D frames
    VRApplication_Overlay = 2,		// Application only interacts with overlays
    VRApplication_Background = 3,	// Application should not start SteamVR if it's not already running, and should not
    // keep it running if everything else quits.
    VRApplication_Utility = 4,		// Init should not try to load any drivers. The application needs access to utility
    // interfaces (like IVRSettings and IVRApplications) but not hardware.
    VRApplication_VRMonitor = 5,	// Reserved for vrmonitor
    VRApplication_SteamWatchdog = 6,// Reserved for Steam
    VRApplication_Bootstrapper = 7, // reserved for vrstartup
    VRApplication_WebHelper = 8,	// reserved for vrwebhelper
    VRApplication_OpenXRInstance = 9, // reserved for openxr (created instance, but not session yet)
    VRApplication_OpenXRScene = 10,	  // reserved for openxr (started session)
    VRApplication_OpenXROverlay = 11, // reserved for openxr (started overlay session)
    VRApplication_Prism = 12,		// reserved for the vrprismhost process

    VRApplication_Max
};
export const IsOpenXRAppType = function (eType: EVRApplicationType): boolean {
    return eType === EVRApplicationType.VRApplication_OpenXRInstance
        || eType === EVRApplicationType.VRApplication_OpenXRScene
        || eType === EVRApplicationType.VRApplication_OpenXROverlay;
}
export enum EVRFirmwareError {
    VRFirmwareError_None = 0,
    VRFirmwareError_Success = 1,
    VRFirmwareError_Fail = 2,
};
export enum EVRNotificationError {
    VRNotificationError_OK = 0,
    VRNotificationError_InvalidNotificationId = 100,
    VRNotificationError_NotificationQueueFull = 101,
    VRNotificationError_InvalidOverlayHandle = 102,
    VRNotificationError_SystemWithUserValueAlreadyExists = 103,
};
export enum EVRSkeletalMotionRange {
    VRSkeletalMotionRange_WithController = 0,
    VRSkeletalMotionRange_WithoutController = 1,
};
export enum EVRSkeletalTrackingLevel {
    // body part location can't be directly determined by the device. Any skeletal pose provided by
    // the device is estimated by assuming the position required to active buttons, triggers, joysticks,
    // or other input sensors.
    // E.g. Vive Controller, Gamepad
    VRSkeletalTracking_Estimated = 0,

    // body part location can be measured directly but with fewer degrees of freedom than the actual body
    // part. Certain body part positions may be unmeasured by the device and estimated from other input data.
    // E.g. Index Controllers, gloves that only measure finger curl
    VRSkeletalTracking_Partial = 1,

    // Body part location can be measured directly throughout the entire range of motion of the body part.
    // E.g. Mocap suit for the full body, gloves that measure rotation of each finger segment
    VRSkeletalTracking_Full = 2,

    VRSkeletalTrackingLevel_Count,
    VRSkeletalTrackingLevel_Max = VRSkeletalTrackingLevel_Count - 1
};
export type BoneIndex_t = number;
export const k_unInvalidBoneIndex: BoneIndex_t = -1;
export enum EVRInitError {
    VRInitError_None = 0,
    VRInitError_Unknown = 1,

    VRInitError_Init_InstallationNotFound = 100,
    VRInitError_Init_InstallationCorrupt = 101,
    VRInitError_Init_VRClientDLLNotFound = 102,
    VRInitError_Init_FileNotFound = 103,
    VRInitError_Init_FactoryNotFound = 104,
    VRInitError_Init_InterfaceNotFound = 105,
    VRInitError_Init_InvalidInterface = 106,
    VRInitError_Init_UserConfigDirectoryInvalid = 107,
    VRInitError_Init_HmdNotFound = 108,
    VRInitError_Init_NotInitialized = 109,
    VRInitError_Init_PathRegistryNotFound = 110,
    VRInitError_Init_NoConfigPath = 111,
    VRInitError_Init_NoLogPath = 112,
    VRInitError_Init_PathRegistryNotWritable = 113,
    VRInitError_Init_AppInfoInitFailed = 114,
    VRInitError_Init_Retry = 115, // Used internally to cause retries to vrserver
    VRInitError_Init_InitCanceledByUser = 116, // The calling application should silently exit. The user canceled app startup
    VRInitError_Init_AnotherAppLaunching = 117,
    VRInitError_Init_SettingsInitFailed = 118,
    VRInitError_Init_ShuttingDown = 119,
    VRInitError_Init_TooManyObjects = 120,
    VRInitError_Init_NoServerForBackgroundApp = 121,
    VRInitError_Init_NotSupportedWithCompositor = 122,
    VRInitError_Init_NotAvailableToUtilityApps = 123,
    VRInitError_Init_Internal = 124,
    VRInitError_Init_HmdDriverIdIsNone = 125,
    VRInitError_Init_HmdNotFoundPresenceFailed = 126,
    VRInitError_Init_VRMonitorNotFound = 127,
    VRInitError_Init_VRMonitorStartupFailed = 128,
    VRInitError_Init_LowPowerWatchdogNotSupported = 129,
    VRInitError_Init_InvalidApplicationType = 130,
    VRInitError_Init_NotAvailableToWatchdogApps = 131,
    VRInitError_Init_WatchdogDisabledInSettings = 132,
    VRInitError_Init_VRDashboardNotFound = 133,
    VRInitError_Init_VRDashboardStartupFailed = 134,
    VRInitError_Init_VRHomeNotFound = 135,
    VRInitError_Init_VRHomeStartupFailed = 136,
    VRInitError_Init_RebootingBusy = 137,
    VRInitError_Init_FirmwareUpdateBusy = 138,
    VRInitError_Init_FirmwareRecoveryBusy = 139,
    VRInitError_Init_USBServiceBusy = 140,
    VRInitError_Init_VRWebHelperStartupFailed = 141,
    VRInitError_Init_TrackerManagerInitFailed = 142,
    VRInitError_Init_AlreadyRunning = 143,
    VRInitError_Init_FailedForVrMonitor = 144,
    VRInitError_Init_PropertyManagerInitFailed = 145,
    VRInitError_Init_WebServerFailed = 146,
    VRInitError_Init_IllegalTypeTransition = 147,
    VRInitError_Init_MismatchedRuntimes = 148,
    VRInitError_Init_InvalidProcessId = 149,
    VRInitError_Init_VRServiceStartupFailed = 150,
    VRInitError_Init_PrismNeedsNewDrivers = 151,
    VRInitError_Init_PrismStartupTimedOut = 152,
    VRInitError_Init_CouldNotStartPrism = 153,
    VRInitError_Init_CreateDriverDirectDeviceFailed = 154,
    VRInitError_Init_PrismExitedUnexpectedly = 155,

    VRInitError_Driver_Failed = 200,
    VRInitError_Driver_Unknown = 201,
    VRInitError_Driver_HmdUnknown = 202,
    VRInitError_Driver_NotLoaded = 203,
    VRInitError_Driver_RuntimeOutOfDate = 204,
    VRInitError_Driver_HmdInUse = 205,
    VRInitError_Driver_NotCalibrated = 206,
    VRInitError_Driver_CalibrationInvalid = 207,
    VRInitError_Driver_HmdDisplayNotFound = 208,
    VRInitError_Driver_TrackedDeviceInterfaceUnknown = 209,
    // VRInitError_Driver_HmdDisplayNotFoundAfterFix = 210, // not needed: here for historic reasons
    VRInitError_Driver_HmdDriverIdOutOfBounds = 211,
    VRInitError_Driver_HmdDisplayMirrored = 212,
    VRInitError_Driver_HmdDisplayNotFoundLaptop = 213,
    // Never make error 259 because we return it from main and it would conflict with STILL_ACTIVE

    VRInitError_IPC_ServerInitFailed = 300,
    VRInitError_IPC_ConnectFailed = 301,
    VRInitError_IPC_SharedStateInitFailed = 302,
    VRInitError_IPC_CompositorInitFailed = 303,
    VRInitError_IPC_MutexInitFailed = 304,
    VRInitError_IPC_Failed = 305,
    VRInitError_IPC_CompositorConnectFailed = 306,
    VRInitError_IPC_CompositorInvalidConnectResponse = 307,
    VRInitError_IPC_ConnectFailedAfterMultipleAttempts = 308,
    VRInitError_IPC_ConnectFailedAfterTargetExited = 309,
    VRInitError_IPC_NamespaceUnavailable = 310,

    VRInitError_Compositor_Failed = 400,
    VRInitError_Compositor_D3D11HardwareRequired = 401,
    VRInitError_Compositor_FirmwareRequiresUpdate = 402,
    VRInitError_Compositor_OverlayInitFailed = 403,
    VRInitError_Compositor_ScreenshotsInitFailed = 404,
    VRInitError_Compositor_UnableToCreateDevice = 405,
    VRInitError_Compositor_SharedStateIsNull = 406,
    VRInitError_Compositor_NotificationManagerIsNull = 407,
    VRInitError_Compositor_ResourceManagerClientIsNull = 408,
    VRInitError_Compositor_MessageOverlaySharedStateInitFailure = 409,
    VRInitError_Compositor_PropertiesInterfaceIsNull = 410,
    VRInitError_Compositor_CreateFullscreenWindowFailed = 411,
    VRInitError_Compositor_SettingsInterfaceIsNull = 412,
    VRInitError_Compositor_FailedToShowWindow = 413,
    VRInitError_Compositor_DistortInterfaceIsNull = 414,
    VRInitError_Compositor_DisplayFrequencyFailure = 415,
    VRInitError_Compositor_RendererInitializationFailed = 416,
    VRInitError_Compositor_DXGIFactoryInterfaceIsNull = 417,
    VRInitError_Compositor_DXGIFactoryCreateFailed = 418,
    VRInitError_Compositor_DXGIFactoryQueryFailed = 419,
    VRInitError_Compositor_InvalidAdapterDesktop = 420,
    VRInitError_Compositor_InvalidHmdAttachment = 421,
    VRInitError_Compositor_InvalidOutputDesktop = 422,
    VRInitError_Compositor_InvalidDeviceProvided = 423,
    VRInitError_Compositor_D3D11RendererInitializationFailed = 424,
    VRInitError_Compositor_FailedToFindDisplayMode = 425,
    VRInitError_Compositor_FailedToCreateSwapChain = 426,
    VRInitError_Compositor_FailedToGetBackBuffer = 427,
    VRInitError_Compositor_FailedToCreateRenderTarget = 428,
    VRInitError_Compositor_FailedToCreateDXGI2SwapChain = 429,
    VRInitError_Compositor_FailedtoGetDXGI2BackBuffer = 430,
    VRInitError_Compositor_FailedToCreateDXGI2RenderTarget = 431,
    VRInitError_Compositor_FailedToGetDXGIDeviceInterface = 432,
    VRInitError_Compositor_SelectDisplayMode = 433,
    VRInitError_Compositor_FailedToCreateNvAPIRenderTargets = 434,
    VRInitError_Compositor_NvAPISetDisplayMode = 435,
    VRInitError_Compositor_FailedToCreateDirectModeDisplay = 436,
    VRInitError_Compositor_InvalidHmdPropertyContainer = 437,
    VRInitError_Compositor_UpdateDisplayFrequency = 438,
    VRInitError_Compositor_CreateRasterizerState = 439,
    VRInitError_Compositor_CreateWireframeRasterizerState = 440,
    VRInitError_Compositor_CreateSamplerState = 441,
    VRInitError_Compositor_CreateClampToBorderSamplerState = 442,
    VRInitError_Compositor_CreateAnisoSamplerState = 443,
    VRInitError_Compositor_CreateOverlaySamplerState = 444,
    VRInitError_Compositor_CreatePanoramaSamplerState = 445,
    VRInitError_Compositor_CreateFontSamplerState = 446,
    VRInitError_Compositor_CreateNoBlendState = 447,
    VRInitError_Compositor_CreateBlendState = 448,
    VRInitError_Compositor_CreateAlphaBlendState = 449,
    VRInitError_Compositor_CreateBlendStateMaskR = 450,
    VRInitError_Compositor_CreateBlendStateMaskG = 451,
    VRInitError_Compositor_CreateBlendStateMaskB = 452,
    VRInitError_Compositor_CreateDepthStencilState = 453,
    VRInitError_Compositor_CreateDepthStencilStateNoWrite = 454,
    VRInitError_Compositor_CreateDepthStencilStateNoDepth = 455,
    VRInitError_Compositor_CreateFlushTexture = 456,
    VRInitError_Compositor_CreateDistortionSurfaces = 457,
    VRInitError_Compositor_CreateConstantBuffer = 458,
    VRInitError_Compositor_CreateHmdPoseConstantBuffer = 459,
    VRInitError_Compositor_CreateHmdPoseStagingConstantBuffer = 460,
    VRInitError_Compositor_CreateSharedFrameInfoConstantBuffer = 461,
    VRInitError_Compositor_CreateOverlayConstantBuffer = 462,
    VRInitError_Compositor_CreateSceneTextureIndexConstantBuffer = 463,
    VRInitError_Compositor_CreateReadableSceneTextureIndexConstantBuffer = 464,
    VRInitError_Compositor_CreateLayerGraphicsTextureIndexConstantBuffer = 465,
    VRInitError_Compositor_CreateLayerComputeTextureIndexConstantBuffer = 466,
    VRInitError_Compositor_CreateLayerComputeSceneTextureIndexConstantBuffer = 467,
    VRInitError_Compositor_CreateComputeHmdPoseConstantBuffer = 468,
    VRInitError_Compositor_CreateGeomConstantBuffer = 469,
    VRInitError_Compositor_CreatePanelMaskConstantBuffer = 470,
    VRInitError_Compositor_CreatePixelSimUBO = 471,
    VRInitError_Compositor_CreateMSAARenderTextures = 472,
    VRInitError_Compositor_CreateResolveRenderTextures = 473,
    VRInitError_Compositor_CreateComputeResolveRenderTextures = 474,
    VRInitError_Compositor_CreateDriverDirectModeResolveTextures = 475,
    VRInitError_Compositor_OpenDriverDirectModeResolveTextures = 476,
    VRInitError_Compositor_CreateFallbackSyncTexture = 477,
    VRInitError_Compositor_ShareFallbackSyncTexture = 478,
    VRInitError_Compositor_CreateOverlayIndexBuffer = 479,
    VRInitError_Compositor_CreateOverlayVertexBuffer = 480,
    VRInitError_Compositor_CreateTextVertexBuffer = 481,
    VRInitError_Compositor_CreateTextIndexBuffer = 482,
    VRInitError_Compositor_CreateMirrorTextures = 483,
    VRInitError_Compositor_CreateLastFrameRenderTexture = 484,
    VRInitError_Compositor_CreateMirrorOverlay = 485,
    VRInitError_Compositor_FailedToCreateVirtualDisplayBackbuffer = 486,
    VRInitError_Compositor_DisplayModeNotSupported = 487,
    VRInitError_Compositor_CreateOverlayInvalidCall = 488,
    VRInitError_Compositor_CreateOverlayAlreadyInitialized = 489,
    VRInitError_Compositor_FailedToCreateMailbox = 490,
    VRInitError_Compositor_WindowInterfaceIsNull = 491,
    VRInitError_Compositor_SystemLayerCreateInstance = 492,
    VRInitError_Compositor_SystemLayerCreateSession = 493,

    VRInitError_VendorSpecific_UnableToConnectToOculusRuntime = 1000,
    VRInitError_VendorSpecific_WindowsNotInDevMode = 1001,

    VRInitError_VendorSpecific_HmdFound_CantOpenDevice = 1101,
    VRInitError_VendorSpecific_HmdFound_UnableToRequestConfigStart = 1102,
    VRInitError_VendorSpecific_HmdFound_NoStoredConfig = 1103,
    VRInitError_VendorSpecific_HmdFound_ConfigTooBig = 1104,
    VRInitError_VendorSpecific_HmdFound_ConfigTooSmall = 1105,
    VRInitError_VendorSpecific_HmdFound_UnableToInitZLib = 1106,
    VRInitError_VendorSpecific_HmdFound_CantReadFirmwareVersion = 1107,
    VRInitError_VendorSpecific_HmdFound_UnableToSendUserDataStart = 1108,
    VRInitError_VendorSpecific_HmdFound_UnableToGetUserDataStart = 1109,
    VRInitError_VendorSpecific_HmdFound_UnableToGetUserDataNext = 1110,
    VRInitError_VendorSpecific_HmdFound_UserDataAddressRange = 1111,
    VRInitError_VendorSpecific_HmdFound_UserDataError = 1112,
    VRInitError_VendorSpecific_HmdFound_ConfigFailedSanityCheck = 1113,
    VRInitError_VendorSpecific_OculusRuntimeBadInstall = 1114,

    VRInitError_Steam_SteamInstallationNotFound = 2000,

    // Strictly a placeholder
    VRInitError_LastError
};
export enum EVRScreenshotType {
    VRScreenshotType_None = 0,
    VRScreenshotType_Mono = 1, // left eye only
    VRScreenshotType_Stereo = 2,
    VRScreenshotType_Cubemap = 3,
    VRScreenshotType_MonoPanorama = 4,
    VRScreenshotType_StereoPanorama = 5
};
export enum EVRScreenshotPropertyFilenames {
    VRScreenshotPropertyFilenames_Preview = 0,
    VRScreenshotPropertyFilenames_VR = 1,
};
export enum EVRTrackedCameraError {
    VRTrackedCameraError_None = 0,
    VRTrackedCameraError_OperationFailed = 100,
    VRTrackedCameraError_InvalidHandle = 101,
    VRTrackedCameraError_InvalidFrameHeaderVersion = 102,
    VRTrackedCameraError_OutOfHandles = 103,
    VRTrackedCameraError_IPCFailure = 104,
    VRTrackedCameraError_NotSupportedForThisDevice = 105,
    VRTrackedCameraError_SharedMemoryFailure = 106,
    VRTrackedCameraError_FrameBufferingFailure = 107,
    VRTrackedCameraError_StreamSetupFailure = 108,
    VRTrackedCameraError_InvalidGLTextureId = 109,
    VRTrackedCameraError_InvalidSharedTextureHandle = 110,
    VRTrackedCameraError_FailedToGetGLTextureId = 111,
    VRTrackedCameraError_SharedTextureFailure = 112,
    VRTrackedCameraError_NoFrameAvailable = 113,
    VRTrackedCameraError_InvalidArgument = 114,
    VRTrackedCameraError_InvalidFrameBufferSize = 115,
};
export enum EVRTrackedCameraFrameLayout {
    EVRTrackedCameraFrameLayout_Mono = 0x0001,
    EVRTrackedCameraFrameLayout_Stereo = 0x0002,
    EVRTrackedCameraFrameLayout_VerticalLayout = 0x0010,	// Stereo frames are Top/Bottom (left/right)
    EVRTrackedCameraFrameLayout_HorizontalLayout = 0x0020,	// Stereo frames are Left/Right
};
export enum EVRTrackedCameraFrameType {
    VRTrackedCameraFrameType_Distorted = 0,			// This is the camera video frame size in pixels, still distorted.
    VRTrackedCameraFrameType_Undistorted,			// In pixels, an undistorted inscribed rectangle region without invalid regions. This size is subject to changes shortly.
    VRTrackedCameraFrameType_MaximumUndistorted,	// In pixels, maximum undistorted with invalid regions. Non zero alpha component identifies valid regions.
    MAX_CAMERA_FRAME_TYPES
};
export enum EVRDistortionFunctionType {
    VRDistortionFunctionType_None,
    VRDistortionFunctionType_FTheta,
    VRDistortionFunctionType_Extended_FTheta,
    MAX_DISTORTION_FUNCTION_TYPES,
};
export const k_unMaxDistortionFunctionParameters: number = 8;
export type TrackedCameraHandle_t = number;
export type CameraVideoStreamFrameHeader_t = {
    eFrameType: EVRTrackedCameraFrameType;
    nWidth: number;
    nHeight: number;
    nBytesPerPixel: number;

    nFrameSequence: number;
    trackedDevicePose: TrackedDevicePose_t;
    ulFrameExposureTime: number;
};
export type ScreenshotHandle_t = number;
export const k_unScreenshotHandleInvalid: number = 0;
export const VRCompositor_ReprojectionReason_Cpu: number = 0x01;
export const VRCompositor_ReprojectionReason_Gpu: number = 0x02;
export const VRCompositor_ReprojectionAsync: number = 0x04;
export const VRCompositor_ReprojectionMotion: number = 0x08;
export const VRCompositor_PredictionMask: number = 0xF0;
export const VRCompositor_ThrottleMask: number = 0xF00;

export type Compositor_FrameTiming = {
    m_nSize: number;
    m_nFrameIndex: number;
    m_nNumFramePresents: number;
    m_nNumMisPresented: number;
    m_nNumDroppedFrames: number;
    m_nReprojectionFlags: number;

    m_flSystemTimeInSeconds: number;

    m_flPreSubmitGpuMs: number;
    m_flPostSubmitGpuMs: number;
    m_flTotalRenderGpuMs: number;
    m_flCompositorRenderGpuMs: number;
    m_flCompositorRenderCpuMs: number;
    m_flCompositorIdleCpuMs: number;

    m_flClientFrameIntervalMs: number;
    m_flPresentCallCpuMs: number;
    m_flWaitForPresentCpuMs: number;
    m_flSubmitFrameMs: number;

    m_flWaitGetPosesCalledMs: number;
    m_flNewPosesReadyMs: number;
    m_flNewFrameReadyMs: number;
    m_flCompositorUpdateStartMs: number;
    m_flCompositorUpdateEndMs: number;
    m_flCompositorRenderStartMs: number;

    m_HmdPose: TrackedDevicePose_t;
    m_nNumVSyncsReadyForUse: number;
    m_nNumVSyncsToFirstView: number;
}
export type Compositor_BenchmarkResults = {
    m_flMegaPixelsPerSecond: number;
    m_flHmdRecommendedMegaPixelsPerSecond: number;
}
export type DriverDirectMode_FrameTiming = {
    m_nSize: number;
    m_nNumFramePresents: number;
    m_nNumMisPresented: number;
    m_nNumDroppedFrames: number;
    m_nReprojectionFlags: number;
}
export const VRCompositor_ReprojectionMotion_Enabled: number = 0x100;
export const VRCompositor_ReprojectionMotion_ForcedOn: number = 0x200;
export const VRCompositor_ReprojectionMotion_AppThrottled: number = 0x400;

export enum EVSync {
    VSync_None,
    VSync_WaitRender,
    VSync_NoWaitRender,
};
export enum EVRMuraCorrectionMode {
    EVRMuraCorrectionMode_Default = 0,
    EVRMuraCorrectionMode_NoCorrection
};
export enum Imu_OffScaleFlags {
    OffScale_AccelX = 0x01,
    OffScale_AccelY = 0x02,
    OffScale_AccelZ = 0x04,
    OffScale_GyroX = 0x08,
    OffScale_GyroY = 0x10,
    OffScale_GyroZ = 0x20,
};
export type ImuSample_t = {
    fSampleTime: number;
    vAccel: HmdVector3_t;
    vGyro: HmdVector3_t;
    unOffScaleFlags: number;
};

export const VR_Init = function (eApplicationType: EVRApplicationType): IVRSystem { return openvr.VR_Init(eApplicationType); }
export const VR_Shutdown = function (): void { openvr.VR_Shutdown(); }
export const VR_IsHmdPresent = function (): boolean { return openvr.VR_IsHmdPresent(); }
export const VR_IsRuntimeInstalled = function (): boolean { return openvr.VR_IsRuntimeInstalled(); }
export const VR_GetRuntimePath = function (): string { return openvr.VR_GetRuntimePath(); }
export const VR_GetVRInitErrorAsSymbol = function (error: EVRInitError): string { return openvr.VR_GetVRInitErrorAsSymbol(); }
export const VR_GetVRInitErrorAsEnglishDescription = function (error: EVRInitError): string { return openvr.VR_GetVRInitErrorAsEnglishDescription(); }
// export const VR_GetGenericInterface = function( sInterfaceVersion: string ): any { return openvr.VR_GetGenericInterface(); }
// export const VR_IsInterfaceVersionValid = function( sInterfaceVersion: string ): boolean { return openvr.VR_IsInterfaceVersionValid(); }
export const VR_GetInitToken = function (): number { return openvr.VR_GetInitToken(); }

export const IVROverlay_Init = function (): IVROverlay { return openvr.IVROverlay_Init(); }


export class IVRSystem {

    // ------------------------------------
    // Display Methods
    // ------------------------------------

    GetRecommendedRenderTargetSize(): { width: number, height: number } { return openvr.IVRSystem.GetRecommendedRenderTargetSize(); }
    GetProjectionMatrix(eEye: EVREye, fNearZ: number, fFarZ: number): HmdMatrix44_t { return openvr.IVRSystem.GetProjectionMatrix(eEye, fNearZ, fFarZ); }
    GetProjectionRaw(eEye: EVREye): { left: number, right: number, top: number, bottom: number } { return openvr.IVRSystem.GetProjectionRaw(eEye); }
    ComputeDistortion(eEye: EVREye, fU: number, fV: number): DistortionCoordinates_t { return openvr.IVRSystem.ComputeDistortion(eEye, fU, fV); }
    GetEyeToHeadTransform(eEye: EVREye): HmdMatrix34_t { return openvr.IVRSystem.GetEyeToHeadTransform(eEye); }
    GetTimeSinceLastVsync(): { seconds: number, frame: number } { return openvr.IVRSystem.GetTimeSinceLastVsync(); }
    GetD3D9AdapterIndex(): number { return openvr.IVRSystem.GetD3D9AdapterIndex(); }
    GetDXGIOutputInfo(): number { return openvr.IVRSystem.GetDXGIOutputInfo(); }
    GetOutputDevice(textureType: ETextureType): number { return openvr.IVRSystem.GetOutputDevice(textureType); }

    // ------------------------------------
    // Display Mode methods
    // ------------------------------------

    IsDisplayOnDesktop(): boolean { return openvr.IVRSystem.IsDisplayOnDesktop(); }
    SetDisplayVisibility(bIsVisibleOnDesktop: boolean): boolean { return openvr.IVRSystem.SetDisplayVisibility(bIsVisibleOnDesktop); }

    // ------------------------------------
    // Tracking Methods
    // ------------------------------------

    GetDeviceToAbsoluteTrackingPose(eOrigin: ETrackingUniverseOrigin, fPredictedSecondsToPhotonsFromNow: number): TrackedDevicePose_t[] { return openvr.IVRSystem.GetDeviceToAbsoluteTrackingPose(eOrigin, fPredictedSecondsToPhotonsFromNow); }
    GetSeatedZeroPoseToStandingAbsoluteTrackingPose(): HmdMatrix34_t { return openvr.IVRSystem.GetSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
    GetRawZeroPoseToStandingAbsoluteTrackingPose(): HmdMatrix34_t { return openvr.IVRSystem.GetRawZeroPoseToStandingAbsoluteTrackingPose(); }
    GetSortedTrackedDeviceIndicesOfClass(eTrackedDeviceClass: ETrackedDeviceClass, unRelativeToTrackedDeviceIndex?: ETrackedDeviceClass): TrackedDeviceIndex_t[] {
        if (unRelativeToTrackedDeviceIndex === undefined) return openvr.IVRSystem.GetSortedTrackedDeviceIndicesOfClass(eTrackedDeviceClass, 0);
        else return openvr.IVRSystem.GetSortedTrackedDeviceIndicesOfClass(eTrackedDeviceClass, unRelativeToTrackedDeviceIndex);
    }
    GetTrackedDeviceActivityLevel(unDeviceId: TrackedDeviceIndex_t): EDeviceActivityLevel { return openvr.IVRSystem.GetTrackedDeviceActivityLevel(unDeviceId); }
    ApplyTransform(trackedDevicePose: TrackedDevicePose_t, transform: HmdMatrix34_t): TrackedDevicePose_t { return openvr.IVRSystem.ApplyTransform(trackedDevicePose, transform); }
    GetTrackedDeviceIndexForControllerRole(nDeviceType: ETrackedControllerRole): TrackedDeviceIndex_t { return openvr.IVRSystem.GetTrackedDeviceIndexForControllerRole(nDeviceType); }

    // ------------------------------------
    // Property methods
    // ------------------------------------

    GetTrackedDeviceClass(unDeviceIndex: TrackedDeviceIndex_t): ETrackedDeviceClass { return openvr.IVRSystem.GetTrackedDeviceClass(unDeviceIndex); }
    IsTrackedDeviceConnected(unDeviceIndex: TrackedDeviceIndex_t): boolean { return openvr.IVRSystem.IsTrackedDeviceConnected(unDeviceIndex); }
    GetBoolTrackedDeviceProperty(nDeviceIndex: TrackedDeviceIndex_t, nDeviceProp: ETrackedDeviceProperty): boolean { return openvr.IVRSystem.GetBoolTrackedDeviceProperty(nDeviceIndex, nDeviceProp); }
    GetFloatTrackedDeviceProperty(nDeviceIndex: TrackedDeviceIndex_t, nDeviceProp: ETrackedDeviceProperty): number { return openvr.IVRSystem.GetFloatTrackedDeviceProperty(nDeviceIndex, nDeviceProp); }
    GetInt32TrackedDeviceProperty(nDeviceIndex: TrackedDeviceIndex_t, nDeviceProp: ETrackedDeviceProperty): number { return openvr.IVRSystem.GetInt32TrackedDeviceProperty(nDeviceIndex, nDeviceProp); }
    GetUint64TrackedDeviceProperty(nDeviceIndex: TrackedDeviceIndex_t, nDeviceProp: ETrackedDeviceProperty): number { return openvr.IVRSystem.GetUint64TrackedDeviceProperty(nDeviceIndex, nDeviceProp); }
    GetMatrix34TrackedDeviceProperty(nDeviceIndex: TrackedDeviceIndex_t, nDeviceProp: ETrackedDeviceProperty): HmdMatrix34_t { return openvr.IVRSystem.GetMatrix34TrackedDeviceProperty(nDeviceIndex, nDeviceProp); }

    // ------------------------------------
    // Controller methods
    // ------------------------------------

    IsInputAvailable(): boolean { return openvr.IVRSystem.IsInputAvailable(); }
    IsSteamVRDrawingControllers(): boolean { return openvr.IVRSystem.IsSteamVRDrawingControllers(); }
    ShouldApplicationPause(): boolean { return openvr.IVRSystem.ShouldApplicationPause(); }
    ShouldApplicationReduceRenderingWork(): boolean { return openvr.IVRSystem.ShouldApplicationReduceRenderingWork(); }

    // ------------------------------------
    // Firmware methods
    // ------------------------------------

    PerformFirmwareUpdate(uiTrackedDeviceIndex: TrackedDeviceIndex_t): EVRFirmwareError { return openvr.IVRSystem.PerformFirmwareUpdate(uiTrackedDeviceIndex); }
    AcknowledgeQuit_Exiting(): void { openvr.IVRSystem.AcknowledgeQuit_Exiting(); }
}

export const k_unVROverlayMaxKeyLength: number = 128;
export const k_unVROverlayMaxNameLength: number = 128;
export const k_unMaxOverlayCount: number = 128;
export const k_unMaxOverlayIntersectionMaskPrimitivesCount: number = 32;

export enum VROverlayInputMethod {
    VROverlayInputMethod_None = 0, // No input events will be generated automatically for this overlay
    VROverlayInputMethod_Mouse = 1, // Tracked controllers will get mouse events automatically
    // VROverlayInputMethod_DualAnalog = 2, // No longer supported
};

export enum VROverlayTransformType {
    VROverlayTransform_Invalid = -1,
    VROverlayTransform_Absolute = 0,
    VROverlayTransform_TrackedDeviceRelative = 1,
    VROverlayTransform_SystemOverlay = 2,
    VROverlayTransform_TrackedComponent = 3,
    VROverlayTransform_Cursor = 4,
    VROverlayTransform_DashboardTab = 5,
    VROverlayTransform_DashboardThumb = 6,
    VROverlayTransform_Mountable = 7,
    VROverlayTransform_Projection = 8,
};

export enum VROverlayFlags {
    // Set this flag on a dashboard overlay to prevent a tab from showing up for that overlay
    VROverlayFlags_NoDashboardTab = 1 << 3,

    // When this is set the overlay will receive VREvent_ScrollDiscrete events like a mouse wheel.
    // Requires mouse input mode.
    VROverlayFlags_SendVRDiscreteScrollEvents = 1 << 6,

    // Indicates that the overlay would like to receive
    VROverlayFlags_SendVRTouchpadEvents = 1 << 7,

    // If set this will render a vertical scroll wheel on the primary controller,
    //  only needed if not using VROverlayFlags_SendVRScrollEvents but you still want to represent a scroll wheel
    VROverlayFlags_ShowTouchPadScrollWheel = 1 << 8,

    // If this is set ownership and render access to the overlay are transferred
    // to the new scene process on a call to IVRApplications::LaunchInternalProcess
    VROverlayFlags_TransferOwnershipToInternalProcess = 1 << 9,

    // If set, renders 50% of the texture in each eye, side by side
    VROverlayFlags_SideBySide_Parallel = 1 << 10, // Texture is left/right
    VROverlayFlags_SideBySide_Crossed = 1 << 11, // Texture is crossed and right/left

    VROverlayFlags_Panorama = 1 << 12, // Texture is a panorama
    VROverlayFlags_StereoPanorama = 1 << 13, // Texture is a stereo panorama

    // If this is set on an overlay owned by the scene application that overlay
    // will be sorted with the "Other" overlays on top of all other scene overlays
    VROverlayFlags_SortWithNonSceneOverlays = 1 << 14,

    // If set, the overlay will be shown in the dashboard, otherwise it will be hidden.
    VROverlayFlags_VisibleInDashboard = 1 << 15,

    // If this is set and the overlay's input method is not none, the system-wide laser mouse
    // mode will be activated whenever this overlay is visible.
    VROverlayFlags_MakeOverlaysInteractiveIfVisible = 1 << 16,

    // If this is set the overlay will receive smooth VREvent_ScrollSmooth that emulate trackpad scrolling.
    // Requires mouse input mode.
    VROverlayFlags_SendVRSmoothScrollEvents = 1 << 17,

    // If this is set, the overlay texture will be protected content, preventing unauthorized reads.
    VROverlayFlags_ProtectedContent = 1 << 18,

    // If this is set, the laser mouse splat will not be drawn over this overlay. The overlay will
    // be responsible for drawing its own "cursor".
    VROverlayFlags_HideLaserIntersection = 1 << 19,

    // If this is set, clicking away from the overlay will cause it to receive a VREvent_Modal_Cancel event.
    // This is ignored for dashboard overlays.
    VROverlayFlags_WantsModalBehavior = 1 << 20,

    // If this is set, alpha composition assumes the texture is pre-multiplied
    VROverlayFlags_IsPremultiplied = 1 << 21,
};

export enum VRMessageOverlayResponse {
    VRMessageOverlayResponse_ButtonPress_0 = 0,
    VRMessageOverlayResponse_ButtonPress_1 = 1,
    VRMessageOverlayResponse_ButtonPress_2 = 2,
    VRMessageOverlayResponse_ButtonPress_3 = 3,
    VRMessageOverlayResponse_CouldntFindSystemOverlay = 4,
    VRMessageOverlayResponse_CouldntFindOrCreateClientOverlay = 5,
    VRMessageOverlayResponse_ApplicationQuit = 6
};

export type VROverlayIntersectionParams_t = {
    vSource: HmdVector3_t,
    vDirection: HmdVector3_t,
    eOrigin: ETrackingUniverseOrigin
}

export type VROverlayIntersectionResults_t = {
    vPoint: HmdVector3_t,
    vNormal: HmdVector3_t,
    vUVs: HmdVector2_t,
    fDistance: number
}

export enum EGamepadTextInputMode {
    k_EGamepadTextInputModeNormal = 0,
    k_EGamepadTextInputModePassword = 1,
    k_EGamepadTextInputModeSubmit = 2,
};

export enum EGamepadTextInputLineMode {
    k_EGamepadTextInputLineModeSingleLine = 0,
    k_EGamepadTextInputLineModeMultipleLines = 1
};

export enum EVROverlayIntersectionMaskPrimitiveType {
    OverlayIntersectionPrimitiveType_Rectangle,
    OverlayIntersectionPrimitiveType_Circle,
};

export type IntersectionMaskRectangle_t = {
    m_flTopLeftX: number,
    m_flTopLeftY: number,
    m_flWidth: number,
    m_flHeight: number
}

export type IntersectionMaskCircle_t = {
    m_flCenterX: number,
    m_flCenterY: number,
    m_flRadius: number
}

export type VROverlayIntersectionMaskPrimitive_Data_t = {
    m_Rectangle: IntersectionMaskRectangle_t,
    m_Circle: IntersectionMaskCircle_t
}

export type VROverlayIntersectionMaskPrimitive_t = {
    m_nPrimitiveType: EVROverlayIntersectionMaskPrimitiveType,
    m_Primitive: VROverlayIntersectionMaskPrimitive_Data_t
}

export enum EKeyboardFlags {
    KeyboardFlag_Minimal = 1 << 0, // makes the keyboard send key events immediately instead of accumulating a buffer
    KeyboardFlag_Modal = 2 << 0, // makes the keyboard take all focus and dismiss when clicking off the panel
};

export type VROverlayProjection_t = {
    fLeft: number,
    fRight: number,
    fTop: number,
    fBottom: number
}

export class IVROverlay {

    // ---------------------------------------------
    // Overlay management methods
    // ---------------------------------------------

    FindOverlay(OverlayKey: string): VROverlayHandle_t { return openvr.IVROverlay.FindOverlay(OverlayKey); }
    CreateOverlay(OverlayKey: string, OverlayName: string): VROverlayHandle_t { return openvr.IVROverlay.CreateOverlay(OverlayKey, OverlayName); }
    DestroyOverlay(OverlayHandle: VROverlayHandle_t): EVROverlayError { return openvr.IVROverlay.DestroyOverlay(OverlayHandle); }
    GetOverlayKey(OverlayHandle: VROverlayHandle_t): string { return openvr.IVROverlay.GetOverlayKey(OverlayHandle); }
    GetOverlayName(OverlayHandle: VROverlayHandle_t): string { return openvr.IVROverlay.GetOverlayName(OverlayHandle); }
    SetOverlayName(OverlayHandle: VROverlayHandle_t, Name: string) { openvr.IVROverlay.SetOverlayName(OverlayHandle, Name); }
    GetOverlayErrorNameFromEnum(error: EVROverlayError): string { return openvr.IVROverlay.GetOverlayErrorNameFromEnum(error); }

    // ---------------------------------------------
    // Overlay rendering methods
    // ---------------------------------------------

    SetOverlayRenderingPid(OverlayHandle: VROverlayHandle_t, PID: number) { openvr.IVROverlay.SetOverlayRenderingPid(OverlayHandle, PID); }
    GetOverlayRenderingPid(OverlayHandle: VROverlayHandle_t): number { return openvr.IVROverlay.GetOverlayRenderingPid(OverlayHandle); }
    SetOverlayFlag(OverlayHandle: VROverlayHandle_t, OverlayFlag: VROverlayFlags, Enabled: boolean) { return openvr.IVROverlay.SetOverlayFlag(OverlayHandle, OverlayFlag, Enabled); }
    GetOverlayFlag(OverlayHandle: VROverlayHandle_t, OverlayFlag: VROverlayFlags) { return openvr.IVROverlay.GetOverlayFlag(OverlayHandle, OverlayFlag); }
    GetOverlayFlags(OverlayHandle: VROverlayHandle_t) { return openvr.IVROverlay.GetOverlayFlags(OverlayHandle); }
    SetOverlayColor(OverlayHandle: VROverlayHandle_t, Red: number, Green: number, Blue: number) { openvr.IVROverlay.SetOverlayColor(OverlayHandle, Red, Green, Blue); }
    GetOverlayColor(OverlayHandle: VROverlayHandle_t): { Red: number, Green: number, Blue: number } { return openvr.IVROverlay.GetOverlayColor(OverlayHandle); }
    SetOverlayAlpha(OverlayHandle: VROverlayHandle_t, Alpha: number) { openvr.IVROverlay.SetOverlayAlpha(OverlayHandle, Alpha); }
    GetOverlayAlpha(OverlayHandle: VROverlayHandle_t): number { return openvr.IVROverlay.GetOverlayAlpha(OverlayHandle); }
    SetOverlayTexelAspect(OverlayHandle: VROverlayHandle_t, TexelAspect: number) { openvr.IVROverlay.SetOverlayTexelAspect(OverlayHandle, TexelAspect); }
    GetOverlayTexelAspect(OverlayHandle: VROverlayHandle_t): number { return openvr.IVROverlay.GetOverlayTexelAspect(OverlayHandle); }
    SetOverlaySortOrder(OverlayHandle: VROverlayHandle_t, SortOrder: number) { openvr.IVROverlay.SetOverlaySortOrder(OverlayHandle, SortOrder); }
    GetOverlaySortOrder(OverlayHandle: VROverlayHandle_t): number { return openvr.IVROverlay.GetOverlaySortOrder(OverlayHandle); }
    SetOverlayWidthInMeters(OverlayHandle: VROverlayHandle_t, WidthInMeters: number) { openvr.IVROverlay.SetOverlayWidthInMeters(OverlayHandle, WidthInMeters); }
    GetOverlayWidthInMeters(OverlayHandle: VROverlayHandle_t): number { return openvr.IVROverlay.GetOverlayWidthInMeters(OverlayHandle); }
    SetOverlayCurvature(OverlayHandle: VROverlayHandle_t, Curvature: number) { openvr.IVROverlay.SetOverlayCurvature(OverlayHandle, Curvature); }
    GetOverlayCurvature(OverlayHandle: VROverlayHandle_t): number { return openvr.IVROverlay.GetOverlayCurvature(OverlayHandle); }
    SetOverlayTextureColorSpace(OverlayHandle: VROverlayHandle_t, TextureColorSpace: EColorSpace) { openvr.IVROverlay.SetOverlayTextureColorSpace(OverlayHandle, TextureColorSpace); }
    GetOverlayTextureColorSpace(OverlayHandle: VROverlayHandle_t): EColorSpace { return openvr.IVROverlay.GetOverlayTextureColorSpace(OverlayHandle); }
    SetOverlayTextureBounds(OverlayHandle: VROverlayHandle_t, OverlayTextureBounds: VRTextureBounds_t) { openvr.IVROverlay.SetOverlayTextureBounds(OverlayHandle, OverlayTextureBounds); }
    GetOverlayTextureBounds(OverlayHandle: VROverlayHandle_t): VRTextureBounds_t { return openvr.IVROverlay.GetOverlayTextureBounds(OverlayHandle); }
    GetOverlayTransformType(OverlayHandle: VROverlayHandle_t): VROverlayTransformType { return openvr.IVROverlay.GetOverlayTransformType(OverlayHandle); }
    SetOverlayTransformAbsolute(OverlayHandle: VROverlayHandle_t, TrackingOrigin: ETrackingUniverseOrigin, TrackingOriginToOverlayTransform: HmdMatrix34_t) { openvr.IVROverlay.SetOverlayTransformAbsolute(OverlayHandle, TrackingOrigin, TrackingOriginToOverlayTransform); }
    GetOverlayTransformAbsolute(OverlayHandle: VROverlayHandle_t): { TrackingOrigin: ETrackingUniverseOrigin, TrackingOriginToOverlayTransform: HmdMatrix34_t } { return openvr.IVROverlay.GetOverlayTransformAbsolute(OverlayHandle); }
    SetOverlayTransformTrackedDeviceRelative(OverlayHandle: VROverlayHandle_t, TrackedDevice: TrackedDeviceIndex_t, TrackedDeviceToOverlayTransform: HmdMatrix34_t) { openvr.IVROverlay.SetOverlayTransformTrackedDeviceRelative(OverlayHandle, TrackedDevice, TrackedDeviceToOverlayTransform); }
    GetOverlayTransformTrackedDeviceRelative(OverlayHandle: VROverlayHandle_t): { TrackedDevice: TrackedDeviceIndex_t, TrackedDeviceToOverlayTransform: HmdMatrix34_t } { return openvr.IVROverlay.GetOverlayTransformTrackedDeviceRelative(OverlayHandle); }
    SetOverlayTransformTrackedDeviceComponent(OverlayHandle: VROverlayHandle_t, DeviceIndex: TrackedDeviceIndex_t, ComponentName: string) { openvr.IVROverlay.SetOverlayTransformTrackedDeviceComponent(OverlayHandle, DeviceIndex, ComponentName); }
    GetOverlayTransformTrackedDeviceComponent(OverlayHandle: VROverlayHandle_t): { DeviceIndex: TrackedDeviceIndex_t, ComponentName: string } { return openvr.IVROverlay.GetOverlayTransformTrackedDeviceComponent(OverlayHandle); }
    GetOverlayTransformOverlayRelative(OverlayHandle: VROverlayHandle_t): { OverlayHandleParent: VROverlayHandle_t, ParentOverlayToOverlayTransform: HmdMatrix34_t } { return openvr.IVROverlay.GetOverlayTransformOverlayRelative(OverlayHandle); }
    SetOverlayTransformOverlayRelative(OverlayHandle: VROverlayHandle_t, OverlayHandleParent: VROverlayHandle_t, ParentOverlayToOverlayTransform: HmdMatrix34_t) { openvr.IVROverlay.SetOverlayTransformOverlayRelative(OverlayHandle, OverlayHandleParent, ParentOverlayToOverlayTransform); }
    SetOverlayTransformCursor(OverlayHandle: VROverlayHandle_t, HotSpot: HmdVector2_t) { openvr.IVROverlay.SetOverlayTransformCursor(OverlayHandle, HotSpot); }
    GetOverlayTransformCursor(OverlayHandle: VROverlayHandle_t): HmdVector2_t { return openvr.IVROverlay.GetOverlayTransformCursor(OverlayHandle); }
    SetOverlayTransformProjection(OverlayHandle: VROverlayHandle_t, TrackingOrigin: ETrackingUniverseOrigin, TrackingOriginToOverlayTransform: HmdMatrix34_t, Projection: VROverlayProjection_t, eEye: EVREye) { openvr.IVROverlay.SetOverlayTransformProjection(OverlayHandle, TrackingOrigin, TrackingOriginToOverlayTransform, Projection, eEye); }
    ShowOverlay(OverlayHandle: VROverlayHandle_t) { openvr.IVROverlay.ShowOverlay(OverlayHandle); }
    HideOverlay(OverlayHandle: VROverlayHandle_t) { openvr.IVROverlay.HideOverlay(OverlayHandle); }
    IsOverlayVisible(OverlayHandle: VROverlayHandle_t): boolean { return openvr.IVROverlay.IsOverlayVisible(OverlayHandle); }
    GetTransformForOverlayCoordinates(OverlayHandle: VROverlayHandle_t, TrackingOrigin: ETrackingUniverseOrigin, CoordinatesInOverlay: HmdVector2_t): HmdMatrix34_t { return openvr.IVROverlay.GetTransformForOverlayCoordinates(OverlayHandle, TrackingOrigin, CoordinatesInOverlay); }

    // ---------------------------------------------
    // Overlay input methods
    // ---------------------------------------------

    PollNextOverlayEvent(OverlayHandle: VROverlayHandle_t): VREvent_t { return openvr.IVROverlay.PollNextOverlayEvent(OverlayHandle); }
    GetOverlayInputMethod(OverlayHandle: VROverlayHandle_t): VROverlayInputMethod { return openvr.IVROverlay.GetOverlayInputMethod(OverlayHandle); }
    SetOverlayInputMethod(OverlayHandle: VROverlayHandle_t, InputMethod: VROverlayInputMethod) { openvr.IVROverlay.SetOverlayInputMethod(OverlayHandle, InputMethod); }
    GetOverlayMouseScale(OverlayHandle: VROverlayHandle_t): HmdVector2_t { return openvr.IVROverlay.GetOverlayMouseScale(OverlayHandle); }
    SetOverlayMouseScale(OverlayHandle: VROverlayHandle_t, MouseScale: HmdVector2_t) { openvr.IVROverlay.SetOverlayMouseScale(OverlayHandle, MouseScale); }
    ComputeOverlayIntersection(OverlayHandle: VROverlayHandle_t, Params: VROverlayIntersectionParams_t, Results: VROverlayIntersectionResults_t) { openvr.IVROverlay.ComputeOverlayIntersection(OverlayHandle, Params, Results); }
    IsHoverTargetOverlay(OverlayHandle: VROverlayHandle_t): boolean { return openvr.IVROverlay.IsHoverTargetOverlay(OverlayHandle); }
    TriggerLaserMouseHapticVibration(OverlayHandle: VROverlayHandle_t, DurationSeconds: number, Frequency: number, Amplitude: number) { openvr.IVROverlay.TriggerLaserMouseHapticVibration(OverlayHandle, DurationSeconds, Frequency, Amplitude); }
    SetOverlayCursor(OverlayHandle: VROverlayHandle_t, CursorHandle: VROverlayHandle_t) { openvr.IVROverlay.SetOverlayCursor(OverlayHandle, CursorHandle); }
    SetOverlayCursorPositionOverride(OverlayHandle: VROverlayHandle_t, Cursor: HmdVector2_t) { openvr.IVROverlay.SetOverlayCursorPositionOverride(OverlayHandle, Cursor); }
    ClearOverlayCursorPositionOverride(OverlayHandle: VROverlayHandle_t) { openvr.IVROverlay.ClearOverlayCursorPositionOverride(OverlayHandle); }

    // ---------------------------------------------
    // Overlay texture methods
    // ---------------------------------------------

    SetOverlayTexture(OverlayHandle: VROverlayHandle_t, Texture: Texture_t) { openvr.IVROverlay.SetOverlayTexture(OverlayHandle, Texture); }
    ClearOverlayTexture(OverlayHandle: VROverlayHandle_t) { openvr.IVROverlay.ClearOverlayTexture(OverlayHandle); }
    SetOverlayRaw(OverlayHandle: VROverlayHandle_t, Buffer: number, Width: number, Height: number, BytesPerPixel: number) { openvr.IVROverlay.SetOverlayRaw(OverlayHandle, Buffer, Width, Height, BytesPerPixel); }
    SetOverlayFromFile(OverlayHandle: VROverlayHandle_t, FilePath: String) { openvr.IVROverlay.SetOverlayFromFile(OverlayHandle, FilePath); }
    ReleaseNativeOverlayHandle(OverlayHandle: VROverlayHandle_t, NativeTextureHandle: number) { openvr.IVROverlay.ReleaseNativeOverlayHandle(OverlayHandle, NativeTextureHandle); }
    GetOverlayTextureSize(OverlayHandle: VROverlayHandle_t): { Width: number, Height: number } { return openvr.IVROverlay.GetOverlayTextureSize(OverlayHandle); }

    // ----------------------------------------------
    // Dashboard Overlay Methods
    // ----------------------------------------------

    CreateDashboardOverlay(OverlayKey: string, OverlayFriendlyName: string): { MainHandle: number, ThumbnailHandle: number } { return openvr.IVROverlay.CreateDashboardOverlay(OverlayKey, OverlayFriendlyName); }
    IsDashboardVisible(): boolean { return openvr.IVROverlay.IsDashboardVisible(); }
    IsActiveDashboardOverlay(OverlayHandle: VROverlayHandle_t): boolean { return openvr.IVROverlay.IsActiveDashboardOverlay(OverlayHandle); }
    SetDashboardOverlaySceneProcess(OverlayHandle: VROverlayHandle_t, ProcessId: number) { openvr.IVROverlay.SetDashboardOverlaySceneProcess(OverlayHandle, ProcessId); }
    GetDashboardOverlaySceneProcess(OverlayHandle: VROverlayHandle_t): number { return openvr.IVROverlay.GetDashboardOverlaySceneProcess(OverlayHandle); }
    ShowDashboard(OverlayToShow: string) { openvr.IVROverlay.ShowDashboard(OverlayToShow); }
    GetPrimaryDashboardDevice(): TrackedDeviceIndex_t { return openvr.IVROverlay.GetPrimaryDashboardDevice(); }

    // ---------------------------------------------
    // Keyboard methods
    // ---------------------------------------------

    ShowKeyboard(InputMode: EGamepadTextInputMode, LineInputMode: EGamepadTextInputLineMode, Flags: number, Description: string, ExistingText: string, UserValue: number) { openvr.IVROverlay.ShowKeyboard(InputMode, LineInputMode, Flags, Description, ExistingText, UserValue); }
    ShowKeyboardForOverlay(OverlayHandle: VROverlayHandle_t, InputMode: EGamepadTextInputMode, LineInputMode: EGamepadTextInputLineMode, Flags: number, Description: string, ExistingText: string, UserValue: number) { openvr.IVROverlay.ShowKeyboardForOverlay(OverlayHandle, InputMode, LineInputMode, Flags, Description, ExistingText, UserValue); }
    GetKeyboardText(TextLength: number): string { return openvr.IVROverlay.GetKeyboardText(TextLength); }
    HideKeyBoard() { openvr.IVROverlay.HideKeyBoard(); }
    SetKeyboardTransformAbsolute(TrackingOrigin: ETrackingUniverseOrigin, TrackingOriginToKeyboardTransform: HmdMatrix34_t) { openvr.IVROverlay.SetKeyboardTransformAbsolute(TrackingOrigin, TrackingOriginToKeyboardTransform); }
    SetKeyboardPositionForOverlay(OverlayHandle: VROverlayHandle_t, AvoidRect: HmdRect2_t) { openvr.IVROverlay.SetKeyboardPositionForOverlay(OverlayHandle, AvoidRect); }

    // ---------------------------------------------
    // Message box methods
    // ---------------------------------------------

    ShowMessageOverlay(Text: string, Caption: string, Button0Text: string, Button1Text?: string, Button2Text?: string, Button3Text?: string) {
        if (Button1Text === undefined) openvr.IVROverlay.ShowMessageOverlay(Text, Caption, Button0Text);
        else if (Button2Text === undefined) openvr.IVROverlay.ShowMessageOverlay(Text, Caption, Button0Text, Button1Text);
        else if (Button3Text === undefined) openvr.IVROverlay.ShowMessageOverlay(Text, Caption, Button0Text, Button1Text, Button2Text);
        else openvr.IVROverlay.ShowMessageOverlay(Text, Caption, Button0Text, Button1Text, Button2Text, Button3Text);
    }
    CloseMessageOverlay() { openvr.IVROverlay.CloseMessageOverlay(); }
}