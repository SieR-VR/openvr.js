import * as vr from "../tssrc/index";
import * as fs from "fs";
import { PNG } from "pngjs";

test("pngjs_test", () => {
    // defailt initalization
    vr.VR_Init(vr.EVRApplicationType.VRApplication_Overlay);

    const overlay = vr.IVROverlay_Init();
    const { MainHandle, ThumbnailHandle } = overlay.CreateDashboardOverlay("test", "test");

    const pngBufferRaw = fs.readFileSync(__dirname + "/assets/test.png");
    const pngBuffer = PNG.sync.read(pngBufferRaw);

    const pixelBuffer = Buffer.from(pngBuffer.data);

    overlay.SetOverlayRaw(MainHandle, pixelBuffer, pngBuffer.width, pngBuffer.height, 4);

    while (true) {
        // do nothing
    }
});