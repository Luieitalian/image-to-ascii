#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include "bitmap.h"
#include <math.h>
#include <stdlib.h>

#define gscale " .:-=+*#%@"

typedef struct Brightness_Matrix {
  unsigned short **matrix;
  unsigned int width;
  unsigned int height;
} Brightness_Matrix_t;

unsigned short calcBrightness(Pixel_t *pixel);
Brightness_Matrix_t *getBrightness_Matrix(BitMap_t *bitmap);
void printBrightness_Matrix(Brightness_Matrix_t *br_matrix);
void freeBrightness_Matrix(Brightness_Matrix_t *br_matrix);

#endif