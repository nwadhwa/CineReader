#include "setup.h"

SETUP::SETUP(std::ifstream *inputCine, const CINEFILEHEADER &cineheader) {
  bitreader br(inputCine);
  br.seekToByte(cineheader.getOffSetup());
  //Look for "ST" mark, marking start of non obsolete setup
  int count = 0;
  BYTE first, second;
  first = br.readBYTE();
  second = br.readBYTE();
  while (true) {    
    if (first == 83 && second == 84) {      
      break;
    }
    first = second;
    second = br.readBYTE();
    count = count + 1;
    if (count > 4096)
      throw(exceptionMarkNotFound());
  } 
  Length = br.readWORD();
  Binning = br.readWORD();
  SigOption = br.readWORD();
  BinChannels = br.readSHORT();
  SamplesPerImage = br.readBYTE();
  for(int k = 0; k < 8; k++) {
    BinName[k] = br.readLengthNSTRING(11);
  }
  AnaOption = br.readWORD();
  AnaChannels = br.readSHORT();
  Res6 = br.readBYTE();
  AnaBoard = br.readBYTE();
  for (int k = 0; k < 8; k++) {
    ChOption[k] = br.readSHORT();
  }
  for (int k = 0; k < 8; k++) {
    AnaGain[k] = br.readFLOAT();
  }
  for(int k = 0; k < 8; k++) {
    AnaUnit[k] = br.readLengthNSTRING(6);
  }

  for (int k = 0; k< 8; k++) {
    AnaName[k] = br.readLengthNSTRING(11);
  }  
  IFirstImage = br.readLONG();
  dwImageCount = br.readDWORD();
  nQFactor = br.readSHORT();
  wCineFileType = br.readWORD();
  for (int k = 0; k < 4; k++) {
    szCinePath[k] = br.readLengthNSTRING(65);
  }
  bMainsFreq = br.readWORD();
  bTimeCode = br.readBYTE();
  bPriority = br.readBYTE();
  wLeapSecDY = br.readWORD();
  dDelayTC = br.readDOUBLE();
  dDelayPPS = br.readDOUBLE();
  GenBits = br.readWORD();
  Res1 = br.readINT();
  Res2 = br.readINT();
  Res3 = br.readINT();
  ImWidth = br.readWORD();
  ImHeight = br.readWORD();
  EDRShutter16 = br.readWORD();
  Serial = br.readUINT();
  Saturation = br.readINT();
  Res5 = br.readBYTE();
  AutoExposure = br.readUINT();
  bFlipH = br.readBOOL();
  bFlipV = br.readBOOL();
  Grid = br.readUINT();
  FrameRate = br.readUINT();
  Shutter = br.readUINT();
  EDRShutter = br.readUINT();
  PostTrigger = br.readUINT();
  FrameDelay = br.readUINT();
  bEnableColor = br.readBOOL();
  CameraVersion = br.readUINT();
  FirmwareVersion = br.readUINT();
  SoftwareVersion = br.readUINT();
  RecordingTimeZone = br.readINT();
  CFA = br.readUINT();
  Bright = br.readINT();
  Contrast = br.readINT();
  Gamma = br.readINT();
  Reserved1 = br.readUINT();
  AutoExpLevel = br.readUINT();
  AutoExpSpeed = br.readUINT();
  for (int k = 0; k < 4; k++) 
    AutoExpRect[k] = br.readDWORD();
  for (int k = 0; k < 4; k++) 
    WBGain[k] = br.readWBGAIN();
  Rotate = br.readINT();
  WBView = br.readWBGAIN();
  RealBPP = br.readUINT();
  Conv8Min = br.readUINT();
  Conv8Max = br.readUINT();
  FilterCode = br.readINT();
  FilterParam = br.readINT();
  UF = br.readIMFILTER();
  BlackCalSVer = br.readUINT();
  WhiteCalSVer = br.readUINT();
  GrayCalSVer = br.readUINT();
  bStampTime = br.readBOOL();
  SoundDest = br.readUINT();
  FRPSteps = br.readUINT();
  for (int k = 0; k < 16; k++) 
    FRPImgNr[k] = br.readINT();
  for (int k = 0; k < 16; k++) 
    FRPRate[k] = br.readUINT();
  for (int k = 0; k < 16; k++) 
    FRPExp[k] = br.readUINT();
  MCCnt = br.readINT();
  for (int k = 0; k < 64; k++) 
    MCPercent[k] = br.readFLOAT();
  CICalib = br.readUINT();
  CalibWidth = br.readUINT();
  CalibHeight = br.readUINT();
  CalibRate = br.readUINT();
  CalibExp = br.readUINT();
  CalibEDR = br.readUINT();
  CalibTemp = br.readUINT();
  for (int k = 0; k < 4; k++) 
    HeadSerial[k] = br.readUINT();
  RangeCode = br.readUINT();
  RangeSize = br.readUINT();
  Decimation = br.readUINT();
  MasterSerial = br.readUINT();
  Sensor = br.readUINT();
  ShutterNs = br.readUINT();
  EDRShutterNs = br.readUINT();
  FrameDelayNs = br.readUINT();
  ImPosXAcq = br.readUINT();
  ImPosYAcq = br.readUINT();
  ImWidthAcq = br.readUINT();
  ImHeightAcq = br.readUINT();
  Description = br.readLengthNSTRING(4096);                
}

// Prints out all non obsolete values
std::ostream& operator<<(std::ostream& os, const SETUP & setupheader) {
  os << "Setup Length: " << setupheader.getLength() << std::endl;
  os << "Global Signal Options: " << setupheader.getSigOption() << std::endl;
  os << "Number of Binary Channels read from SAM: " << setupheader.getBinChannels() << std::endl;
  os << "Samples per Image: " << static_cast<unsigned>(setupheader.getSamplesPerImage()) << std::endl;
  os << " Binary Signal Names: " << std::endl;
  for (int k = 0; k < 8; k++) 
    os << "\t" << setupheader.getBinName(k) << std::endl;
  os << "Global Analog Option: " << setupheader.getAnaOption() << std::endl;
  os << "Number of Analog Channels: " << setupheader.getAnaChannels() << std::endl; 
  os << "Analog Board Type: " << setupheader.getAnaBoard() << std::endl;
  os << "Per Channel Analog Options: " << std::endl;
  for (int k = 0; k < 8; k++) 
    os << "\t" << setupheader.getChOption(k) << std::endl;
  os << "Per Channel Gain: " <<  std::endl;
  for (int k = 0; k < 8; k++) 
    os << "\t" << setupheader.getAnaGain(k) << std::endl;
  os << "Per Channel Measurement Unit: " <<  std::endl;
  for (int k = 0; k < 8; k++)     
    os << "\t" << setupheader.getAnaUnit(k) << std::endl;
  os << "Channel Name: " <<  std::endl;
  for (int k = 0; k < 8; k++)     
    os << "\t" << setupheader.getAnaName(k) << std::endl;
  os << "First Image in Range: " << setupheader.getIFirstImage() << std::endl;
  os << "Image Count in Range: " << setupheader.getdwImageCount() << std::endl;
  os << "Quality (Compressed Files): " << setupheader.getnQFactor() << std::endl;
  os << "Cine File Type: " << setupheader.getwCineFileType() << std::endl;
  os << "Cine File Save Paths: " << std::endl;
  for (int k = 0; k < 4; k++) 
    os << "\t" << setupheader.getszCinePath(k) << std::endl;
  os << "Image Width: " << setupheader.getImWidth() << std::endl;
  os << "Image Height: " << setupheader.getImHeight() << std::endl;
  os << "Camera Serial: " << setupheader.getSerial() << std::endl;
  os << "Saturation: " << setupheader.getSaturation() << std::endl;
  os << "Auto Exposure: " << setupheader.getAutoExposure() << std::endl;
  os << "Flipped Horizontally: " << setupheader.getbFlipH() << std::endl;
  os << "Flipped Vertically: " << setupheader.getbFlipV() << std::endl;
  os << "Grid: " << setupheader.getGrid() << std::endl;
  os << "Frame Rate: " << setupheader.getFrameRate() << std::endl;
  os << "Number of Post Trigger Frames: " << setupheader.getPostTrigger() << std::endl;
  os << "Color Enabled: " << setupheader.getbEnableColor() << std::endl;
  os << "Camera Version: " << setupheader.getCameraVersion() << std::endl;
  os << "Firmware Version: " << setupheader.getFirmwareVersion() << std::endl;
  os << "Software Version: " << setupheader.getSoftwareVersion() << std::endl;
  os << "Recording Time Zone: " << setupheader.getRecordingTimeZone() << std::endl;
  os << "Color Filter Array Type: " << setupheader.getCFA() << std::endl;
  os << "Brightness: " << setupheader.getBright() << std::endl;
  os << "Contrast: " << setupheader.getContrast() << std::endl;
  os << "Gamma: " << setupheader.getGamma() << std::endl;
  os << "Auto Exposure Level: " << setupheader.getAutoExpLevel() << std::endl;
  os << "Auto Exposure Speed: " << setupheader.getAutoExpSpeed() << std::endl;
  os << "White Balance Gain: " << std::endl;
  for (int k = 0; k < 4; k++) 
    os << "\t(" << setupheader.getWBGain(k).R << "," << setupheader.getWBGain(k).B << ")\n";
  os << "Rotate: " << setupheader.getRotate() << std::endl;
  os << "Bits Per Pixel: " << setupheader.getRealBPP() << std::endl;
  os << "Minimum Value When Converting to 8 Bits: " << setupheader.getConv8Min() << std::endl;
  os << "Maximum Value When Converting to 8 Bits: " << setupheader.getConv8Max() << std::endl;
  os << "Filter Code: " << setupheader.getFilterCode() << std::endl;
  os << "Filter Param: " << setupheader.getFilterParam() << std::endl;
  os << "Software Version for Black Reference: " << setupheader.getBlackCalSVer() << std::endl;
  os << "Software Version for White Reference: " << setupheader.getWhiteCalSVer() << std::endl;
  os << "Software Version for Gray Reference: " << setupheader.getGrayCalSVer() << std::endl;
  os << "Stamp Time: " << setupheader.getbStampTime() << std::endl;
  os << "Sound Destination: " << setupheader.getSoundDest() << std::endl;
  // Skipped stuff about changing frames (FRPSteps)
  os << "Calibration Width: " << setupheader.getCalibWidth() << std::endl;
  os << "Calibration Height: " << setupheader.getCalibHeight() << std::endl;
  os << "Calibration Exposure: " << setupheader.getCalibExp() << std::endl;
  os << "Calibration EDR: " << setupheader.getCalibEDR() << std::endl;
  os << "Calibration Temperature: " << setupheader.getCalibTemp() << std::endl;
  os << "Range Code: " << setupheader.getRangeCode() << std::endl;
  os << "Range Size: " << setupheader.getRangeSize() << std::endl;
  os << "Decimation: " << setupheader.getDecimation() << std::endl;
  os << "Master Serial: " << setupheader.getMasterSerial() << std::endl;
  os << "Sensor: " << setupheader.getSensor() << std::endl;
  os << "Shutter (ns): " << setupheader.getShutterNs() << std::endl;
  os << "EDR Shutter (ns): " << setupheader.getEDRShutterNs() << std::endl;
  os << "Frame Delay (ns): " << setupheader.getFrameDelayNs() << std::endl;
  os << "Description: " << setupheader.getDescription() << std::endl;

  return os;
}
