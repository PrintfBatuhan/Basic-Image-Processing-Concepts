#include <iostream>
#include "Img_Processing_Lib.h"

using namespace std;

int main()
{
    Mask lpMask;
    signed char *tmp;
    int i;

    float imgHist[NO_OF_GRAYLEVELS];
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[_512by512_IMG_SIZE];
    unsigned char imgOutBuffer[_512by512_IMG_SIZE];

    const char imgName[] ="images/barbara.bmp";
    const char newImgName[] ="images/barbara_conv.bmp";

    Img_Processing_Lib *myImage  = new Img_Processing_Lib(imgName,
                                                          newImgName,
                                                          &imgHeight,
                                                          &imgWidth,
                                                          &imgBitDepth,
                                                          &imgHeader[0],
                                                          &imgColorTable[0],
                                                          &imgInBuffer[0],
                                                          &imgOutBuffer[0]);
    lpMask.Rows=5;
    lpMask.Cols=5;
    lpMask.Data=(unsigned char *)malloc(25);

    /*  -1 -1 -1 -1 -1
        -1 -1 -1 -1 -1
        -1 -1 24 -1 -1
        -1 -1 -1 -1 -1
        -1 -1 -1 -1 -1 */

    //set all value to 24
    tmp = (signed char *)lpMask.Data;
    for(i=0;i<25;i++)
    {
        *tmp=-1;
        ++tmp;
    }
    //set middle value to 24
    tmp=(signed char *)lpMask.Data+13;
    *tmp=24;

     myImage->readImage();
     myImage->Convolve2D(imgHeight,imgWidth,&lpMask,imgInBuffer,imgOutBuffer);
     myImage->writeImage();
     cout<<"Success"<<endl;
     cout<<"Image Height : "<<imgHeight<<endl;
     cout<<"Image Width  : "<<imgWidth<<endl;


    return 0;
}
