#include "ascii_matrix.h"
#include <stdlib.h>

char convertToASCII(int brightness) {
  char ascii = gscale[(int)(brightness * 9.5f) / 255];
  return ascii;
}

ASCII_Matrix_t *getASCII_Matrix(Brightness_Matrix_t *br_matrix) {
  ASCII_Matrix_t *ascii_matrix =
      (ASCII_Matrix_t *)malloc(sizeof(ASCII_Matrix_t));

  ascii_matrix->width = br_matrix->width;
  ascii_matrix->height = br_matrix->height;

  ascii_matrix->matrix = (char **)malloc(sizeof(char *) * ascii_matrix->height);

  for (unsigned int i = 0; i < ascii_matrix->height; i++) {
    ascii_matrix->matrix[i] =
        (char *)malloc(sizeof(char) * ascii_matrix->width);
  }

  for (unsigned int i = 0; i < ascii_matrix->height; i++) {
    for (unsigned int j = 0; j < ascii_matrix->width; j++) {
      char ascii = convertToASCII(br_matrix->matrix[i][j]);
      ascii_matrix->matrix[i][j] = ascii;
    }
  }

  return ascii_matrix;
}

void printASCII_Matrix(ASCII_Matrix_t *ascii_matrix) {
  for (long i = ascii_matrix->height - 1; i >= 0; i--) {
    printf("-- \n\n-- ");
    for (long j = 0; j < ascii_matrix->width; j++) {
      for (short k = 0; k < ascii_matrix->height / 40; k++) {
        printf("%c", ascii_matrix->matrix[i][j]);
      }
    }
  }
}