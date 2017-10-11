#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


void employee_print(ArrayList* pList)
{
    int i=0;
    Employee sEmployee;
    Employee* pAux=&sEmployee;//CREAMOS UN PUNTERO A ESTRUCTURA TIPO Employee
    for(i=0;i<pList->size;i++){
        pAux= (Employee*)pList->get(pList,i);
        printf("ID: %d - NAME: %s - LAST NAME: %s - IS EMPTY: %d\n",pAux->id,pAux->name,pAux->lastName,pAux->isEmpty);
        }
}


Employee* employee_new(void)
{
    Employee* returnAux=(Employee*)malloc(sizeof(Employee));
    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* pEmployee, char* id)
{
    int returnAux=-1;
    if (pEmployee!=NULL){
        system("cls");
        pEmployee->id=atoi(id);
        returnAux=0;
    }
    return returnAux;
}
int employee_setName(Employee* this, char* name)
{
    int returnAux=-1;
    if(this != NULL && strlen(name) > 0){
        strncpy(this->name,name,32);
        returnAux=0;
    }
    return returnAux;
}

int employee_setLastName(Employee* this, char lastName[32])
{
    int returnAux=-1;
    if (this!=NULL){
        strcpy(this->lastName,lastName);
        returnAux=0;
    }
    return returnAux;
}
int employee_setIsEmpty(Employee* this, char isEmpty[32])
{
    int returnAux=-1;
    if (this!=NULL){
        if(!(strcmp(isEmpty,"true")))
            this->isEmpty=1;
        else
            this->isEmpty=0;
        returnAux=0;
    }
    return returnAux;
}
int employee_getId(Employee* this)
{

    return 0;

}


