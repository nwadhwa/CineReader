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

  // Need to do bound checking on some of these
  WORD getLength() const { return Length; }
  WORD getBinning() const { return Binning; }
  WORD getSigOption() const { return SigOption; }
  SHORT getBinChannels() const { return BinChannels; }
  BYTE getSamplesPerImage() const { return SamplesPerImage; }
  STRING getBinName(int k) const { return BinName[k]; }
  WORD  getAnaOption() const { return AnaOption; }
  SHORT  getAnaChannels() const { return AnaChannels; }
  BYTE getAnaBoard() const { return AnaBoard; }
  SHORT getChOption(int k) const { return ChOption[k]; }
  FLOAT getAnaGain(int k) const { return AnaGain[k]; } 
  STRING getAnaUnit(int k) const { return AnaUnit[k]; }
  STRING getAnaName(int k) const { return AnaName[k]; }
  LONG getIFirstImage() const { return IFirstImage; }
  DWORD getdwImageCount() const { return dwImageCount; }
  SHORT getnQFactor() const { return nQFactor; }
  WORD getwCineFileType() const { return wCineFileType; }
  STRING getszCinePath(int k) const { return szCinePath[k]; }
  WORD  getImWidth() const { return ImWidth; }
  WORD getImHeight() const { return ImHeight; }
  WORD getEDRShutter16() const { return EDRShutter16; }
  UINT getSerial() const { return Serial; }
  INT getSaturation() const {return Saturation; }
  UINT getAutoExposure() const { return AutoExposure; }
  BOOL getbFlipH() const { return bFlipH; }
  BOOL getbFlipV() const { return bFlipV; }
  UINT getGrid() const { return Grid; }
  UINT getFrameRate() const { return FrameRate; }
  UINT getShutter() const { return Shutter; }
  UINT getEDRShutter() const { return EDRShutter; }
  UINT getPostTrigger() const { return PostTrigger; }
  UINT getFrameDelay() const { return FrameDelay; }
  BOOL getbEnableColor() const { return bEnableColor; }
  UINT getCameraVersion() const { return CameraVersion; }
  UINT getFirmwareVersion() const { return FirmwareVersion; }
  UINT getSoftwareVersion() const { return SoftwareVersion; }
  INT getRecordingTimeZone() const { return RecordingTimeZone; }
  UINT getCFA() const { return CFA; }
  INT getBright() const { return Bright; }
  INT getContrast() const { return Contrast; }
  INT getGamma() const { return Gamma; }
  UINT getAutoExpLevel() const { return AutoExpLevel; }
  UINT getAutoExpSpeed() const { return AutoExpSpeed; }
  WORD getAutoExpRect(int k) const { return AutoExpRect[k]; }
  WBGAIN getWBGain(int k) const { return WBGain[k]; }
  INT getRotate() const { return Rotate; }
  WBGAIN getWBView() const { return WBView; }
  UINT getRealBPP() const { return RealBPP; }
  UINT getConv8Min() const { return Conv8Min; }
  UINT getConv8Max() const { return Conv8Max; }
  INT getFilterCode() const { return FilterCode; }
  INT getFilterParam() const { return FilterParam; }
  IMFILTER getUF() const { return UF; }
  UINT getBlackCalSVer() const { return BlackCalSVer; }
  UINT getWhiteCalSVer() const { return WhiteCalSVer; }
  UINT getGrayCalSVer() const { return GrayCalSVer; }
  BOOL getbStampTime() const { return bStampTime; }
  UINT getSoundDest() const { return SoundDest; }
  UINT getFRPSteps() const { return FRPSteps; }
  INT getFRPImgNr( int k) const { return FRPImgNr[k]; }
  UINT getFRPRate(int k) const { return FRPRate[k]; }
  UINT getFRPExp(int k) const { return FRPExp[k]; }
  INT getMCCnt() const { return MCCnt; }
  FLOAT getMCPercent(int k) const { return MCPercent[k]; }
  UINT getCICalib() const { return CICalib; }
  UINT getCalibWidth() const { return CalibWidth; }
  UINT getCalibHeight() const { return CalibHeight; }
  UINT getCalibRate() const { return CalibRate; }
  UINT getCalibExp() const { return CalibExp; }
  UINT getCalibEDR() const { return CalibEDR; }
  UINT getCalibTemp() const { return CalibTemp; }
  UINT getHeadSerial(int k) const { return HeadSerial[k]; }
  UINT getRangeCode() const { return RangeCode; }
  UINT getRangeSize() const { return RangeSize; }
  UINT getDecimation() const { return Decimation; }
  UINT getMasterSerial() const { return MasterSerial; }
  UINT getSensor() const { return Sensor; }
  UINT getShutterNs() const { return ShutterNs; }
  UINT getEDRShutterNs() const { return EDRShutterNs; }
  UINT getFrameDelayNs() const { return FrameDelayNs; }
  UINT getImPosXAcq() const { return ImPosXAcq; }
  UINT getImPosYAcq() const { return ImPosYAcq; }
  UINT getImWidthAcq() const { return ImWidthAcq; }
  UINT getImHeightAcq() const { return ImHeightAcq; }
  STRING getDescription() const { return Description; }

  BOOL getRisingEdge() const { return RisingEdge; }
  DWORD getFilterTime() const { return FilterTime; } 
  BOOL getLongReady() const { return LongReady;}
  BOOL getShutterOff() const { return ShutterOff;  }  
  BOOL getbMetaWB() const { return bMetaWB;}
  DWORD getHue() const { return Hue;}
  INT getBlackLevel() const { return BlackLevel;}
  INT getWhiteLevel() const { return WhiteLevel;}
  STRING getLensDescription() const { return LensDescription;}
  FLOAT getLensAperture() const { return LensAperture;}
  FLOAT getLensFocusDistance() const { return LensFocusDistance;}
  FLOAT getLensFocalLength() const { return LensFocalLength;}
  FLOAT getfOffset() const { return fOffset;}
  FLOAT getfGain() const { return fGain;}
  FLOAT getfSaturation() const { return fSaturation;}
  FLOAT getfHue() const { return fHue;}
  FLOAT getfGamma() const { return fGamma;}
  FLOAT getfGammaR() const { return fGammaR;}
  FLOAT getfGammaB() const { return fGammaB;}
  FLOAT getfFlare() const { return fFlare;}
  FLOAT getfPedestalR() const { return fPedestalR;}
  FLOAT getfPedestalG() const { return fPedestalG;}
  FLOAT getfPedestalB() const { return fPedestalB;}
  FLOAT getfChroma() const { return fChroma;}
  
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
  STRING szCinePath[4];
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
  INT FRPImgNr[16];
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

  // Cine 705 format
  BOOL RisingEdge;
  DWORD FilterTime;
  BOOL LongReady;
  BOOL ShutterOff;  
  BYTE Res4[16];
  BOOL bMetaWB;
  DWORD Hue;
  INT BlackLevel;
  INT WhiteLevel;
  STRING LensDescription;
  FLOAT LensAperture;
  FLOAT LensFocusDistance;
  FLOAT LensFocalLength;
  FLOAT fOffset;
  FLOAT fGain;
  FLOAT fSaturation;
  FLOAT fHue;
  FLOAT fGamma;
  FLOAT fGammaR;
  FLOAT fGammaB;
  FLOAT fFlare;
  FLOAT fPedestalR;
  FLOAT fPedestalG;
  FLOAT fPedestalB;
  FLOAT fChroma;
  // Skipping following fields 
  STRING ToneLabel;
  INT TonePoints;
  FLOAT fTone[64];
  STRING UserMatrixLabel;
  BOOL EnableMatrices;
  FLOAT fUserMatrix[9];
  BOOL EnableCrop;
  WORD CropRect[4];
  BOOL EnableResample;
  DWORD ResampleWidth;
  DWORD ResampleHeight;
  FLOAT fGain16_8;
  DWORD FRPShape[16];
  // Skipping  remaining fields
  // TrigTC
  // fPbRate
  // fTcRate
  // CineName[256]
  



  


};



std::ostream& operator<<(std::ostream& os, const SETUP & setupheader);

class exceptionMarkNotFound : public std::exception {

  virtual const char * what() const throw() 
  {
    return "Mark not found in Cine file";
  } 
};


#endif
