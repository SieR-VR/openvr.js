const vr = require('bindings')('openvr');

vr.VR_Init(2);
console.log(vr.VR_IsRuntimeInstalled());