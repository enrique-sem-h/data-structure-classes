/*Crie uma struct chamada "Funcionario" com campos para nome, cargo, salário e data de admissão. Implemente funções para dar um aumento de salário e calcular quanto tempo um funcionário está na empresa.*/

#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct Employee {
    char name[50];
    char position[50];
    float salary;
    struct tm hireDate;
} Employee;

void giveSalaryRaise(Employee *employee, float raiseAmount) {
    employee->salary += raiseAmount;
    printf("%s's salary has been increased by $%.2f. New salary: $%.2f\n", employee->name, raiseAmount, employee->salary);
}

int calculateYearsOfWork(Employee *employee) {
    time_t currentTime;
    time(&currentTime);
    struct tm *currentDate = localtime(&currentTime);

    int years = currentDate->tm_year - employee->hireDate.tm_year;
    if (currentDate->tm_mon < employee->hireDate.tm_mon ||
        (currentDate->tm_mon == employee->hireDate.tm_mon && currentDate->tm_mday < employee->hireDate.tm_mday)) {
        years--;
    }

    return years;
}

int main() {
    Employee emp1 = {
        .name = "John Doe",
        .position = "Manager",
        .salary = 50000.0,
        .hireDate = { .tm_year = 2020 - 1900, .tm_mon = 6, .tm_mday = 15 }
    };

    printf("Employee: %s\nPosition: %s\nSalary: $%.2f\nHire Date: %d-%02d-%02d\n",
           emp1.name, emp1.position, emp1.salary,
           emp1.hireDate.tm_year + 1900, emp1.hireDate.tm_mon + 1, emp1.hireDate.tm_mday);

    giveSalaryRaise(&emp1, 2000.0);

    int yearsWorked = calculateYearsOfWork(&emp1);
    printf("%s has worked at the company for %d years.\n", emp1.name, yearsWorked);
}
