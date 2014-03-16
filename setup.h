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

 private:
  WORD FrameRate16;
  WORD Shutter16;
  WORD PostTrigger16;
  WORD FrameDelay16;
  WORD AspectRatio;
  WORD Contrast16;
  WORD Bright16;
  BYTE Rotate16;
  BYTE TimeAnnotation;
  BYTE TrigCine;
  BYTE TrigFrame;
  BYTE ShutterOn;
   


};

std::ostream& operator<<(std::ostream& os, const SETUP & setupheader);




#endif
