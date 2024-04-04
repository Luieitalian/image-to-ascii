#include "bitmap.h"

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

  for (int i = 0; i < height; i++) {
    printRow(image, width, data_offset + (i * pixel_offset * width),
             pixel_offset);
    data_offset += 0;
    printf("\n");
  }
}

int main() {
  FILE *image = fopen("bmps/example3.bmp", "r");
  BMP_CONFIG_T *bmp_config = createBMPConfig(0); // BITMAPINFOHEADER
  BitMap_t *bitmap = createBitMap(image, bmp_config);

  printf("width: %d\n", bitmap->width);
  printf("height: %d\n", bitmap->height);

  printf("bitmap[1][1]: (%d %d %d)\n", bitmap->map[1][1].r, bitmap->map[1][1].g,
         bitmap->map[1][1].b);

  free(bmp_config);

  return 0;
}
