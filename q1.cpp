/* Implemente um algoritmo que recebe como entrada o tamanho N do vetor e
retorna um vetor de tamanho N como valores aleatórios variando de 0 a N. */


#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   

std::vector<int> gerarVetorAleatorio(int N) {
    std::vector<int> vetor(N);
    for (int i = 0; i < N; ++i) {
        vetor[i] = rand() % (N + 1); 
    }
    return vetor;
}

int main() {
    int N;

    std::cout << "Digite o tamanho do vetor: ";
    std::cin >> N;

    srand(static_cast<unsigned>(time(0)));

    std::vector<int> vetor = gerarVetorAleatorio(N);

    std::cout << "Vetor gerado: ";
    for (int i = 0; i < N; ++i) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
