#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[50];
    char class[30];
    char email[50];
    char phone[10];
    int code;
    float grade1;
    float grade2;
}Student;

int main(){
    int addStudent = 1, stdCount = 0;
    Student a[1000];
    int i = 0;

    while(addStudent != 0){

        
        printf("Type the student's name: ");
        scanf(" %[^\n]s", &a[i].name);

        printf("Type the student's class: ");
        scanf(" %[^\n]s", &a[i].class);

        printf("Type the student's e-mail: ");
        scanf(" %[^\n]s", &a[i].email);
        
        printf("Type the student's phone: ");
        scanf(" %[^\n]s", &a[i].phone);

        printf("Type the student's 1st grade: ");
        scanf("%f", &a[i].grade1);

        printf("Type the student's 2nd grade: ");
        scanf("%f", &a[i].grade2);
        a[i].code = 1000 + i;
        i++;
        
        printf("Do you wish to add more students?\n1.Yes\n0.No\n");
        scanf("%d", &addStudent);
        stdCount++;
    }

    for (int i = 0; i < stdCount; i++){
        printf("\tStudent %d\n", i + 1);
        printf("Name: %s\n", a[i].name);
        printf("Class: %s\n", a[i].class);
        printf("E-mail: %s\n", a[i].email);
        printf("Phone: %s\n", a[i].phone);
        printf("Code: %d\n", a[i].code);
        printf("Average Grade: %.2f\n", (a[i].grade1 + a[i].grade2) / 2);
        printf("----------------\n");
    }
}