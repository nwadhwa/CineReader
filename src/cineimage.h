#ifndef __cineimage_h
#define __cineimage_h

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

  bool bit16() {return is16bit; }
  //void saveToTIFF(char *filename);
  BYTE* get8IM() { return im8;}
  WORD* get16IM() {return im16;}

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
