#ifndef BMP_CONFIG_H
#define BMP_CONFIG_H
#include <stdio.h>
#include <stdlib.h>

typedef enum BMP_DIB_TYPE { BITMAPINFOHEADER } BMP_DIB_TYPE_T;

typedef struct BMP_CONFIG {
  unsigned int width_offset;
  unsigned int height_offset;
  unsigned int pixel_offset;
  unsigned int data_offset;
  unsigned int optional_padding;
  unsigned int bits_per_pixel_offset;
} BMP_CONFIG_T;

BMP_CONFIG_T *createEmptyBMPConfig();
BMP_CONFIG_T *createBMPConfig(BMP_DIB_TYPE_T bmp_dib_type);

#endif