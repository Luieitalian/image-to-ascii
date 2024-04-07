#ifndef BMP_CONFIG_H
#define BMP_CONFIG_H
#include <stdio.h>
#include <stdlib.h>

typedef enum BMP_DIB_TYPE { BITMAPINFOHEADER, BITMAPV5HEADER} BMP_DIB_TYPE_T;

typedef struct BMP_CONFIG {
  unsigned int width;
  unsigned int height;
  unsigned int pixel_offset;
  unsigned int data_offset;
  unsigned int bits_per_pixel_offset;
} BMP_CONFIG_T;

BMP_CONFIG_T *createEmptyBMPConfig();
BMP_CONFIG_T *createBMPConfig(FILE* image);
unsigned int detectDIBType(FILE *image);

#endif