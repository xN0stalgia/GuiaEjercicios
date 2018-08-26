#include <stdio.h>
#include <stdlib.h>

//int contador(float);

int main()
{
    float numero;
    int i;
    int contPos=0;
    int contNeg=0;

    for(i=0;i<10;i++)
    {
        printf("ingrese un numero: ");
        scanf("%f",&numero);
        if(i>=0)
        {
            contPos++;

        }
        else
        {
            contNeg++;

        }
    }
    printf("la cantidad de positivos son: %d\n",contPos);
    printf("la cantidad de negativos son: %d",contNeg);

    return 0;
}

/*int contador(float numero)
{
    int i;
    int contPos=0;
    int contNeg=0;

     for(i=0;i<10;i++)
    {

        if(i>0)
        {
            contPos++;

        }
        else
        {
            contNeg++;

        }

    }
    printf("la cantidad de positivos son: %d\n",contPos);
    printf("la cantidad de negativos son: %d",contNeg);

    return 0;
}*/
