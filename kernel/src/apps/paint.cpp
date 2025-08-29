#include "paint.h"
#include "../BasicRenderer.h"
#include "appManager.h"

extern bool LeftMouseDown;
extern bool RightMouseDown;

void PaintApp::OnStart(){
    GlobalRenderer->ClearColour = 0xffffffff; // Tuval rengini beyaza ayarla
    GlobalRenderer->Clear(); // Tuvali temizle
    GlobalRenderer->XCenter();
    GlobalRenderer->Colour = 0xff000000;
    GlobalRenderer->Print("Paint - Cikmak icin sag tikla");
}

void PaintApp::OnUpdate(){
    // Sağ tuş ile masaüstüne dön
    if (RightMouseDown){
        GlobalAppManager->SwitchTo(GlobalAppManager->Desktop);
    }

    // Sol tuş basılıyken çizim yap
    if (LeftMouseDown){
        GlobalRenderer->Colour = 0xff000000;
        GlobalRenderer->PutChar('a',MousePosition.X, MousePosition.Y); // Siyah renkle çiz
    }
}
