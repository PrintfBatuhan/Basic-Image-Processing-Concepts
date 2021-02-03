#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE         54
#define BMP_COLOR_TABLE_SIZE    1024
#define CUSTOM_IMG_SIZE         1024*1024

int imgWidth, imgHeight, imgBitDepth;            // definition about image knowledge
unsigned char imgHeader[BMP_HEADER_SIZE];        // Definition about BMP format
unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
unsigned char imgBuffer[CUSTOM_IMG_SIZE];


void img_reader(const char *imgName,    //Image reader function
                int *_height,
                int *_width,
                int *_bitDepth,
                unsigned char *_header,
                unsigned char *_colorTable,
                unsigned char*_buffer)
{
    int i;
    FILE *Input;
    Input=fopen(imgName,"rb");             //read image

    if(Input==(FILE*)0)                    //error control
    {
        printf("Unable to read image\n");
    }

    for(i=0;i<54;i++)                      //read header value to image
    {
        _header[i]=getc(Input);
    }

    *_width=*(int*)&_header[18];            //Read the width from the image header array  and this indicates the offset 18 from bitmap header table
    *_height=*(int*)&_header[22];
    *_bitDepth=*(int*)&_header[28];

    if(*_bitDepth<=8)
    {
        fread(_colorTable,sizeof(unsigned char),1024,Input);
    }
    fread(_buffer,sizeof(unsigned char),CUSTOM_IMG_SIZE,Input);

    fclose(Input);
}

void img_writer(const char *imgName,         //write image (for copy)
                unsigned char *header,
                unsigned char *colorTable,
                unsigned char *buffer,
                int bitDepth)
{
    FILE*Output;                             //We use knowledge in part write to make copy image
    Output=fopen(imgName,"wb");
    fwrite(header,sizeof(unsigned char),54,Output);

    if(bitDepth<=8)
    {
        fwrite(colorTable,sizeof(unsigned char),1024,Output);
    }

    fwrite(buffer,sizeof(unsigned char),CUSTOM_IMG_SIZE,Output);
    fclose(Output);
}


int main()
{
   const char imgName[] ="images/man.bmp";
   const char newImgName[] ="images/man_copy.bmp";

   img_reader(imgName,&imgWidth,&imgHeight,&imgBitDepth,&imgHeader[0],&imgColorTable[0],&imgBuffer[0]);
   img_writer(newImgName,imgHeader,imgColorTable,imgBuffer,imgBitDepth);

   printf("Success !\n");

    return 0;
}
