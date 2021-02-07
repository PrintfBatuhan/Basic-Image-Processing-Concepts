#include "Img_Processing_Lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Img_Processing_Lib::Img_Processing_Lib( //definition of required arguments
                                        const char *_inImgName,
                                        const char *_outImgName,
                                        int * _height,  // to store image height
                                        int * _width,   //to store image width
                                        int * _bitDepth, //to store image bitdepth
                                        unsigned char * _header, //to store image header
                                        unsigned char * _colorTable,
                                        unsigned char * _inBuffer,
                                        unsigned char * _outBuffer
                                       )
{
    inImgName  = _inImgName;
    outImgName = _outImgName;
    height     = _height;
    width      = _width;
    bitDepth   = _bitDepth;
    header     = _header;
    colorTable = _colorTable;
    inBuffer   = _inBuffer;
    outBuffer  = _outBuffer;
}
void Img_Processing_Lib::readImage()  //Image reader function
{
    int i;
    FILE *Input;
    Input = fopen(inImgName,"rb");

    if(Input ==(FILE *)0) //Error control
    {
        cout<<"Unable to open file. Maybe file does not exist"<<endl;
        exit(0);
    }

    for(i=0;i<BMP_HEADER_SIZE;i++)
    {
        header[i] =  getc(Input);
    }
    *width = *(int *)&header[18];           //read the width from the image header
    *height = *(int *)&header[22];          //read the height from the image header
    *bitDepth = *(int *)&header[28];        //read the bitdepth from the image header

    //If bith depth is less than or equal to eight color table exist.
    if(*bitDepth <=8)  //reading color table.
    {

        fread(colorTable,sizeof(unsigned char),BMP_COLOR_TABLE_SIZE,Input);
        //fread(what you want to read, size of element you want to read,total number of elements, source)
    }

    fread(inBuffer,sizeof(unsigned char),_512by512_IMG_SIZE,Input); //read pixel data

    fclose(Input);
}

void Img_Processing_Lib::writeImage(){ //Image writer function

    FILE  *Output = fopen(outImgName,"wb");
    fwrite(header,sizeof(unsigned char),BMP_HEADER_SIZE,Output);

    if(*bitDepth <=8)
    {
        fwrite(colorTable,sizeof(unsigned char),BMP_COLOR_TABLE_SIZE,Output);
    }

   fwrite(outBuffer, sizeof(unsigned char),_512by512_IMG_SIZE,Output);
   fclose(Output);
   //Create a new image, first image read func. reads the input image, stores it in the input buffer
   //and the the process between read and write takes what's in the input buffer manipulate its stores
   //in an output buffer and then the image right takes what's in the output buffer and then create a new
   //from that show over here.
}

//Copy image data function
void Img_Processing_Lib ::copyImgData(unsigned char *_srcBuffer, unsigned char *_destBuffer, int bufferSize)
{                                  //(image data we want to copy (input img), empty array(copy it into), size of the image)

    for(int i =0;i<bufferSize;i++)
    {
        _destBuffer[i] = _srcBuffer[i];
    }
}
Img_Processing_Lib::~Img_Processing_Lib()
{
    //dtor
}
