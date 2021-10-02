//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void){
    //defined in employeeOne.c or employeeTwo.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *phoneToFind);
    
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);


    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; //delcaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);


    //Example not found
    if(matchPtr != NULL){
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    }else{
        printf("Employee ID 1045 is NOT found in the record\n");

    }

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if(matchPtr != NULL){
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    }else{
        printf("Employee Tony Bobcat is NOT found in the record\n");
    }


    //Example found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");
    if(matchPtr != NULL){
        printf("Phone number 714-555-2749 is in record %d\n", matchPtr - EmployeeTable);
    }else{
        printf("Phone numbr 714-555-2749 is NOT found in the record\n");
    }

    //Example found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 5.00);
    if(matchPtr != NULL){
        printf("Employee with salary 5.09 in record %d\n", matchPtr - EmployeeTable);
    }else{
        printf("Employee with salary 5.00 is NOT found in the record\n");
    }
    return EXIT_SUCCESS;

}