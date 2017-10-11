#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "post.h"
s_post* post_new(){
    s_post* returnAux=(s_post*)malloc(sizeof(s_post));
    return returnAux;
}
int post_setIdMensaje(s_post* pPost, char* id_mensaje){
    int returnAux=0;
    if(pPost!=NULL){
        pPost->id_mensaje=atoi(id_mensaje);
        returnAux=1;
    }
    return returnAux;
}

int post_setIdUsuario(s_post* pPost, char* id_usuario){
    int returnAux=0;
    if(pPost!=NULL){
        pPost->id_usuario=atoi(id_usuario);
        returnAux=1;
    }
    return returnAux;
}

int post_setPopularidad(s_post* pPost, char* popularidad){
    int returnAux=0;
    if(pPost!=NULL){
        pPost->popularidad=atoi(popularidad);
        returnAux=1;
    }
    return returnAux;
}

int post_setMensaje(s_post* pPost, char* mensaje){
    int returnAux=0;
    if(pPost!=NULL){
        strcpy(pPost->mensaje,mensaje);
        returnAux=1;
    }
    return returnAux;
}

void post_append(ArrayList* al_post, s_post* pPost, char* id_mensaje, char* id_usuario, char* popularidad, char* mensaje){
    post_setIdMensaje(pPost, id_mensaje);
    post_setIdUsuario(pPost, id_usuario);
    post_setPopularidad(pPost, popularidad);
    post_setMensaje(pPost, mensaje);
    al_post->add(al_post, (void*)pPost);
}


void parsePost(ArrayList* al_post){
    s_post* pPost;
    FILE* pFile;
    int flag=0;
    char id_mensaje[15], id_usuario[15], popularidad[15], mensaje[4050];
    pFile=fopen("mensajes.csv","r");
    if(pFile==NULL){
        printf("\n\nERROR FATAL AL ABRIR EL ARCHIVO\n\n"); return;
    }
    while(!(feof(pFile)))
    {
        pPost=post_new();
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id_mensaje,id_usuario,popularidad,mensaje);
        if(flag==0){
            flag=1;
            continue;
        }
        post_append(al_post, pPost,id_mensaje,id_usuario,popularidad,mensaje);
    }
    fclose(pFile);
    printf("\nTAMAÑO DEL ARRAYLIST: %d\n\n", al_len(al_post));
}
