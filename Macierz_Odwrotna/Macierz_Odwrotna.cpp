#include <locale>
#include <stdlib.h>
#include <iostream>
void wypisz_macierz(float macierz[10][10],int wymiar);
int main()
{

    setlocale(LC_CTYPE, "Polish");
    float pomoc[3], help[3];
    float x;
    int i, j, wymiar = 3;
    float macierz[10][10];
    for (j = 0; j < wymiar; j++) {
        for (i = 0; i < wymiar; i++) {
            std::cout << "Wprowadź liczbę w rzędzie " << j + 1 << " oraz kolumnie " << i + 1 << ":";
            std::cin >> macierz[j][i];
        }
    }

    wypisz_macierz(macierz,wymiar);
    float macierz_odwrotna[10][10];
    for (j = 0; j < wymiar; j++) {
        for (i = 0; i < wymiar; i++) {
            if (i == j) {
                macierz_odwrotna[j][i] = 1;
            }
            else
            {
                macierz_odwrotna[j][i] = 0;
            }
        }
    }
    std::cout << std::endl;
    wypisz_macierz(macierz_odwrotna,wymiar);
    std::cout << std::endl;
    // 0x0 robienie 1
    for (i = 1; i <= 120; ++i) {
        std::cout << "*";
    }
    std::cout << std::endl;
    // 0x0 robienie 1
    for (i = 1; i <= 120; ++i) {
        std::cout << "*";
    }
    std::cout << "Zamieniamy 1x1 na 1.";
    std::cout << std::endl;
    x = macierz[0][0];
    // co jeśli 0?
    if (x == 0) {
        for (i = 0; i < 3; i++) {
            pomoc[i] = macierz[0][i];
            macierz[0][i] = macierz[1][i];
            macierz[1][i] = pomoc[i];
            //to samo z drugą
            help[i] = macierz_odwrotna[0][i];
            macierz_odwrotna[0][i] = macierz_odwrotna[1][i];
            macierz_odwrotna[1][i] = help[i];

        }
        x = macierz[0][0];
    }
    // jeśli dalej 0?
    if (x == 0) {
        for (i = 0; i < 3; i++) {
            pomoc[i] = macierz[0][i];
            macierz[0][i] = macierz[2][i];
            macierz[2][i] = pomoc[i];
            //to samo z drugą
            help[i] = macierz_odwrotna[0][i];
            macierz_odwrotna[0][i] = macierz_odwrotna[2][i];
            macierz_odwrotna[2][i] = help[i];

        }
        x = macierz[0][0];
    }
    // Jeśli znowu 0?
    if (x == 0) {
        system("cls");
        std::cout << "Macierz jest nieodwracalna!";
        exit(0);
    }
    for (i = 0; i < 3; i++) {
        macierz[0][i] = macierz[0][i] * (1 / x);
    }
    for (i = 0; i < 3; i++) {
        macierz_odwrotna[0][i] = macierz_odwrotna[0][i] * (1 / x);
    }

    wypisz_macierz(macierz,wymiar);
    std::cout << std::endl;
    wypisz_macierz(macierz_odwrotna,wymiar);
    std::cout << std::endl;
    // w2 - w1
    for (i = 1; i <= 120; ++i) {
        std::cout << "*";
    }
    std::cout << "Odejmujemy od 2 wiersza, wiersz 1.";
    std::cout << std::endl;
    x = macierz[1][0];
    for (i = 0; i < 3; i++) {
        macierz[1][i] = macierz[1][i] - macierz[0][i] * x;
    }
    for (i = 0; i < 3; i++) {
        macierz_odwrotna[1][i] = macierz_odwrotna[1][i] - macierz_odwrotna[0][i] * x;
    }
    wypisz_macierz(macierz,wymiar);
    std::cout << std::endl;
    wypisz_macierz(macierz_odwrotna,wymiar);
    std::cout << std::endl;
    // w3 - w1
    for (i = 1; i <= 120; ++i) {
        std::cout << "*";
    }
    std::cout << "Odejmujemy od 3 wiersza, wiersz 1.";
    std::cout << std::endl;
    x = macierz[2][0];
    for (i = 0; i < 3; i++) {
        macierz[2][i] = macierz[2][i] - macierz[0][i] * x;
    }
    for (i = 0; i < 3; i++) {
        macierz_odwrotna[2][i] = macierz_odwrotna[2][i] - macierz_odwrotna[0][i] * x;
    }
    wypisz_macierz(macierz,wymiar);
    std::cout << std::endl;
    wypisz_macierz(macierz_odwrotna,wymiar);
    std::cout << std::endl;
    // 1x1 robienie 1
    for (i = 1; i <= 120; ++i) {
        std::cout << "*";
    }
    std::cout << "Zamieniamy 2x2 na 1.";
    std::cout << std::endl;
    x = macierz[1][1];
    // co jeśli 0?
    if (x == 0) {
        for (i = 0; i < 3; i++) {
            pomoc[i] = macierz[1][i];
            macierz[1][i] = macierz[2][i];
            macierz[2][i] = pomoc[i];
            //to samo z drugą
            help[i] = macierz_odwrotna[1][i];
            macierz_odwrotna[1][i] = macierz_odwrotna[2][i];
            macierz_odwrotna[2][i] = help[i];

        }
        x = macierz[1][1];
    }
    if (x == 0) {
        system("cls");
        std::cout << "Macierz jest nieodwracalna!";
        exit(0);
    }
    for (i = 0; i < 3; i++) {
        macierz[1][i] = macierz[1][i] * (1 / x);
    }
    for (i = 0; i < 3; i++) {
        macierz_odwrotna[1][i] = macierz_odwrotna[1][i] * (1 / x);
    }
    wypisz_macierz(macierz,wymiar);
    std::cout << std::endl;
    wypisz_macierz(macierz_odwrotna,wymiar);
    std::cout << std::endl;
    // w3 - w2
    for (i = 1; i <= 120; ++i) {
        std::cout << "*";
    }
    std::cout << "Odejmujemy od wiersza 3, wiersz 2.";
    std::cout << std::endl;
    x = macierz[2][1];
    for (i = 0; i < 3; i++) {
        macierz[2][i] = macierz[2][i] - macierz[1][i] * x;
    }
    for (i = 0; i < 3; i++) {
        macierz_odwrotna[2][i] = macierz_odwrotna[2][i] - macierz_odwrotna[1][i] * x;
    }
    wypisz_macierz(macierz,wymiar);
    std::cout << std::endl;
    wypisz_macierz(macierz_odwrotna,wymiar);
    std::cout << std::endl;
    // 3x3 robienie 1
    for (i = 1; i <= 120; ++i) {
        std::cout << "*";
    }
    std::cout << "Zamieniamy 3x3 na 1";
    std::cout << std::endl;
    x = macierz[2][2];
    if (x == 0) {
        system("cls");
        std::cout << "Macierz jest nieodwracalna!";
        exit(0);
    }
    for (i = 0; i < 3; i++) {
        macierz[2][i] = macierz[2][i] * (1 / x);
    }
    for (i = 0; i < 3; i++) {
        macierz_odwrotna[2][i] = macierz_odwrotna[2][i] * (1 / x);
    }
    wypisz_macierz(macierz,wymiar);
    std::cout << std::endl;
    wypisz_macierz(macierz_odwrotna,wymiar);
    std::cout << std::endl;
    // w2 - w3
    for (i = 1; i <= 120; ++i) {
        std::cout << "*";
    }
    std::cout << "Odejmujemy od wiersza 2, wiersz 3.";
    std::cout << std::endl;
    x = macierz[1][2];
    for (i = 0; i < 3; i++) {
        macierz[1][i] = macierz[1][i] - macierz[2][i] * x;
    }
    for (i = 0; i < 3; i++) {
        macierz_odwrotna[1][i] = macierz_odwrotna[1][i] - macierz_odwrotna[2][i] * x;
    }
    wypisz_macierz(macierz,wymiar);
    std::cout << std::endl;
    wypisz_macierz(macierz_odwrotna,wymiar);
    std::cout << std::endl;
    // w1 - w3
    for (i = 1; i <= 120; ++i) {
        std::cout << "*";
    }
    std::cout << "Odejmujemy od wiersza 1, wiersz 3";
    std::cout << std::endl;
    x = macierz[0][2];
    for (i = 0; i < 3; i++) {
        macierz[0][i] = macierz[0][i] - macierz[2][i] * x;
    }
    for (i = 0; i < 3; i++) {
        macierz_odwrotna[0][i] = macierz_odwrotna[0][i] - macierz_odwrotna[2][i] * x;
    }
    wypisz_macierz(macierz,wymiar);
    std::cout << std::endl;
    wypisz_macierz(macierz_odwrotna,wymiar);
    std::cout << std::endl;
    // w1 - w2
    for (i = 1; i <= 120; ++i) {
        std::cout << "*";
    }
    std::cout << "Odejmujemy od wiersza 1, wiersz 2.";
    std::cout << std::endl;
    x = macierz[0][1];
    for (i = 0; i < 3; i++) {
        macierz[0][i] = macierz[0][i] - macierz[1][i] * x;
    }
    for (i = 0; i < 3; i++) {
        macierz_odwrotna[0][i] = macierz_odwrotna[0][i] - macierz_odwrotna[1][i] * x;
    }
    wypisz_macierz(macierz,wymiar);
    std::cout << std::endl;
    wypisz_macierz(macierz_odwrotna,wymiar);
    std::cout << std::endl;
}

void wypisz_macierz(float macierz[10][10],int wymiar){
    int i, j;
    for (i = 0; i < wymiar; i++) {
        for (j = 0; j < wymiar; j++) {
            std::cout << macierz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
