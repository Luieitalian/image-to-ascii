#include "../include/brightness.h"
#include <stdio.h>
#include <stdlib.h>

unsigned short calcBrightness(Pixel_t *pixel) {
  float average;
  average = (float)(pixel->r + pixel->g + pixel->b) / 3.0f;
  return floorf(average);
}

Brightness_Matrix_t *getBrightness_Matrix(BitMap_t *bitmap) {
  Brightness_Matrix_t *br_matrix =
      (Brightness_Matrix_t *)malloc(sizeof(Brightness_Matrix_t));
  br_matrix->width = bitmap->bmp_config->width;
  br_matrix->height = bitmap->bmp_config->height;

  br_matrix->matrix =
      (unsigned short **)malloc(sizeof(unsigned short *) * br_matrix->height);

  for (unsigned int i = 0; i < br_matrix->height; i++) {
    br_matrix->matrix[i] =
        (unsigned short *)malloc(sizeof(unsigned short) * br_matrix->width);
  }

  for (unsigned int i = 0; i < br_matrix->height; i++) {
    for (unsigned int j = 0; j < br_matrix->width; j++) {
      br_matrix->matrix[i][j] = calcBrightness(&bitmap->map[i][j]);
    }
  }
  return br_matrix;
}

void printBrightness_Matrix(Brightness_Matrix_t *br_matrix) {
  for (long i = br_matrix->height - 1; i >= 0; i--) {
    printf("-- \n\n-- ");
    for (long j = 0; j < br_matrix->width; j++) {
      printf("(%d) ", br_matrix->matrix[i][j]);
    }
  }
}

void freeBrightness_Matrix(Brightness_Matrix_t *br_matrix) {
  for (unsigned int i = 0; i < br_matrix->height; i++) {
    free(br_matrix->matrix[i]);
    br_matrix->matrix[i] = NULL;
  }
  free(br_matrix->matrix);
  br_matrix->matrix = NULL;
  free(br_matrix);
  br_matrix = NULL;
}