#include <iostream>
#include <string>
#include <list>
#include <cstdlib> //random
#include <limits> //key

using namespace std;


class Griglia {
private: string simboli[9] = { " "," "," ", " ", " ", " ", " ", " ", " " };
       string coordinate[9]
           = { "A1", "B1", "C1", "A2", "B2", "C2", "A3", "B3", "C3"};
       string coordinate2[9]
           = { "a1", "b1", "c1", "a2", "b2", "c2", "a3", "b3", "c3" };

public:

    void setSimboli(string simb[9]) {
        for (int i = 0; i < 9; i++) {
            simboli[i] = simb[i];
        }
    }

    string* getSimboli() {
        return simboli;
    }

    Griglia(string simb[9])
    {
        setSimboli(simb);
    }

    void Crea()
    {
        cout << "   A   B   C  \n";
        cout << "1  "+simboli[0] +" | "+simboli[1] + " | "+simboli[2] + "  \n";
        cout << "  ---|---|--- \n";
        cout << "2  "+simboli[3] +" | "+simboli[4] + " | "+simboli[5] + "  \n";
        cout << "  ---|---|--- \n";
        cout << "3  "+simboli[6] +" | "+simboli[7] + " | "+simboli[8] + " \n";
    }
    void AggiungiSimbolo(string simb, string coor)
    {
        for (int i = 0; i < 9; i++)
        {
            if (coor == coordinate[i] || coor == coordinate2[i] && simboli[i] == " ")
            {
                simboli[i] = simb;
                return;
            }
        }
    }
    bool TuttoPieno()
    {
        for (int i = 0; simboli[i] != " "; i++)
        {
            if (i == 8)
            {
                return true;
            }
        }
        return false;
    }
    string ToString()
    {
        string s = "";
        for (int i = 0; simboli[i] != ""; i++)
        {
            s = s + simboli[i];
        }
        return s;
    }
    void MossaComputer()
    {
        srand(time(0));

        int min = 0;  // Valore minimo
        int max = 8;  // Valore massimo

        while (0 < 1)
        {
            int random = min + rand() % max - min + 1;
            if (simboli[random] == " ")
            {
                AggiungiSimbolo("O", coordinate[random]);
                return;
            }
        }
    }
    bool ControllaMossa(string c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (c == coordinate[i] || c == coordinate2[i] && simboli[i] == " ")
            {
                return true;
            }
        }
        return false;
    }
};
////////////////////////////////  MAIN  ///////////////////////////////////////////////
int main()
{
    string coordinata;

    string simboli[9] = {" "," "," ", " ", " ", " ", " ", " ", " " };

    Griglia g(simboli);

    cout << "Benvenuto in X&O!\n";
    cout << "\n";

    for (int i = 0; i < 5; i++)
    {
        system("CLS");
        g.Crea();
        cout << "\n";
        cout << "Inserire una coordinata:\n";
        cin >> coordinata;

        if (g.ControllaMossa(coordinata) == false)
        {
            cout << "Mossa non valida!";
            cout << "\n";
            i--;
            cout << "Premi un tasto per riprovare...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
        else
        {
            cout << "Hai inserito: " + coordinata;
            cout << "\n";
            g.AggiungiSimbolo("X", coordinata);
            g.MossaComputer();
            cout << "Premi un tasto per continuare...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    }

}





