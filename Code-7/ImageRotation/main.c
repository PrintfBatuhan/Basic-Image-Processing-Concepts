#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *InputImg=fopen("cameraman.bmp","rb");
    FILE *OutputImg=fopen("cameraman_rotated.bmp","wb");

    int selected;

    unsigned char imgHeader[54];
    unsigned char colorTable[1024];

    if(InputImg == NULL)
    {
        printf("Unable to open file\n");
    }


    for(int i=0;i<54;i++)
    {
        imgHeader[i]=getc(InputImg);
    }
    fwrite(imgHeader,sizeof(unsigned char),54,OutputImg);

    int height = *(int*)&imgHeader[22];
    int width = *(int*)&imgHeader[18];
    int bitDepth = *(int*)&imgHeader[28];

    if(bitDepth<=8)
    {
        fread(colorTable,sizeof(unsigned char),1024,InputImg);
        fwrite(colorTable,sizeof(unsigned char),1024,OutputImg);
    }

    int imgSize = height * width;
    unsigned char in_buffer[width][height];
    unsigned char out_buffer[width][height];

    fread(in_buffer,sizeof(unsigned char),imgSize,InputImg);

    printf("Enter rotation direcrion:\n ");
    printf("1 :Rotate right\n ");
    printf("2 :Rotate left \n ");
    printf("3 :Rotate 180 degree\n");
    scanf("%d",&selected);

    switch(selected)
    {
    case 1:
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<height;j++)
            {
                out_buffer[j][height-1-i]=in_buffer[i][j];
            }
        }
//Let's say that (0,0) is the upper-left corner, and we are wanting to rotate left 90 degrees. Then the upper-left corner of the rotated image is equivalent to the upper-right corner of the original image, which is at (original_height-1,0).
//As you go across the top of the image, increasing, x, you are grabbing pixels from the original image along the right side, increasing y, so the x of your rotated image is like the y of the original image.
//As you go down in the rotated_image, increasing y, you are moving more to the left of the original_image, which is why we're subtracting rotated_y from original_height-1 to get the original_x coordinate.
//Another thing to notice is that the width and height of the rotated image are reversed from the orignal image.
        break;

    case 2:
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<height;j++)
            {
                out_buffer[j][i]=in_buffer[i][j];
            }
        }
        break;

    case 3:
         for(int i=0;i<width;i++)
        {
            for(int j=0;j<height;j++)
            {
                out_buffer[width-i][j]=in_buffer[i][j];
            }
        }

        break;

    default:
        break;
    }

    fwrite(out_buffer,sizeof(unsigned char),imgSize,OutputImg);
    printf("Well Done\n");

    fclose(InputImg);
    fclose(OutputImg);

    return 0;
}
