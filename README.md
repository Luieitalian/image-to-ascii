# I try to convert images to ascii-art using C.

### Contents

- [How To Use](#how-to)
- [Restrictions](#restrictions)
- [TODOs](#TODOs)

### How To
1. Compile & Link 	

```
make compile link
```
2. Run without the angle brackets
```
make run img=<imagename>
```

### TODOs

- [x] Grayscale
- [x] Creating bitmaps
- [ ] Support other raster image types
- [ ] Support image scaling
- [ ] Free memory after allocating

### Restrictions
- These restrictions are temporary.
- Program only accepts bmp format with less than 255 pixels for width and height.
- Program only accepts a certain bmp format which has the header type **BITMAPINFOHEADER** that is provided by Microsoft. (You can check your bmp file via checking the color depth. If it is 24 bit then it's the right header)
- Your image file has to be in the bmps folder for the program to run properly.