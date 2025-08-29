#include "desktop.h"
#include "../BasicRenderer.h"
#include "appManager.h"

extern bool LeftMouseDown;
extern bool RightMouseDown;

void DesktopApp::OnStart(){
    GlobalRenderer->ClearColour =0xff000000;
    GlobalRenderer->Clear(); // Ekranı temizle
    GlobalRenderer->Colour = 0xffffffff;
    GlobalRenderer->CursorPosition = {0, 0};
    GlobalRenderer->Print("BuzaOS");

    uint32_t paintAppX = 50;
    uint32_t paintAppY = 50;
    uint32_t paintAppWidth = 100;
    uint32_t paintAppHeight = 50;

    for(uint32_t y = paintAppY; y < paintAppY + paintAppHeight; y++){
        for(uint32_t x = paintAppX; x < paintAppX + paintAppWidth; x++){
            GlobalRenderer->PutPix(x, y, 0xff888888); // Gri renk
        }
    }

    GlobalRenderer->CursorPosition = {paintAppX + 20, paintAppY + 20};
    GlobalRenderer->Colour = 0xffffffff; 
    GlobalRenderer->Print("Paint");

    // Buza app button
    uint32_t buzaAppX = 50;
    uint32_t buzaAppY = 120;
    uint32_t buzaAppWidth = 100;
    uint32_t buzaAppHeight = 50;

    for(uint32_t y = buzaAppY; y < buzaAppY + buzaAppHeight; y++){
        for(uint32_t x = buzaAppX; x < buzaAppX + buzaAppWidth; x++){
            GlobalRenderer->PutPix(x, y, 0xff00ff00); // Gri renk
        }
    }
    GlobalRenderer->CursorPosition = {buzaAppX + 20, buzaAppY + 20};
    GlobalRenderer->Colour = 0xffffffff; 
    GlobalRenderer->Print("Buza");

    // Buza app button
    uint32_t terminalAppX = 170;
    uint32_t terminalAppY = 50;
    uint32_t terminalAppWidth = 100;
    uint32_t terminalAppHeight = 50;

    for(uint32_t y = terminalAppY; y < terminalAppY + terminalAppHeight; y++){
        for(uint32_t x = terminalAppX; x < terminalAppX + terminalAppWidth; x++){
            GlobalRenderer->PutPix(x, y, 0xff00ffff); // Gri renk
        }
    }
    GlobalRenderer->CursorPosition = {terminalAppX + 20, terminalAppY + 20};
    GlobalRenderer->Colour = 0xffffffff; 
    GlobalRenderer->Print("Terminal");

    // Terminal
    
}

void DesktopApp::OnUpdate(){
    // Sol fare tuşuna basıldıysa ikon tıklamalarını kontrol et
    if (LeftMouseDown) {
        // Paint Butonu
        if (MousePosition.X >= 50 && MousePosition.X <= 150 &&
            MousePosition.Y >= 50 && MousePosition.Y <= 100)
        {
            GlobalAppManager->SwitchTo(GlobalAppManager->Paint);
        }
        // Buza Butonu
        else if (MousePosition.X >= 50 && MousePosition.X <= 150 &&
                 MousePosition.Y >= 120 && MousePosition.Y <= 170)
        {
            if (GlobalAppManager->Buza == nullptr) GlobalAppManager->Buza = new BuzaApp();
            GlobalAppManager->SwitchTo(GlobalAppManager->Buza);
        }
        // Terminal Butonu
        else if (MousePosition.X >= 170 && MousePosition.X <= 270 &&
                 MousePosition.Y >= 50 && MousePosition.Y <= 100)
        {
            if (GlobalAppManager->Terminal == nullptr) GlobalAppManager->Terminal = new TerminalApp();
            GlobalAppManager->SwitchTo(GlobalAppManager->Terminal);
        }
    }
}
