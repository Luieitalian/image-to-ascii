#include "bitmap.h"
#include <stdio.h>
#include <stdlib.h>

BitMap_t *createBitMap(FILE *image, BMP_CONFIG_T *bmp_config) {
  BitMap_t *bitmap = (BitMap_t *)malloc(sizeof(BitMap_t));
  bitmap->bmp_config = bmp_config;

  fseek(image, bitmap->bmp_config->width_offset,
        SEEK_SET); // Get width of the bitmap in terms of pixels
  bitmap->width = fgetc(image);
  fseek(image, bitmap->bmp_config->height_offset,
        SEEK_SET); // Get height of the bitmap in terms of pixels
  bitmap->height = fgetc(image);

  bitmap->map = (Pixel_t **)malloc(sizeof(Pixel_t *) * bitmap->height);

  for (unsigned int i = 0; i < bitmap->height; i++) {
    bitmap->map[i] = (Pixel_t *)malloc(sizeof(Pixel_t) * bitmap->width);
  }

  hydrateBitMap(bitmap, image);

  // TODO
  return bitmap;
}

void hydrateBitMap(BitMap_t *bitmap, FILE *image) {
  fseek(image, bitmap->bmp_config->data_offset, SEEK_SET);
  for (unsigned int i = 0; i < bitmap->height; i++) {
    for (unsigned int j = 0; j < bitmap->width; j++) {
      Pixel_t new_pixel;

      new_pixel.b = fgetc(image);
      new_pixel.g = fgetc(image);
      new_pixel.r = fgetc(image);
      printf("i: %d; j: %d\n", i, j);
      bitmap->map[i][j] = new_pixel;
    }
    fseek(image, bitmap->bmp_config->optional_padding, SEEK_CUR);
  }
}

Pixel_t *createPixel(FILE *image, long offset) {
  Pixel_t *p = (Pixel_t *)malloc(sizeof(Pixel_t));

  fseek(image, offset, SEEK_SET);
  printf("offset: %02lxh ", offset);
  p->b = fgetc(image);
  p->g = fgetc(image);
  p->r = fgetc(image);

  return p;
}
void printBitmap(BitMap_t *bitmap) {}