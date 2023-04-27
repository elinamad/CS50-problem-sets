#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    BYTE buffer[512];
    int counter = 0;
    char filename[9];
    FILE *img = NULL;




    //check if exactly one command line argument
    if(argc != 2)
    {
        printf("usage: file\n");
        return 1;
    }


    //open file and check if successful

     FILE *input = fopen(argv[1], "r");
     if (input == NULL)
     {
        printf("could not open %s check if file exists\n",argv[1]);
        return 1;
     }
     else
     {
        printf("%s opened sucessfully.\n",argv[1]);
     }


    //read the whole image in chunks of 512 BYTES, store in buffer


      while(fread(buffer,1,512,input) == 512)
     {
        //if JPG file starts (checking for JPG header (first 4 bytes))

        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 )
        {
            //if image is open, then close it
            if(img != NULL)
            {
               fclose(img);
            }

            if (counter == 50)
            {

               if(input != NULL)
               {
                  fclose(input);
               }

               if(input == NULL)
               {
                  printf("%s is closed",argv[1]);
               }

               if(img != NULL)
               {
                   fclose(img);
               }

               if (img == NULL)
               {
                  printf("last image is closed");
               }

               return 0;
            }

            //create new file name ( format 000.jpg ; 001.jpg for next and so forth.)
            if (counter < 50)
            {
               sprintf(filename,"%03i.jpg",counter);
               printf("%s\n",filename);
               counter++;

               img = fopen(filename, "w");
            }

        }



         //if jpg file is created
         if (counter >= 1 )
         {
            //write

            if(img != NULL)
            {
               fwrite(buffer,1,512,img);
            }

          }

     }

     printf("found %i image files. \n",counter);


     if(img != NULL)
     {
         fclose(img);
     }

     if(input != NULL)
     {
         fclose(input);
     }


     if(img == NULL)
     {
      printf("last image is closed");
     }


     if(input == NULL)
     {
      printf("source file is closed");
     }

     return 0;




















}