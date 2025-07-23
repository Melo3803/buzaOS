#pragma once
#include "kernel.h" 

// düzeltme..
int draw_image(
    Framebuffer* framebuffer,
    unsigned int x_pos,
    unsigned int y_pos,
    unsigned int width,
    unsigned int height,
    unsigned char* image_data
);