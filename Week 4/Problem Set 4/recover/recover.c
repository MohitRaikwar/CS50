#include <stdio.h>
#include <stdlib.h>
typedef __uint8_t BYTE;
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    BYTE buffer[512];
    if (buffer == NULL)
    {
        return 1;
    }
    char *filename = malloc(3 * sizeof(int));
    int photoCount = 0;

    while (fread(buffer, 512, 1, card) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (photoCount == 1)
            {
                sprintf(filename, "%03i.jpg", photoCount);
                FILE *imageFile = fopen(filename, "w");
                fwrite(buffer, 512, 1, imageFile);
                fclose(imageFile);
            }
            else
            {
                sprintf(filename, "%03i.jpg", photoCount);
                FILE *imageFile = fopen(filename, "w");
                fwrite(buffer, 512, 1, imageFile);
                fclose(imageFile);
            }
            photoCount++;
        }
        else if (photoCount != 0)
        {
            FILE *imageFile = fopen(filename, "a");
            fwrite(buffer, 512, 1, imageFile);
            fclose(imageFile);
        }

    }
    free(filename);
    printf("contagem = %i\n", photoCount);
}