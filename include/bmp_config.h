#ifndef BMP_CONFIG_H
#define BMP_CONFIG_H
#include <stdio.h>
#include <stdlib.h>

typedef struct BMP_CONFIG {
  unsigned int width;
  unsigned int height;
  unsigned int pixel_offset;
  unsigned int data_offset;
  unsigned int bits_per_pixel_offset;
} BMP_CONFIG_T;

BMP_CONFIG_T *createBMPConfig(FILE *image);
void freeBMPConfig(BMP_CONFIG_T *config);

#endif