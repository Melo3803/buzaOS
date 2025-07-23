#include "kernel.h"
#include "image_renderer.h" 
#include "buza_image.h"   

Point CursorPosition;

void putChar(Framebuffer* framebuffer, PSF1_FONT* psf1_font, unsigned int colour, char chr, unsigned int xOff, unsigned int yOff)
{
    unsigned int* pixPtr = (unsigned int*)framebuffer->BaseAddress;
    char* fontPtr = psf1_font->glyphBuffer + (chr * psf1_font->psf1_Header->charsize);
    for (unsigned long y = yOff; y < yOff + 16; y++){
        for (unsigned long x = xOff; x < xOff+8; x++){
            if ((*fontPtr & (0b10000000 >> (x - xOff))) > 0){
                *(unsigned int*)(pixPtr + x + (y * framebuffer->PixelsPerScanLine)) = colour;
            }
        }
        fontPtr++;
    }
}

void Print(Framebuffer* framebuffer, PSF1_FONT* psf1_font, unsigned int colour, char* str)
{
    char* chr = str;
    while(*chr != 0){
        putChar(framebuffer, psf1_font, colour, *chr, CursorPosition.X, CursorPosition.Y);
        CursorPosition.X+=8;
        if(CursorPosition.X + 8 > framebuffer->Width)
        {
            CursorPosition.X = 0;
            CursorPosition.Y += 16;
        }
        chr++;
    }
}


void _start(Framebuffer* framebuffer, PSF1_FONT* psf1_font){
    CursorPosition.X = 50;
    CursorPosition.Y = 50; 
    Print(framebuffer, psf1_font, 0xffffffff, "Hello Buzakernel");

    
    unsigned int image_width = 147; 
    unsigned int image_height = 147;
    
   
    unsigned int margin = 20;
    unsigned int pos_x = framebuffer->Width - image_width - margin;
    unsigned int pos_y = margin;
    
    
    int result = draw_image(framebuffer, pos_x, pos_y, image_width, image_height, buza_rgba);

    CursorPosition.X = 50;
    CursorPosition.Y = pos_y + image_height + 32; 

    
    if (result == 0) {
        Print(framebuffer, psf1_font, 0x00ff00, "Resim cizildi"); //yesil
    } else {
        //buney
        Print(framebuffer, psf1_font, 0xff0000, "Resim cizilemedi"); 
    }

    return ;

}
