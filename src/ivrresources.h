#ifndef IVRRESOURCES_H_JS
#define IVRRESOURCES_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRResources;
}

class IVRResources : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRResources *resources);

private:
    explicit IVRResources(vr::IVRResources *self);
    ~IVRResources() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual uint32_t LoadSharedResource( const char *pchResourceName, char *pchBuffer, uint32_t unBufferLen ) = 0;
    static void LoadSharedResource(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetResourceFullPath( const char *pchResourceName, const char *pchResourceTypeDirectory, VR_OUT_STRING() char *pchPathBuffer, uint32_t unBufferLen ) = 0;
    static void GetResourceFullPath(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRResources *const self_;
};

#endif