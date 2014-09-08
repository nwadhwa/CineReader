#include "cinereader.h"


CineReader::CineReader(char *filename) {
  inputCine = new std::ifstream(filename, std::ios::in|std::ios::binary);
  if (!inputCine) {
    throw exceptionCannotOpenFile();
  }
  cineheader = new CINEFILEHEADER(inputCine);
  bitmapheader = new BITMAPINFOHEADER(inputCine, *cineheader);
  setup = new SETUP(inputCine, *cineheader);
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

UINT CineReader::FrameRate() {
  return setup->getFrameRate();
  
  
}

FLOAT CineReader::whiteBalanceRed() {
  return setup->getWBGain(0).R;
}

FLOAT CineReader::whiteBalanceBlue() { 
  return setup->getWBGain(0).B;
}


INT CineReader::brightness() {
  return setup->getBright();
}

INT CineReader::contrast() {
  return setup->getContrast();
}

FLOAT CineReader::gain() {
  return setup->getfGain();
}

FLOAT CineReader::gamma() {
  return setup->getfGamma();
}

BOOL CineReader::flipH() {
  return setup->getbFlipH();
}

BOOL CineReader::flipV() {
  return setup->getbFlipV();
}

INT CineReader::rotate() {
  return setup->getRotate();
}

UINT CineReader::exposure() {
  return setup->getShutter();
}

UINT CineReader::colorFilterArrayPattern() {
  return setup->getCFA();
}

CineReader::~CineReader() {
  inputCine->close();
  delete(inputCine);
  delete(cineheader);
  delete(bitmapheader);
  delete(pimage);
  

}


