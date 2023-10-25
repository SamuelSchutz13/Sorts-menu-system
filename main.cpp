#include <stdio.h>
#include <locale.h>
#include <iostream>

void menu() {
    puts("1 - Inserir número");
    puts("2 - ");
    puts("3 - ");
    puts("4 - ");
    puts("5 - Sair");
}

void process_menu() {
    int command;
    do {
        scanf("%d", &command);
        switch (command) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default: puts("Comando inválido, tente novamente");
        }
    } while (command != 5);
}

int main() {
    menu();
    process_menu();
    return 0;
}