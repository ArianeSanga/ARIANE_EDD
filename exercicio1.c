#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0


// Função para realizar a busca sequencial indexada
int busca_sequencial_indexada(int chave, int indices[], int num_indices, int dados[]);

void carrega_vetor_aleatorio(int colecao[], int tamanho, int qtd_digitos);

void carrega_vetor_ordenado(int colecao[], int valor_inicial, int tamanho);

void imprime_vetor(int colecao[], int tamanho);


int main() {

    int vetor[10];

    /*carrega_vetor_aleatorio(vetor, 10, 2);

    imprime_vetor(vetor, 10);*/

     carrega_vetor_ordenado(vetor, 0, 10);

     imprime_vetor(vetor, 10);

    return 0;
}

int busca_sequencial_indexada(int chave, int indices[], int num_indices, int dados[]) {
    // Encontrar o índice na tabela auxiliar que é menor ou igual à chave
    int indice_aproximado = -1;
    for (int i = 0; i < num_indices; i++) {
        if (indices[i] <= chave) {
            indice_aproximado = i;
        } else {
            break;
        }
    }

    if (indice_aproximado == -1) {
        return -1; // Chave é menor que todos os índices
    }

    // Realizar a busca sequencial a partir do índice aproximado
    int inicio = indices[indice_aproximado];
    int fim = (indice_aproximado < num_indices - 1) ? indices[indice_aproximado + 1] - 1 : num_indices - 1;

    for (int i = inicio; i <= fim; i++) {
        if (dados[i] == chave) {
            return i; // Chave encontrada
        }
    }

    return -1; // Chave não encontrada
}

void carrega_vetor_aleatorio(int colecao[], int tamanho, int qtd_digitos)
{
    int i, digitos;

    for (i = 1, digitos = 10; i < qtd_digitos; i++)
    {
        digitos *= 10;
    }

    srand((unsigned)time(NULL));
    for (i = 0; i < tamanho; i++)
    {
        colecao[i] = rand() % digitos;
    }
}

void carrega_vetor_ordenado(int colecao[], int valor_inicial, int tamanho)
{
    int i;
    srand((unsigned)time(NULL));
    for (colecao[0] = valor_inicial, i = 1; i < tamanho; i++)
    {
        colecao[i] = colecao[i - 1] + (rand() % 10);
    }
}

void imprime_vetor(int colecao[], int tamanho)
{
    int i = 0;
    for (i = 0; i < tamanho; i++)
    {
        printf("%d, ", colecao[i]);
    }
    printf("\n");
}
