#include "cinefileheader.h"

// This function will take as an input the cine file reader and fill in all the fields of the cinefileheader
CINEFILEHEADER::CINEFILEHEADER(std::ifstream *input) {
  bitreader br(input);
  Type = br.readWORD();
  // Verify that it is a cine file
  if (Type != 18755) {
    throw (exceptionNotCine());
  }
  Headersize = br.readWORD();
  Compression = br.readWORD();
  Version = br.readWORD();
  FirstMovieImage = br.readLONG();
  TotalImageCount = br.readDWORD();
  FirstImageNo = br.readLONG();
  ImageCount = br.readDWORD();
  OffImageHeader = br.readDWORD();
  OffSetup = br.readDWORD();
  OffImageOffsets = br.readDWORD();
  TriggerTime = br.readTIME64();
}

std::ostream& operator<<(std::ostream& os, const CINEFILEHEADER &cineheader) {
  os << "HeaderSize: " << cineheader.getHeadersize() << std::endl;
  os << "Compression: " << cineheader.getHeadersize() << std::endl;
  os << "Version: " << cineheader.getVersion() << std::endl;
  os << "First Movie Image: " << cineheader.getFirstMovieImage() << std::endl;
  os << "Total Image Count: " << cineheader.getTotalImageCount() << std::endl;
  os << "First Image No.: " << cineheader.getFirstImageNo() << std::endl;
  os << "Image Count: " << cineheader.getImageCount() << std::endl;
  os << "Off Image Header: " << cineheader.getOffImageHeader() << std::endl;
  os << "Off Setup: " << cineheader.getOffSetup() << std::endl;
  os << "Off ImageOffsets: " << cineheader.getOffImageOffsets() << std::endl;
  //  os << "Trigger Time: " << cineheader.getTriggerTime() << std::endl;

  return os;
    

}
