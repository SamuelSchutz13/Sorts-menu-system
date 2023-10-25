#include <iostream>
#include <vector>
#include <algorithm>

struct Number {
    int value;
    Number (int val) : value(val) {}
};

void insert_element(std::vector<Number> &array) {
    int number;
    std::cout << "Digite o numero a ser inserido: ";
    std::cin >> number;
    array.push_back(Number(number));
    std::cout << "Numero " << number << " foi inserido com sucesso" << std::endl;
}

void insertion_sort() {

}

void merge_sort() {

}

void quick_sort() {

}

void menu() {
    std::cout << "1 - Inserir elemento" << std::endl;
    std::cout << "2 - Ordenar Insertion Sort" << std::endl;
    std::cout << "3 - Ordenar Merge Sort" << std::endl;
    std::cout << "4 - Ordenar Quick Sort" << std::endl;
    std::cout << "5 - Sair" << std::endl;
    std::cout << "Escolha uma opcao: " << std::endl;
}

void process_menu(std::vector<Number> &array, int command) {
    switch (command) {
        case 1:
            insert_element(array);   
            break;
        case 2:
            insertion_sort();
            break;
        case 3:
            merge_sort();
            break;
        case 4:
            quick_sort();
            break;
        case 5:
        std::cout << "Saindo do sistema..." << std::endl;
        exit(1);
            break;
        default: std::cout << "Comando invalido, tente novamente" << std::endl;
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