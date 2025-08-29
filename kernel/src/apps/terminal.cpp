#include "terminal.h"
#include "../BasicRenderer.h"
#include "appManager.h"


extern bool LeftMouseDown;
extern bool RightMouseDown;

void TerminalApp::OnStart(){
    GlobalRenderer->ClearColour = 0xff000000;
    GlobalRenderer->Clear();
    GlobalRenderer->XCenter();
    GlobalRenderer->Print("Terminal - Cikmak icin sag tikla");
    GlobalRenderer->CursorPosition = {50, 50};
    GlobalRenderer->Colour = 0xff00ffff;
    GlobalRenderer->Print("TERMINAL-");
}

void TerminalApp::OnUpdate(){
    if (RightMouseDown){
        GlobalAppManager->SwitchTo(GlobalAppManager->Desktop);
    }
}
