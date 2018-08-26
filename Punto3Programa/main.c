#include <stdio.h>
#include <stdlib.h>

float DistintoDe0(float,float);
int cuadradoNum1(float);

int main()
{
    float num1=4;
    float num2=2;
    int cuadrado;

    system("cls");
    DistintoDe0(num1,num2);
    printf("\n");
    cuadrado=cuadradoNum1(num1);
    printf("el cuadrado del numero 1 es: %d",cuadrado);


    return 0;
}


float DistintoDe0(float num1,float num2)
{
    float total;

    if(!(num1==0 || num2==0))
    {
       total=num1/num2;
       printf("el producto es: %.2f",total);
       return total;

    }
    else{
        printf("error los numeros deben ser distintos que 0");
    }
    return 0;
}

int cuadradoNum1(float num1)
{
    int cuadrado;
    cuadrado=num1*num1;
    return cuadrado;
}
