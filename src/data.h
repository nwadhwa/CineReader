#ifndef __data_h
#define __data_h

#include <string>
#include <iostream>
#include <stdint.h>

typedef uint8_t BYTE;
typedef signed char CHAR;
typedef uint16_t  WORD;
typedef int16_t INT16;
typedef int16_t SHORT;
typedef int32_t BOOL;
typedef uint32_t DWORD;
typedef uint32_t UINT;
typedef int32_t LONG;
typedef int32_t INT;
typedef float FLOAT;
typedef double DOUBLE;
typedef std::string STRING;

class TIME64 {
 public:
  DWORD Fractions; // Fractions of second, divide by 2^32 to convert to seconds
  DWORD Seconds; // Seconds since Jan 1, 1970

  TIME64() {}
};
/*
std::ostream& operator<<(std::ostream& os, TIME64 &dt) {
  os << dt.Seconds << "," <<  dt.Fractions << std::endl;
  return os;
}
*/
class IMFILTER { //structure to define a convolution filter
 public:
  INT Dim; //square kernel dimension
  INT Shifts; //not sure about this one
  INT Bias; // or this one
  INT Coef[25]; //coefficinets of kernel

  IMFILTER() {}
};

class WBGAIN {
 public:
  FLOAT R; //gain correction for red
  FLOAT B; //gain correction for blue
};





#endif
