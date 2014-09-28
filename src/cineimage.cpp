#include "cineimage.h"

CINEIMAGE::CINEIMAGE(std::ifstream *input, int64_t imagePointer, const BITMAPINFOHEADER & bitmapheader) {
  int k;
  bitreader br(input);
  br.seekToByte(imagePointer);
  AnnotationSize = br.readDWORD();
  if (AnnotationSize-8 >0) {
    Annotation = new BYTE[AnnotationSize-8];
    for (k = 0; k < AnnotationSize-8; k++) {
      Annotation[k] = br.readBYTE();
    }
  } else {
    Annotation = NULL;
  }
  ImageSize = br.readDWORD();

  int totalPixels = bitmapheader.getbiWidth() * bitmapheader.getbiHeight();
  if (bitmapheader.getbiBitCount() == 24 || bitmapheader.getbiBitCount() == 48) {
    samplesPerPixel = 3;
  } else {
    samplesPerPixel = 1;
  }
  totalPixels = totalPixels *samplesPerPixel;

  if (totalPixels > 0) {
    if (bitmapheader.getbiBitCount() == 16 || bitmapheader.getbiBitCount() == 48) {
      is16bit = true;
      im8 = NULL;
      im16 = new WORD[totalPixels]; 
    } else {
      is16bit = false;
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
  } else {
    im8 = NULL;
    im16 = NULL;
  }

  bmh = &bitmapheader;
}
CINEIMAGE::~CINEIMAGE() {
  if (AnnotationSize - 8 > 0 ) {
    delete[] Annotation;
  } else {
    delete Annotation;
  }
  if (is16bit) {
    delete im8;
    delete[] im16;
  } else {
    delete[] im8;
    delete im16;
  }

}






/*
void CINEIMAGE::saveToTIFF(char *filename) {
  TIFF *out = TIFFOpen(filename, "w");
  LONG w = bmh->getbiWidth();
  LONG h = bmh->getbiHeight();
  WORD bitCount = bmh->getbiBitCount();

  TIFFSetField(out, TIFFTAG_IMAGEWIDTH, w);
  TIFFSetField(out, TIFFTAG_IMAGELENGTH, h);
  TIFFSetField(out, TIFFTAG_SAMPLESPERPIXEL, samplesPerPixel);
  if (is16bit) {
    TIFFSetField(out, TIFFTAG_BITSPERSAMPLE, 16);
  } else {
    TIFFSetField(out, TIFFTAG_BITSPERSAMPLE, 8);
  }
  TIFFSetField(out, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
  TIFFSetField(out, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
  if (samplesPerPixel == 3) {
    TIFFSetField(out, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB);
  } else  {
    TIFFSetField(out, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_MINISBLACK);
  }

  tsize_t linebytes = w*samplesPerPixel;
  if (is16bit)
    linebytes = linebytes * 2;
  unsigned char *buf = (unsigned char *)_TIFFmalloc(linebytes);
  
  TIFFSetField(out, TIFFTAG_ROWSPERSTRIP, TIFFDefaultStripSize(out, linebytes));

  for (int k = 0; k < h; k++) {
      if (is16bit) {
	memcpy(buf, &im16[(h-k-1)*linebytes], linebytes);
      } else {
	memcpy(buf, &im8[(h-k-1)*linebytes], linebytes);
      }

      TIFFWriteScanline(out, buf, k);


  }
  


  (void) TIFFClose(out);
 
  if (buf)
    _TIFFfree(buf);

}
*/
