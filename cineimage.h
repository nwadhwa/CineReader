#ifndef __cineimage_h
#define __cineimage_h

#include "data.h"
#include "bitreader.h"
#include "bitmapinfoheader.h"
#include "cinefileheader.h"
#include <fstream>
#include <iostream>

class CINEIMAGE {
 public:
  CINEIMAGE(std::ifstream *input, long long imagePointer, const BITMAPINFOHEADER & bitmapheader);
  ~CINEIMAGE();
  
  

 private:
  DWORD AnnotationSize;
  BYTE *Annotation;
  DWORD ImageSize;
  bool is16bit;
  BYTE *im8;
  WORD *im16;
};


#endif
