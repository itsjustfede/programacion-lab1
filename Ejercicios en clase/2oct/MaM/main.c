#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"





int main()
{
    eAlumno Alumnos[]= {{1, "Jose"}, {3, "Alberto"}, {4, "Juan"}, {7, "Luis"}, {10, "Ana"}, {9, "Silvia"}, {8, "Maria"}, {15, "Sofia"}, {18, "Martin"}, {11, "Dalia"}};
    eMateria Materias[]= {{1, "Progamacion"}, {2, "Matematicas"},{3, "Quimica"}, {4, "Fisica"}, {5, "Electronica"}};
    eInscripcion Inscripciones[]= {{1,2}, {1,3}, {3,2}, {4,4}, {3,5}, {3,1}, {4,1}, {1,1}, {8,1}, {9,3}, {10,2}, {10,5}, {10, 3}, {8, 1}, {1,5}};


    mostrarAlumnosConMaterias(Alumnos, 10, Materias, 5, Inscripciones, 15);
    mostrarMateriasConCantidadDeInscriptos(Materias, 5, Inscripciones, 15);
    materiaMasCursada(Materias, 5, Inscripciones, 15);

    return 0;
}
