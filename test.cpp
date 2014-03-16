#include "data.h"
#include "bitreader.h"
#include <iostream>
#include <fstream>
#include <assert.h>

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
  m_word = bt.readWORD(); assert(m_word == 29545);
  m_int16 = br.readINT16(); assert(m_int16 == 26912);
  m_short = br.readSHORT(); assert(m_short == 8307);
  m_bool = br.readBool(); 

  cout << "All data input tests passed." << endl;







}
