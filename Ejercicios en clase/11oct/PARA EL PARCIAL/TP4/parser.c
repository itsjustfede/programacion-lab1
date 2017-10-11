#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"


void parserEmployee(ArrayList* pList)
{
    int flag=0;
    Employee* pEmployee;
    FILE* pFile;
    int len;
    char id[32], isEmpty[32], name[32], lastName[32];
    pFile=fopen("data.csv","r");
    if(pFile==NULL)
    {
        printf("\nERROR FATAL AL LEER EL ARCHIVO JAPUSH JAPUSH AEEERRRRRGGGGHHHH\n");
        return;
    }
    while(!(feof(pFile)))
    {
        pEmployee=employee_new;
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,isEmpty);
        if(flag==0){
            flag=1;
            continue;
        }
        employee_setId(pEmployee, id);
        employee_setName(pEmployee, name);
        employee_setLastName(pEmployee, lastName);
        employee_setIsEmpty(pEmployee, isEmpty);
        pList->add(pList, pEmployee);
    }
    fclose(pFile);
    len=al_len(pList);
    printf("\n\nTAMAÑO DEL ARRAYLIST: %d\n\n", len);
}
