#ifndef IVRRENDERMODELS_H_JS
#define IVRRENDERMODELS_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRRenderModels;
}

class IVRRenderModels : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRRenderModels *rendermodels);

private:
    explicit IVRRenderModels(vr::IVRRenderModels *self);
    ~IVRRenderModels() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual EVRRenderModelError LoadRenderModel_Async( const char *pchRenderModelName, RenderModel_t **ppRenderModel ) = 0;
    static void LoadRenderModel_Async(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void FreeRenderModel( RenderModel_t *pRenderModel ) = 0;
    static void FreeRenderModel(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRRenderModelError LoadTexture_Async( TextureID_t textureId, RenderModel_TextureMap_t **ppTexture ) = 0;
    static void LoadTexture_Async(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void FreeTexture( RenderModel_TextureMap_t *pTexture ) = 0;
    static void FreeTexture(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRRenderModelError LoadTextureD3D11_Async( TextureID_t textureId, void *pD3D11Device, void **ppD3D11Texture2D ) = 0;
    static void LoadTextureD3D11_Async(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRRenderModelError LoadIntoTextureD3D11_Async( TextureID_t textureId, void *pDstTexture ) = 0;
    static void LoadIntoTextureD3D11_Async(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual void FreeTextureD3D11( void *pD3D11Texture2D ) = 0;
    static void FreeTextureD3D11(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetRenderModelName( uint32_t unRenderModelIndex, VR_OUT_STRING() char *pchRenderModelName, uint32_t unRenderModelNameLen ) = 0;
    static void GetRenderModelName(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetRenderModelCount() = 0;
    static void GetRenderModelCount(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual uint32_t GetComponentCount( const char *pchRenderModelName ) = 0;
    static void GetComponentCount(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetComponentName( const char *pchRenderModelName, uint32_t unComponentIndex, VR_OUT_STRING( ) char *pchComponentName, uint32_t unComponentNameLen ) = 0;
    static void GetComponentName(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint64_t GetComponentButtonMask( const char *pchRenderModelName, const char *pchComponentName ) = 0;
    static void GetComponentButtonMask(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetComponentRenderModelName( const char *pchRenderModelName, const char *pchComponentName, VR_OUT_STRING( ) char *pchComponentRenderModelName, uint32_t unComponentRenderModelNameLen ) = 0;
    static void GetComponentRenderModelName(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetComponentStateForDevicePath( const char *pchRenderModelName, const char *pchComponentName, vr::VRInputValueHandle_t devicePath, const vr::RenderModel_ControllerMode_State_t *pState, vr::RenderModel_ComponentState_t *pComponentState ) = 0;
    static void GetComponentStateForDevicePath(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool GetComponentState( const char *pchRenderModelName, const char *pchComponentName, const vr::VRControllerState_t *pControllerState, const RenderModel_ControllerMode_State_t *pState, RenderModel_ComponentState_t *pComponentState ) = 0;
    static void GetComponentState(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual bool RenderModelHasComponent( const char *pchRenderModelName, const char *pchComponentName ) = 0;
    static void RenderModelHasComponent(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetRenderModelThumbnailURL( const char *pchRenderModelName, VR_OUT_STRING() char *pchThumbnailURL, uint32_t unThumbnailURLLen, vr::EVRRenderModelError *peError ) = 0;
    static void GetRenderModelThumbnailURL(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetRenderModelOriginalPath( const char *pchRenderModelName, VR_OUT_STRING() char *pchOriginalPath, uint32_t unOriginalPathLen, vr::EVRRenderModelError *peError ) = 0;
    static void GetRenderModelOriginalPath(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual const char *GetRenderModelErrorNameFromEnum( vr::EVRRenderModelError error ) = 0;
    static void GetRenderModelErrorNameFromEnum(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRRenderModels *const self_;
};

#endif