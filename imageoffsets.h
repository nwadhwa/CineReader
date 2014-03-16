#ifndef __imageoffsets_h
#define __imageoffsets_h

#include "data.h"
#include "bitreader.h"
#include "cinefileheader.h"
#include <fstream>
#include <iostream>

class IMAGEOFFSETS {
 public:
  IMAGEOFFSETS(std::ifstream *input, const CINEFILEHEADER & header);
  ~IMAGEOFFSETS() {delete pImage;}
  
  long long getPointer(int imageNo);

 private:
  long long * pImage;

};


#endif
