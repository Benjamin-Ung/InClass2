#include <string.h>
#include "employee.h"

//Note: 5 functions have been defined below
//ptr - points to table to be searched
//table size- size of the table
//targetPTr - points to value that will be searched for in table
//functionPtr - points to a comparision function below and will perform the associated check

//What does setting a function to static do?
//functionPtr is the address of teh function just use the name
// ()(The second set of parantheses is the argumetn of the function call)

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr, int (*functionPtr)(const void *, PtrToConstEmployee)){
    PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++){
        if((*functionPtr)(targetPtr, ptr) == 0)     //compareEmployeenumber(&1045, TableRow)
            return (PtrToEmployee) ptr;
    }
    return NULL;
}

//The function Ptr will point to one of these comparision functions to perform a check
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return * (long *)targetPtr != tableValuePtr -> number;      //targetPtr typecasted as long
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return strcmp((char *)targetPtr, tableValuePtr -> name);   //targetptr type casted as char
}
static int compareEmployeePhone(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return strcmp((char *)targetPtr, tableValuePtr -> phone);   //targetptr type casted as char
}
static int compareEmployeeSalary(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return * (double *)targetPtr != tableValuePtr -> salary;       //targetptr type casted as char
}


//These are called wrappers. these functions are what you will use in your main!!!
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number){
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char* name){
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}
PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int size, char* phone){
    return searchEmployeeTable(ptr, size, phone, compareEmployeeName);
}
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary){
    return searchEmployeeTable(ptr, size, &salary, compareEmployeeName);
}
