// X&O_Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Griglia {
private: string simboli[9];
       string coordinateUsate[9];

public:

    void setSimboli(string simb[9]) {
        for (int i = 0; i < 9; i++) {
            simboli[i] = simb[i];
        }
    }

    string* getSimboli() {
        return simboli;
    }

    void setCoordinateUsate(string cor[9]) {
        for (int i = 0; i < 9; i++) {
            coordinateUsate[i] = cor[i];
        }
    }

    string* getCoordinateUsate() {
        return coordinateUsate;
    }

    Griglia(string simb[9], string cor[9])
    {
        setSimboli(simb);
        setCoordinateUsate(cor);
    }

    void Rimuovi() {

    }
    void Crea()
    {
        cout << "   A   B   C  \n";
        cout << "1    |   |    \n";
        cout << "  ---|---|--- \n";
        cout << "2    |   |    \n";
        cout << "  ---|---|--- \n";
        cout << "3    |   |    \n";
    }
    void AggiungiSimbolo(string simb, string coord)
    {

    }
};

int main()
{
    int scelta;
    string coordinata;

    string simboli[9];
    string coordinateUsate[9];

    Griglia g(simboli, coordinateUsate);

    cout << "Benvenuto in X&O!\n";
    cout << "\n";
    g.Crea();
    cout << "\n";
    cout << "Inserire una coordinata:\n";
    cin >> coordinata;
    cout << coordinata;
    /*
    cin >> scelta;
    switch (scelta) {
    case 1:
        // code block
        break;
    case 2:
        // code block
        break;
    default:
        // code block
    }*/
}





