#include "../include/utils.h"
#include <string.h>

int main(int argc, char **argv) {

  char filename[30] = "bmps/";
  strcat(filename, argv[1]);

  openBMP(filename);

  return 0;
}
