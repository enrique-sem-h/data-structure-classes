/*Crie uma struct chamada "Produto" com campos para nome, preço e quantidade em estoque. Escreva um programa que permita ao usuário comprar produtos, atualizando o estoque e calculando o total da compra.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Product{
    char name[50];
    float price;
    int amount;
} Product;

void listProducts(Product products[], int numProducts) {
    printf("Available Products:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d. %s - $%.2f - In Stock: %d\n", i + 1, products[i].name, products[i].price, products[i].amount);
    }
}

int main(){
    Product products[20];
    int numProducts = 0;

    int opt;

    do {
        printf("\nSelect Option\n1. List Products\n2. Add to Cart\n3. View Cart\n0. Quit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                listProducts(products, numProducts);
                break;

            case 2:
                listProducts(products, numProducts);
                int productIndex;
                printf("Enter the product number to add to cart: ");
                scanf("%d", &productIndex);

                if (productIndex >= 1 && productIndex <= numProducts) {
                    int quantity;
                    printf("Enter quantity: ");
                    scanf("%d", &quantity);

                    if (quantity <= products[productIndex - 1].amount) {

                        products[productIndex - 1].amount -= quantity;
                        printf("%d %s added to cart.\n", quantity, products[productIndex - 1].name);
                    } else {
                        printf("Insufficient stock.\n");
                    }
                } else {
                    printf("Invalid product number.\n");
                }
                break;

            case 3:

                break;

            case 0:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid option.\n");
        }

    } while (opt != 0);
}
