/* Implemente um algoritmo que dado um vetor de entrada A, retorne
verdadeiro em caso do vetor está ordenado e falso caso contrário. */

#include <iostream>
#include <vector>

bool estaOrdenado(const std::vector<int>& vetor) {
    for (size_t i = 1; i < vetor.size(); ++i) {
        if (vetor[i] < vetor[i - 1]) {
            return false; 
        }
    }
    return true; 
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

    if (estaOrdenado(vetor)) {
        std::cout << "O vetor está ordenado." << std::endl;
    } else {
        std::cout << "O vetor não está ordenado." << std::endl;
    }

    return 0;
}
