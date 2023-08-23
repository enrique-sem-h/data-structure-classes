/*Crie uma struct chamada "Livro" com campos para título, autor e ano de publicação. Escreva um programa que permita ao usuário adicionar informações de livros, listar todos os livros cadastrados e buscar livros por autor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book{
    char name[50];
    char author[20];
    int releaseDate;
}Book;

Book setBook(const char* name, const char* author, int releaseDate){
    Book c;
    strncpy(c.name, name, sizeof(c.name));
    strncpy(c.author, author, sizeof(c.author));
    c.releaseDate = releaseDate;
    return c;
}

int main(){
    int opt, numBooks = 0;
    Book bookList[50];

    do{
    printf("\nSelect Option\n1. Add Book\n2. Books List\n3. Search Book\n0.Quit\n");
    scanf("%d", &opt);

    switch(opt){
        case 1:
        system("clear");
        if (numBooks < 50) {
                char name[50];
                char author[20];
                int releaseDate;

                printf("Name: ");
                scanf(" %s", &name);
                fflush(stdin);

                printf("author: ");
                scanf(" %s", &author);
                fflush(stdin);

                printf("release date: ");
                scanf("%d", &releaseDate);
                fflush(stdin);

                bookList[numBooks] = setBook(name, author, releaseDate);
                numBooks++;

                printf("Book added successfully!\n");
            } else {
                printf("Book list is full.\n");
            }
        break;
        case 2:
        system("clear");
        printf("Books List:\n");
            for (int i = 0; i < numBooks; i++) {
                printf("Name: %s, author: %s, release date: %d\n", bookList[i].name, bookList[i].author, bookList[i].releaseDate);
            }
        break;
        case 3:
            system("clear");
            int found = 0;
            char searchName[50];
        
         
            printf("Enter author's name to search: ");
            scanf(" %s", searchName);

            for (int i = 0; i < numBooks; i++) {
                if (strcmp(bookList[i].author, searchName) == 0) {
                    found++;
                }
            }

            if (found != 0){
            printf("%d books for %s:\n", found, searchName);
            }

            for (int i = 0; i < numBooks; i++) {
                if (strcmp(bookList[i].author, searchName) == 0) {
                    printf("Name: %s, author: %s, release date: %d\n", bookList[i].name, bookList[i].author, bookList[i].releaseDate);
                }
            }

            if (!found) {
                printf("Book not found.\n");
            }
        break;
        default:
        if (opt != 0)
        printf("error, try again");
    }
    }while(opt != 0);
}