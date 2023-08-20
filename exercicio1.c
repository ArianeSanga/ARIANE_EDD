#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct IndexValue {
    int index;
    int value;
};

int busca_sequencial_indexada(int vetor[], const struct IndexValue indices[], int n, int tam_indice, int chave);
void cria_indice(struct IndexValue indice[], int tam_indice, int v[], int n);
void carrega_vetor_ordenado(int colecao[], int valor_inicial, int tamanho);

int main() {
    int vetor[1000000];
    int tam_vetor = 1000000;

    carrega_vetor_ordenado(vetor, 0, tam_vetor);


    int numeroIndices = 5;
    struct IndexValue *indices = (struct IndexValue *)malloc(numeroIndices * sizeof(struct IndexValue));
    if (indices == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    cria_indice(indices, numeroIndices, vetor, tam_vetor);
    
   
    int i;
    for (i = 0; i < numeroIndices; i++) {
        printf("Indice: %d, Valor: %d\n", indices[i].index, indices[i].value);
    }
    

    int resultado = busca_sequencial_indexada(vetor, indices, tam_vetor, numeroIndices, 35);

    if (resultado == -1) {
        printf("Nao esta no vetor");
    } else {
        printf("Esta no vetor, no indice %d", resultado);
        printf("\nValor: %d", vetor[resultado]);
    }

    return 0;
}

int busca_sequencial_indexada(int vetor[], const struct IndexValue indices[], int n, int tam_indice, int x) {
    int indiceAproximado;
    for (indiceAproximado = 0; indiceAproximado < tam_indice && indices[indiceAproximado].value <= x; indiceAproximado++);
    indiceAproximado--;

    if (indiceAproximado < 0)
        indiceAproximado = 0;

    while (indiceAproximado < n && vetor[indiceAproximado] < x) {
        indiceAproximado++;
    }
    
    if (indiceAproximado < n && vetor[indiceAproximado] == x) {
        return indiceAproximado;
    } else {
        return -1;
    }
}

void cria_indice(struct IndexValue indice[], int tam_indice, int v[], int n) {
    int pos, i = 0;
    while (i < tam_indice) {
        pos = i * (n - 1) / (tam_indice - 1); // Ajuste no cálculo do índice
        indice[i].index = pos;
        indice[i].value = v[pos];
        i++;
    }

}

void carrega_vetor_ordenado(int colecao[], int valor_inicial, int tamanho) {
    int i;
    srand((unsigned)time(NULL));
    for (colecao[0] = valor_inicial, i = 1; i < tamanho; i++) {
        colecao[i] = colecao[i - 1] + (rand() % 10);
    }
}