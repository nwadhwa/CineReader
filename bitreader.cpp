#include "bitreader.h"


BYTE bitreader::readBYTE() 
{
  BYTE out;
  input->read((char *) &out, sizeof(BYTE));
  return out;
}



CHAR  bitreader::readCHAR() {
  CHAR out;
  input->read((char *) &out, sizeof(CHAR));
  return out;
}

WORD  bitreader::readWORD() {
  WORD out;
  input->read((char *) &out, sizeof(WORD));
  return out;
}

INT16 bitreader::readINT16() {
  INT16 out;
  input->read((char *) &out, sizeof(INT16));
  return out;
}

SHORT bitreader::readSHORT() {
  SHORT out;
  input->read((char *) &out, sizeof(SHORT));
  return out;
}

BOOL bitreader::readBOOL() {
  BOOL out;
  input->read((char *) &out, sizeof(BOOL));
  return out;
}

DWORD bitreader::readDWORD() {
  DWORD out;
  input->read((char *) &out, sizeof(DWORD));
  return out;
}

UINT bitreader::readUINT() {
  UINT out;
  input->read((char *) &out, sizeof(UINT));
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
  return out;
}

FLOAT bitreader::readFLOAT() {
  FLOAT out;
  input->read((char *) &out, sizeof(FLOAT));
  return out;
}
DOUBLE bitreader::readDOUBLE() {
  DOUBLE out;
  input->read((char *) &out, sizeof(DOUBLE));
  return out;
}

TIME64 bitreader::readTIME64() {
  TIME64 out;
  input->read((char *) &out, sizeof(TIME64));
  return out;
}

IMFILTER bitreader::readIMFILTER() {
  IMFILTER out;
  input->read((char *) &out, sizeof(IMFILTER));
  return out;
}

WBGAIN bitreader::readWBGAIN() {
  WBGAIN out;
  input->read((char *) &out, sizeof(WBGAIN));
  return out;
}



//STRING readSTRING();
