#include "bitreader.h"

#define debug 0

BYTE bitreader::readBYTE() 
{
  BYTE out;
  input->read((char *) &out, sizeof(BYTE));  
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}



CHAR  bitreader::readCHAR() {
  CHAR out;
  input->read((char *) &out, sizeof(CHAR));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}

WORD  bitreader::readWORD() {
  WORD out;
  input->read((char *) &out, sizeof(WORD));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}

INT16 bitreader::readINT16() {
  INT16 out;
  input->read((char *) &out, sizeof(INT16));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}

SHORT bitreader::readSHORT() {
  SHORT out;
  input->read((char *) &out, sizeof(SHORT));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}

BOOL bitreader::readBOOL() {
  BOOL out;
  input->read((char *) &out, sizeof(BOOL));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}

DWORD bitreader::readDWORD() {
  DWORD out;
  input->read((char *) &out, sizeof(DWORD));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}

UINT bitreader::readUINT() {
  UINT out;
  input->read((char *) &out, sizeof(UINT));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}

LONG bitreader::readLONG() {
  LONG out;
  input->read((char *) &out, sizeof(LONG));
  return out;
}

INT bitreader::readINT() {
  INT out;
  input->read((char *) &out, sizeof(INT));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}

FLOAT bitreader::readFLOAT() {
  FLOAT out;
  input->read((char *) &out, sizeof(FLOAT));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}
DOUBLE bitreader::readDOUBLE() {
  DOUBLE out;
  input->read((char *) &out, sizeof(DOUBLE));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}
int64_t bitreader::readint64() {
  int64_t out;
  input->read((char *) &out, sizeof(int64_t));
  return out;
}

TIME64 bitreader::readTIME64() {
  TIME64 out;
  input->read((char *) &out, sizeof(TIME64));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}

IMFILTER bitreader::readIMFILTER() {
  IMFILTER out;
  input->read((char *) &out, sizeof(IMFILTER));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}

WBGAIN bitreader::readWBGAIN() {
  WBGAIN out;
  input->read((char *) &out, sizeof(WBGAIN));
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}

STRING bitreader::readZeroTerminatedSTRING() {
  STRING out = "";
  char c = 1;
  while( c != 0) {
    c = input->get();
    out.append(1, c);
  }

  if (debug) 
    std::cout << (int) input->tellg() << std::endl;
  return out;
}

STRING bitreader::readLengthNSTRING(int N) {
  STRING out = "";
  char c = 1;
  for (int k = 0; k < N; k++) {
    c = input->get();
    out.append(1,c);
  }
  if (debug) 
    std::cout << input->tellg() << std::endl;
  return out;
}

void bitreader::seekToByte(int64_t g) {
  input->seekg(g);
}





//STRING readSTRING();
