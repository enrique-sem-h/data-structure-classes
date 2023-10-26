/*Elaborar um algoritmo para montar e desmontar o objeto ventilador.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct Fan{
    int top;
    char part[5][15];
}Fan;

void init(Fan *Fan){
    Fan->top = -1;
}

int isEmpty(Fan *Fan){
    return Fan->top == -1;
}

int isFull(Fan *Fan){
    return Fan->top == MAX - 1;
}

void print(Fan *Fan){
    if(isEmpty(Fan)){
        printf("Your Fan is empty\n");
    } else {
    for(int i = 0; i < MAX; i++){
        printf("Fan Part %d: %s\n", i + 1, Fan->part[i]);
    }
    }
}

void append(Fan *Fan, const char *part){
    if(isFull(Fan)){
        printf("Fan already built\n");
    } else {
        Fan->top++;
        strcpy(Fan->part[Fan->top], part);
    }
}

int delete(Fan *Fan){
    if(isEmpty(Fan)){
        printf("Your Fan is empty\n");
    } else {
    Fan->part[--Fan->top];
    }
}

int main(){
    Fan f1;
    int opt;
    char repeat = 'r';
    char part[15];


    init(&f1);

    do{
    printf(("Choose an option\n1. Append\n2. Print\n3. Delete\n4. Quit\n"));
    scanf("%d", &opt);

    switch(opt){
        case 1:
            fflush(stdin);
            printf(("Type the part name to append: "));
            scanf("%[^\n]s", &part);

            append(&f1, part);
            system("clear");
        break;
        case 2:
            system("clear");
            print(&f1);
            printf("\n");
        break;
        case 3:
            delete(&f1);
            system("clear");
        break;
        case 4:
            system("clear");
            printf("Goodbye");
            repeat = 'g';
        break;
        default:
        system("clear");
        printf("Invalid option, restarting...\n");
        break;
    }

    }while(repeat == 'r');

}