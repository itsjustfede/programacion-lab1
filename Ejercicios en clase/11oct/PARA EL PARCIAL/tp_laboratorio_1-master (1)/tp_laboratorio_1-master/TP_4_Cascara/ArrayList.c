#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

#define AL_INITIAL_VALUE 15

ArrayList* al_newArrayList(void)
{
    ArrayList *NewArray;
    ArrayList* AuxRetorno = NULL;
    void* pElements;

    NewArray=(ArrayList*)malloc(AL_INITIAL_VALUE);

    if(NewArray != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            NewArray->size=0;
            NewArray->pElements=pElements;
            NewArray->reservedSize=AL_INITIAL_VALUE;
            NewArray->add=al_add;
            NewArray->len=al_len;
            NewArray->set=al_set;
            NewArray->remove=al_remove;
            NewArray->clear=al_clear;
            NewArray->clone=al_clone;
            NewArray->get=al_get;
            NewArray->contains=al_contains;
            NewArray->push=al_push;
            NewArray->indexOf=al_indexOf;
            NewArray->isEmpty=al_isEmpty;
            NewArray->pop=al_pop;
            NewArray->subList=al_subList;
        /// NewArray->containsAll=al_containsAll;   /// FUNCION NO HECHA
            NewArray->deleteArrayList = al_deleteArrayList;
        /// NewArray->sort = al_sort;               /// FUNCION NO HECHA
            AuxRetorno = NewArray;
        }
    }
        else
            free(NewArray);

    return NewArray;
}

int al_add(ArrayList* pList,void* pElement)
{
    int ValidarTam;
    int retorno=-1;

    if(pList!=NULL&&pElement!=NULL)
    {
        if (pList->size==pList->reservedSize)
            ValidarTam=resizeUp(pList);

        if(ValidarTam)
        {
            pList->pElements[pList->size]=pElement;
            pList->size++;

            retorno=0;
        }
    }

    return retorno;

}

int al_deleteArrayList(ArrayList* pList)
{
    int retorno=-1;

    if(pList!=NULL)
    {
        free(pList->pElements);
        free(pList);

        retorno=0;
    }

    return retorno;
}

int al_len(ArrayList* pList)
{
    int retorno=-1;

    if (pList!=NULL)
    {
        retorno=pList->size;
    }

    return retorno;
}

void* al_get(ArrayList* pList , int index)
{
    int i;
    void* retorno=NULL;

    if (pList!=NULL)
    {
        for (i=0;i<pList->size;i++)
        {
            if (pList->pElements[i]==(index-1))
            {
                retorno=pList->pElements[i];
                break;
            }

        }
    }

    return retorno;
}

int al_contains(ArrayList* pList, void* pElement)
{
    int retorno=-1;
    int i;

    if (pList!=NULL&&pElement!=NULL)
    {
        for (i=0;i<pList->size;i++)
        {
            if (pList->pElements[i]==(i-1))
            {
                retorno=1;
                break;
            }
        }

        if (pList->size==i&&retorno!=1)
            retorno=0;
    }

    return retorno;
}

int al_set(ArrayList* pList, int index,void* pElement)
{
    int retorno;

    if(pList!=NULL&pElement!=NULL)
    {
        pList->pElements[index]=pElement;

        retorno=0;
    }

    return retorno;
}

int al_remove(ArrayList* pList,int index)
{
    int retorno=-1;
    int ValidarContract;

    if(pList!=NULL)
    {
        ValidarContract=contract(pList,index);

        if (ValidarContract)
        {
            retorno=0;
            pList->size--;
        }

    }

    return retorno;

}

int al_clear(ArrayList* pList)
{
/** no se como se haceeeee lalalalalalalalalala */
}

ArrayList* al_clone(ArrayList* pList)
{
    int retorno;
    ArrayList* ClonedArray;
    void* AuxArray;

    if (pList!=NULL)
    {
        ClonedArray=(ArrayList*)malloc(pList->reservedSize);

        if (ClonedArray!=NULL)
        {
            AuxArray=(void*)realloc(pList->pElements,sizeof(void*)*(pList->reservedSize));

            if (AuxArray!=NULL)
            {
                ClonedArray->size=pList->size;
                ClonedArray->reservedSize=pList->reservedSize;
                ClonedArray->pElements=AuxArray;

                free(AuxArray);
            }
        }

    }
}

int al_push(ArrayList* pList, int index,void* pElement)
{
    int retorno=-1;
    int ValidarExpnd;

    if(pList!=NULL&pElement!=NULL)
    {
        ValidarExpnd=expand(pList,index);

        if (ValidarExpnd)
        {
            pList->pElements[index]=pElement;
            retorno=0;
        }

    }

    return retorno;
}

int al_indexOf(ArrayList* pList, void* pElement)
{
    int retorrno=-1;

    if(pList!=NULL&&pElement!=NULL)
    {
        if (pList->size!=0)
            retorrno=1;
    }

    return retorrno;
}

int al_isEmpty(ArrayList* pList)
{
    int retorno=-1;

    if (pList!=NULL)
    {
        if(pList->size!=0)
            retorno=0;
            else
                retorno=1;
    }

    return retorno;
}

void* al_pop(ArrayList* pList,int index)
{
    int ValidarRemove;
    void* retorno;

    if (pList!=NULL)
    {
        retorno=pList->pElements[index];

        ValidarRemove=al_remove(pList,index);
    }

    return retorno;
}

ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    int i;
    int cont=0;
    int ValidarResize;
    ArrayList* retorno;



    if(pList!=NULL)
    {
        retorno=al_newArrayList();
        if (retorno==NULL)
        {
            while (retorno->reservedSize<(to-from))
            {
                ValidarResize=resizeUp(retorno);
                if (ValidarResize==0)
                    break;
            }


            for(i=from;i<=to;i++)
            {
                retorno->pElements[cont]=pList->pElements[i];
            }
        }


    }

    return retorno;
}

int resizeUp(ArrayList* pList)
{
    int retorno=0;
    void* aux;


    if(pList!=NULL)
    {
        aux=(void*)realloc(pList->pElements,sizeof(void*)*(pList->reservedSize+AL_INITIAL_VALUE));
        if(aux!=NULL)
        {
            pList->pElements=aux;
            pList->reservedSize+=AL_INITIAL_VALUE;

            retorno=1;
        }
        free(aux);
    }

    return retorno;
}

int expand(ArrayList* pList,int index)
{
    int retorno=0;
    int i;
    int ValidarTam=1;

    if (pList!=NULL)
    {
        if (pList->size==pList->reservedSize)
            ValidarTam=resizeUp(pList);

        if (ValidarTam)
        {
            for (i=(pList->size-1);i<=index;i--)
                pList->pElements[i+1]=pList->pElements[i];

            pList->size++;
            retorno=1;
        }
    }

    return retorno;
}

int contract(ArrayList* pList,int index)
{
    int retorno=0;
    int i;

    if (pList!=NULL)
    {
        for (i=index;i<pList->size;i++)
        {
            pList->pElements[i]=pList->pElements[i+1];

        }
        pList->size--;
        retorno=1;
    }

    return retorno;
}

