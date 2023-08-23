/*Crie uma struct chamada "Estudante" com campos para nome, matrícula e notas em três disciplinas. Implemente funções para calcular a média das notas e determinar se um aluno está aprovado (média maior ou igual a 7).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    char name[50];
    int code;
    float grade1, grade2, grade3;
}Student;

void setStudent(Student *s, const char* name, float g1, float g2, float g3){
    strncpy(s->name, name, sizeof(s->name));
    s->code = 10000000 + (rand() % 2000000);
    s->grade1 = g1;
    s->grade2 = g2;
    s->grade3 = g3;
}

int approveCheck(float g1, float g2, float g3){
    if ((g1 + g2 + g3) / 3 >= 7){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int stdCount = 0;
    Student a[1000];
    int opt;

    do{
    printf("Select an option\n1.Add Student\n2.Check Students\n0.Quit\n");
    scanf("%d", &opt);

    switch (opt){

    case 0:
    break;

    case 1:
        system("clear");
        if (stdCount < 1000) {
                char name[50];
                float grades[2];

                printf("Name: ");
                scanf(" %s", name);
                printf("%s", name);
                fflush(stdin);

                printf("grade 1: ");
                scanf("%f", &grades[0]);

                printf("grade 2: ");
                scanf("%f", &grades[1]);

                printf("grade 3: ");
                scanf("%f", &grades[2]);


                setStudent(&a[stdCount], name, grades[0], grades[1], grades[2]);
                stdCount++;

                printf("Student added successfully!\n");
        } else printf("Students list full\n");
        break;

    case 2:
        system("clear");
        printf("Students List:\n");
            for (int i = 0; i < stdCount; i++) {
                if (approveCheck(a[i].grade1, a[i].grade2, a[i].grade3) == 1){
                printf("Name: %s, code: %d, Approved!\n", a[i].name, a[i].code);
                } else {
                    printf("Name: %s, code: %d, Flunk!\n", a[i].name, a[i].code);
                }
            }
        break;

    default:
    printf("Invalid option\n");
        break;
    }
    }while(opt != 0);
}