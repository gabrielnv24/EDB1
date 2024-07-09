/* Para cada algoritmo de ordenação implementado, realize testes com vetores desordenados e utilize o algoritmo da questão 2 para verificar se a ordenação está correta. */

#include <iostream>
#include <vector>
#include <algorithm> 

bool estaOrdenado(const std::vector<int>& vetor) {
    for (size_t i = 1; i < vetor.size(); ++i) {
        if (vetor[i] < vetor[i - 1]) {
            return false; 
        }
    }
    return true; 
}

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

void merge(std::vector<int>& vetor, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = vetor[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = vetor[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& vetor, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vetor, left, mid);
        mergeSort(vetor, mid + 1, right);
        merge(vetor, left, mid, right);
    }
}

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

void printVetor(const std::vector<int>& vetor) {
    for (int num : vetor) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void testarAlgoritmos(std::vector<int>& vetor) {
    std::vector<int> vetorCopia;

    vetorCopia = vetor;
    insertionSort(vetorCopia);
    std::cout << "Vetor após Insertion Sort: ";
    printVetor(vetorCopia);
    std::cout << "Está ordenado? " << (estaOrdenado(vetorCopia) ? "Sim" : "Não") << std::endl;

    vetorCopia = vetor;
    mergeSort(vetorCopia, 0, vetorCopia.size() - 1);
    std::cout << "Vetor após Merge Sort: ";
    printVetor(vetorCopia);
    std::cout << "Está ordenado? " << (estaOrdenado(vetorCopia) ? "Sim" : "Não") << std::endl;

    vetorCopia = vetor;
    countingSort(vetorCopia);
    std::cout << "Vetor após Counting Sort: ";
    printVetor(vetorCopia);
    std::cout << "Está ordenado? " << (estaOrdenado(vetorCopia) ? "Sim" : "Não") << std::endl;
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

    testarAlgoritmos(vetor);

    return 0;
}

