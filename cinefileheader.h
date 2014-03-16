#ifndef __cinefileheader_h
#define __cinefileheader_h

#include "data.h"
#include "bitreader.h"
#include <fstream>
#include <iostream>
#include <exception>

#define CC_RGB 0 // Gray cines
#define CC_JPEG 1 // Jpeg compressed cines
#define CC_UNINT 2 // uninterpolated color images


class CINEFILEHEADER {
 public:
  CINEFILEHEADER(std::ifstream *input); 

  WORD getType() const {return Type;}
  WORD getHeadersize() const {return Headersize; }
  WORD getCompression() const  {return Compression;}
  WORD getVersion() const {return Version;}
  LONG getFirstMovieImage() const {return FirstMovieImage;}
  DWORD getTotalImageCount() const {return TotalImageCount;}
  LONG getFirstImageNo() const {return FirstImageNo;}
  DWORD getImageCount() const {return ImageCount;}
  DWORD getOffImageHeader() const {return OffImageHeader;}
  DWORD getOffSetup() const {return OffSetup;}
  DWORD getOffImageOffsets() const {return OffImageOffsets;}
  TIME64 getTriggerTime() const {return TriggerTime;}



 private:
  WORD Type; // must be "CI"
  WORD Headersize; // size of header in bytes
  WORD Compression; // one of CC_RGB, CC_JPEG, CC_UNINT
  WORD Version;
  LONG FirstMovieImage; // first recorded image number
  DWORD TotalImageCount; // total count of imges, recorded in camera memory
  LONG FirstImageNo; //first image saved to this file, relative to trigger
  DWORD ImageCount; //count of image saved to this file
  DWORD OffImageHeader; //offset of BITMAPINFOHEADER
  DWORD OffSetup; //offset of setup structure
  DWORD OffImageOffsets; //offset in the cinef ile of an array with the positions of each image
  TIME64 TriggerTime; // Trigger Time
  
};


std::ostream& operator<<(std::ostream& os, const CINEFILEHEADER &cineheader);


class exceptionNotCine : public std::exception {
  virtual const char * what() const throw() 
  {
    return "File is not a CINE file";
  } 
};

#endif
