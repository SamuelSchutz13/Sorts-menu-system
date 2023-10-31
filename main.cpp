#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

struct Number {
    int value;
    Number(int val) : value(val) {}
};

void insert_element(std::vector<Number> &array) {
    int count;
    std::cout << "Quantos numeros deseja inserir: ";
    std::cin >> count;

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<int> insertedNumbers;

    for (int i = 0; i < count; i++) {
        int number = std::rand();
        array.push_back(Number(number));
        insertedNumbers.push_back(number);
    }

    std::cout << "Numeros inseridos: ";
    for (int i = 0; i < insertedNumbers.size(); i++) {
        std::cout << insertedNumbers[i] << " ";
    }
    std::cout << std::endl;
}

void insertion_sort(std::vector<Number> &array, bool ascending) {
    if (array.empty()) {
        std::cout << "O vetor está vazio, insira elementos" << std::endl;
        return;
    }

    int number = array.size();

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < number; i++) {
        Number key = array[i];
        int j = i - 1;

        while (j >= 0 && ((ascending && array[j].value > key.value) || (!ascending && array[j].value < key.value))) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Array ordenado usando Insertion Sort: ";

    for (int i = 0; i < number; i++) {
        std::cout << array[i].value << " ";
    }

    std::cout << std::endl;

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Tempo de resposta: " << duration << " ms" << std::endl;

    array.clear();
}

void merge_sort(std::vector<Number> &array, int left, int right, bool ascending) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        auto start = std::chrono::high_resolution_clock::now();

        merge_sort(array, left, middle, ascending);
        merge_sort(array, middle + 1, right, ascending);

        std::vector<Number> mergedArray;

        int i = left, j = middle + 1;

        while (i <= middle && j <= right) {
            if ((ascending && array[i].value <= array[j].value) || (!ascending && array[i].value >= array[j].value)) {
                mergedArray.push_back(array[i]);
                i++;
            } else {
                mergedArray.push_back(array[j]);
                j++;
            }
        }

        while (i <= middle) {
            mergedArray.push_back(array[i]);
            i++;
        }

        while (j <= right) {
            mergedArray.push_back(array[j]);
            j++;
        }

        for (i = left, j = 0; i <= right; i++, j++) {
            array[i] = mergedArray[j];
        }

        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Tempo de resposta: " << duration << " ms" << std::endl;
    }
}

int partitionArray(std::vector<Number> &array, int low, int high, bool ascending);

void quick_sort(std::vector<Number> &array, int low, int high, bool ascending) {
    if (low < high) {
        int pi = partitionArray(array, low, high, ascending);

        quick_sort(array, low, pi - 1, ascending);
        quick_sort(array, pi + 1, high, ascending);
    }
}

int partitionArray(std::vector<Number> &array, int low, int high, bool ascending) {
    Number pivot = array[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        bool shouldSwap = (ascending && array[j].value < pivot.value) || (!ascending && array[j].value > pivot.value);
        if (shouldSwap) {
            i++;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[high]);

    return (i + 1);
}

void printArray(std::vector<Number> &array) {
    if (array.empty()) {
        std::cout << "O vetor esta vazio, insira elementos" << std::endl;
        return;
    }

    std::cout << "Array ordenado: ";
    for (Number &num : array) {
        std::cout << num.value << " ";
    }
    
    std::cout << std::endl;

    array.clear();
}

void menu() {
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "1 - Inserir elemento" << std::endl;
    std::cout << "2 - Ordenar Insertion Sort" << std::endl;
    std::cout << "3 - Ordenar Merge Sort" << std::endl;
    std::cout << "4 - Ordenar Quick Sort" << std::endl;
    std::cout << "5 - Sair" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Escolha uma opcao: " << std::endl;
}

void process_menu(std::vector<Number> &array, int command, std::vector<Number> &original) {
    switch (command) {
        case 1:
            insert_element(array);
            break;
        case 2:
            bool ascending;
            std::cout << "Deseja ordenar em ordem crescente (1) ou decrescente (0)? ";
            std::cin >> ascending;
            insertion_sort(array, ascending);
            printArray(array);
            break;
        case 3:
            bool ascendingMergeSort;
            std::cout << "Deseja ordenar o Merge Sort em ordem crescente (1) ou decrescente (0)? ";
            std::cin >> ascendingMergeSort;
            merge_sort(array, 0, array.size() - 1, ascendingMergeSort);
            printArray(array);
            break;
        case 4:
            bool ascendingQuickSort;
            std::cout << "Deseja ordenar o Quick Sort em ordem crescente (1) ou decrescente (0)? ";
            std::cin >> ascendingQuickSort;
            quick_sort(array, 0, array.size() - 1, ascendingQuickSort);
            printArray(array);
            break;
        case 5:
            std::cout << "Saindo do sistema..." << std::endl;
            exit(1);
            break;
        default:
            std::cout << "Comando inválido, tente novamente" << std::endl;
    }
}

int main() {
    int command;
    std::vector<Number> array;
    std::vector<Number> original;

    do {
        menu();
        std::cin >> command;
        process_menu(array, command, original);
    } while (command != 5);

    return 0;
}
