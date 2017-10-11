#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "usuario.h"

s_usuario* usuario_new(){
    s_usuario* returnAux=(s_usuario*)malloc(sizeof(s_usuario));
    return returnAux;
}

int usuario_setIdUsuario(s_usuario* pUsuario, char* id_usuario){
    int returnAux=0;
    if(pUsuario!=NULL){
        pUsuario->id_usuario=atoi(id_usuario);
        returnAux=1;
    }
    return returnAux;
}

int usuario_setPopularidad(s_usuario* pUsuario, char* popularidad){
    int returnAux=0;
    if(pUsuario!=NULL){
        pUsuario->popularidad=atoi(popularidad);
        returnAux=1;
    }
    return returnAux;
}

int usuario_setNick(s_usuario* pUsuario, char* nick){
    int returnAux=0;
    if(pUsuario!=NULL){
        strcpy(pUsuario->nick,nick);
        returnAux=1;
    }
    return returnAux;
}

void usuario_append(ArrayList* al_usuario, s_usuario* pUsuario, char* id_usuario, char* popularidad, char* nick){
    usuario_setIdUsuario(pUsuario, id_usuario);
    usuario_setPopularidad(pUsuario, popularidad);
    usuario_setNick(pUsuario, nick);
    al_usuario->add(al_usuario, (void*)pUsuario);
}

void parseUsuario(ArrayList* al_usuario){
    s_usuario* pUsuario;
    FILE* pFile;
    int flag=0;
    char id_usuario[15], nick[50], popularidad[15];
    pFile=fopen("usuarios.csv","r");
    if(pFile==NULL){
        printf("\n\nERROR FATAL AL ABRIR EL ARCHIVO\n\n"); return;
    }
    while(!(feof(pFile)))
    {
        pUsuario=usuario_new();
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id_usuario,nick,popularidad);
        if(flag==0){
            flag=1;
            continue;
        }
        usuario_append(al_usuario, pUsuario,id_usuario,popularidad,nick);
    }
    fclose(pFile);
    printf("\nTAMAÑO DEL ARRAYLIST: %d\n\n", al_len(al_usuario));
}
