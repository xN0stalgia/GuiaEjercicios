#include <stdio.h>
#include <stdlib.h>
float superficieTriangulo(float,float);

int main()
{
    float base;
    float altura;
    float superficie;

    printf("ingrese la base del triangulo: ");
    scanf("%f",&base);
    printf("ingrese la altura del triangulo: ");
    scanf("%f",&altura);
    superficie=superficieTriangulo(base,altura);
    printf("la superficie del triangulo es: %.2f",superficie);

    return 0;
}


float superficieTriangulo(float base, float altura)
{
    float resultado;

    resultado=base*(altura/2);
    return resultado;
}
