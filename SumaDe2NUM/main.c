#include <stdio.h>
#include <stdlib.h>
float suma(float,float);

int main()
{
    float num1;
    float num2;
    float total;

    printf("ingrese el primer numero a sumar: ");
    scanf("%f",&num1);
    printf("ingrese el segundo numero a sumar: ");
    scanf("%f",&num2);
    total=suma(num1,num2);
    printf("la suma es: %.2f", total);

    return 0;
}


float suma(float A , float B)
{
    float total;
    total =A+B;
    return total;
}
