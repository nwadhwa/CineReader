#include "../src/cinereader.h"
#include "class_handle.hpp"
#include <iostream>
#include <stdio.h>
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    char cmd[64];
    char filename[512];
    if (nrhs < 1 || mxGetString(prhs[0], cmd, sizeof(cmd)))
		mexErrMsgTxt("First input should be a command string less than 64 characters long.");
    
    if (!strcmp("new", cmd)) {
        // Check parameters
        mxGetString(prhs[1], filename, sizeof(filename));        
        if (nlhs != 1)
            mexErrMsgTxt("New: One output expected.");
        // Return a handle to a new C++ instance                
        plhs[0] = convertPtr2Mat<CineReader>(new CineReader(filename));
        return;
    }
    if (nrhs < 2)
        mexErrMsgTxt("Second input should be a class instance handle.");
    
    // Delete
    if (!strcmp("delete", cmd)) {
        // Destroy the C++ object
        destroyObject<CineReader>(prhs[1]);
        // Warn if other commands were ignored
        if (nlhs != 0 || nrhs != 2)
            mexWarnMsgTxt("Delete: Unexpected arguments ignored.");
        return;
    }
    
    // Get the class instance pointer from the second input
    CineReader *cr_instance = convertMat2Ptr<CineReader>(prhs[1]);
    
    
    if(!strcmp("NumberOfFrames", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("NumberOfFrames: Unexpected arguments.");
        int n = cr_instance->NumberOfFrames();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    }
    
    if(!strcmp("Width", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Width: Unexpected arguments.");
        int n = cr_instance->width();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    }   
    if(!strcmp("Height", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Height: Unexpected arguments.");
        int n = cr_instance->height();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    if(!strcmp("FrameRate", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("FrameRate: Unexpected arguments.");
        int n = cr_instance->FrameRate();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    
    if(!strcmp("WBR", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("WhiteBalanceRedGain: Unexpected arguments.");
        float n = cr_instance->whiteBalanceRed();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    if(!strcmp("WBB", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("WhiteBalanceBlueGain: Unexpected arguments.");
        float n = cr_instance->whiteBalanceBlue();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    if(!strcmp("BPP", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Bits Per Pixel: Unexpected arguments.");
        float n = cr_instance->bitsPerPixel();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    }  
    
    if(!strcmp("Bright", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Bright: Unexpected arguments.");
        int n = cr_instance->brightness();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    if(!strcmp("Contrast", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Contrast: Unexpected arguments.");
        int n = cr_instance->contrast();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    
    if(!strcmp("Gain", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Gain: Unexpected arguments.");
        float n = cr_instance->gain();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    if(!strcmp("Gamma", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Gamma: Unexpected arguments.");
        float n = cr_instance->gamma();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    if(!strcmp("flipH", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("flipH: Unexpected arguments.");
        int n = cr_instance->flipH();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    if(!strcmp("flipV", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("flipV: Unexpected arguments.");
        int n = cr_instance->flipV();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    if(!strcmp("rotate", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("rotate: Unexpected arguments.");
        int n = cr_instance->rotate();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    if(!strcmp("Exposure", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Exposure: Unexpected arguments.");
        int n = cr_instance->exposure();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    if(!strcmp("CFA", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Color Filter Array: Unexpected arguments.");
        int n = cr_instance->colorFilterArrayPattern();
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
        double *output = mxGetPr(plhs[0]);
        output[0] = n;
        return;    
    } 
    
    
    
    
    
    if(!strcmp("read", cmd)) {
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("read: Unexpected arguments.");
        double *data = mxGetPr(prhs[2]);
        int n = (int) data[0];
        CINEIMAGE im = cr_instance->read(n);
        int h = cr_instance->height();
        int w = cr_instance->width();
        
        if (im.bit16()) {
            plhs[0] = mxCreateNumericMatrix(w, h, mxUINT16_CLASS, mxREAL);
            uint16_T *output = (uint16_T *)mxGetData(plhs[0]);
            memcpy(output, im.get16IM(), sizeof(uint16_T)*h*w);
        } else {            
            plhs[0] = mxCreateNumericMatrix(w, h, mxUINT8_CLASS, mxREAL);
            uint8_T *output = (uint8_T *)mxGetData(plhs[0]);             
            memcpy(output, im.get8IM(), sizeof(uint8_T)*h*w);            
        }
        return;    
    }
    
}
