#include <stdio.h>
#include "blok1.h"

int main()
{
    int cislo, asciiKod, testCislo;
    cislo = 99999;
    asciiKod = 88;
    testCislo = 10;
    //uloha1_1(cislo, asciiKod);
    printf("%d\n", decToBin(cislo));
    printf("mocnia 10 %d, pre exponent %d\n", mocninaDesat(testCislo), testCislo);
    return 0;
}

int uloha1_1(int cislo, int asciiKod)
{
    printf("cislo %d, v dvojkovej:%d\n", cislo, decToBin(cislo));
    printf("cislo %d, v desiatkovej:%d\n", cislo, cislo);
    printf("cislo %d, v hexadecimalnej:%x\n", cislo, cislo);

    printf("ascii kod %d, v dvojkovej:%d\n", asciiKod, decToBin(asciiKod));
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
        //vypocet poctu cifier, 0 je prva cifra
        while (tmp>=1)
        {
            tmp = tmp/2;
            cifier++;
        }
        printf("cifier %d\n", cifier);
        //naplnenie pola, pole[0] je LSB
        int binCisloInvert[cifier];
        for (int i = 0; i < cifier; i++)
        {
            binCisloInvert[i] = cislo%2;
            cislo = cislo/2;
        }

        int binCislo=0;
        //vytvorenie actual binarneho cisla 
        for (int i = 0; i < cifier; i++)
        {
            binCislo = binCislo + binCisloInvert[i]*mocninaDesat(i);
            //printf("binCislo %d, opakovanie %d\n", binCislo, i );
        }
        return binCislo;
    }
}

int mocninaDesat(int exponent)
{
    int mocnina = 1;
    for (int i = 0; i < exponent; i++)
    {
        mocnina = mocnina * 10;
    }
    return mocnina;
}