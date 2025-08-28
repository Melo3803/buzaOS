#include "buza.h"
#include "../BasicRenderer.h"
#include "../apps/appManager.h"

extern bool LeftMouseDown; // Fare durumunu dışarıdan alacağız
extern bool RightMouseDown;

BuzaApp::BuzaApp(){

}

BuzaApp::~BuzaApp(){
    
}


void BuzaApp::Run(){

        // arkaplan rengi
        GlobalRenderer->ClearColour = 0xff00ffff;
        GlobalRenderer->XCenter();
        GlobalRenderer->Print("BuzaApp - Cikmak icin sag tikla");
            

        GlobalRenderer->CursorPosition = {50, 50};
        GlobalRenderer->Colour = 0xffff00ff;
        GlobalRenderer->Print("Buza App");
    

    

    
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
