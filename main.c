#include "bitmap.h"

int main() {
  FILE *image = fopen("bmps/example2.bmp", "r");
  BMP_CONFIG_T *bmp_config = createBMPConfig(0); // BITMAPINFOHEADER
  BitMap_t *bitmap = createBitMap(image, bmp_config);

  printBitMap(bitmap);
  free(bmp_config);

  return 0;
}
