#include "image_renderer.h"

// degisim void -> int oldu artik
int draw_image(
    Framebuffer* framebuffer,
    unsigned int x_pos, 
    unsigned int y_pos, 
    unsigned int width, 
    unsigned int height,
    unsigned char* image_data
) {
  //gecerlilik kontrolu
      if (framebuffer == 0 || framebuffer->BaseAddress == 0) {
        return -1;
    }
    if (image_data == 0) {
        return -2;
    }
    unsigned int* pix_ptr = (unsigned int*)framebuffer->BaseAddress;
    
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            
            unsigned int screen_x = x_pos + x;
            unsigned int screen_y = y_pos + y;

            if (screen_x >= framebuffer->Width || screen_y >= framebuffer->Height) {
                continue;
            }

            unsigned char r = image_data[(y * width + x) * 4 + 0];
            unsigned char g = image_data[(y * width + x) * 4 + 1];
            unsigned char b = image_data[(y * width + x) * 4 + 2];
           
            unsigned int color = (b << 16) | (g << 8) | r;
            
            *(pix_ptr + screen_x + (screen_y * framebuffer->PixelsPerScanLine)) = color;
        }
    }

    return 0;
}