#include "paint.h"
#include "../BasicRenderer.h"
#include "../apps/appManager.h"

extern bool LeftMouseDown; // Fare durumunu dışarıdan alacağız
extern bool RightMouseDown;

PaintApp::PaintApp(){

    
}

PaintApp::~PaintApp(){

}

void PaintApp::Run(){
    if (LeftMouseDown){
        GlobalRenderer->PutChar('a', MousePosition.X, MousePosition.Y);
        
    }
    GlobalRenderer->ClearColour = 0x00000000; //arkaplan rengi
    GlobalRenderer->XCenter();
    
    GlobalRenderer->Print("Paint - Cikmak icin sag tikla");
    
    if (RightMouseDown){
        
        GlobalAppManager->SwitchTo(GlobalAppManager->Desktop);
        GlobalRenderer->Clear();
        }
    
    
    /* if(GlobalAppManager->CurrentApp == GlobalAppManager->Paint){
                    GlobalAppManager->SwitchTo(GlobalAppManager->Desktop);
                }
                else if(GlobalAppManager->CurrentApp == GlobalAppManager->Buza){
                    GlobalAppManager->SwitchTo(GlobalAppManager->Desktop);
                }*/
}
