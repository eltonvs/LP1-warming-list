/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Implemente um programa em C++ chamado test string.cpp onde você deverá implementar
 * as funções solicitadas nas questões 16 à 19. Não esqueça de declarar o protótipo
 * de cada função no início do programa. Basicamente o que o programa deve fazer é criar
 * uma série de strings e aplicar cada uma das funções de forma a testar sua funcionalidade
 * e se a mesma funciona como deveria.
 * Algumas observações devem ser feitas com relaçãao a funções que criam e manipulam strings:
 *  - Geralmente a string passada como parâmetro não deve ser alterada, e;
 *  - Novas strings devem ser criada com alocação dinâmica (uso de new e delete).
 * 16. Implemente uma função que receba uma string e um número inteiro n como parâmetros,
 * e retorne uma nova string com os n primeiros caracteres da string passada como
 * parâmetro. Por exemplo, recebendo como parâmetros a string “Gosto de programar
 * em C++” e o número 5, essa função deve alocar dinamicamente uma nova string
 * contendo a sequência de caracteres “Gosto”. Essa função deve obedecer o protótipo:
 *   char * prefix(const char * str, int n);
 *   Obs.: Teste se n é sempre menor do que o tamanho da string (que pode ser recuperado
 *         com a função strlen); se n for maior ou igual ao tamanho da string função deve
 *         simplesmente retornar uma cópia da string original.
 * 17. Implemente uma função que receba uma string como parâmetro e retorne uma nova
 * string que é o reverso da string original. Por exemplo, recebendo como parâmetros a
 * string “Sabedoria e honra” a função deve retornar uma nova string contendo “arnoh
 * e airodebaS”. Essa função deve obedecer o protótipo:
 *   char * reverse(const char * str);
 * 18. Implemente uma função que receba uma string como parâmetro e retorne uma nova
 * string com os caracteres minúsculos trocados para maiúsculas e vice-versa. Caracteres
 * que não forem letras devem ser copiados sem alteração para a nova string. Por exemplo,
 * se for passado como parâmetro a string “UFRN - DIMAp - Dim0426”, essa função
 * deve retornar uma nova string contendo a sequência “ufrn - dimaP - dIM0426”. Essa
 * função deve obedecer o protótipo:
 *   char * invertCase (const char * str);
 * 19. Implemente uma função que receba uma string como parâmetro e retorne uma nova
 * string com as letras da string original substituídas por suas sucessoras no alfabeto. Por
 * exemplo, recebendo como parâmetro a string “Casa”, essa função retornaria a string
 * “Dbtb”. Essa função deve obedecer o protótipo:
 *   char * shiftString(const char * str);
 *   Obs.: A letra ’z’ deve ser substituída pela letra ’a’ (e ’Z’ por ’A’). Caracteres que
 *         não forem letras devem ser copiados para a nova string sem sofrer alteração. A string
 *         passada como parâmetro não pode ser alterada.
 */

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cerr;
using std::bad_alloc;

// Prototypes
char *prefix(const char *str, int n);
char *reverse(const char *str);
char *invertCase(const char *str);
char *shiftString(const char *str);

int main(int argc, char const *argv[]) {
    char *new_str;

    new_str = prefix("I like to program in C++", 6);
    cout << new_str << endl;
    delete[] new_str;

    new_str = reverse("Wisdom and Honor");
    cout << new_str << endl;
    delete[] new_str;

    new_str = invertCase("UFRN - DIMAp - Dim0426");
    cout << new_str << endl;
    delete[] new_str;

    new_str = shiftString("House");
    cout << new_str << endl;
    delete[] new_str;

    return EXIT_SUCCESS;
}

char *prefix(const char *str, int n) {
    int str_size = strlen(str);
    char *new_str;

    if (n >= str_size) {
        try {
            new_str = new char[str_size];
        }catch (const bad_alloc & e) {
            cerr << "[prefix()]: bad_alloc caught:" << e.what() << "\n";
        }
        strcpy(new_str, str);
    } else {
        try {
            new_str = new char[n];
        }catch (const bad_alloc & e) {
            cerr << "[prefix()]: bad_alloc caught:" << e.what() << "\n";
        }
        for (int i = 0; i < n; i++)
            *(new_str+i) = *(str+i);
    }

    return new_str;
}

char *reverse(const char *str) {
    int str_size = strlen(str);
    char *new_str;

    try {
        new_str = new char[str_size];
    }catch (const bad_alloc & e) {
        cerr << "[reverse()]: bad_alloc caught:" << e.what() << "\n";
    }

    for (int i = 0; i < str_size; i++)
        *(new_str+i) = *(str+str_size-i-1);

    return new_str;
}

char *invertCase(const char *str) {
    int str_size = strlen(str);
    char *new_str;

    try {
        new_str = new char[str_size];
    }catch (const bad_alloc & e) {
        cerr << "[invertCase()]: bad_alloc caught:" << e.what() << "\n";
    }

    for (int i = 0; i < str_size; i++)
        *(new_str+i) = (*(str+i) >= 65 && *(str+i) <= 90) ? *(str+i) + 32 : (*(str+i) >= 97 && *(str+i) <= 122) ? *(str+i) - 32 : *(str+i);

    return new_str;
}

char *shiftString(const char *str) {
    int str_size = strlen(str);
    char *new_str;

    try {
        new_str = new char[str_size];
    }catch (const bad_alloc & e) {
        cerr << "[shiftString()]: bad_alloc caught:" << e.what() << "\n";
    }

    for (int i = 0; i < str_size; i++)
        *(new_str+i) = (*(str+i) == 90) ? 65 : (*(str+i) == 122) ? 97 : *(str+i) + 1;

    return new_str;
}
