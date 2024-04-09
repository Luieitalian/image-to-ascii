#include "../include/bmp_config.h"
#include <stdio.h>
#include <stdlib.h>

BMP_CONFIG_T *createBMPConfig(FILE *image) {
  BMP_CONFIG_T *new_config = (BMP_CONFIG_T *)malloc(sizeof(BMP_CONFIG_T));

  // BITMAPINFOHEADER
  new_config->pixel_offset = 0x3;
  new_config->data_offset = 0xE + 40;
  new_config->bits_per_pixel_offset = 0x1C;

  fseek(image, 0x12, SEEK_SET);
  new_config->width = fgetc(image);

  fseek(image, 0x16, SEEK_SET);
  new_config->height = fgetc(image);

  return new_config;
}

void freeBMPConfig(BMP_CONFIG_T *config) {
  free(config);
  config = NULL;
}