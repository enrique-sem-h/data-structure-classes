#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Movie{
    char title[100];
    char genre[50];
    char director[50];
    char duration[50];
    int classification;
}Movie;

void setMovie(Movie *M, const char* title, const char* genre, const char* director, const char* duration, int classification){
    strncpy(M->title, title, sizeof(M->title));
    strncpy(M->genre, genre, sizeof(M->genre));
    strncpy(M->director, director, sizeof(M->director));
    strncpy(M->duration, duration, sizeof(M->duration));
    M->classification = classification;
}

void printMovie(Movie M){
    printf("Title: %s\n", M.title);
    printf("Genre: %s\n", M.genre);
    printf("Director: %s\n", M.director);
    printf("Duration: %s\n", M.duration);
    printf("Classification: %d\n", M.classification);
}

int main(){
    Movie matrix;

    setMovie(&matrix, "Matrix 01", "Action", "Sei La Johnson", "2:03h", 16);
    printMovie(matrix);

}