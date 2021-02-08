#include <iostream>
#include "Img_Processing_Lib.h"

using namespace std;

int main()
{   float imgHist[NO_OF_GRAYLEVELS];
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[_512by512_IMG_SIZE];
    unsigned char imgOutBuffer[_512by512_IMG_SIZE];

    const char imgName[] ="images/barbara_Noise.bmp";
    const char newImgName[] ="images/image_Medaaa.bmp";

    Img_Processing_Lib *myImage  = new Img_Processing_Lib(imgName,
                                                          newImgName,
                                                          &imgHeight,
                                                          &imgWidth,
                                                          &imgBitDepth,
                                                          &imgHeader[0],
                                                          &imgColorTable[0],
                                                          &imgInBuffer[0],
                                                          &imgOutBuffer[0]);
     myImage->readImage();
     //myImage->setMask(3,3,HighPass_3x3);
     //myImage->Convolve2D(imgHeight,imgWidth,&myImage->myMask,imgInBuffer,imgOutBuffer);
     //myImage->MaxFilter(imgInBuffer,imgOutBuffer,imgWidth,imgHeight);
     myImage->MedianFilter(imgInBuffer,imgOutBuffer,imgWidth,imgHeight);
     //myImage->MinFilter(imgInBuffer,imgOutBuffer,imgWidth,imgHeight);
     myImage->writeImage();
     cout<<"Success"<<endl;
     cout<<"Image Height : "<<imgHeight<<endl;
     cout<<"Image Width  : "<<imgWidth<<endl;


    return 0;
}
