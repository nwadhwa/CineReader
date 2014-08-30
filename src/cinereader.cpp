#include "cinereader.h"


CineReader::CineReader(char *filename) {
  inputCine = new std::ifstream(filename, std::ios::in|std::ios::binary);
  if (!inputCine) {
    throw exceptionCannotOpenFile();
  }
  cineheader = new CINEFILEHEADER(inputCine);
  bitmapheader = new BITMAPINFOHEADER(inputCine, *cineheader);
  pimage = new IMAGEOFFSETS(inputCine, *cineheader);
}

CINEIMAGE CineReader::read(int frame) {
  CINEIMAGE im(inputCine, pimage->getPointer(frame), *bitmapheader);
  return im;
}



DWORD CineReader::NumberOfFrames() {
  return cineheader->getImageCount();
}

LONG CineReader::width() {
  return bitmapheader->getbiWidth();
}

LONG CineReader::height() {
  return bitmapheader->getbiHeight();
}

CineReader::~CineReader() {
  inputCine->close();
  delete(inputCine);
  delete(cineheader);
  delete(bitmapheader);
  delete(pimage);
  

}


