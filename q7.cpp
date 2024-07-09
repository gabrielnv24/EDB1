/* Para cada algoritmo de ordenação implementado nas questões 3, 4 e 5, realize a medição do tempo de execução de cada algoritmo para vetores aleatórios gerados através do algoritmo da questão 1 de tamanho 100, 1000, 10000, 100000, 500000. 
edit */



#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstdlib>   
#include <ctime>     

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

std::vector<int> gerarVetorAleatorio(int N) {
    std::vector<int> vetor(N);
    for (int i = 0; i < N; ++i) {
        vetor[i] = rand() % (N + 1);
    }
    return vetor;
}

void medirTempoExecucao(void (*func)(std::vector<int>&), std::vector<int>& vetor, const std::string& nomeAlgoritmo) {
    clock_t start = clock();
    func(vetor);
    clock_t end = clock();
    double tempo = double(end - start) / CLOCKS_PER_SEC;
    std::cout << nomeAlgoritmo << " levou " << tempo << " segundos." << std::endl;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    std::vector<int> tamanhos = {100, 1000, 10000, 100000, 500000};

    for (int tamanho : tamanhos) {
        std::cout << "\nTestando com vetor de tamanho " << tamanho << ":" << std::endl;

        std::vector<int> vetor = gerarVetorAleatorio(tamanho);

        std::vector<int> vetorCopia = vetor;
        medirTempoExecucao(insertionSort, vetorCopia, "Insertion Sort");

        vetorCopia = vetor;
        medirTempoExecucao([](std::vector<int>& v) { mergeSort(v, 0, v.size() - 1); }, vetorCopia, "Merge Sort");

        vetorCopia = vetor;
        medirTempoExecucao(countingSort, vetorCopia, "Counting Sort");
    }

    return 0;
}

