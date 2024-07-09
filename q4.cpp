/* Implemente um dos algoritmos de complexidade O(nlogn): escolha entre o algoritmo merge sort e o insertion sort. */

#include <iostream>
#include <vector>

void merge(std::vector<int>& vetor, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = vetor[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = vetor[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left; 

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

int main() {
    int N;

    std::cout << "Digite o tamanho do vetor: ";
    std::cin >> N;

    std::vector<int> vetor(N);

    std::cout << "Digite os elementos do vetor: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> vetor[i];
    }

    mergeSort(vetor, 0, N - 1);

    std::cout << "Vetor ordenado: ";
    for (int i = 0; i < N; ++i) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

