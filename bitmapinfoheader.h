#ifndef __bitmapinfoheader_h
#define __bigmapinfoheader_h

#include "data.h"
#include "bitreader.h"
#include "cinefileheader.h"
#include <fstream>
#include <iostream>

class BITMAPINFOHEADER {
 public:
  BITMAPINFOHEADER(std::ifstream *input, const CINEFILEHEADER & header);

  DWORD getbiSize() const {return biSize; }
  LONG getbiWidth() const {return biWidth;}
  LONG getbiHeight() const {return biHeight;}
  WORD getbiPlanes() const { return biPlanes; }
  WORD getbiBitCount() const {return biBitCount; }
  DWORD getbiCompression() const { return biCompression; }
  DWORD getbiSizeImage() const { return biSizeImage; }
  LONG getbiXPelsPerMeter() const { return biXPelsPerMeter; }
  LONG getbiYPelsPerMeter() const { return biYPelsPerMeter;}
  DWORD getbiClrUsed() const { return biClrUsed; }
  DWORD getbiClrImportant() const { return biClrImportant; }
 private:
  DWORD biSize;
  LONG biWidth;
  LONG biHeight;
  WORD biPlanes;
  WORD biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG biXPelsPerMeter;
  LONG biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
};

std::ostream& operator<<(std::ostream& os, const BITMAPINFOHEADER & bitmapheader);




#endif
