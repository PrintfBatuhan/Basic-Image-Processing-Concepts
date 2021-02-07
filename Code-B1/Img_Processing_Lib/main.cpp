#include <iostream>
#include "Img_Processing_Lib.h"

using namespace std;

int main()
{
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[_512by512_IMG_SIZE];
    unsigned char imgOutBuffer[_512by512_IMG_SIZE];


    int i;
    cout<<"Press 1 for increase the bright of image"<<endl;
    cout<<"Press 2 for increase the dark of image"<<endl;
    cin>>i;

    if(i==1)
    {
    const char imgName[] ="images/lena.bmp";
    const char newImgName[] ="images/lena_Bright_Fact_100.bmp";

    Img_Processing_Lib *myImage  = new Img_Processing_Lib(
                                                            imgName,
                                                            newImgName,
                                                            &imgHeight,
                                                            &imgWidth,
                                                            &imgBitDepth,
                                                            &imgHeader[0],
                                                            &imgColorTable[0],
                                                            &imgInBuffer[0],
                                                            &imgOutBuffer[0]
                                                          );
     myImage->readImage();
     myImage->brightnessUP(imgInBuffer,imgOutBuffer,_512by512_IMG_SIZE,100);
     myImage->writeImage();

     cout<<"Success"<<endl;
     cout<<"Image Height : "<<imgHeight<<endl;
     cout<<"Image Width  : "  <<imgWidth<<endl;
     cout<<"Brightness Factor is 100"<<endl;
    }

    else if(i==2)
    {
    const char imgName[] ="images/lena.bmp";
    const char newImgName[] ="images/lena_Dark_Fact_100.bmp";

    Img_Processing_Lib *myImage  = new Img_Processing_Lib(
                                                            imgName,
                                                            newImgName,
                                                            &imgHeight,
                                                            &imgWidth,
                                                            &imgBitDepth,
                                                            &imgHeader[0],
                                                            &imgColorTable[0],
                                                            &imgInBuffer[0],
                                                            &imgOutBuffer[0]
                                                          );
     myImage->readImage();
     myImage->brightnessDOWN(imgInBuffer,imgOutBuffer,_512by512_IMG_SIZE,100);
     myImage->writeImage();

     cout<<"Success"<<endl;
     cout<<"Image Height : "<<imgHeight<<endl;
     cout<<"Image Width  : "  <<imgWidth<<endl;
     cout<<"Darkness Factor is 100"<<endl;
    }
    else{
        cout<<"Please enter a defined command"<<endl;
    }
    return 0;
}
