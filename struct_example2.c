#include <stdio.h>
#include <stdlib.h>

typedef struct Person
{
    int age;
    float weight, height;
}Person;

Person setPerson(int age, float weight, float height){
    Person p;
    p.age = age;
    p.weight = weight;
    p.height = height;
    return p;
}

int main(){
    Person john;

    john = setPerson(20, 74.5, 1.78);

    printf("John is %dy old\nweight: %.2f\nheight: %.2f\n", john.age, john.weight, john.height);
}