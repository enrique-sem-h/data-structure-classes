/* Crie uma struct chamada "Moeda" que possa armazenar valores em dólares e euros. Escreva um programa que permita ao usuário escolher uma moeda e converter um valor entre dólares e euros, usando a taxa de câmbio atual.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Currency {
    float dollars;
    float euros;
} Currency;

void convertDollarsToEuros(Currency *currency, float rate) {
    currency->euros = currency->dollars * rate;
}

void convertEurosToDollars(Currency *currency, float rate) {
    currency->dollars = currency->euros / rate;
}

int main() {
    float exchangeRate = 0.85; // 1 USD = 0.85 EUR

    Currency money;

    int choice;
    printf("Select Currency:\n");
    printf("1. Dollars\n");
    printf("2. Euros\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter amount in Dollars: $");
        scanf("%f", &money.dollars);
        convertDollarsToEuros(&money, exchangeRate);
        printf("Converted amount: %.2f Dollars = %.2f Euros\n", money.dollars, money.euros);
    } else if (choice == 2) {
        printf("Enter amount in Euros: €");
        scanf("%f", &money.euros);
        convertEurosToDollars(&money, exchangeRate);
        printf("Converted amount: %.2f Euros = %.2f Dollars\n", money.euros, money.dollars);
    } else {
        printf("Invalid choice.\n");
    }
}
