#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
typedef struct{
    int id_usuario;
    int popularidad;
    char nick[40];
}s_usuario;

s_usuario* usuario_new(void);
int usuario_setIdUsuario(s_usuario* pUsuario, char* id_usuario);
int usuario_setPopularidad(s_usuario* pUsuario, char* popularidad);
int usuario_setNick(s_usuario* pUsuario, char* nick);
void parseUsuario(ArrayList* al_usuario);
void usuario_append(ArrayList* al_usuario, s_usuario* pUsuario, char* id_usuario, char* popularidad, char* nick);
