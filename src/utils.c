#include "../include/utils.h"

void openBMP(char *filename) {

  FILE *image = fopen(filename, "rb");
  BMP_CONFIG_T *bmp_config = createBMPConfig(image);

  BitMap_t *bitmap = createBitMap(image, bmp_config);
  Brightness_Matrix_t *br_matrix = getBrightness_Matrix(bitmap);
  ASCII_Matrix_t *ascii_matrix = getASCII_Matrix(br_matrix);

  printASCII_Matrix(ascii_matrix);

  freeASCII_Matrix(ascii_matrix);
  freeBrightness_Matrix(br_matrix);
  freeBitmap(bitmap);
}