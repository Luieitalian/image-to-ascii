#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include "bitmap.h"
#include <math.h>
#include <stdlib.h>

#define gscale " .:-=+*#%@"
#define gscale2 "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~i!lI;:,\"^`\". "

typedef struct Brightness_Matrix {
  int **matrix;
  unsigned int width;
  unsigned int height;
} Brightness_Matrix_t;

int calcBrightness(Pixel_t *pixel);
Brightness_Matrix_t *getBrightness_Matrix(BitMap_t *bitmap);
void printBrightness_Matrix(Brightness_Matrix_t *br_matrix);

#endif