#ifndef IMG_PROCESSING_LIB_H
#define IMG_PROCESSING_LIB_H

static const int _512by512_IMG_SIZE   = 262144; //Bmp format knowledges
static const int BMP_COLOR_TABLE_SIZE = 1024;
static const int BMP_HEADER_SIZE      = 54;
static const int MAX_COLOR            = 255; //for 8-bit
static const int MIN_COLOR            = 0;
static const int WHITE                = MAX_COLOR;
static const int BLACK                = MIN_COLOR;
static const int NO_OF_GRAYLEVELS     =255;

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
        void readImage();
        void writeImage();
        void copyImgData(unsigned char *_srcBuffer, unsigned char *_destBuffer, int bufferSize);
        void brightnessUP(unsigned char *_inputImageData,unsigned char *_outImgData, int imgSize, int brightness);
        void brightnessDOWN(unsigned char *_inputImageData,unsigned char *_outImgData, int imgSize, int darkness);
        void Histogram(unsigned char *_imgData, int imgRows, int imgCols,float hist[]);


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
