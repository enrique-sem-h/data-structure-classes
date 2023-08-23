/* Crie uma struct chamada "Pessoa" que contenha os seguintes campos: nome, idade e altura. Em seguida,
escreva um programa que declare uma variável do tipo Pessoa, preencha seus campos e imprima os valores..
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
    char name[50];
    int age;
    float height;
}Person;

void setPerson(Person *p, const char* name, int age, float height){
    strncpy(p->name, name, sizeof(p->name));
    p->age = age;
    p->height = height;
}

int main(){
    Person john;

    setPerson(&john, "john", 22, 1.78);

    printf("%s is %dy old\nheight: %.2f\n", john.name, john.age, john.height);
}