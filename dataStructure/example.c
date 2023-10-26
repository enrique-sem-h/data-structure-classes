#include <stdio.h>
#include <stdlib.h>

#define MAX 2

typedef struct Pile{
    int items[MAX];
    int top;
}Pile;

void init(Pile *Pile){
    Pile->top = -1;
}

int isEmpty(Pile *Pile){
    return Pile->top == -1;
}

int isFull(Pile *Pile){
    return Pile->top == MAX - 1;
}

void print(Pile *Pile){
    for(int i = 0; i < MAX; i++){
        printf("Pile item %d: %d\n", i + 1, Pile->items[i]);
    }
}

void append(Pile *Pile, int num){
    if(isFull(Pile)){
        printf("Your Pile is full\n");
    } else {
        Pile->items[++Pile->top] = num;
    }
}

int delete(Pile *Pile){
    if(isEmpty(Pile)){
        printf("Your pile is empty\n");
    } else {
    Pile->items[--Pile->top];
    }
}

int main(){
    Pile p1;

    init(&p1);

    append(&p1, 0);
    append(&p1, 3);

    print(&p1);

    append(&p1, 4);

    delete(&p1);
}