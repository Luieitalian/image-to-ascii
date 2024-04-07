#include "ascii_matrix.h"
#include "bitmap.h"
#include "brightness.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

  char filename[30] = "bmps/";
  strcat(filename, argv[1]);

  BitMap_3_t *bitmap_3;
  FILE *image = fopen(filename, "rb");
  BMP_CONFIG_T *bmp_config = createBMPConfig(image);

  // fseek(image, 0xE, SEEK_SET);
  // printf("%d", fgetc(image));

  bitmap_3 = createBitMap_3(image, bmp_config);
  Brightness_Matrix_t *br_matrix = getBrightness_Matrix(bitmap_3);
  //printBitMap_3(bitmap_3);
  ASCII_Matrix_t *ascii_matrix = getASCII_Matrix(br_matrix);
  printASCII_Matrix(ascii_matrix);
  return 0;
}
