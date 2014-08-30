#include "data.h"
#include "bitreader.h"
#include "cinefileheader.h"
#include "bitmapinfoheader.h"
#include "imageoffsets.h"
#include "cinereader.h"
#include "cineimage.h"
#include "setup.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

int main() {
  // Verify sizes of all datatypes in data.h
  BYTE m_byte;
  CHAR m_char;
  WORD m_word;
  INT16 m_int16;
  SHORT m_short;
  BOOL m_bool;
  DWORD m_dword;
  UINT m_uint;
  LONG m_long;
  INT m_int;
  FLOAT m_float;
  DOUBLE m_double;

  assert(sizeof(m_byte) == 1);
  assert(sizeof(m_char) == 1);

  assert(sizeof(m_word) == 2);
  assert(sizeof(m_int16) == 2);
  assert(sizeof(m_short) == 2);
  
  assert(sizeof(m_bool) == 4);
  assert(sizeof(m_dword) == 4);
  assert(sizeof(m_uint) == 4);
  assert(sizeof(m_int) == 4);
  assert(sizeof(m_long) == 4);
  assert(sizeof(m_float) == 4);

  assert(sizeof(m_double) == 8);

  cout << "All primitive data types are the correct size." << endl;
  
  // Now testing if bitreader works
  //  ifstream input("/home/nwadhwa/Downloads/pipeOrgan04_200FPS.cine", ios::in|ios::binary);
  ifstream input("testfile.dat", ios::in|ios::binary);
  bitreader br(&input);
  
  m_byte = br.readBYTE(); assert(m_byte == 84); 
  m_char = br.readCHAR(); assert(m_char == 104); 
  m_word = br.readWORD(); assert(m_word == 29545);
  m_int16 = br.readINT16(); assert(m_int16 == 26912);
  m_short = br.readSHORT(); assert(m_short == 8307);
  m_bool = br.readBOOL(); assert(m_bool == 1768038497);
  m_dword = br.readDWORD(); assert(m_dword == 2037539182);
  m_uint = br.readUINT(); assert(m_uint == 1818846752);
  m_long = br.readLONG(); assert(m_long == 1752440933);
  m_int = br.readINT(); assert(m_int == 1746957409);
  m_float = br.readFLOAT(); assert(abs(m_float-1.849871e+20) < 1e-6);
  m_double = br.readDOUBLE(); assert(abs(m_double-2.139469e+161)<1e-6);
  
  // Verify that we read structures correctly
  TIME64 m_time64 =   br.readTIME64();
  WBGAIN m_wbgain = br.readWBGAIN();
  IMFILTER m_imfilter = br.readIMFILTER();

  assert(m_time64.Fractions == 543517794);
  assert(m_time64.Seconds == 1229148993);

  assert(abs(m_wbgain.R-1.772777e+28) < 1e-6);
  assert(abs(m_wbgain.B - 1.726007e+25) < 1e-6);


  assert(m_imfilter.Dim == 539912046);
  assert(m_imfilter.Shifts == 1746957385);
  assert(m_imfilter.Bias == 1864397665);


  cout << "All data input tests passed." << endl;
  cout << "Note that we haven't verified the sign of any variables yet" << endl;
  input.close();

  //Test actual cine file
  ifstream inputCine("/home/nwadhwa/Downloads/drumhead_20140613.cine", ios::in|ios::binary);
  CINEFILEHEADER cineheader(&inputCine);
  cout << cineheader;
  /*
  BITMAPINFOHEADER bitmapheader(&inputCine, cineheader);
  cout << bitmapheader;

  IMAGEOFFSETS pimage(&inputCine, cineheader);
  CINEIMAGE im(&inputCine, pimage.getPointer(1000), bitmapheader);
  */
  SETUP  setup(&inputCine, cineheader);
  cout << setup;
  //  im.saveToTIFF("spice.tiff");


  // String test
  ifstream inputStr("/home/nwadhwa/Downloads/drumhead_20140613.cine", ios::in|ios::binary);
  br = bitreader(&inputStr);
  STRING out = br.readZeroTerminatedSTRING();
  assert(out.compare("CI,"));
  cout << "All string tests passed" << endl;


  


}
