#include "bmp_config.h"
#include <stdio.h>

BMP_CONFIG_T *createEmptyBMPConfig() {
  BMP_CONFIG_T *new_config = (BMP_CONFIG_T *)malloc(sizeof(BMP_CONFIG_T));

  new_config->width = 0;
  new_config->height = 0;
  new_config->pixel_offset = 0;
  new_config->data_offset = 0;
  new_config->bits_per_pixel_offset = 0;

  return new_config;
}

BMP_CONFIG_T *createBMPConfig(FILE *image) {
  BMP_CONFIG_T *new_config = (BMP_CONFIG_T *)malloc(sizeof(BMP_CONFIG_T));

  switch (detectDIBType(image)) {
  case 0: // BITMAPINFOHEADER
    new_config->pixel_offset = 0x3;
    new_config->data_offset = 0xE + 40;
    new_config->bits_per_pixel_offset = 0x1C;

    fseek(image, 0x12, SEEK_SET);
    new_config->width = fgetc(image);

    fseek(image, 0x16, SEEK_SET);
    new_config->height = fgetc(image);
    break;

  case 1: // BITMAPV5HEADER
    new_config->pixel_offset = 0x4;
    new_config->data_offset = 0xE + 124;
    new_config->bits_per_pixel_offset = 0x1C;

    fseek(image, 0x12, SEEK_SET);
    new_config->width = fgetc(image);

    fseek(image, 0x16, SEEK_SET);
    new_config->height = fgetc(image);
    break;
  }

  return new_config;
}

unsigned int detectDIBType(FILE *image) {
  fseek(image, 0xE, SEEK_SET);
  unsigned int data_offset = fgetc(image);
  switch (data_offset) {
  case 124:
    return 1; // BITMAPV5HEADER
    break;
  case 40:
    return 0; // BITMAPINFOHEADER
    break;
  default:
    return 0;
    break;
  }
}