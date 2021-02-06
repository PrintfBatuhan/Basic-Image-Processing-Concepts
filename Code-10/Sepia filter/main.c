#include <stdio.h>
#include <stdlib.h>
#define MAX_PIX         255
int main()
{
   FILE *Input=fopen("fruits.bmp","rb");
   FILE *Output=fopen("fruits_sepia.bmp","wb");

   unsigned char imgHeader[54];
   unsigned char colorTable[1024];

   if(Input==NULL)
   {
       printf("Error");
   }

   for(int i=0;i<54;i++)
   {
       imgHeader[i]=getc(Input);
   }
   fwrite(imgHeader,sizeof(unsigned char),54,Output);

   int height =*(int*)&imgHeader[22];
   int width =*(int*)&imgHeader[18];
   int bitDepth=*(int*)&imgHeader[28];

   if(bitDepth<=8)
   {
       fread(colorTable,sizeof(unsigned char),1024,Input);
       fwrite(colorTable,sizeof(unsigned char),1024,Output);
   }

   int imgSize =height*width;
   int r,g,b;
   unsigned char InBuffer[imgSize][3];

   for(int i=0;i<imgSize;i++)
   {
       r=g=b=0;
       InBuffer[i][0]=getc(Input); //Red
       InBuffer[i][1]=getc(Input); //Green
       InBuffer[i][2]=getc(Input); //Blue

       r=(InBuffer[i][0]*0.393)+(InBuffer[i][1]*0.769)+(InBuffer[i][2]*0.189);
       g=(InBuffer[i][0]*0.349)+(InBuffer[i][1]*0.686)+(InBuffer[i][2]*0.168);
       b=(InBuffer[i][0]*0.272)+(InBuffer[i][1]*0.534)+(InBuffer[i][2]*0.131);

       if(r>MAX_PIX){r=MAX_PIX;}
       if(g>MAX_PIX){g=MAX_PIX;}
       if(b>MAX_PIX){b=MAX_PIX;}

       putc(b,Output);
       putc(g,Output);
       putc(r,Output);
   }

   fclose(Output);
   fclose(Input);


    return 0;
}
