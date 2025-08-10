#pragma once
#include "math.h"
#include "Framebuffer.h"
#include "simpleFonts.h"

class BasicRenderer{
    public:
    BasicRenderer(Framebuffer* targetFramebuffer, PSF1_FONT* psf1_Font);
    Point CursorPosition;
    Framebuffer* TargetFramebuffer;
    PSF1_FONT* PSF1_Font;
    unsigned int Colour;
    void Print(const char* str);
    void PutChar(char chr, unsigned int xOff, unsigned int yOff);

    void drawImage(const unsigned char* imageData, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

};