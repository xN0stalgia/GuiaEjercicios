#include <stdio.h>
#include <stdlib.h>

int cuadradoNum1(float num1);
int validarNumero(float num1);

int main()
{
    float num1;
    int cuadrado;

    printf("ingrese un numero: ");
    scanf("%f",&num1);

    if(!(validarNumero(num1)))
    {
        cuadrado=cuadradoNum1(num1);
        printf("el cuadrado del numero es: %d",cuadrado);
    }
    return 0;
}

int cuadradoNum1(float num1)
{
    int cuadrado;
    cuadrado=num1*num1;
    return cuadrado;
}

int validarNumero(float num1)
{
    while(num1<0)
    {
        printf("ERROR el numero debe ser mayor a 0\n");
        return 1;
    }
    return 0;
}
