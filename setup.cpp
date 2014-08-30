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
    BinName[k] = br.readZeroTerminatedSTRING();
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
    AnaUnit[k] = br.readZeroTerminatedSTRING();
  }
  for (int k = 0; k< 8; k++) {
    AnaName[k] = br.readZeroTerminatedSTRING();
  }
  IFirstImage = br.readLONG();
  dwImageCount = br.readDWORD();
  nQFactor = br.readSHORT();
  wCineFileType = br.readWORD();
  for (int k = 0; k < 4; k++) {
    szCinePath[k] = br.readZeroTerminatedSTRING();
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
    AutoExpRect[k] = br.readWORD();
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
  os << "Setup Length: " << Length << std::endl;
  os << "Global Signal Options: " << SigOption << std::endl;
  os << "Number of Binary Channels read from SAM: " << BinChannels << std::endl;
  os << "Samples per Image: " << SamplesPerImage << std::endl;
  os << " Binary Signal Names: " << std::endl;
  for (int k = 0; k < 64; k++) 
    os << "\t" << BinName[k] << std::endl;
  os << "Global Analog Option: " << AnaOption << std::endl;
  os << "Number of Analog Channels: " << AnaChannels << std::endl; 
  os << "Analog Board Type: " << AnaBoard << std::endl;
  os << "Per Channel Analog Options: " << std::endl;
  for (int k = 0; k < 64; k++) 
    os << "\t" << ChOptions[k] << std::endl;
  os << "Per Channel Gain: " <<  std::endl;
  for (int k = 0; k < 64; k++) 
    os << "\t" << AnaGain[k] << std::endl;
  os << "Per Channel Measurement Unit: " <<  std::endl;
  for (int k = 0; k < 64; k++)     
    os << "\t" << AnaUnit[k] << std::endl;
  os << "Channel Name: " <<  std::endl;
  for (int k = 0; k < 64; k++)     
    os << "\t" << AnaName[k] << std::endl;
  os << "First Image in Range: " << IFirstImage << std::endl;
  os << "Image Count in Range: " << dwImageCount << std::endl;
  os << "Quality (Compressed Files): " << nQFactor << std::endl;
  os << "Cine File Type: " << wCineFileType << std::endl;
  os << "Cine File Save Paths: " << std::endl;
  for (int k = 0; k < 4; k++) 
    os << "\t" << szCinePath[k] << std::endl;
  os << "Image Width: " << ImWidth << std::endl;
  os << "Image Height: " << ImHeight << std::endl;
  os << "Camera Serial: " << Serial << std::endl;
  os << "Saturation: " << Saturation << std::endl;
  os << "Auto Exposure: " << AutoExposure << std::endl;
  os << "Flipped Horizontally: " << bFlipH << std::endl;
  os << "Flipped Vertically: " << bFlipV << std::endl;
  os << "Grid: " << Grid << std::endl;
  os << "Frame Rate: " << FrameRate << std::endl;
  os << "Number of Post Trigger Frames: " << PostTrigger << std::endl;
  os << "Color Enabled: " << bEnableColor << std::endl;
  os << "Camera Version: " << CameraVersion << std::endl;
  os << "Firmware Version: " << FirmwareVersion << std::endl;
  os << "Software Version: " << SoftwareVersion << std::endl;
  os << "Recording Time Zone: " <<RecordingTimeZone << std::endl;
  os << "Color Filter Array Type: " << CFA << std::endl;
  os << "Brightness: " << Bright << std::endl;
  os << "Contrast: " << Contrast << std::endl;
  os << "Gamma: " << Gamma << std::endl;
  os << "Auto Exposure Level: " << AutoExpLevel << std::endl;
  os << "Auto Exposure Speed: " << AutoExpSpeed << std::endl;
  os << "White Balance Gain: " << std::endl;
  for (int k = 0; k < 4; k++) 
    os << "\t(" << WBGain[k].R << "," << WBGain[k].B << ")\n";
  os << "Rotate: " << Rotate << std::endl;
  os << "Bits Per Pixel: " << RealBPP << std::endl;
  os << "Minimum Value When Converting to 8 Bits: " << Conv8Min << std::endl;
  os << "Maximum Value When Converting to 8 Bits: " << Conv8Max << std::endl;
  os << "Filter Code: " << FilterCode << std::endl;
  os << "Filter Param: " <<FilterParam << std::endl;
  os << "Software Version for Black Reference: " << BlackCalSVer << std::endl;
  os << "Software Version for White Reference: " << WhiteCalSVer << std::endl;
  os << "Software Version for Gray Reference: " << GrayCalSVer << std::endl;
  os << "Stamp Time: " << bStampTime << std::endl;
  os << "Sound Destination: " << SoundDest << std::endl;
  // Skipped stuff about changing frames (FRPSteps)
  os << "Calibration Width: " << CalibWidth << std::endl;
  os << "Calibration Height: " << CalibHeight << std::endl;
  os << "Calibration Exposure: " << CalibExposure << std::endl;
  os << "Calibration EDR: " << CalibEDR << std::endl;
  os << "Calibration Temperature: " << CalibTemp << std::endl;
  os << "Range Code: " << RangeCode << std::endl;
  os << "Range Size: " << RangeSize << std::endl;
  os << "Decimation: " << Decimation << std::endl;
  os << "Master Serial: " << MasterSerial << std::endl;
  os << "Sensor: " << Sensor << std::endl;
  os << "Shutter (ns): " << ShutterNs << std::endl;
  os << "EDR Shutter (ns): " << EDRShutterNs << std::endl;
  os << "Frame Delay (ns): " << FrameDelayNs << std::endl;
  
  os << "Description: " << Description << std::endl;


  
}
