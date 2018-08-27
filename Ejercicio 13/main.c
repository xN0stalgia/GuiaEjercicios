#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador=0;
    int i;

    for(i=1;i<=100;i++)
    {
        if(i%2==0)
        {
            contador++;
        }

    }
    printf("cantidad pares: %d",contador);

    return 0;
}
