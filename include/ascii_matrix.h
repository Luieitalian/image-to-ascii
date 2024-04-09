#ifndef ASCII_MATRIX_H
#define ASCII_MATRIX_H

#include "brightness.h"

typedef struct ASCII_Matrix {
  char **matrix;
  unsigned int width;
  unsigned int height;
} ASCII_Matrix_t;

char convertToASCII(unsigned short brightness);
ASCII_Matrix_t *getASCII_Matrix(Brightness_Matrix_t *br_matrix);
void printASCII_Matrix(ASCII_Matrix_t *ascii_matrix);
void freeASCII_Matrix(ASCII_Matrix_t *ascii_matrix);

#endif