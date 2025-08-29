#include "buza.h"
#include "../BasicRenderer.h"
#include "appManager.h"


extern bool RightMouseDown;

const int DUMMY_WIDTH = 16;
const int DUMMY_HEIGHT = 16;
unsigned char dummy_rgba[DUMMY_WIDTH * DUMMY_HEIGHT * 4];

void CreateDummyImage() {
    for (int y = 0; y < DUMMY_HEIGHT; y++) {
        for (int x = 0; x < DUMMY_WIDTH; x++) {
            int idx = (y * DUMMY_WIDTH + x) * 4;
            dummy_rgba[idx + 0] = 255; // R
            dummy_rgba[idx + 1] = 0;   // G
            dummy_rgba[idx + 2] = 0;   // B
            dummy_rgba[idx + 3] = 255; // A
        }
    }
}

void BuzaApp::OnStart(){
    GlobalRenderer->ClearColour = 0xff00ffff;
    GlobalRenderer->Clear();
    GlobalRenderer->XCenter();
    GlobalRenderer->Colour = 0xffff00ff;
    GlobalRenderer->Print("BuzaApp - Cikmak icin sag tikla");
    GlobalRenderer->CursorPosition = {50, 50};
    GlobalRenderer->Print("BUZA:");

    CreateDummyImage(); // Resmi hazırla

    int startX = (GlobalRenderer->TargetFramebuffer->Width - DUMMY_WIDTH) / 2;
    int startY = (GlobalRenderer->TargetFramebuffer->Height - DUMMY_HEIGHT) / 2;
    GlobalRenderer->DrawImageRGBA(dummy_rgba, DUMMY_WIDTH, DUMMY_HEIGHT, startX, startY);
}

void BuzaApp::OnUpdate(){
    if (RightMouseDown){
        GlobalAppManager->SwitchTo(GlobalAppManager->Desktop);
    }
}
