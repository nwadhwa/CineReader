#ifndef __cineimage_h
#define __cineimage_h

#include <tiffio.h>
#include "data.h"
#include "bitreader.h"
#include "bitmapinfoheader.h"
#include "cinefileheader.h"
#include <fstream>
#include <iostream>
#include <string.h>

class CINEIMAGE {
 public:
  CINEIMAGE(std::ifstream *input, long long imagePointer, const BITMAPINFOHEADER & bitmapheader);
  ~CINEIMAGE();

  void saveToTIFF(char *filename);
  

 private:
  const BITMAPINFOHEADER *bmh;
  DWORD AnnotationSize;
  BYTE *Annotation;
  DWORD ImageSize;
  bool is16bit;
  int samplesPerPixel;
  BYTE *im8;
  WORD *im16;
};


#endif
