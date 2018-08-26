#include <stdio.h>
#include <stdlib.h>


float promedio(int,int,int);
//void menu();
//int soloNum(int);

int main()
{
    float num1;
    int num2;
    int num3;
    float total;

   // menu();

   printf("ingrese un numero para realizar el promedio: ");
   scanf("%f",&num1);
   printf("ingrese un numero para realizar el promedio: ");
   scanf("%d",&num2);
   printf("ingrese un numero para realizar el promedio: ");
   scanf("%d",&num3);
   total=promedio(num1,num2,num3);
   printf("el promedio es: %.2f", total);


    return 0;
}

float promedio(int a,int b,int c)
{

    float total;
    int suma;
    suma=(a+b+c);
    total=(float)suma;
    return total;
}


/**void menu()
{
    printf("1- Sumar\n");
    printf("2- Restar\n");
    printf("3- Dividir\n");
    printf("4- Multiplicacion\n");
    system("cls");
}*/

