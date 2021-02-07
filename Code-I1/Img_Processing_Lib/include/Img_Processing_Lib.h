#ifndef IMG_PROCESSING_LIB_H
#define IMG_PROCESSING_LIB_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
static const int _512by512_IMG_SIZE   = 262144; //Bmp format knowledges
static const int BMP_COLOR_TABLE_SIZE = 1024;
static const int BMP_HEADER_SIZE      = 54;
static const int MAX_COLOR            = 255; //for 8-bit
static const int MIN_COLOR            = 0;
static const int WHITE                = MAX_COLOR;
static const int BLACK                = MIN_COLOR;
static const int NO_OF_GRAYLEVELS     =255;

struct Mask{
int Rows;
int Cols;
unsigned char *Data;
};


static const int LINE_DETECTOR_HORIZONAL_MSK[3][3]={{-1,2,-1},
                                                    {-1,2,-1},
                                                    {-1,2,-1}};

static const int LINE_DETECTOR_VERTICAL_MSK[3][3] ={{-1,-1,-1},
                                                    {2, 2, 2},
                                                    {-1,-1,-1}};

static const int LINE_DETECTOR_LDIA_MSK[3][3]     ={{2,-1,-1},
                                                    {-1,2,-1},
                                                    {-1,-1,2}};

static const int LINE_DETECTOR_RDIA_MSK[3][3]     ={{-1,-1,2},
                                                    {-1,2,-1},
                                                    {2,-1,-1}};


//Prewitt Mask Operatorr;
static const int PREWITT_VERTICAL[]={-1,0,1,-1,0,1,-1,0,1};
static const int PREWITT_HORIZONAL[]={-1,-1,-1,0,0,0,1,1,1};

//Sobel Mask Operator;
static const int SOBEL_VERTICAL[]={-1,0,1,-2,0,2,-1,0,1};
static const int SOBEL_HORIZONAL[]={-1,-2,-1,0,0,0,1,2,1};

//Robinson Mask Operator;
static const int ROBINSON_NORTH[]={-1,0,1,-2,0,2,-1,0,1};
static const int ROBINSON_SOUTH[]={1,0,-1,2,0,-2,1,0,-1};
static const int ROBINSON_WEST[]={1,2,1,0,0,0,-1,-2,-1};
static const int ROBINSON_EAST[]={-1,-2,-1,0,0,0,1,2,1};

//Kirsch Mask Operator;
static const int KIRSCH_NORTH[]={5,5,5,-3,0,-3,-3,-3,-3};
static const int KIRSCH_SOUTH[]={-3,-3,-3,-3,0,-3,5,5,5};
static const int KIRSCH_WEST[]={5,-3,-3,5,0,-3,5,-3,-3};
static const int KIRSCH_EAST[]={-3,-3,5,-3,0,5,-3,-3,5};

//Laplacian Operator;
static const int LAPLACE_NEG[]={0,-1,0,-1,4,-1,0,-1,0};
static const int LAPLACE_POZ[]={0,1,0,1,-4,1,0,1,0};

//Roberts Mask Operator;
static const int ROBERTS_GX []={1,0,0,-1};
static const int ROBERTS_GY []={0,1,-1,0};


class Img_Processing_Lib
{
    public:
        Img_Processing_Lib(      const char *_inImgName,
                                 const char *_outImgName,
                                 int * _height,
                                 int * _width,
                                 int * _bitDepth,
                                 unsigned char * _header,
                                 unsigned char * _colorTable,
                                 unsigned char * _inBuffer,
                                 unsigned char * _outBuffer);
        Mask myMask;
        void readImage();
        void writeImage();
        void copyImgData(unsigned char *_srcBuffer, unsigned char *_destBuffer, int bufferSize);
        void brightnessUP(unsigned char *_inputImageData,unsigned char *_outImgData, int imgSize, int brightness);
        void brightnessDOWN(unsigned char *_inputImageData,unsigned char *_outImgData, int imgSize, int darkness);
        void Histogram(unsigned char * _imgData, int imgRows, int imgCols, float hist[], const char *histFile);
        void EqualizeHistogram(unsigned char *_inptImgData, unsigned char *_outputImgData, int imgRows, int imgCols);
        void ImageNegative(unsigned char *_InimgData, unsigned char*_outImgData, int imgWidth, int imgHeight);
        void Convolve2D(int imgRows,int Cols, struct Mask *myMask, unsigned char *inputBuffer, unsigned char *OutputBuffer);
        void DetectLine(unsigned char *_inImgData, unsigned char *_outImgData,int imgCols, int imgRows, const int MASK[][3]);
        void setMask(int MskRows, int MskCols, const int MskData[]);
        void GaussNoise(unsigned char*_inImgData, int imCols,int imgRows, float var,float mean);
        void SaltandPepper(unsigned char*_intImgData, int imgCols,int imgRows, float prob);

        virtual ~Img_Processing_Lib();

    protected:

    private:
        const char *inImgName;
        const char *outImgName;
        int * height;
        int * width;
        int * bitDepth;
        unsigned char * header;
        unsigned char * colorTable;
        unsigned char * inBuffer;
        unsigned char * outBuffer;
};

#endif // IMG_PROCESSING_LIB_H
