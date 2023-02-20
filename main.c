#include <stdio.h>
#include "blok1.h"

int main()
{
    uloha1_1();
    //arabToRoman();
    //uloha1_3();
    return 0;
}

int uloha1_1()
{
    int cislo, asciiKod;
    cislo = 33777;
    asciiKod = 88;

    printf("cislo %d, v dvojkovej: ", cislo);
    decToBin(cislo);
    printf("cislo %d, v desiatkovej: %d\n", cislo, cislo);
    printf("cislo %d, v hexadecimalnej: %x\n\n", cislo, cislo);

    printf("ascii kod %d, v dvojkovej: ", asciiKod);
    decToBin(asciiKod);
    printf("ascii kod %d, v desiatkovej: %d\n", asciiKod, asciiKod);
    printf("ascii kod %d, v hexadecimalnej: %x\n", asciiKod, asciiKod);

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
            if (i%4 == 0)
            {
                printf(" ");
            }
            
            if (i == 0)
            {
                printf("\n");
            }
        }
        return 0;
    }
}

//uloha1_2
int arabToRoman()
{
    int cislo;
    scanf("%d", &cislo);
    while (cislo>0)
    {
        if (cislo==100)
        {
            printf("C");
            cislo = cislo - 100;
        }
        else if(cislo>=90)
        {
            printf("XC");
            cislo = cislo - 90;
        }
        else if (cislo>=50)
        {
            printf("L");
            cislo = cislo - 50;
        }
        else if (cislo>=40)
        {
            printf("XL");
            cislo = cislo - 40;
        }
        else if (cislo>=10)
        {
            printf("X");
            cislo = cislo - 10;
        }
        else if (cislo == 9)
        {
            printf("IX");
            cislo = cislo - 9;
        }
        else if (cislo>=5)
        {
            printf("V");
            cislo = cislo - 5;
        }
        else if (cislo == 4)
        {
            printf("IV");
            cislo = cislo - 4;
        }
        else if (cislo >=1)
        {
            printf("I");
            cislo = cislo - 1;
        }
        //printf("\ncislo=%d\n", cislo);
    }    
    return 0;
}

//fibonaciho cisla
int uloha1_3()
{
    int clen1=1, clen2=1, fibC=0, k;
    scanf("%d", &k);
    if (k<2)
    {
        printf("Zadaj cislo >=2");
    }
    else
    {
        printf("1\n1\n");
        while (clen1+clen2<k)
        {
            fibC = clen1 + clen2;
            printf("%d\n", fibC);
            clen1 = clen2;
            clen2 = fibC;
        }
    }
    return 0;
}