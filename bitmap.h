#ifndef BITMAP_H
#define BITMAP_H
#include "bmp_config.h"

typedef struct Pixel {
  unsigned char r, g, b;
} Pixel_t;

typedef struct BitMap {
  unsigned int width, height;
  BMP_CONFIG_T *bmp_config;
  Pixel_t **map;
} BitMap_t;

BitMap_t *createBitMap(FILE *image, BMP_CONFIG_T *bmp_config);
Pixel_t *createPixel(FILE *image, long offset);
void hydrateBitMap(BitMap_t *bitmap, FILE *image);
void printBitmap(BitMap_t *bitmap);

#endif
