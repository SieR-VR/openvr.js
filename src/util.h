#ifndef UTIL_H_JS
#define UTIL_H_JS

#include <algorithm>
#include <array>
#include <limits>
#include <nan.h>
#include <openvr.h>
#include <v8.h>

using TrackedDevicePoseArray = std::array<vr::TrackedDevicePose_t, vr::k_unMaxTrackedDeviceCount>;
using TrackedDeviceIndexArray = std::array<vr::TrackedDeviceIndex_t, vr::k_unMaxTrackedDeviceCount>;

//=========================================================
// C++ -> Node
template <typename T>
v8::Local<v8::Value> encode(const T &value);

// Node -> C++
template <typename T>
T decode(const v8::Local<v8::Value>, v8::Isolate *);

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::HmdMatrix44_t &value);

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::HmdMatrix34_t &value);

//=========================================================
template <>
vr::HmdMatrix34_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate);

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::HmdVector3_t &value);

//=========================================================
template <>
vr::HmdVector3_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate);

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::HmdVector2_t &value);

//=========================================================
template <>
vr::HmdVector2_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate);

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::DistortionCoordinates_t &value);

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::TrackedDeviceIndex_t &value);

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::TrackedDevicePose_t &value);

//=========================================================
template <>
vr::TrackedDevicePose_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate);

//=========================================================
template <>
v8::Local<v8::Value> encode(const TrackedDeviceIndexArray &value);

//=========================================================
template <>
v8::Local<v8::Value> encode(const TrackedDevicePoseArray &value);

//=========================================================
template<>
vr::VRTextureBounds_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate);

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::VRTextureBounds_t &textureBounds);

//=========================================================
template<>
vr::VROverlayProjection_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate);

//=========================================================
template <typename T>
v8::Local<v8::Value> encode(const T &eventData, vr::EVREventType eventType);

//=========================================================
template <>
v8::Local<v8::Value> encode(const vr::VREvent_t &value);

//=========================================================
template<>
vr::VROverlayIntersectionParams_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate);

//=========================================================
template<>
vr::VROverlayIntersectionResults_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate);

//=========================================================
template<>
vr::Texture_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate);

//=========================================================
template<>
vr::HmdRect2_t decode(const v8::Local<v8::Value> value, v8::Isolate *isolate);

//=========================================================
template <typename T>
v8::Local<v8::Value> encode(const T &value);

#endif
