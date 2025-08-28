#include "desktop.h"
#include "../BasicRenderer.h"

DesktopApp::DesktopApp(){
    
}

DesktopApp::~DesktopApp(){

}

void DesktopApp::Run(){
    GlobalRenderer->ClearColour = 0x00000000; //arkaplan rengi

    

    // Paint app button
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
            GlobalRenderer->PutPix(x, y, 0xff888888); // Gri renk
        }
    }

    GlobalRenderer->CursorPosition = {buzaAppX + 20, buzaAppY + 20};
    GlobalRenderer->Colour = 0xffffffff; 
    GlobalRenderer->Print("Buza");

    GlobalRenderer->XCenter();
    GlobalRenderer->Print("Masaustu");
}
