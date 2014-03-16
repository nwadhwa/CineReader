#include "bitreader.h"


BYTE bitreader::readBYTE() 
{
  int sz = 1;
  char buff[sz];
  input->read(buff, sz);
  BYTE out = (BYTE) buff[0];
  return out;
}



CHAR  bitreader::readCHAR() {
  int sz = 1;
  char buff[sz];
  input->read(buff, sz);
  CHAR out = (CHAR) buff[0];
  return out;
}

WORD  bitreader::readWORD() {
  int sz = 2;
  char buff[sz];
  input->read(buff, sz);
  WORD out = (WORD) buff[0];
  return out;
}

INT16 bitreader::readINT16() {
  int sz = 2;
  char buff[sz];
  input->read(buff, sz);
  INT16 out = (INT16) buff[0];
  return out;
}

SHORT bitreader::readSHORT() {
  int sz = 2;
  char buff[sz];
  input->read(buff, sz);
  SHORT out = (SHORT) buff[0];
  return out;
}

BOOL bitreader::readBOOL() {
  int sz = 4;
  char buff[sz];
  input->read(buff, sz);
  BOOL out = (BOOL) buff[0];
  return out;
}

DWORD bitreader::readDWORD() {
  int sz = 4;
  char buff[sz];
  input->read(buff, sz);
  DWORD out = (DWORD) buff[0];
  return out;
}

UINT bitreader::readUINT() {
  int sz = 4;
  char buff[sz];
  input->read(buff, sz);
  UINT out = (UINT) buff[0];
  return out;
}

LONG bitreader::readLONG() {
  int sz = 4;
  char buff[sz];
  input->read(buff, sz);
  LONG out = (LONG) buff[0];
  return out;
}

INT bitreader::readINT() {
  int sz = 4;
  char buff[sz];
  input->read(buff, sz);
  INT out = (INT) buff[0];
  return out;
}

FLOAT bitreader::readFLOAT() {
  int sz = 4;
  char buff[sz];
  input->read(buff, sz);
  FLOAT out = (FLOAT) buff[0];
  return out;
}
DOUBLE bitreader::readDOUBLE() {
  int sz = 8;
  char buff[sz];
  input->read(buff, sz);
  DOUBLE out = (DOUBLE) buff[0];
  return out;
}

//STRING readSTRING();
