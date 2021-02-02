#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *Input = fopen("images/cameraman.bmp","rb");         //Read
    FILE *Output = fopen("images/cameraman_copy.bmp","wb");   //Write
    //FILE *variable = fopen("file name/image name","rb/wb");

    //ERROR CHECKING
    if(Input ==(FILE*)0)
    {
        printf("Unable to open file\n");
    }
/***********************Read_Part***************************/
    //Some variables to hold the image head and color table. For bitMap Format:
    unsigned char header[54];        //Image Header is 54 bytes for BMP
    unsigned char colorTable[1024];  //Color Table is 1028 bytes for BMP

    for(int i=0; i<54; i++)
    {
        header[i]=getc(Input);
    }
    int width =*(int*)&header[18];   //Read the width from the image header array  and this indicates the offset 18 from bitmap header table
    int height =*(int*)&header[22];  // offset 22 from bitmap header table
    int bitDepth=*(int*)&header[28]; // offset 28 from bitmap header table

    if(bitDepth<=8)                  //If color table exists, we're going to read it here
    {
        fread(colorTable,sizeof(unsigned char),1024,Input);
    }

     unsigned char buff[height * width];
     fread(buff,sizeof(unsigned char), (height*width), Input); // Read pixel data and store it buffer
                                                               //this large parameter is basically Input

/***********************Write_Part***************************/

     fwrite(header,sizeof(unsigned char),54,Output);

     if(bitDepth<=8)
     {
         fwrite(colorTable,sizeof(unsigned char),1024,Output);
     }
         fwrite(buff,sizeof(unsigned char),(height*width),Output);

         fclose(Output); //close both files
         fclose(Input);

         printf("Success\n");
         printf("Width: %d\n", width);
         printf("Height: %d\n", height);

  return 0;
}
