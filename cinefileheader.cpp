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


}

