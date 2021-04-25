#ifndef IVRNOTIFICATIONS_H_JS
#define IVRNOTIFICATIONS_H_JS

#include <nan.h>
#include <v8.h>

using namespace v8;

namespace vr
{
    class IVRNotifications;
}

class IVRNotifications : public Nan::ObjectWrap
{
public:
    static void Init(Local<Object> exports);
    static Local<Object> NewInstance(vr::IVRNotifications *notifications);

private:
    explicit IVRNotifications(vr::IVRNotifications *self);
    ~IVRNotifications() = default;

    static void New(const Nan::FunctionCallbackInfo<Value> &info);

    // virtual EVRNotificationError CreateNotification( VROverlayHandle_t ulOverlayHandle, uint64_t ulUserValue, EVRNotificationType type, const char *pchText, EVRNotificationStyle style, const NotificationBitmap_t *pImage, /* out */ VRNotificationId *pNotificationId ) = 0;
    static void CreateNotification(const Nan::FunctionCallbackInfo<Value> &info);
    // virtual EVRNotificationError RemoveNotification( VRNotificationId notificationId ) = 0;
    static void RemoveNotification(const Nan::FunctionCallbackInfo<Value> &info);

    static Nan::Persistent<v8::Function> constructor;
    vr::IVRNotifications *const self_;
};

#endif