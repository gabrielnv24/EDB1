/* Implemente um dos algoritmos de ordenação por distribuição: escolha entre o counting sort e o radix sort. */

#include <iostream>
#include <vector>
#include <algorithm> 

void countingSort(std::vector<int>& vetor) {
    if (vetor.empty()) return;

    int maxElement = *std::max_element(vetor.begin(), vetor.end());

    std::vector<int> count(maxElement + 1, 0);

    for (int num : vetor) {
        count[num]++;
    }

    int index = 0;
    for (int i = 0; i <= maxElement; ++i) {
        while (count[i] > 0) {
            vetor[index++] = i;
            count[i]--;
        }
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

    countingSort(vetor);

    std::cout << "Vetor ordenado: ";
    for (int i = 0; i < N; ++i) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

