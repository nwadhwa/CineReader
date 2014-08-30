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
  INT FrameRate();
  WBGAIN whiteBalance();
  INT gamma();
  UINT exposure(); //in Nanonseconds

  
 private:
  std::ifstream *inputCine;
  CINEFILEHEADER *cineheader;
  BITMAPINFOHEADER *bitmapheader;
  IMAGEOFFSETS *pimage;


    
  
  
};
class exceptionCannotOpenFile : public std::exception {
  virtual const char * what() const throw() 
  {
    return "Cannot open file.";
  } 
};
#endif
