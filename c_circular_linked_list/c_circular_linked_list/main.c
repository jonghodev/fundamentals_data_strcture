#include "CLinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Employee.h"

int main(int argc, const char * argv[]) {
    List list;
    ListInit(&list);
    Employee *employee;
    
    employee = (Employee*)malloc(sizeof(Employee));
    employee->num = 1;
    employee->name = "Jongho";
    LInsert(&list, employee);

    employee = (Employee*)malloc(sizeof(Employee));
    employee->name = "Jieun";
    employee->num = 2;
    LInsert(&list, employee);

    employee = (Employee*)malloc(sizeof(Employee));
    employee->name = "Wonseok";
    employee->num = 3;
    LInsert(&list, employee);

    employee = (Employee*)malloc(sizeof(Employee));
    employee->name = "Minho";
    employee->num = 4;
    LInsert(&list, employee);
    
    Employee *data;
    if (LFirst(&list, &data))
    {
        printf("%s is working time. %s num is %d. \n", data->name, data->name, data->num);

        if (LNext(&list, &data))
            printf("%s is working time. %s num is %d. \n", data->name, data->name, data->num);
    }

    return 0;
}
