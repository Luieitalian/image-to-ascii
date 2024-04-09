#include "../include/utils.h"

void openBMP(char *filename) {

  BitMap_t *bitmap;
  FILE *image = fopen(filename, "rb");
  BMP_CONFIG_T *bmp_config = createBMPConfig(image);

  bitmap = createBitMap(image, bmp_config);
  Brightness_Matrix_t *br_matrix = getBrightness_Matrix(bitmap);

  ASCII_Matrix_t *ascii_matrix = getASCII_Matrix(br_matrix);
  printASCII_Matrix(ascii_matrix);
}