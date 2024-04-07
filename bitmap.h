#ifndef BITMAP_H
#define BITMAP_H
#include "bmp_config.h"

typedef struct Pixel_3 {
  unsigned char r, g, b;
} Pixel_3_t;

typedef struct Pixel_4 {
  unsigned char r, g, b, a;
} Pixel_4_t;

typedef struct BitMap_3 {
  BMP_CONFIG_T *bmp_config;
  Pixel_3_t **map;
} BitMap_3_t;

typedef struct BitMap_4 {
  BMP_CONFIG_T *bmp_config;
  Pixel_4_t **map;
} BitMap_4_t;

BitMap_3_t *createBitMap_3(FILE *image, BMP_CONFIG_T *bmp_config);
BitMap_4_t *createBitMap_4(FILE *image, BMP_CONFIG_T *bmp_config);
void hydrateBitMap_3(BitMap_3_t *bitmap, FILE *image);
void hydrateBitMap_4(BitMap_4_t *bitmap, FILE *image);
void printBitMap_3(BitMap_3_t *bitmap);
void printBitMap_4(BitMap_4_t *bitmap);

#endif
