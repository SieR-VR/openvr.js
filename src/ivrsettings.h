#ifndef IVRSETTINGS_H_JS
#define IVRSETTINGS_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRSettings;
}

class IVRSettings : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRSettings *settings);

private:
    explicit IVRSettings(vr::IVRSettings *self);
    ~IVRSettings() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual const char *GetSettingsErrorNameFromEnum( EVRSettingsError eError ) = 0;
    static void GetSettingsErrorNameFromEnum(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetBool( const char *pchSection, const char *pchSettingsKey, bool bValue, EVRSettingsError *peError = nullptr ) = 0;
    static void SetBool(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetInt32( const char *pchSection, const char *pchSettingsKey, int32_t nValue, EVRSettingsError *peError = nullptr ) = 0;
    static void SetInt32(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetFloat( const char *pchSection, const char *pchSettingsKey, float flValue, EVRSettingsError *peError = nullptr ) = 0;
    static void SetFloat(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void SetString( const char *pchSection, const char *pchSettingsKey, const char *pchValue, EVRSettingsError *peError = nullptr ) = 0;
    static void SetString(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual bool GetBool( const char *pchSection, const char *pchSettingsKey, EVRSettingsError *peError = nullptr ) = 0;
    static void GetBool(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual int32_t GetInt32( const char *pchSection, const char *pchSettingsKey, EVRSettingsError *peError = nullptr ) = 0;
    static void GetInt32(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual float GetFloat( const char *pchSection, const char *pchSettingsKey, EVRSettingsError *peError = nullptr ) = 0;
    static void GetFloat(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void GetString( const char *pchSection, const char *pchSettingsKey, VR_OUT_STRING() char *pchValue, uint32_t unValueLen, EVRSettingsError *peError = nullptr ) = 0;
    static void GetString(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual void RemoveSection( const char *pchSection, EVRSettingsError *peError = nullptr ) = 0;
    static void RemoveSection(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void RemoveKeyInSection( const char *pchSection, const char *pchSettingsKey, EVRSettingsError *peError = nullptr ) = 0;
    static void RemoveKeyInSection(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRSettings *const self_;
};

#endif