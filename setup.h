// Structure that contains the acquisition parameters used during the recording of the cine
#ifndef __setup_h
#define __setup_h

#include "data.h"
#include "bitreader.h"
#include "cinefileheader.h"
#include <fstream>
#include <iostream>

class SETUP {
 public:
  SETUP(std::ifstream *inputCine, const CINEFILEHEADER &cineheader);
  
 private:
  // Obsolete variables that are no longer used
  /*
  WORD FrameRate16; //obsolete
  WORD Shutter16; //obsolete
  WORD PostTrigger16; //obsolete
  WORD FrameDelay16; //obsolete
  WORD AspectRatio; //obsolete
  WORD Contrast16; //obsolete
  WORD Bright16; //obsolete 
  BYTE Rotate16;//obsolete 
  BYTE TimeAnnotation; //obsolete
  BYTE TrigCine; //obsolete
  BYTE TrigFrame;
  BYTE ShutterOn; //obsolete
  CHAR * DescriptionOLD; //obsolete
  */
  WORD Mark;
  WORD Length;
  WORD Binning; //obsolete
  WORD SigOption;
  SHORT BinChannels;
  BYTE SamplesPerImage;
  STRING BinName[8];
  WORD AnaOption;
  SHORT AnaChannels;
  BYTE Res6; //obsolete
  BYTE AnaBoard;
  SHORT ChOption[8];
  FLOAT AnaGain[8];
  STRING AnaUnit[8];
  STRING AnaName[8];
  LONG IFirstImage;
  DWORD dwImageCount;
  SHORT nQFactor;
  WORD wCineFileType;
  STRING szCinePath;
  WORD bMainsFreq; //obsolete
  BYTE bTimeCode; //obsolete
  BYTE bPriority; //obsolete
  WORD wLeapSecDY; //obsolete
  DOUBLE dDelayTC; //obsolete
  DOUBLE dDelayPPS; //obsolete
  WORD GenBits; //obsolete
  INT Res1; //obsolete
  INT Res2; //obsolete
  INT Res3; //obsolete
  WORD ImWidth;
  WORD ImHeight;
  WORD EDRShutter16;
  UINT Serial;
  INT Saturation;
  BYTE Res5; //obsolete
  UINT AutoExposure;
  BOOL bFlipH;
  BOOL bFlipV;
  UINT Grid;
  UINT FrameRate;
  UINT Shutter;
  UINT EDRShutter;
  UINT PostTrigger;
  UINT FrameDelay;
  BOOL bEnableColor;
  UINT CameraVersion;
  UINT FirmwareVersion;
  UINT SoftwareVersion;
  INT RecordingTimeZone;
  UINT CFA;
  INT Bright;
  INT Contrast;
  INT Gamma;
  UINT Reserved1; //obsolete
  UINT AutoExpLevel;
  UINT AutoExpSpeed;
  WORD AutoExpRect[4];
  WBGAIN WBGain[4];
  INT Rotate;
  WBGAIN WBView;
  UINT RealBPP;
  UINT Conv8Min;
  UINT Conv8Max;
  INT FilterCode;
  INT FilterParam;
  IMFILTER UF;
  UINT BlackCalSVer;
  UINT WhiteCalSVer;
  UINT GrayCalSVer;
  BOOL bStampTime;
  UINT SoundDest;
  UINT FRPSteps;
  INT FRPImgNR[16];
  UINT FRPRate[16];
  UINT FRPExp[16];
  INT MCCnt;
  FLOAT MCPercent[64];
  UINT CICalib;
  UINT CalibWidth;
  UINT CalibHeight;
  UINT CalibRate;
  UINT CalibExp;
  UINT CalibEDR;
  UINT CalibTemp;
  UINT HeadSerial[4];
  UINT RangeCode;
  UINT RangeSize;
  UINT Decimation;
  UINT MasterSerial;
  UINT Sensor;
  UINT ShutterNs;
  UINT EDRShutterNs;
  UINT FrameDelayNs;
  UINT ImPosXAcq;
  UINT ImPosYAcq;
  UINT ImWidthAcq;
  UINT ImHeightAcq;
  STRING Description;

 



  


};



std::ostream& operator<<(std::ostream& os, const SETUP & setupheader);

class exceptionMarkNotFound : public std::exception {
  virtual const char * what() const throw() 
  {
    return "Mark not found in Cine file";
  } 
};


#endif
