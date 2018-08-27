#include <stdio.h>
#include <stdlib.h>

char caracterContador();

int main()
{
    caracterContador();

    return 0;
}


char caracterContador( )
{
    int i;
    char letra;
    int contadorA=0;
    int contadorE=0;
    int contadorI=0;
    int contadorO=0;
    int contadorU=0;

    for(i=0;i<20;i++)
    {
         printf("ingrese una letra: ");
         scanf("%c",&letra);

        while(i=='a'||i =='A')
        {
            contadorA++;
        }
        while(i=='e'||i=='E')
        {
            contadorE++;
        }
        while(i=='i'||i=='I')
        {
            contadorI++;
        }
        while(i=='o'||i=='O')
        {
            contadorO++;
        }
        while(i=='u'||i=='U')
        {
            contadorU++;
        }


    }
    printf("cantidad de a: %c",contadorA);
    printf("cantidad de e: %c",contadorE);
    printf("cantidad de i: %c",contadorI);
    printf("cantidad de o: %c",contadorO);
    printf("cantidad de u: %c",contadorU);
    return 0;
}

