#ifndef BMP_CONFIG
#define BMP_CONFIG

typedef enum BMP_CONFIGS { BITMAPINFOHEADER } BMP_CONFIGS_T;

typedef struct CONFIG {
  unsigned int pixel_offset;
  unsigned int data_offset;
  unsigned int optional_padding;
} CONFIG_T;

CONFIG_T createEmptyConfig();
CONFIG_T createConfig(BMP_CONFIGS_T);

#endif