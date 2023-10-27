#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
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

void insertion_sort(std::vector<Number> &array) {
    int number = array.size();

    for (int i = 1; i < number; i++) {
        Number key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j].value > key.value) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }

    std::cout << "Array ordenado usando Insertion Sort: ";

    for (int i = 0; i < number; i++) {
        std::cout << array[i].value << " ";
    }

    std::cout << std::endl;
}

void merge_sort(std::vector<Number> &array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);

        std::vector<Number> mergedArray;

        int i = left, j = middle + 1;

        while (i <= middle && j <= right) {
            if (array[i].value <= array[j].value) {
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
    }
}

int partitionArrayInQuickSort(std::vector<Number> &array, int low, int high) {
    Number pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j].value < pivot.value) {
            i++;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[high]);
    return (i + 1);
}

void quick_sort(std::vector<Number> &array, int low, int high) {
    if (low < high) {
        int pi = partitionArrayInQuickSort(array, low, high);

        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

void save_original_order(const std::vector<Number> &array, std::vector<Number> &original) {
    original = array;
}

void restore_original_order(std::vector<Number> &array, const std::vector<Number> &original) {
    array = original;
}

void printArray(const std::vector<Number> &array) {
    std::cout << "Array ordenado: ";
    for (const Number &num : array) {
        std::cout << num.value << " ";
    }
    std::cout << std::endl;
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

void process_menu(std::vector<Number> &array, int command) {
    switch (command) {
        case 1:
            insert_element(array);
            break;
        case 2:
            insertion_sort(array);
            printArray(array);
            break;
        case 3:
            merge_sort(array, 0, array.size() - 1);
            printArray(array);
            break;
        case 4:
            quick_sort(array, 0, array.size() - 1);
            printArray(array);
            break;
        case 5:
            std::cout << "Saindo do sistema..." << std::endl;
            exit(1);
            break;
        default:
            std::cout << "Comando invalido, tente novamente" << std::endl;
    }
}

int main() {
    int command;
    std::vector<Number> array;

    do {
        menu();
        std::cin >> command;
        process_menu(array, command);
    } while (command != 5);

    return 0;
}
