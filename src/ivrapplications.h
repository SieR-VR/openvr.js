#ifndef IVRAPPLICATIONS_H_JS
#define IVRAPPLICATIONS_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRApplications;
}

class IVRApplications : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRApplications *applications);

private:
    explicit IVRApplications(vr::IVRApplications *self);
    ~IVRApplications() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // ---------------  Application management  --------------- //

    // virtual EVRApplicationError AddApplicationManifest( const char *pchApplicationManifestFullPath, bool bTemporary = false )
    static void AddApplicationManifest(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRApplicationError RemoveApplicationManifest( const char *pchApplicationManifestFullPath )
    static void RemoveApplicationManifest(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsApplicationInstalled( const char *pchAppKey )
    static void IsApplicationInstalled(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetApplicationCount()
    static void GetApplicationCount(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRApplicationError GetApplicationKeyByIndex( uint32_t unApplicationIndex, VR_OUT_STRING() char *pchAppKeyBuffer, uint32_t unAppKeyBufferLen ) = 0;
    static void GetApplicationKeyByIndex(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRApplicationError GetApplicationKeyByProcessId( uint32_t unProcessId, VR_OUT_STRING() char *pchAppKeyBuffer, uint32_t unAppKeyBufferLen ) = 0;
    static void GetApplicationKeyByProcessId(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRApplicationError LaunchApplication( const char *pchAppKey )
    static void LaunchApplication(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRApplicationError LaunchTemplateApplication( const char *pchTemplateAppKey, const char *pchNewAppKey, VR_ARRAY_COUNT( unKeys ) const AppOverrideKeys_t *pKeys, uint32_t unKeys ) = 0;
    static void LaunchTemplateApplication(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRApplicationError LaunchApplicationFromMimeType( const char *pchMimeType, const char *pchArgs )
    static void LaunchApplicationFromMimeType(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRApplicationError LaunchDashboardOverlay( const char *pchAppKey )
    static void LaunchDashboardOverlay(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool CancelApplicationLaunch( const char *pchAppKey )
    static void CancelApplicationLaunch(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRApplicationError IdentifyApplication( uint32_t unProcessId, const char *pchAppKey )
    static void IdentifyApplication(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetApplicationProcessId( const char *pchAppKey )
    static void GetApplicationProcessId(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual const char *GetApplicationsErrorNameFromEnum( EVRApplicationError error )
    static void GetApplicationsErrorNameFromEnum(const Nan::FunctionCallbackInfo<Value> &info);

    // ---------------  Application properties  --------------- //

    // virtual uint32_t GetApplicationPropertyString( const char *pchAppKey, EVRApplicationProperty eProperty, VR_OUT_STRING() char *pchPropertyValueBuffer, uint32_t unPropertyValueBufferLen, EVRApplicationError *peError = nullptr )
    static void GetApplicationPropertyString(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetApplicationPropertyBool( const char *pchAppKey, EVRApplicationProperty eProperty, EVRApplicationError *peError = nullptr )
    static void GetApplicationPropertyBool(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint64_t GetApplicationPropertyUint64( const char *pchAppKey, EVRApplicationProperty eProperty, EVRApplicationError *peError = nullptr )
    static void GetApplicationPropertyUint64(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRApplicationError SetApplicationAutoLaunch( const char *pchAppKey, bool bAutoLaunch )
    static void SetApplicationAutoLaunch(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetApplicationAutoLaunch( const char *pchAppKey )
    static void GetApplicationAutoLaunch(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRApplicationError SetDefaultApplicationForMimeType( const char *pchAppKey, const char *pchMimeType )
    static void SetDefaultApplicationForMimeType(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetDefaultApplicationForMimeType( const char *pchMimeType, VR_OUT_STRING() char *pchAppKeyBuffer, uint32_t unAppKeyBufferLen )
    static void GetDefaultApplicationForMimeType(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetApplicationSupportedMimeTypes( const char *pchAppKey, VR_OUT_STRING() char *pchMimeTypesBuffer, uint32_t unMimeTypesBuffer )
    static void GetApplicationSupportedMimeTypes(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetApplicationsThatSupportMimeType( const char *pchMimeType, VR_OUT_STRING() char *pchAppKeysThatSupportBuffer, uint32_t unAppKeysThatSupportBuffer )
    static void GetApplicationsThatSupportMimeType(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetApplicationLaunchArguments( uint32_t unHandle, VR_OUT_STRING() char *pchArgs, uint32_t unArgs )
    static void GetApplicationLaunchArguments(const Nan::FunctionCallbackInfo<Value> &info);

    // ---------------  Transition methods --------------- //
    
    // virtual EVRApplicationError GetStartingApplication( VR_OUT_STRING() char *pchAppKeyBuffer, uint32_t unAppKeyBufferLen )
    static void GetStartingApplication(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRSceneApplicationState GetSceneApplicationState()
    static void GetSceneApplicationState(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRApplicationError PerformApplicationPrelaunchCheck( const char *pchAppKey )
    static void PerformApplicationPrelaunchCheck(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual const char *GetSceneApplicationStateNameFromEnum( EVRSceneApplicationState state ) = 0;
    static void GetSceneApplicationStateNameFromEnum(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRApplicationError LaunchInternalProcess( const char *pchBinaryPath, const char *pchArguments, const char *pchWorkingDirectory ) = 0;
    static void LaunchInternalProcess(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetCurrentSceneProcessId() = 0;
    static void GetCurrentSceneProcessId(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRApplications *const self_;
};

#endif