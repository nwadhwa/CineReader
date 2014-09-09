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
  
  //Test actual cine file
  ifstream inputCine("C:\\Users\\wadhwa\\Desktop\\test01_4_87Hz_damageBall.cine", ios::in|ios::binary);
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




  


}
