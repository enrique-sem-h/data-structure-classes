/*Crie uma struct chamada "Tipo" que possa armazenar um valor do tipo inteiro, um valor do tipo ponto flutuante e uma letra. Escreva um programa que demonstre o uso da struct, atribuindo valores de diferentes tipos e imprimindo-os.*/

#include <stdio.h>

typedef struct Type{
    int integer;
    float flunctuant;
    char character;
}Type;

void setType(Type *t, int integer, float flunctuant, char character){
    t->integer = integer;
    t->flunctuant = flunctuant;
    t->character = character;
}

int main(){
    Type t1;

    setType(&t1, 1, 1.1, 'c');

    printf("int: %d\nfloat: %.2f\nchar: %c\n", t1.integer, t1.flunctuant, t1.character);
}