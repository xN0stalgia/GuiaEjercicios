#ifndef TDAFECHA_H_INCLUDED
#define TDAFECHA_H_INCLUDED

//*******************************************************
// Interfaz de TDAFecha
//*******************************************************

// Estructura que define al tipo
typedef struct Fecha {
    int diaJuliano;
} Fecha;

// Typedef de puntero al tipo de dato
typedef Fecha* FechaPtr;

// Primitivas

// Operación de creación (Constructor)
// Precondicion: la fecha no ha sido creada
// Postcondición: se crea una fecha con día, mes y año
// Parámetros:
//  dia: entero representando el día del mes
//  mes: entero representando el mes
//  anio: entero representando el anio
// Devuelve puntero a la estructura Fecha en memoria dinámica
FechaPtr crearFecha(int dia, int mes, int anio);

// Operación de destrucción (Destructor)
// Precondicion: fecha debe haberse creado con crearFecha
// Postcondición: se destruye fecha y se libera la memoria que ocupaba
// Parámetros:
//  fecha: TDAFecha a destruir
// Devuelve NULL
FechaPtr destruirFecha(FechaPtr fecha);

// Operación de obtención de día del mes
// Precondicion: fecha debe haberse creado
// Postcondición: se obtiene el día del mes de fecha
// Parámetros:
//  fecha: TDAFecha del que es obtiene el día
// Devuelve un entero representando el día del mes
int getDia(FechaPtr fecha);

// Operación de obtencióndel mes
// Precondicion: fecha debe haberse creado
// Postcondición: se obtiene el mes de fecha
// Parámetros:
//  fecha: TDAFecha del que es obtiene el mes
// Devuelve un entero representando el mes
int getMes(FechaPtr fecha);

// Operación de obtención de año
// Precondicion: fecha debe haberse creado
// Postcondición: se obtiene el año de fecha
// Parámetros:
//  fecha: TDAFecha del que es obtiene el año
// Devuelve un entero representando el año
int getAnio(FechaPtr fecha);

// Operación de asignación de día
// Precondicion: fecha debe haberse creado
// Postcondición: fecha cambia con el nuevo valor de dia
// Parámetros:
//  fecha: TDAFecha al que se asignara el nuevo valor de dia
//  dia: entreo representando el nuevo valor de día del mes
// No devuelve valor.
void setDia(FechaPtr fecha, int dia);

// Operación de asignación de mes
// Precondicion: fecha debe haberse creado
// Postcondición: fecha cambia con el nuevo valor de mes
// Parámetros:
//  fecha: TDAFecha al que se asignara el nuevo valor de mes
//  dia: entreo representando el nuevo valor del mes
// No devuelve valor.
void setMes(FechaPtr fecha, int mes);

// Operación de asignación de año
// Precondicion: fecha debe haberse creado
// Postcondición: fecha cambia con el nuevo valor de año
// Parámetros:
//  fecha: TDAFecha al que se asignara el nuevo valor de año
//  dia: entreo representando el nuevo valor de año
// No devuelve valor.
void setAnio(FechaPtr fecha, int anio);

// Operación de resta de fechas
// Precondicion: fecha1 y fecha2 deben haberse creado
// Postcondición: se obtiene la diferencia entre ambdas fechas (fecha1-fecha2) en días
// Parámetros:
//  fecha1: TDAFecha al que se restará fecha2
//  fecha2: TDAFecha que restará a fecha1
// Devuelve un entero representando la diferencia en días
int calcularDiferenciaFechas(FechaPtr fecha1, FechaPtr fecha2);


// Operación de conversión a string
// Precondicion: fecha debe haberse creado
// Postcondición: se obtiene la representación "dd/mm/aaaa" de la fecha
// Parámetros:
//  fecha: TDAFecha a convertir
//  Buffer: buffer de memoria con capacidad para 11 char
// No devuelve valor.
void traerFechaCorta(FechaPtr fecha, char* buffer);

// Operación de conversión a string
// Precondicion: fecha debe haberse creado
// Postcondición: se obtiene la representación "dd/mm/aaaa" de la fecha en memoria dinámica
// Parámetros:
//  fecha: TDAFecha a convertir
// Devuelve puntero a la representación como srtring en memoria dinámica
// **** Recordar liberar memoria luego de utilizar ****//
char* traerFechaCortaDinamica(FechaPtr fecha);

#endif // TDAFECHA_H_INCLUDED
