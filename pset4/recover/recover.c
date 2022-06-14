#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("file can't opened\n");
        return 1;
    }
    uint8_t buffer[512];
    bool firstTime = true;
    int count;
    FILE *img;
    char f[8];
    while (fread(&buffer, sizeof(uint8_t), 512, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (firstTime)
            {
                firstTime = false;
                count = 0;
                sprintf(f, "%03i.jpg", count);
                img = fopen(f, "w");
                fwrite(&buffer, 512, 1, img);


            }
            else
            {
                fclose(img);
                count++;
                sprintf(f, "%03i.jpg", count);
                img = fopen(f, "w");
                fwrite(&buffer, 512, 1, img);

            }
        }
        else
        {
            if (firstTime)
            {
                continue;
            }
            fwrite(&buffer, 512, 1, img);
        }
    }
    fclose(img);
    fclose(file);
}