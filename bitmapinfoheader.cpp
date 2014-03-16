#include "bitmapinfoheader.h"


BITMAPINFOHEADER::BITMAPINFOHEADER(std::ifstream *input, const CINEFILEHEADER & header) {
  bitreader br(input);
  br.seekToByte(header.getOffImageHeader());
  biSize = br.readDWORD();
  biWidth = br.readLONG();
  biHeight = br.readLONG();
  biPlanes = br.readWORD();
  biBitCount = br.readWORD();
  biCompression = br.readDWORD();
  biSizeImage = br.readDWORD();
  biXPelsPerMeter = br.readLONG();
  biYPelsPerMeter = br.readLONG();
  biClrUsed = br.readDWORD();
  biClrImportant = br.readDWORD();

}



std::ostream& operator<<(std::ostream& os, const BITMAPINFOHEADER & bitmapheader) {
  os << "Bitmap Size: " << bitmapheader.getbiSize() << std::endl;
  os << "Bitmap Width: " << bitmapheader.getbiWidth() << std::endl;
  os << "Bitmap Height: " << bitmapheader.getbiHeight() << std::endl;
  os << "Bitmap Planes: " << bitmapheader.getbiPlanes() << std::endl;
  os << "Bitmap  Bits per Pixel: " << bitmapheader.getbiBitCount() << std::endl;
  os << "Bitmap Compression: " << bitmapheader.getbiCompression() << std::endl;
  os << "Bitmap Image Size (bytes): " << bitmapheader.getbiSizeImage() << std::endl;
  os << "Bitmap X Pixels per Meter: " << bitmapheader.getbiXPelsPerMeter() << std::endl;
  os << "Bitmap Y Pixels per Meter: " << bitmapheader.getbiYPelsPerMeter() << std::endl;
  os << "Bitmap Colors Used: " << bitmapheader.getbiClrUsed() << std::endl;
  os << "Bitmap Colors Important: " << bitmapheader.getbiClrImportant() << std::endl;
  return os;

}
