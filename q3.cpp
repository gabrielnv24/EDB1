/* Implemente um dos algoritmos de complexidade O(n²): escolha entre o
algoritmo insertion sort e o selection sort. */

#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& vetor) {
    int n = vetor.size();
    for (int i = 1; i < n; ++i) {
        int key = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = key;
    }
}

int main() {
    int N;

    std::cout << "Digite o tamanho do vetor: ";
    std::cin >> N;

    std::vector<int> vetor(N);

    std::cout << "Digite os elementos do vetor: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> vetor[i];
    }

    insertionSort(vetor);

    std::cout << "Vetor ordenado: ";
    for (int i = 0; i < N; ++i) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

