#ifndef UTIL_JS
#define UTIL_JS

#include <algorithm>
#include <limits>
#include <nan.h>
#include <openvr.h>
#include <v8.h>

//=========================================================
// C++ -> Node
template <typename T>
v8::Local<v8::Value> encode(const T &value);

// Node -> C++
template <typename T>
T decode(const v8::Local<v8::Value>, v8::Isolate *);

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::HmdMatrix44_t &value)
{
    Nan::EscapableHandleScope scope;
    auto result = Nan::New<v8::Array>();

    for (uint32_t rowIdx = 0; rowIdx < 4; ++rowIdx)
    {
        auto row = Nan::New<v8::Array>();
        for (uint32_t colIdx = 0; colIdx < 4; ++colIdx)
            Nan::Set(row, colIdx, Nan::New<v8::Number>(value.m[rowIdx][colIdx]));
        Nan::Set(result, rowIdx, row);
    }

    return scope.Escape(result);
}

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::HmdMatrix34_t &value)
{
    Nan::EscapableHandleScope scope;
    auto result = Nan::New<v8::Array>();

    for (uint32_t rowIdx = 0; rowIdx < 3; ++rowIdx)
    {
        auto row = Nan::New<v8::Array>();
        for (uint32_t colIdx = 0; colIdx < 4; ++colIdx)
            Nan::Set(row, colIdx, Nan::New<v8::Number>(value.m[rowIdx][colIdx]));
        Nan::Set(result, rowIdx, row);
    }

    return scope.Escape(result);
}

//=========================================================
template <>
vr::HmdMatrix34_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate)
{
    vr::HmdMatrix34_t result;
    const auto matrix = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();

    for (uint32_t rowIdx = 0; rowIdx < 3; ++rowIdx)
    {
        const auto row = Nan::Get(matrix, rowIdx).ToLocalChecked()->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
        for (uint32_t colIdx = 0; colIdx < 4; ++colIdx)
        {
            const auto cell = Nan::Get(row, colIdx).ToLocalChecked();
            result.m[rowIdx][colIdx] = static_cast<float>(cell->NumberValue(isolate->GetCurrentContext()).FromJust());
        }
    }

    return result;
}

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::HmdVector3_t &value)
{
    Nan::EscapableHandleScope scope;
    auto result = Nan::New<v8::Array>();

    for (uint32_t idx = 0; idx < 3; ++idx)
        Nan::Set(result, idx, Nan::New<v8::Number>(value.v[idx]));

    return scope.Escape(result);
}

//=========================================================
template <>
vr::HmdVector3_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate)
{
    vr::HmdVector3_t result;
    const auto array = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();

    for (uint32_t idx = 0; idx < 3; ++idx)
    {
        const auto cell = Nan::Get(array, idx).ToLocalChecked();
        result.v[idx] = static_cast<float>(cell->NumberValue(isolate->GetCurrentContext()).FromJust());
    }

    return result;
}

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::HmdVector2_t &value)
{
    Nan::EscapableHandleScope scope;
    auto result = Nan::New<v8::Array>();

    for (uint32_t idx = 0; idx < 2; ++idx)
        Nan::Set(result, idx, Nan::New<v8::Number>(value.v[idx]));

    return scope.Escape(result);
}

//=========================================================
template <>
vr::HmdVector2_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate)
{
    vr::HmdVector2_t result;
    const auto array = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();

    for (uint32_t idx = 0; idx < 2; ++idx)
    {
        const auto cell = Nan::Get(array, idx).ToLocalChecked();
        result.v[idx] = static_cast<float>(cell->NumberValue(isolate->GetCurrentContext()).FromJust());
    }

    return result;
}

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::DistortionCoordinates_t &value)
{
    Nan::EscapableHandleScope scope;
    auto result = Nan::New<v8::Object>();

    // Extract red values.
    {
        auto red = Nan::New<v8::Array>();
        Nan::Set(red, 0, Nan::New<v8::Number>(value.rfRed[0]));
        Nan::Set(red, 1, Nan::New<v8::Number>(value.rfRed[1]));

        auto red_prop = Nan::New<v8::String>("red").ToLocalChecked();
        Nan::Set(result, red_prop, red);
    }

    // Extract green values.
    {
        auto green = Nan::New<v8::Array>();
        Nan::Set(green, 0, Nan::New<v8::Number>(value.rfGreen[0]));
        Nan::Set(green, 1, Nan::New<v8::Number>(value.rfGreen[1]));

        auto green_prop = Nan::New<v8::String>("green").ToLocalChecked();
        Nan::Set(result, green_prop, green);
    }

    // Extract blue values.
    {
        auto blue = Nan::New<v8::Array>();
        Nan::Set(blue, 0, Nan::New<v8::Number>(value.rfBlue[0]));
        Nan::Set(blue, 1, Nan::New<v8::Number>(value.rfBlue[1]));

        auto blue_prop = Nan::New<v8::String>("blue").ToLocalChecked();
        Nan::Set(result, blue_prop, blue);
    }

    return scope.Escape(result);
}

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::TrackedDeviceIndex_t &value)
{
    return Nan::New<v8::Number>(value);
}

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::TrackedDevicePose_t &value)
{
    Nan::EscapableHandleScope scope;
    auto result = Nan::New<v8::Object>();

    auto deviceToAbsoluteTracking_prop =
        Nan::New<v8::String>("deviceToAbsoluteTracking").ToLocalChecked();
    Nan::Set(
        result, deviceToAbsoluteTracking_prop,
        encode(value.mDeviceToAbsoluteTracking));

    auto velocity_prop =
        Nan::New<v8::String>("velocity").ToLocalChecked();
    Nan::Set(result, velocity_prop, encode(value.vVelocity));

    auto angularVelocity_prop =
        Nan::New<v8::String>("angularVelocity").ToLocalChecked();
    Nan::Set(result, angularVelocity_prop, encode(value.vAngularVelocity));

    auto trackingResult_prop =
        Nan::New<v8::String>("trackingResult").ToLocalChecked();
    Nan::Set(
        result, trackingResult_prop,
        Nan::New<v8::Number>(static_cast<uint32_t>(value.eTrackingResult)));

    auto poseIsValid_prop =
        Nan::New<v8::String>("poseIsValid").ToLocalChecked();
    Nan::Set(
        result, poseIsValid_prop,
        Nan::New<v8::Boolean>(value.bPoseIsValid));

    auto deviceIsConnected_prop =
        Nan::New<v8::String>("deviceIsConnected").ToLocalChecked();
    Nan::Set(
        result, deviceIsConnected_prop,
        Nan::New<v8::Boolean>(value.bDeviceIsConnected));

    return scope.Escape(result);
}

//=========================================================
template <>
vr::TrackedDevicePose_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate)
{
    vr::TrackedDevicePose_t result;
    const auto object = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();

    auto deviceToAbsoluteTracking_prop =
        Nan::New<v8::String>("deviceToAbsoluteTracking").ToLocalChecked();
    result.mDeviceToAbsoluteTracking =
        decode<vr::HmdMatrix34_t>(
            Nan::Get(object, deviceToAbsoluteTracking_prop).ToLocalChecked(), isolate);

    auto velocity_prop =
        Nan::New<v8::String>("velocity").ToLocalChecked();
    result.vVelocity =
        decode<vr::HmdVector3_t>(Nan::Get(object, velocity_prop).ToLocalChecked(), isolate);

    auto angularVelocity_prop =
        Nan::New<v8::String>("angularVelocity").ToLocalChecked();
    result.vAngularVelocity =
        decode<vr::HmdVector3_t>(
            Nan::Get(object, angularVelocity_prop).ToLocalChecked(), isolate);

    auto trackingResult_prop =
        Nan::New<v8::String>("trackingResult").ToLocalChecked();
    result.eTrackingResult =
        static_cast<vr::ETrackingResult>(
            Nan::Get(object, trackingResult_prop).ToLocalChecked()->Uint32Value(isolate->GetCurrentContext()).FromJust());

    auto poseIsValid_prop =
        Nan::New<v8::String>("poseIsValid").ToLocalChecked();
    result.bPoseIsValid =
        Nan::Get(object, poseIsValid_prop).ToLocalChecked()->BooleanValue(isolate);

    auto deviceIsConnected_prop =
        Nan::New<v8::String>("deviceIsConnected").ToLocalChecked();
    result.bDeviceIsConnected =
        Nan::Get(object, deviceIsConnected_prop).ToLocalChecked()->BooleanValue(isolate);

    return result;
}

//=========================================================
template <typename T>
v8::Local<v8::Value> encode(const T &value, uint32_t nDeviceIndices)
{
    Nan::EscapableHandleScope scope;
    auto result = Nan::New<v8::Array>();

    const uint32_t numElements = std::min(static_cast<uint32_t>(value.size()), nDeviceIndices);
    for (uint32_t idx = 0; idx < numElements; ++idx)
        Nan::Set(result, idx, encode(value[idx]));

    return scope.Escape(result);
}

//=========================================================
template<>
vr::VRTextureBounds_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate)
{
    vr::VRTextureBounds_t result;
    const auto object = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();

    auto uMin_prop = Nan::New<v8::String>("uMin").ToLocalChecked();
    result.uMin = Nan::Get(object, uMin_prop).ToLocalChecked()->NumberValue(isolate->GetCurrentContext()).FromJust();

    auto uMax_prop = Nan::New<v8::String>("uMax").ToLocalChecked();
    result.uMax = Nan::Get(object, uMax_prop).ToLocalChecked()->NumberValue(isolate->GetCurrentContext()).FromJust();

    auto vMax_prop = Nan::New<v8::String>("vMax").ToLocalChecked();
    result.vMax = Nan::Get(object, vMax_prop).ToLocalChecked()->NumberValue(isolate->GetCurrentContext()).FromJust();

    auto vMin_prop = Nan::New<v8::String>("vMin").ToLocalChecked();
    result.vMin = Nan::Get(object, vMin_prop).ToLocalChecked()->NumberValue(isolate->GetCurrentContext()).FromJust();

    return result;
}

//=========================================================
template <typename T>
v8::Local<v8::Value> encode(const vr::VRTextureBounds_t textureBounds)
{
    Nan::EscapableHandleScope scope;
    auto result = Nan::New<v8::Object>();

    auto uMin_prop = Nan::New<v8::String>("uMin").ToLocalChecked();
    Nan::Set(result, uMin_prop, Nan::New<v8::Number>(textureBounds.uMin);

    auto uMax_prop = Nan::New<v8::String>("uMax").ToLocalChecked();
    Nan::Set(result, uMax_prop, Nan::New<v8::Number>(textureBounds.uMax);

    auto vMax_prop = Nan::New<v8::String>("vMax").ToLocalChecked();
    Nan::Set(result, vMax_prop, Nan::New<v8::Number>(textureBounds.vMax));

    auto vMin_prop = Nan::New<v8::String>("vMin").ToLocalChecked();
    Nan::Set(result, vMin_prop, Nan::New<v8::Number>(textureBounds.vMin);

    return scope.Escape(result);
}

//=========================================================
template<>
vr::VROverlayProjection_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate)
{
    vr::VROverlayProjection_t result;
    const auto object = value->ToObject(isolate->GetCurrentContext()).ToLocalChecked();

    auto fBottom_prop = Nan::New<v8::String>("fBottom").ToLocalChecked();
    result.fBottom = Nan::Get(object, fBottom_prop).ToLocalChecked()->NumberValue(isolate->GetCurrentContext()).FromJust();

    auto fLeft_prop = Nan::New<v8::String>("fLeft").ToLocalChecked();
    result.fLeft = Nan::Get(object, fLeft_prop).ToLocalChecked()->NumberValue(isolate->GetCurrentContext()).FromJust();

    auto fRight_prop = Nan::New<v8::String>("fRight").ToLocalChecked();
    result.fRight = Nan::Get(object, fRight_prop).ToLocalChecked()->NumberValue(isolate->GetCurrentContext()).FromJust();

    auto fTop_prop = Nan::New<v8::String>("fTop").ToLocalChecked();
    result.fTop = Nan::Get(object, fTop_prop).ToLocalChecked()->NumberValue(isolate->GetCurrentContext()).FromJust();

    return result;
}

//=========================================================
template <typename T>
v8::Local<v8::Value> encode(const T &value)
{
    return encode(value, value.size());
}

#endif