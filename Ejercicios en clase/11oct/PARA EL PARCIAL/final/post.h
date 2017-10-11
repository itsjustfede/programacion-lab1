#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
typedef struct{
    int id_mensaje;
    int id_usuario;
    int popularidad;
    char mensaje[4050];
}s_post;

s_post* post_new(void);

int post_setIdMensaje(s_post* pPost, char id_mensaje[5]);

int post_setIdUsuario(s_post* pPost, char* id_usuario);

int post_setPopularidad(s_post* pPost, char* popularidad);

int post_setMensaje(s_post* pPost, char* mensaje);

void post_append(ArrayList* al_post, s_post* pPost, char* id_mensaje, char* id_usuario, char* popularidad, char* mensaje);

void parsePost(ArrayList* al_usuario);
