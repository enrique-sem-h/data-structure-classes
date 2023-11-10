/*Escreva um programa em C que solicite o tamanho da lista e possua um método de Inserir Lista Ordenada
de compras de produtos alimentícios.*/
#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    char nome[50];
    float preco;
} Produto;

typedef struct {
    Produto lista[MAX_PRODUTOS];
    int tamanho;
    int quantidade;
} ListaDeCompras;

void inicializarLista(ListaDeCompras *lista, int tamanho) {
    lista->tamanho = tamanho > MAX_PRODUTOS ? MAX_PRODUTOS : tamanho;
    lista->quantidade = 0;
}

void inserirProduto(ListaDeCompras *lista, char nome[], float preco) {
    if (lista->quantidade >= lista->tamanho) {
        printf("A lista de compras está cheia.\n");
        return;
    }

    Produto novoProduto;
    strcpy(novoProduto.nome, nome);
    novoProduto.preco = preco;

    int posicao = lista->quantidade;

    while (posicao > 0 && strcmp(novoProduto.nome, lista->lista[posicao - 1].nome) < 0) {
        lista->lista[posicao] = lista->lista[posicao - 1];
        posicao--;
    }

    lista->lista[posicao] = novoProduto;
    lista->quantidade++;
}

void exibirLista(ListaDeCompras *lista) {
    printf("Lista de Compras:\n");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%s - R$%.2f\n", lista->lista[i].nome, lista->lista[i].preco);
    }
}

int main() {
    int tamanhoLista;

    printf("Digite o tamanho da lista de compras: ");
    scanf("%d", &tamanhoLista);

    ListaDeCompras listaDeCompras;
    inicializarLista(&listaDeCompras, tamanhoLista);

    printf("Inserir produtos na lista (Digite 'Fim' no nome para encerrar)\n");

    char nomeProduto[50];
    float precoProduto;

    while (1) {
        getchar();
        printf("Nome do produto: ");
        scanf("%[^\n]s", nomeProduto);

        if (strcmp(nomeProduto, "Fim") == 0) {
            break;
        }

        printf("Preço do produto: ");
        scanf("%f", &precoProduto);

        inserirProduto(&listaDeCompras, nomeProduto, precoProduto);
    }

    exibirLista(&listaDeCompras);

    return 0;
}
