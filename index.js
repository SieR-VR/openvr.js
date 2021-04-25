import { vr } from './dist/vrtypes.js'

const IVRSystem = vr.VR_Init(vr.EVRApplicationType.VRApplication_Overlay);
console.log(IVRSystem);

console.log(IVRSystem.GetProjectionMatrix(vr.EVREye.Eye_Left, 1, 1));