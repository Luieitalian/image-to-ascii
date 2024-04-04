#include "bmp_config.h"

CONFIG_T createEmptyConfig() {
  CONFIG_T new_config;
  new_config.pixel_offset = 0;
  new_config.data_offset = 0;
  new_config.optional_padding = 0;
  return new_config;
}

CONFIG_T createConfig(BMP_CONFIGS_T bmp_config) {
  CONFIG_T new_config;

  switch (bmp_config) {
  case 0: // BITMAPINFOHEADER
    new_config.pixel_offset = 0x3;
    new_config.data_offset = 0x36;
    new_config.optional_padding = 0x2;
    break;
  }

  return new_config;
}