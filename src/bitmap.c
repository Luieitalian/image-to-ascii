#include "../include/bitmap.h"
#include <stdio.h>

BitMap_t *createBitMap_t_3(FILE *image, BMP_CONFIG_T *bmp_config) {
  BitMap_t *bitmap = (BitMap_t *)malloc(sizeof(BitMap_t));
  bitmap->bmp_config = bmp_config;

  bitmap->map =
      (Pixel_t **)malloc(sizeof(Pixel_t *) * bitmap->bmp_config->height);

  for (unsigned int i = 0; i < bitmap->bmp_config->height; i++) {
    bitmap->map[i] =
        (Pixel_t *)malloc(sizeof(Pixel_t) * bitmap->bmp_config->width);
  }

  hydrateBitMap(bitmap, image);

  return bitmap;
}

void hydrateBitMap(BitMap_t *bitmap, FILE *image) {
  fseek(image, bitmap->bmp_config->bits_per_pixel_offset, SEEK_SET);
  unsigned int padding = ((fgetc(image) / 8) * bitmap->bmp_config->width) % 4;

  fseek(image, bitmap->bmp_config->data_offset, SEEK_SET);
  for (unsigned int i = 0; i < bitmap->bmp_config->height; i++) {
    for (unsigned int j = 0; j < bitmap->bmp_config->width; j++) {
      Pixel_t new_pixel;

      new_pixel.b = (unsigned char)fgetc(image);
      new_pixel.g = (unsigned char)fgetc(image);
      new_pixel.r = (unsigned char)fgetc(image);

      bitmap->map[i][j] = new_pixel;
    }
    fseek(image, padding, SEEK_CUR);
  }
}

void printBitMap(BitMap_t *bitmap) {
  for (long i = bitmap->bmp_config->height - 1; i >= 0; i--) {
    printf("-- \n\n-- ");
    for (long j = 0; j < bitmap->bmp_config->width; j++) {
      printf("(%d, %d, %d) ", bitmap->map[i][j].r, bitmap->map[i][j].g,
             bitmap->map[i][j].b);
    }
  }
}


void freeBitmap() {

}