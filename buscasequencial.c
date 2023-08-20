#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
#define TAM 5

void carrega_arquivo_classificado(int array[], int size);

void imprime_arquivo(int array[], int size);

void preenche_tabela(struct indice arquivo[], int size);

struct indice
{
    int chave;
    int posicao;
};


int main()
{
    struct indice tabela[TAM];

    int arquivo[SIZE];

    carrega_arquivo_classificado(arquivo, SIZE);

    imprime_arquivo(arquivo, SIZE);

    return 0;


    
     

}

void carrega_arquivo_classificado(int array[], int size)
{
    srand((unsigned)time(NULL));

    array[0] = rand() % 1000;
    for (int i = 1; i != size; i++)
    {
        array[i] = array[i - 1] + (rand() % 100);
    }
}

void imprime_arquivo(int array[], int size)
{
    for (int i = 0; i != size; i += 1)
    {
        printf("[%d]: %d\n", i, array[i]);
    }
    printf("\n\n");
}

