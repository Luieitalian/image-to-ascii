#include <stdio.h>

#define BMP_WIDTH_OFFSET 0x12
#define BMP_HEIGHT_OFFSET 0x16

int main() {

  FILE *image = fopen("example.bmp", "r");
  int c = 0;

  fseek(image, BMP_WIDTH_OFFSET, SEEK_SET); // Get width of the bitmap in terms of pixels
  int img_width = fgetc(image);
  fseek(image, BMP_HEIGHT_OFFSET, SEEK_SET); // Get height of the bitmap in terms of pixels
  int img_height = fgetc(image);

  printf("Width: %dpx\n", img_width);
  printf("Height: %dpx\n", img_height);

  fseek(image, 0xE, SEEK_SET); // start of the data E + 7C
  printf("%d\n", fgetc(image));
  
  

  return 0;
}