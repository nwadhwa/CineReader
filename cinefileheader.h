#ifndef __cinefileheader_h
#define __cinefileheader_h

#include "data.h"

#define CC_RGB 0 // Gray cines
#define CC_JPEG 1 // Jpeg compressed cines
#define CC_UNINT 2 // uninterpolated color images


class CINEFILEHEADER {
 public:
  WORD getType() {return Type;}
  WORD getHeadersize() {return Headersize; }
  WORD getCompression() {return Compression;}
  WORD getVersion() {return Version;}
  LONG getFirstMovieImage() {return FirstMovieImage;}
  DWORD getTotalImageCount() {return TotalImageCount;}
  LONG getFirstImageNo() {return FirstImageNo;}
  DWORD getImageCount() {return ImageCount;}
  DWORD getOffImageHeader() {return OffImageHeader;}
  DWORD getOffSetup() {return OffSetup;}
  DWORD getOffImageOffsets() {return OffImageOffsets;}
  TIME64 getTriggerTime() {return TriggerTime;}

  void readCineFileHeader(char * data); 

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

#endif
