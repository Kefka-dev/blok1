#include <stdio.h>
#include "blok1.h"

int main()
{
    int cislo, asciiKod;
    cislo = 33777;
    asciiKod = 88;
    uloha1_1(cislo, asciiKod);
    return 0;
}

int uloha1_1(int cislo, int asciiKod)
{
    printf("cislo %d, v dvojkovej:", cislo);
    decToBin(cislo);
    printf("cislo %d, v desiatkovej:%d\n", cislo, cislo);
    printf("cislo %d, v hexadecimalnej:%x\n\n", cislo, cislo);

    printf("ascii kod %d, v dvojkovej:", asciiKod);
    decToBin(asciiKod);
    printf("ascii kod %d, v desiatkovej:%d\n", asciiKod, asciiKod);
    printf("ascii kod %d, v hexadecimalnej:%x\n", asciiKod, asciiKod);

    return 0;
}

int decToBin(int cislo)
{
    if (cislo == 0)
    {
        return 0;
    }
    else
    {
        int cifier = 0;
        int tmp = cislo;
        //vypocet poctu cifier, 0 je prva cifra, algoritmums z Logickych systemov
        while (tmp>=1)
        {
            tmp = tmp/2;
            cifier++;
        }
        //printf("cifier %d\n", cifier);
        //naplnenie pola, pole[0] je LSB
        int binCisloInvert[cifier];
        for (int i = 0; i < cifier; i++)
        {
            binCisloInvert[i] = cislo%2;
            cislo = cislo/2;
        }

        for (int i = cifier-1; i >= 0; i--)
        {
            printf("%d",binCisloInvert[i]);
            if (i == 0)
            {
                printf("\n");
            }
        }
        return 0;
    }
}