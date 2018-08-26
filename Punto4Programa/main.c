#include <stdio.h>
#include <stdlib.h>

float resta(float,float);
float validarResta(float,float);

int main()
{
   system("cls");
   float num1=4;
   float num2=2;
   float total;

   total=resta(num1,num2);
   printf("la resta es: %.2f",total);
   printf("\n");
   validarResta(num1,num2);


    return 0;
}

float resta(float num1,float num2)
{
    float total;
    total=num1-num2;
    return total;
}

float validarResta(float num1,float num2)
{
    if(resta(num1,num2)>=0)
    {
        printf("el resultado es positivo");
    }
    else
    {
     printf("el resultado es negativo");
    }

    return 0;

}
