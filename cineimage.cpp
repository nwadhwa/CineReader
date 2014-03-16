#include "cineimage.h"

CINEIMAGE::CINEIMAGE(std::ifstream *input, long long imagePointer, const BITMAPINFOHEADER & bitmapheader) {
  int k;
  bitreader br(input);
  br.seekToByte(imagePointer);
  AnnotationSize = br.readDWORD();
  Annotation = new BYTE[AnnotationSize-8];
  for (k = 0; k < AnnotationSize-8; k++) {
    Annotation[k] = br.readBYTE();
  }
  ImageSize = br.readDWORD();
  int totalPixels = bitmapheader.getbiWidth() * bitmapheader.getbiHeight();
  if (bitmapheader.getbiBitCount() == 24 || bitmapheader.getbiBitCount() == 48) {
    totalPixels = totalPixels *3;
  }
  if (bitmapheader.getbiBitCount() == 16 || bitmapheader.getbiBitCount() == 48) {
    is16bit = true;
    im8 = NULL;
    im16 = new WORD[totalPixels]; 
  } else {
    im8 = new BYTE[totalPixels];
    im16 = NULL;
  }
  
  for (k = 0; k < totalPixels; k++) {
    if(is16bit) {
      im16[k] = br.readWORD();
    } else {
      im8[k] = br.readBYTE();
    }
  }

  
}
CINEIMAGE::~CINEIMAGE() {
  delete Annotation;
  delete im8;
  delete im16;
}
