#include "imageoffsets.h"

IMAGEOFFSETS::IMAGEOFFSETS(std::ifstream *input, const CINEFILEHEADER & header) {
  pImage = new long long[header.getImageCount()];
  bitreader br(input);
  br.seekToByte(header.getOffImageOffsets());
  for (int k = 0; k < header.getImageCount(); k++ ) {    
    pImage[k] = br.readint64();
  }
}



long long IMAGEOFFSETS::getPointer(int imageNo) {
  return pImage[imageNo];
}
