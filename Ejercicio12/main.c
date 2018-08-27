#include <stdio.h>
#include <stdlib.h>

//int Impares(int);


int main()
{
    int contador=0;
    int i;

    for(i=1;i<=100;i++)
    {
        if(i%2!=0)
        {
            contador++;
        }

    }
    printf("cantidad impares: %d",contador);


    return 0;
}

/*int Impares(int numero)
{
    int contador=0;
    int i;

    for(i=1;i<=100;i++)
    {
        if(i%2!=0)
        {
            contador++;
        }

    }
    printf("cantidad impares: %d",contador);
    return 0;
}*/
