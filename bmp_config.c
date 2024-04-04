#include "bmp_config.h"

BMP_CONFIG_T *createEmptyBMPConfig() {
  BMP_CONFIG_T *new_config = (BMP_CONFIG_T *)malloc(sizeof(BMP_CONFIG_T));

  new_config->pixel_offset = 0;
  new_config->data_offset = 0;
  new_config->optional_padding = 0;
  new_config->width_offset = 0;
  new_config->height_offset = 0;
  new_config->bits_per_pixel_offset = 0;

  return new_config;
}

BMP_CONFIG_T *createBMPConfig(BMP_DIB_TYPE_T bmp_dib_type) {
  BMP_CONFIG_T *new_config = (BMP_CONFIG_T *)malloc(sizeof(BMP_CONFIG_T));

  switch (bmp_dib_type) {
  case 0: // BITMAPINFOHEADER
    new_config->pixel_offset = 0x3;
    new_config->data_offset = 0x36;
    new_config->optional_padding = 0x2;
    new_config->width_offset = 0x12;
    new_config->height_offset = 0x16;
    new_config->bits_per_pixel_offset = 0x1C;
    break;
  }

  return new_config;
}