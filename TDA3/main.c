#include <stdio.h>
#include <stdlib.h>
#include "TDAFecha.h"
#include "util.h"

int main()
{
    FechaPtr fecha=crearFecha(22,10,2018);
    printf("%d/%d/%d\n", getDia(fecha),getMes(fecha),getAnio(fecha));
    setDia(fecha,26);
    printf("Nueva fecha: %d/%d/%d\n", getDia(fecha),getMes(fecha),getAnio(fecha));
    FechaPtr fecha2=crearFecha(22,10,2017);
    printf("\n%d/%d/%d\n", getDia(fecha2),getMes(fecha2),getAnio(fecha2));

    printf("Diferencia en días: %d\n", calcularDiferenciaFechas(fecha,fecha2));

    // usando buffer local

    char strFecha[11];
    traerFechaCorta(fecha,strFecha);
    printf("Fecha corta: %s\n",strFecha);

    // usando memoria dinámica
    char* fcorta=obtenerMemoria(sizeof(char)*11);
    traerFechaCorta(fecha,fcorta);
    printf("Fecha corta con memoria dinámica: %s\n",fcorta);
    free(fcorta);

    // Usando memoria dinámica generada en TDAFecha
    // printf("Fecha corta dinámica: %s\n",fechaCortaDinamica(fecha));
    // como libero la memoria del string que devolvió fechaCortaDinámica? Memory leak!
    // forma correcta

    fcorta=traerFechaCortaDinamica(fecha);
    printf("Fecha corta dinámica desde TDA: %s\n",fcorta);
    free(fcorta);

    fecha=destruirFecha(fecha);
    fecha2=destruirFecha(fecha2);

    return 0;
}
