/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Implemente um programa em C++ chamado hanoi.cpp que resolve, recursivamente,
 * o problema das Torres de Hanoi. O problema das Torres de Hanoi consiste em 3
 * pinos - A (origem), B (destino) e C (auxiliar) - e n discos de diâmetros diferentes.
 * Inicialmente, todos os discos se encontram empilhados no pino origem (A), em ordem
 * decrescente de tamanho, de baixo para cima. O objetivo é empilhar todos os discos
 * no pino-destino (B), atendendo às seguintes restrições: (i) apenas um disco pode ser
 * movido de cada vez, e; (ii) qualquer disco não pode ser jamais colocado sobre outro de
 * tamanho menor.
 * O programa deve receber, via linha de comando, um valor inteiro positivo correspondente
 * ao número de discos a ser resolvido e deve exibir a sequẽncia de movimentos para achar a
 * resposta, seguido do número de movimentos feito no total. Segue abaixo um exemplo de
 * execução desse programa:
 *   $ ./hanoi 3
 *   Mova disco de A para B
 *   Mova disco de A para C
 *   Mova disco de B para C
 *   Mova disco de A para B
 *   Mova disco de C para A
 *   Mova disco de C para B
 *   Mova disco de A para B
 *   Foram necessários 7 movimentos.
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void move(int n, char from, char to, char other, int *num_movements) {
    if (n == 1) {
        cout << "Move from " << from << " to " << to << endl;
    } else {
        move(n - 1, from, other, to, num_movements);
        cout << "Move from " << from << " to " << to << endl;
        move(n - 1, other, to, from, num_movements);
    }
    (*num_movements)++;
}

int main(int argc, char const *argv[]) {
    int discs, mv = 0;

    // Get discs number
    cout << "Number of discs: ";
    cin >> discs;

    // Call function
    move(discs, 'A', 'C', 'B', &mv);

    // Print number of movements
    cout << mv << " movement" << (mv > 1 ? "s" : "") << " required" << endl;

    return EXIT_SUCCESS;
}
