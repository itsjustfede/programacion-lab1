#include "funcionesVarias.h"
#include "usuario.h"
#include "post.h"
void listar(ArrayList* al_post, ArrayList* al_usuario){
    system("cls");
    s_post* pPost=post_new();
    s_usuario* pUsuario=usuario_new();
    int i=0;
    for(i=0;i<al_usuario->size;i++){
        pUsuario=(s_usuario*)al_get(al_usuario,i);
        printf("ID: %i - NOMBRE: %s - POPULARIDAD: %i / ",pUsuario->id_usuario,pUsuario->nick,pUsuario->popularidad);
    }
    system("pause");
    system("cls");
    for(i=0;i<al_post->size;i++){
        pPost=(s_post*)al_get(al_post,i);
        printf("\n%i,%i,%i,%s\n",pPost->id_usuario,pPost->id_mensaje,pPost->popularidad,pPost->mensaje);
    }
    system("pause");
    system("cls");
}

/*int compare_seguidores(void* pUsuarioA,void* pUsuarioB)
{
    int retorno;
    void* auxiliarA = (void*)pUsuarioA;
    void* auxiliarB = (void*)pUsuarioB;
    if(strcmp(auxiliarA->nick,auxiliarB->nick)<0)
        retorno = 1;
    else if(strcmp(auxiliarA->nick,auxiliarB->nick)>0)
        retorno = -1;
    else if(strcmp(auxiliarA->nick,auxiliarB->nick)==0)
        retorno = 0;
    return retorno;
}

int compare_string(void* pUsuarioA,void* pUsuarioB)
{
    int retorno;

    void* auxiliarA = (void*)pUsuarioA;
    void* auxiliarB = (void*)pUsuarioB;

    if(auxiliarA->seguidores < auxiliarB->seguidores)
        retorno = 1;
    else if(auxiliarA->seguidores > auxiliarB->seguidores)
        retorno = -1;
    else if(auxiliarA->seguidores == auxiliarB->seguidores)
        retorno = 0;

    return retorno;
}*/
