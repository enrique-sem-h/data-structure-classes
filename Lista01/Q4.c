/*Crie uma struct chamada "Contato" que armazene o nome e o número de telefone de uma pessoa. escreva um programa que permita ao usuário adicionar contatos, listar todos os contatos e buscar um contato pelo nome.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact{
    char name[50];
    char number[20];
}Contact;

Contact setContact(const char* name, const char* number){
    Contact c;
    strncpy(c.name, name, sizeof(c.name));
    strncpy(c.number, number, sizeof(c.number));
    return c;
}

int main(){
    int opt, numContacts = 0;
    Contact cttList[50];

    do{
    printf("Select Option\n1. Add Contact\n2. Contacts List\n3. Search Contact\n0.Quit\n");
    scanf("%d", &opt);

    switch(opt){
        case 1:
        system("clear");
        if (numContacts < 50) {
                char name[50];
                char number[20];

                printf("Name: ");
                scanf(" %s", name);
                fflush(stdin);

                printf("Number: ");
                scanf(" %s", number);
                fflush(stdin);

                cttList[numContacts] = setContact(name, number);
                numContacts++;

                printf("Contact added successfully!\n");
            } else {
                printf("Contact list is full.\n");
            }
        break;
        case 2:
        system("clear");
        printf("Contacts List:\n");
            for (int i = 0; i < numContacts; i++) {
                printf("Name: %s, Number: %s\n", cttList[i].name, cttList[i].number);
            }
        break;
        case 3:
        system("clear");
         printf("Enter name to search: ");
            char searchName[50];
            scanf("%s", searchName);

            int found = 0;
            for (int i = 0; i < numContacts; i++) {
                if (strcmp(cttList[i].name, searchName) == 0) {
                    printf("Contact found:\n");
                    printf("Name: %s, Number: %s\n", cttList[i].name, cttList[i].number);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Contact not found.\n");
            }
        break;
        default:
        if (opt != 0)
        printf("error, try again");
    }
    }while(opt != 0);
}