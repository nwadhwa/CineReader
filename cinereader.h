#ifndef __cinereader_h
#define __cinereader_h

#include "cinefileheader.h"
#include "bitmapinfoheader.h"
#include "data.h"
#include "imageoffsets.h"
#include "cineimage.h"
#include <fstream>

class CineReader {
 public:
  CineReader(char * filename);
  ~CineReader();
  CINEIMAGE read(int frame);
  DWORD NumberOfFrames();
  LONG width();
  LONG height();

  
 private:
  std::ifstream *inputCine;
  CINEFILEHEADER *cineheader;
  BITMAPINFOHEADER *bitmapheader;
  IMAGEOFFSETS *pimage;


    
  
  
};

#endif
