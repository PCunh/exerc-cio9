#include <stdio.h>
#include <stdlib.h>

// Função para calcular a média
float calcularMedia(int *numeros, int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += numeros[i];
    }
    return soma / tamanho;
}

// Função para calcular a mediana
float calcularMediana(int *numeros, int tamanho) {
    int meio = tamanho / 2;
    if (tamanho % 2 == 0) {
        return (numeros[meio - 1] + numeros[meio]) / 2.0;
    } else {
        return numeros[meio];
    }
}

// Função para calcular a moda
int calcularModa(int *numeros, int tamanho) {
    int moda = numeros[0];
    int frequencia = 1;
    int maxFrequencia = 1;

    for (int i = 1; i < tamanho; i++) {
        if (numeros[i] == numeros[i - 1]) {
            frequencia++;
        } else {
            if (frequencia > maxFrequencia) {
                maxFrequencia = frequencia;
                moda = numeros[i - 1];
            }
            frequencia = 1;
        }
    }

    if (frequencia > maxFrequencia) {
        moda = numeros[tamanho - 1];
    }

    return moda;
}

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *numeros = (int *)malloc(tamanho * sizeof(int));
    printf("Digite os numeros separados por espaco: ");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &numeros[i]);
    }

    float media = calcularMedia(numeros, tamanho);
    float mediana = calcularMediana(numeros, tamanho);
    int moda = calcularModa(numeros, tamanho);

    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    free(numeros); // Liberar a memória alocada para o array
    return 0;
}
