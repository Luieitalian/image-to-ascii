#ifndef BITMAP_H
#define BITMAP_H
#include "bmp_config.h"

typedef struct Pixel {
  unsigned char r, g, b;
} Pixel_t;

typedef struct BitMap {
  BMP_CONFIG_T *bmp_config;
  Pixel_t **map;
} BitMap_t;

BitMap_t *createBitMap(FILE *image, BMP_CONFIG_T *bmp_config);
void hydrateBitMap(BitMap_t *bitmap, FILE *image);
void printBitMap(BitMap_t *bitmap);
void freeBitmap(BitMap_t *bitmap);

#endif
