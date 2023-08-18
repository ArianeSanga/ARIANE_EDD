#include <stdio.h>

int buscaSequencial(int arr[], int tamanho, int chave) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == chave) {
            return i;  // Retorna o índice onde a chave foi encontrada
        }
    }
    return -1;  // Retorna -1 se a chave não foi encontrada
}

int main() {
    int array[] = {10, 5, 8, 3, 15, 7, 12};
    int tamanho = sizeof(array) / sizeof(array[0]);
    int chave = 15;

    int indice = buscaSequencial(array, tamanho, chave);

    if (indice != -1) {
        printf("Chave encontrada no índice: %d\n", indice);
    } else {
        printf("Chave não encontrada no array.\n");
    }

    return 0;
}
