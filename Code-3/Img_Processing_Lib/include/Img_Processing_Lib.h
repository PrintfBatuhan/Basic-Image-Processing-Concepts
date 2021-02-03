#ifndef IMG_PROCESSING_LIB_H
#define IMG_PROCESSING_LIB_H

static const int _512by512_IMG_SIZE = 262144; //Bmp format knowledges
static const int BMP_COLOR_TABLE_SIZE = 1024;
static const int BMP_HEADER_SIZE = 54;

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
