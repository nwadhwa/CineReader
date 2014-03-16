#include "bitmapinfoheader.h"


BITMAPINFOHEADER::BITMAPINFOHEADER(std::ifstream *input, const CINEFILEHEADER & header) {
  bitreader br(input);
  br.seekToByte(header.getOffImageHeader());
  biSize = br.getDWORD();
  biWidth = br.getLONG();
  biHeight = br.getLONG();
  biPlanes = br.getWORD();
  biBitCount = br.getWORD();
  biCompression = br.getDWORD();
  biSizeImage = br.getDWORD();
  biXPelsPerMeter = br.getLONG();
  biYPelsPerMeter = br.getLONG();
  biClrUsed = br.getDWORD();
  biClrImportant = br.getDWORD();

}



std::ostream& operator<<(std::ostream& os, const BITMAPINFOHEADER & bitmapheader) {
  os << "Bitmap Size: " << getbiSize() << std::endl;
  os << "Bitmap Width: " << getbiWidth() << std::endl;
  os << "Bitmap Height: " << getbiHeight() << std::endl;
  os << "Bitmap Planes: " << getbiPlanes() << std::endl;
  os << "Bitmap  Bits per Pixel: " << getbiBitCount() << std::endl;
  os << "Bitmap Compression: " << getbiCompression() << std::endl;
  os << "Bitmap Image Size (bytes): " << getbiSizeImage() << std::endl;
  os << "Bitmap X Pixels per Meter: " << getbiXPelsPerMeter() << std::endl;
  os << "Bitmap Y Pixels per Meter: " << getbiYPelsPerMeter() << std::endl;
  os << "Bitmap Colors Used: " << getbiClrUsed() << std::endl;
  os << "Bitmap Colors Important: " << getbiClrImportant() << std::endl;
  return os;

}
