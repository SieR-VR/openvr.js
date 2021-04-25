#ifndef IVRSCREENSHOTS_H_JS
#define IVRSCREENSHOTS_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRScreenshots;
}

class IVRScreenshots : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRScreenshots *screenshots);

private:
    explicit IVRScreenshots(vr::IVRScreenshots *self);
    ~IVRScreenshots() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual vr::EVRScreenshotError RequestScreenshot( vr::ScreenshotHandle_t *pOutScreenshotHandle, vr::EVRScreenshotType type, const char *pchPreviewFilename, const char *pchVRFilename ) = 0;
    static void RequestScreenshot(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRScreenshotError HookScreenshot( VR_ARRAY_COUNT( numTypes ) const vr::EVRScreenshotType *pSupportedTypes, int numTypes ) = 0;
    static void HookScreenshot(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRScreenshotType GetScreenshotPropertyType( vr::ScreenshotHandle_t screenshotHandle, vr::EVRScreenshotError *pError ) = 0;
    static void GetScreenshotPropertyType(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual uint32_t GetScreenshotPropertyFilename( vr::ScreenshotHandle_t screenshotHandle, vr::EVRScreenshotPropertyFilenames filenameType, VR_OUT_STRING() char *pchFilename, uint32_t cchFilename, vr::EVRScreenshotError *pError ) = 0;
    static void GetScreenshotPropertyFilename(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRScreenshotError UpdateScreenshotProgress( vr::ScreenshotHandle_t screenshotHandle, float flProgress ) = 0;
    static void UpdateScreenshotProgress(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRScreenshotError TakeStereoScreenshot( vr::ScreenshotHandle_t *pOutScreenshotHandle, const char *pchPreviewFilename, const char *pchVRFilename ) = 0;
    static void TakeStereoScreenshot(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual vr::EVRScreenshotError SubmitScreenshot( vr::ScreenshotHandle_t screenshotHandle, vr::EVRScreenshotType type, const char *pchSourcePreviewFilename, const char *pchSourceVRFilename ) = 0;
    static void SubmitScreenshot(const Nan::FunctionCallbackInfo<Value> &info);
    

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRScreenshots *const self_;
};

#endif