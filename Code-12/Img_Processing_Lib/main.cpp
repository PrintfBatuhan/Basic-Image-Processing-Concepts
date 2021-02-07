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

    const char imgName[] ="imgRoberts/girlface.bmp";
    const char newImgName[] ="imgRoberts/girlface_GY.bmp";

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
    //myImage->DetectLine(imgInBuffer,imgOutBuffer,imgWidth,imgHeight,LINE_DETECTOR_RDIA_MSK);

    //myImage->setMask(3,3,PREWITT_VERTICAL);
    //myImage->setMask(3,3,PREWITT_HORIZONAL);

    //myImage->setMask(3,3,SOBEL_VERTICAL);
    //myImage->setMask(3,3,SOBEL_HORIZONAL);

    //myImage->setMask(3,3,ROBINSON_NORTH);
    //myImage->setMask(3,3,ROBINSON_SOUTH);
    //myImage->setMask(3,3,ROBINSON_WEST);
    //myImage->setMask(3,3,ROBINSON_EAST);

    //myImage->setMask(3,3,KIRSCH_NORTH);
    //myImage->setMask(3,3,KIRSCH_SOUTH);
    //myImage->setMask(3,3,KIRSCH_WEST);
    //myImage->setMask(3,3,KIRSCH_EAST);

    //myImage->setMask(3,3,LAPLACE_NEG);
    //myImage->setMask(3,3,LAPLACE_POZ);

    //myImage->setMask(2,2,ROBERTS_GX);
      myImage->setMask(2,2,ROBERTS_GY);
     myImage->Convolve2D(imgHeight,imgWidth,&myImage->myMask,imgInBuffer,imgOutBuffer);
     myImage->writeImage();
     cout<<"Success"<<endl;
     cout<<"Image Height : "<<imgHeight<<endl;
     cout<<"Image Width  : "<<imgWidth<<endl;


    return 0;
}
