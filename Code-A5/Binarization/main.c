#include <stdio.h>
#include <stdlib.h>

#define White 255
#define Black 0
#define Treshold 200

int main()
{
FILE *Input =fopen("lighthouse.bmp","rb");
FILE *Output=fopen("lighthouse_Bin2.bmp","wb");

unsigned char imgHeader[54];
unsigned char colorTable[1024];

if(Input==NULL)
{
    printf("Error\n");
}

    for (int i=0;i<54;i++)
    {
        imgHeader[i]=getc(Input);
    }
    fwrite(imgHeader,sizeof(unsigned char),54,Output);

    int height=*(int*)&imgHeader[22];
    int width=*(int*)&imgHeader[18];
    int bitDepth=*(int*)&imgHeader[28];

    if(bitDepth<=8)
    {
        fread(colorTable,sizeof(unsigned char),1024,Input);
        fwrite(colorTable,sizeof(unsigned char),1024,Output);
    }


    int imgSize=height*width;
    unsigned char InBuffer[imgSize];
    fread(InBuffer,sizeof(unsigned char),imgSize,Input);

    for(int i=0;i<imgSize;i++)
    {
        InBuffer[i]=(InBuffer[i]>Treshold)?White:Black;
    }
    fwrite(InBuffer,sizeof(unsigned char),imgSize,Output);
    fclose(Input);
    fclose(Output);
    return 0;
}
