#ifndef IVRIOBUFFER_H_JS
#define IVRIOBUFFER_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRIOBuffer;
}

class IVRIOBuffer : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRIOBuffer *iobuffer);

private:
    explicit IVRIOBuffer(vr::IVRIOBuffer *self);
    ~IVRIOBuffer() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual vr::EIOBufferError Open( const char *pchPath, vr::EIOBufferMode mode, uint32_t unElementSize, uint32_t unElements, vr::IOBufferHandle_t *pulBuffer ) = 0;
    static void Open(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EIOBufferError Close( vr::IOBufferHandle_t ulBuffer ) = 0;
    static void Close(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EIOBufferError Read( vr::IOBufferHandle_t ulBuffer, void *pDst, uint32_t unBytes, uint32_t *punRead ) = 0;
    static void Read(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EIOBufferError Write( vr::IOBufferHandle_t ulBuffer, void *pSrc, uint32_t unBytes ) = 0;
    static void Write(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::PropertyContainerHandle_t PropertyContainer( vr::IOBufferHandle_t ulBuffer ) = 0;
    static void PropertyContainer(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool HasReaders( vr::IOBufferHandle_t ulBuffer ) = 0;
    static void HasReaders(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRIOBuffer *const self_;
};

#endif