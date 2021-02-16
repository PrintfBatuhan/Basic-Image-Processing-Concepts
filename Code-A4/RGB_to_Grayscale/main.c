#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *Input = fopen("lena_color.bmp","rb");
    FILE *Output = fopen("lena_gray.bmp","wb");

    unsigned char imgHeader[54];
    unsigned char colorTable[1024];

    if(Input==NULL)
    {
        printf("Error\n");
    }

    for(int i=0;i<54;i++)
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
    unsigned char InBuffer[imgSize][3];

    for(int i=0;i<imgSize;i++)
    {
        InBuffer[i][0]=getc(Input);    //RED
        InBuffer[i][1]=getc(Input);    //GREEN
        InBuffer[i][2]=getc(Input);    //BLUE

        int y=0;

        y=(InBuffer[i][0]*0.3)+(InBuffer[i][1]*0.59)+(InBuffer[i][2]*0.11);
        putc(y,Output);
        putc(y,Output);
        putc(y,Output);
    }
    printf("imgSize: %d\n",&imgSize);
    fclose(Input);
    fclose(Output);
    return 0;
}
