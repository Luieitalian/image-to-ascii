#include "bmp_config.h"
#include <stdio.h>
#include <stdlib.h>

#define BMP_WIDTH_OFFSET 0x12
#define BMP_HEIGHT_OFFSET 0x16
#define BMP_DATA_OFFSET 0xA
#define BMP_BITS_PER_PIXEL 0x1C

typedef struct Pixel {
  int r, g, b, a;
} Pixel_t;

typedef struct BitMap {
  Pixel_t **map;
} BitMap_t;

BitMap_t *createBitMap(FILE *image, int width, int height) {
  BitMap_t *bitmap = (BitMap_t *)malloc(sizeof(BitMap_t));

  for (int i = 0; i < height; i++) {
    bitmap->map[i] = (Pixel_t *)malloc(sizeof(Pixel_t) * width);
  }

  return 0;
}

Pixel_t *createPixel(FILE *image, long offset) {
  Pixel_t *p = (Pixel_t *)malloc(sizeof(Pixel_t));

  fseek(image, offset, SEEK_SET);
  printf("offset: %02lxh ", offset);
  p->b = fgetc(image);
  p->g = fgetc(image);
  p->r = fgetc(image);

  return p;
}

void printPixel(Pixel_t *pixel) {
  fflush(stdout);
  printf("(%d %d %d)\n", pixel->r, pixel->g, pixel->b);
}

void printRow(FILE *image, int width, long data_offset, int pixel_offset) {
  for (int i = 0; i < width; i++) {
    Pixel_t *pixel = createPixel(image, data_offset);
    printPixel(pixel);
    data_offset += pixel_offset;
    free(pixel);
  }
}

void printImage(FILE *image, int width, int height, long data_offset,
                int pixel_offset) {
  int padding = width % 4;

  for (int i = 0; i < height; i++) {
    printRow(image, width, data_offset + (i * pixel_offset * width),
             pixel_offset);
    data_offset += padding;
    printf("\n");
  }
}

void printImagev2(FILE *image, int width, int height, long data_offset) {}

int main() {

  FILE *image = fopen("example3.bmp", "r");
  int img_width, img_height, img_pixel_offset;
  long img_data_offset;

  fseek(image, BMP_WIDTH_OFFSET,
        SEEK_SET); // Get width of the bitmap in terms of pixels
  img_width = fgetc(image);
  fseek(image, BMP_HEIGHT_OFFSET,
        SEEK_SET); // Get height of the bitmap in terms of pixels
  img_height = fgetc(image);

  fseek(image, BMP_DATA_OFFSET, SEEK_SET);
  img_data_offset = fgetc(image);

  fseek(image, BMP_BITS_PER_PIXEL, SEEK_SET);
  img_pixel_offset = fgetc(image) / 8;

  // fseek(image, 0x46, SEEK_SET);
  // printf("%d\n", fgetc(image));

  printImage(image, img_width, img_height, img_data_offset, img_pixel_offset);
  return 0;
}
