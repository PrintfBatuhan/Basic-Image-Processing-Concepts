#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *Input=fopen("baboon.bmp","rb");
    FILE *Output=fopen("baboon_blurring.bmp","wb");

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
    unsigned char OutBuffer[imgSize][3];

    for(int i=0;i<imgSize;i++)
    {
        InBuffer[i][2]= getc(Input);   //Blue
        InBuffer[i][1]= getc(Input);   //Green
        InBuffer[i][0]= getc(Input);   //Red
    }



    float kernel[3][3]={{1.0/9.0,1.0/9.0,1.0/9.0},       // Kernel matrix     	    [1][1][1]
                        {1.0/9.0,1.0/9.0,1.0/9.0},		//				      1/9 x [1][1][1]
                        {1.0/9.0,1.0/9.0,1.0/9.0} };	//						   	[1][1][1]


    // Please go to link on Readme.txt file for this section :
    for(int x=1;x<height-1;x++)
    {
        for(int y=1;y<width-1;y++)
        {
            float sum0=0.0;
            float sum1=0.0;
            float sum2=0.0;
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    sum0=sum0+(float)kernel[i+1][j+1]*InBuffer[(x+i)*width+(y+j)][0];
                    sum1=sum1+(float)kernel[i+1][j+1]*InBuffer[(x+i)*width+(y+j)][1];
                    sum2=sum2+(float)kernel[i+1][j+1]*InBuffer[(x+i)*width+(y+j)][2];
                }
            }
            OutBuffer[(x)*width+(y)][0]=sum0;
            OutBuffer[(x)*width+(y)][1]=sum1;
            OutBuffer[(x)*width+(y)][2]=sum2;
        }
    }
    // Write data
    for(int i=0;i<imgSize;i++)
    {
        putc(OutBuffer[i][2],Output);
        putc(OutBuffer[i][1],Output);
        putc(OutBuffer[i][0],Output);
    }
     // close the file
    fclose(Output);
    fclose(Input);
    return 0;
}
