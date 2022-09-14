#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct Estudiante{
    char* apellido;
    char* nombre;
    int dni;
    int legajo;
};

typedef struct Estudiante Estudiante;
typedef Estudiante* EstudiantePtr;

typedef struct Docente{
    char* apellido;
    char* nombre;
    int cuil;
    int legajo;
} Docente;
typedef Docente* DocentePtr;

typedef struct Curso{
    char* nombre;
    DocentePtr docente;
    int anio;
    int cuatrimestre;
    Estudiante estudiantes[30];
} Curso;


typedef Curso* CursoPtr;


void mostrarEstudiante(struct Estudiante e);
void mostrarEstudiantePtr(struct Estudiante *e);
void* obtenerMemoria(size_t tamanio);
int agregarEstudiantePorIndice(CursoPtr curso, char* nombre, char*
apellido, int legajo, int dni, int indice);
void mostrarCurso(CursoPtr curso);
int eliminarEstudiante(CursoPtr curso,int indice);


EstudiantePtr crearEstudiante(char* nombre, char* apellido, int legajo, int dni);
EstudiantePtr destruirEstudiante(EstudiantePtr ep);

DocentePtr crearDocente(char* nombre, char* apellido, int legajo, int cuil);
DocentePtr destruirDocente(DocentePtr dp);

CursoPtr crearCurso(char* nombre, DocentePtr docente, int anio, int cuatrimestre);
CursoPtr destruirCurso(CursoPtr cp);




int main()
{


    struct Estudiante e = {"Perez", "Juan", 35624896, 123456 };

    printf("Estudiante: %s, %s\n",e.apellido, e.nombre);

    struct Estudiante  e2 = { .nombre="Jose", .apellido="Lopez", .legajo=333333, .dni=12345678 };

    printf("Estudiante: %s, %s\n",e2.apellido, e2.nombre);


    struct Estudiante estudiantes[4];
    estudiantes[0]=(Estudiante){"Perez", "Juan", 35624896, 123456 };
    estudiantes[1]=(Estudiante){"Rodriguez", "Jose", 44444444, 123457 };
    estudiantes[2]=(Estudiante){"Perez", "Juan", 35624896, 123456 };
    estudiantes[3]=(Estudiante){ .nombre="Jose", .apellido="Lopez", .legajo=333333, .dni=12345678 };


    struct Estudiante estudiantes2[]={{"Perez", "Juan", 35624896, 123456 },
                                      {"Rodriguez", "Jose", 44444444, 123457 },
                                      {"Perez", "Juan", 35624896, 123456 },
                                      {.nombre="Jose", .apellido="Lopez", .legajo=333333, .dni=12345678 }};



    int k=0;
    for(k=0;k<4;k++){
        mostrarEstudiante(estudiantes2[k]);
    }

    //return 0;

    printf("\nPase con Punteros\n\n");

    for(k=0;k<4;k++){
        mostrarEstudiantePtr(&estudiantes[k]);
    }



    EstudiantePtr ep=(EstudiantePtr)obtenerMemoria(sizeof(Estudiante));
    ep->nombre="Laura";
    ep->apellido="Rojas";
    ep->legajo=9999999;
    ep->dni=55555555;

    mostrarEstudiantePtr(ep);

    mostrarEstudiante(*ep);

    free(ep);

    ep=crearEstudiante("Roberto","Olivera",555555,66666666);

    mostrarEstudiantePtr(ep);

    ep = destruirEstudiante(ep);

    printf("%lu\n", sizeof(Estudiante));
    printf("%lu\n", sizeof(Docente));
    printf("%lu\n", sizeof(Curso));

    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(char*));

    Docente d1 = {"Perez", "Juan", 35624896, 123456 };
    Curso c1={"Programación", &d1,2018,1};
    printf("%s\n",c1.docente->nombre);

    return 0;

}

void mostrarEstudiante(Estudiante e){
    printf("--------------------------------------------\n");
    printf("Estudiante legajo %d:\n", e.legajo);
    printf("--------------------------------------------\n");
    printf("Apellido y nombre: %s, %s\nDNI: %d\n\n",e.apellido, e.nombre, e.dni);
}

void mostrarEstudiantePtr(Estudiante *e){
    printf("--------------------------------------------\n");
    printf("Estudiante legajo %d:\n", e->legajo);
    printf("--------------------------------------------\n");
    printf("Apellido y nombre: %s, %s\nDNI: %d\n\n",e->apellido, e->nombre, e->dni);
}



void* obtenerMemoria(size_t tamanio){
    void* ptr=malloc(tamanio);
    if(ptr==NULL){
        printf("No se ha podido obtener memoria\n");
        exit(1);
    }
    return ptr;
}

/*
EstudiantePtr crearEstudiante(char* nombre, char* apellido, int legajo, int dni){

    EstudiantePtr ep=(EstudiantePtr)obtenerMemoria(sizeof(Estudiante));

    ep->nombre=nombre;
    ep->apellido=apellido;
    ep->legajo=legajo;
    ep->dni=dni;

    return ep;
}*/

EstudiantePtr crearEstudiante(char* nombre, char* apellido, int legajo, int dni){

    EstudiantePtr ep=(EstudiantePtr)obtenerMemoria(sizeof(Estudiante));
    char* nom=(char*)obtenerMemoria(sizeof(char)*(strlen(nombre)+1));
    char* ape=(char*)obtenerMemoria(sizeof(char)*(strlen(apellido)+1));
    strcpy(nom,nombre);
    strcpy(ape,apellido);
    ep->nombre=nom;
    ep->apellido=ape;
    ep->legajo=legajo;
    ep->dni=dni;

    return ep;
}

EstudiantePtr destruirEstudiante(EstudiantePtr ep){

    free(ep->nombre);
    free(ep->apellido);
    free(ep);

    return NULL;
}

DocentePtr crearDocente(char* nombre, char* apellido, int legajo, int cuil)
{
    DocentePtr dp=(DocentePtr)obtenerMemoria(sizeof(Docente));
    char* name=(char*)obtenerMemoria(sizeof(char)*(strlen(nombre)+1));
    char* lastName=(char*)obtenerMemoria(sizeof(char)*(strlen(apellido)+1));
    strcpy(name,nombre);
    strcpy(lastName,apellido);
    dp->nombre=name;
    dp->apellido=lastName;
    dp->cuil=cuil;
    dp->legajo=legajo;

    return dp;
}

DocentePtr destruirDocente(DocentePtr dp)
{
    free(dp->nombre);
    free(dp->apellido);
    free(dp);

    return NULL;
}

CursoPtr crearCurso(char* nombre, DocentePtr docente, int anio, int cuatrimestre)
{
    CursoPtr cp=(CursoPtr)obtenerMemoria(sizeof(CursoPtr));
    cp->docente=docente;
    char* name=(char*)obtenerMemoria(sizeof(char)*(strlen(nombre)+1));
    strcpy(nombre,name);
    cp->nombre=name;
    cp->anio=anio;

    for(int k=0;k<30;k++)
    {
       cp->estudiantes[k].apellido=NULL;
       cp->estudiantes[k].nombre=NULL;
       cp->estudiantes[k].dni=NULL;//falta castear
       cp->estudiantes[k].legajo=NULL;//falta castear
    }

    return cp;
}

CursoPtr destruirCurso(CursoPtr cp)
{
    free(cp->nombre);
    free(cp->docente);
    free(cp->estudiantes);
    free(cp);

    return NULL;
}


int agregarEstudiantePorIndice(CursoPtr curso, char* nombre, char*
apellido, int legajo, int dni, int indice)
{
    indice=0;
    while(indice < 30)
    {
        indice++;
       if(curso->estudiantes[indice].apellido==NULL && curso->estudiantes[indice].nombre==NULL)
        {
            crearEstudiante(nombre,apellido,legajo,dni);
            return indice;
        }
    }
    return -1;
}


void mostrarCurso(CursoPtr curso)
{
    printf("-------CURSOS--------");
    printf("--------------------------------------------\n");
    printf("anio %d:\n",curso->anio );
    printf("--------------------------------------------\n");
    printf("Cuatrimestre %d: ",curso->cuatrimestre);
    printf("--------------------------------------------\n");
    printf("Docente Apellido y Nombre:%s,%s",curso->docente->apellido,curso->docente->nombre);
    printf("--------------------------------------------\n");
   for(int i=0;i<30;i++)
   {
       if(curso->estudiantes[i].nombre!=NULL && curso->estudiantes[i].apellido!=NULL)
       {
            printf("Estudiante Apellido y Nombre: %s,%s\n",curso->estudiantes[i].apellido,curso->estudiantes[i].nombre);
       }
   }

}

/**int eliminarEstudiante(CursoPtr curso,int indice)
{

}**/

