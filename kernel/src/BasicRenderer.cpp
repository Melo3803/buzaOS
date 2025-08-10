#include "BasicRenderer.h"
#include <cstdint>

BasicRenderer::BasicRenderer(Framebuffer* targetFramebuffer, PSF1_FONT* psf1_Font)
{
    TargetFramebuffer = targetFramebuffer;
    PSF1_Font = psf1_Font;
    Colour = 0xffffffff;
    CursorPosition = {0, 0};
}

void BasicRenderer::Print(const char* str)
{
    
    char* chr = (char*)str;
    while(*chr != 0){
        PutChar(*chr, CursorPosition.X, CursorPosition.Y);
        CursorPosition.X+=8;
        if(CursorPosition.X + 8 > TargetFramebuffer->Width)
        {
            CursorPosition.X = 0;
            CursorPosition.Y += 16;
        }
        chr++;
    }
}

void BasicRenderer::PutChar(char chr, unsigned int xOff, unsigned int yOff)
{
    unsigned int* pixPtr = (unsigned int*)TargetFramebuffer->BaseAddress;
    char* fontPtr = (char*)PSF1_Font->glyphBuffer + (chr * PSF1_Font->psf1_Header->charsize);
    for (unsigned long y = yOff; y < yOff + 16; y++){
        for (unsigned long x = xOff; x < xOff+8; x++){
            if ((*fontPtr & (0b10000000 >> (x - xOff))) > 0){
                    *(unsigned int*)(pixPtr + x + (y * TargetFramebuffer->PixelsPerScanLine)) = Colour;
                }

        }
        fontPtr++;
    }
}

void BasicRenderer::drawImage(const unsigned char* imageData, unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
    // Framebuffer'a erişim için (unsigned int* veya uint32_t* kullanabilirsiniz)
    unsigned int* pixPtr = (unsigned int*)TargetFramebuffer->BaseAddress;
    
    // DEĞİŞİKLİK: Her piksel artık 4 byte (RGBA)
    int bytesPerPixel = 4;

    for (unsigned int h = 0; h < height; h++) {
        for (unsigned int w = 0; w < width; w++) {
            
            unsigned int screenX = x + w;
            unsigned int screenY = y + h;

            // Ekran sınırlarını kontrol et
            if (screenX >= TargetFramebuffer->Width || screenY >= TargetFramebuffer->Height) {
                continue;
            }

            // Kaynak resimdeki pikselin indeksini hesapla
            int sourceIndex = (h * width + w) * bytesPerPixel;

            // DEĞİŞİKLİK: Renk kanallarını RGBA sırasıyla oku
            unsigned char r = imageData[sourceIndex + 0];
            unsigned char g = imageData[sourceIndex + 1];
            unsigned char b = imageData[sourceIndex + 2];
            unsigned char a = imageData[sourceIndex + 3];

            // YENİLİK: Eğer piksel tamamen saydamsa (alfa=0), o pikseli çizme, atla.
            // Bu, arka planın görünmesini sağlar.
            if (a == 0) {
                continue;
            }

            // DEĞİŞİKLİK: Renkleri birleştirirken Alfa kanalını resim verisinden al.
            // Framebuffer formatı: 0xAARRGGBB
            unsigned int pixelColor = (a << 24) | (r << 16) | (g << 8) | b;
            
            // Eğer resimdeki alfa değeri 255'ten küçükse (yarı saydamsa) ve
            // tam bir saydamlık efekti isteniyorsa burada "alpha blending" yapılmalıdır.
            // Şimdilik bunu basit tutarak sadece rengi doğrudan yazıyoruz.

            // Rengi framebuffer'a yaz
            *(pixPtr + screenX + (screenY * TargetFramebuffer->PixelsPerScanLine)) = pixelColor;
        }
    }
}