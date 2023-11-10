/*Elaborar um algoritmo para incluir e excluir pessoas em uma fila de clientes.

Solicitar para o usuário o nome da pessoa e a quantidade de pessoas a serem atendidas na fila.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int end, start, size;
    char name[15];
}People;

void initPeople(People *people, int size){
    people->size = size;
    people->start = -1;
    people->end = -1;
}

int isFull(People *people){
    return (people->end + 1) % people->size == people->start;
}

int isEmpty(People *people){
    return (people->start == -1 && people->end == -1) || (people->start > people->end);
}

void append(People *people){
    if (isFull(people)){
        printf("Sorry, the array is full\n");
    } else {
        getchar();
        if (people->start == -1){
            people->start = 0;
        }
    printf("Type in the person's name: ");
    scanf("%[^\n]s", &people->name[++people->end]);
    }
    system("clear");
}

void print(People *people){
    system("clear");
    for (int i = 0; i <= people->end; i++){
        if (i >= people->start){
            printf("Person %d: %s\n", i - people->start + 1, people->name);
        }
    }
}


int main(){
    People p;
    int size, opt;

    printf("Type in the array size: ");
    scanf("%d", &size);

    initPeople(&p, size);

    do{
    printf("Choose an option:\n1. Append\n2. Print\n3. Quit\n");
    scanf("%d", &opt);

    switch(opt){
        case 1:
        append(&p);
        break;
        case 2:
        print(&p);
        break;
        case 3:
        printf("Ending..\n");
        break;
        default:
        break;
    }
    }while (opt != 3);
}