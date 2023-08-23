/* Crie uma struct chamada "ContaBancaria" com campos para nome do titular, número da conta e saldo. Implemente funções para depositar, sacar e verificar o saldo.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct BankAccount{
    char holder[50];
    int number;
    float balance;
}BankAccount;

BankAccount openAccount(const char* name){
    BankAccount acc;
    strncpy(acc.holder, name, sizeof(acc.holder));
    acc.number = 100000 + rand();
    acc.balance = 0;
    return acc;
}

void checkBalance(BankAccount *acc){
    printf("%s\n", acc->holder);
    printf("%d\n", acc->number);
    printf("Your balance is: %.2f\n", acc->balance);
}

void deposit(BankAccount *acc, float ammount){
    acc->balance += ammount;
    printf("Safely deposited U$%.2f\n", ammount);
    printf("Balance: %.2f\n", acc->balance);
}

void withdraw(BankAccount *acc, float ammount){
    acc->balance -= ammount;
    printf("Safely withdrew U$%.2f\n", ammount);
    printf("Balance: %.2f\n", acc->balance);
}

int main(){
    BankAccount ac1;

    ac1 = openAccount("Enrique de Lima");

    checkBalance(&ac1);

    deposit(&ac1, 1000);
    withdraw(&ac1, 500);

    checkBalance(&ac1);

}