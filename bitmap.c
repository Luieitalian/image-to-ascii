#include "bitmap.h"
#include <stdio.h>

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

      bitmap->map[i][j] = new_pixel;
    }
    fseek(image, bitmap->bmp_config->optional_padding, SEEK_CUR);
  }
}

void printBitMap(BitMap_t *bitmap) {
  for (long i = bitmap->height - 1; i >= 0; i--) {
    for (long j = 0; j < bitmap->width; j++) {
      printf("(%d, %d, %d) ", bitmap->map[i][j].r, bitmap->map[i][j].g, bitmap->map[i][j].b);
    }
    printf("-- \n\n-- ");
  }
}
