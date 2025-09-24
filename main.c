#include <stdio.h>

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int temp = *a; 
    *a = *b;
    *b = temp;
}

// Função de partição para reorganizar o array em torno do pivô
int partition(int arr[], int low, int high) {

    // Inicializa o pivô como o primeiro elemento
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // Encontra o primeiro elemento maior que o pivô (da esquerda para a direita)
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }

        // Encontra o primeiro elemento menor que o pivô (da direita para a esquerda)
        while (arr[j] > p && j >= low + 1) {
            j--;
        }

        // Troca os elementos encontrados se ainda estiverem fora de ordem
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Coloca o pivô na posição correta
    swap(&arr[low], &arr[j]);
    return j; // Retorna o índice de partição
}

// Função QuickSort para ordenar o array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Chama a função de partição para encontrar o índice de partição
        int pi = partition(arr, low, high);

        // Chama recursivamente o quickSort para a metade esquerda e direita com base no índice de partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Cria um array de exemplo
    int arr[] = { 4, 2, 5, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    // Chama a função quickSort para ordenar o array dado
    quickSort(arr, 0, n - 1);

    // Imprime o array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
