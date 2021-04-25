#ifndef IVRDRIVERMANAGER_H_JS
#define IVRDRIVERMANAGER_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRDriverManager;
}

class IVRDriverManager : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRDriverManager *drivermanager);

private:
    explicit IVRDriverManager(vr::IVRDriverManager *self);
    ~IVRDriverManager() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual uint32_t GetDriverCount() const = 0;
    static void GetDriverCount(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetDriverName( vr::DriverId_t nDriver, VR_OUT_STRING() char *pchValue, uint32_t unBufferSize ) = 0;
    static void GetDriverName(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual DriverHandle_t GetDriverHandle( const char *pchDriverName ) = 0;
    static void GetDriverHandle(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool IsEnabled( vr::DriverId_t nDriver ) const = 0;
    static void IsEnabled(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRDriverManager *const self_;
};

#endif