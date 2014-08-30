#include "../cinereader.h"
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
