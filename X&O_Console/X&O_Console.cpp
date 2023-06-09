#include <iostream>
#include <string>
#include <list>
#include <cstdlib> //random
#include <limits> //key
#include <ctime> //random
#include <fstream> //file w/r

using namespace std;

void SalvaStatistiche(int vittorieComputer, int vittorieUtente, int parita) {
    ofstream file("statistiche.txt");
    if (file.is_open()) {
        file << vittorieComputer << ";" << vittorieUtente << ";" << parita;
        file.close();
    }
    else {
        cout << "Impossibile salvare le statistiche su file." << endl;
    }
}

string Split(string s, string delim, int j)
{
    string array[100];
    int x = 0;
    int i = 0;
    for (i = 0; s.find(delim) != -1; i++)
    {
        x = s.find(delim);
        string token = s.substr(0, x);
        array[i] = token;
        s = s.substr((x + 1), s.length());
    }

    array[i] = s;
    return array[j];

}

void CaricaStatistiche(int& vittorieComputer, int& vittorieUtente, int& parita) {
    ifstream file("statistiche.txt");
    if (file.is_open()) {
        string s;
        cin >> s;
        vittorieComputer = stoi(Split(s, ";", 0));
        vittorieUtente = stoi(Split(s, ";", 0));
        parita = stoi(Split(s, ";", 0));
        file.close();
    }
    else {
        vittorieComputer = 0;
        vittorieUtente = 0;
        parita = 0;
    }
}

void EliminaStatistiche()
{
    if (remove("statistiche.txt") == 0)
    {
        cout << "File statistiche.txt eliminato correttamente." << endl;
    }
    else
    {
        cout << "Impossibile eliminare il file statistiche.txt." << endl;
    }
}

class Griglia {
private: string simboli[9]
    = { " "," "," ", " ", " ", " ", " ", " ", " " };
       string coordinate[9]
           = { "A1", "B1", "C1", "A2", "B2", "C2", "A3", "B3", "C3" };
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
        cout << "1  " + simboli[0] + " | " + simboli[1] + " | " + simboli[2] + "  \n";
        cout << "  ---|---|--- \n";
        cout << "2  " + simboli[3] + " | " + simboli[4] + " | " + simboli[5] + "  \n";
        cout << "  ---|---|--- \n";
        cout << "3  " + simboli[6] + " | " + simboli[7] + " | " + simboli[8] + " \n";
    }
    void AggiungiSimbolo(string simb, string coor)
    {
        for (int i = 0; i < 9; i++)
        {
            if ((coor == coordinate[i] || coor == coordinate2[i]) && simboli[i] == " ")
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

        while (true)
        {
            int random = min + rand() % (max - min + 1);
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
            if ((c == coordinate[i] || c == coordinate2[i]) && simboli[i] == " ")
            {
                return true;
            }
        }
        return false;
    }
    string ControllaVittoria(string symbol)
    {
        if (simboli[0] == symbol && simboli[1] == symbol && simboli[2] == symbol) {
            return symbol;
        }
        else if (simboli[3] == symbol && simboli[4] == symbol && simboli[5] == symbol) {
            return symbol;
        }
        else if (simboli[6] == symbol && simboli[7] == symbol && simboli[8] == symbol) {
            return symbol;
        }
        else if (simboli[0] == symbol && simboli[3] == symbol && simboli[6] == symbol) {
            return symbol;
        }
        else if (simboli[1] == symbol && simboli[4] == symbol && simboli[7] == symbol) {
            return symbol;
        }
        else if (simboli[2] == symbol && simboli[5] == symbol && simboli[8] == symbol) {
            return symbol;
        }
        else if (simboli[0] == symbol && simboli[4] == symbol && simboli[8] == symbol) {
            return symbol;
        }
        else if (simboli[2] == symbol && simboli[4] == symbol && simboli[6] == symbol) {
            return symbol;
        }
        else {
            return "-1";
        }
    }

};
////////////////////////////////  MAIN  ///////////////////////////////////////////////
int main()
{
    int vittorieComputer, vittorieUtente, parita;
    CaricaStatistiche(vittorieComputer, vittorieUtente, parita);

    while (true)
    {
        int scelta;
        cout << "Benvenuto in X&O!\n";
        cout << "\n";
        cout << "Cosa vuoi fare?\n";
        cout << "\n1. Gioca.";
        cout << "\n2. Visualizza statistiche di gioco.";
        cout << "\n3. Elimina cronologia partite (statistiche).\n";
        cin >> scelta;
        if (scelta != 1 && scelta != 2 && scelta != 3)
        {
            cout << "Scelta non valida! (Premi un tasto per riprovare)";
        }

        string coordinata;

        string simboli[9] = { " "," "," ", " ", " ", " ", " ", " ", " " };

        Griglia g(simboli);

        int tot = vittorieUtente + vittorieComputer + parita;
        int perc;
        if (tot == 0)
        {
            perc = 0;
        }
        else
        {
            perc = 100 * vittorieUtente / tot;
        }

        switch (scelta) {
        case 1:

            for (int i = 0; i < 5; i++)
            {
                if (g.ControllaVittoria("O") != "-1")
                {
                    system("CLS");
                    g.Crea();
                    cout << "\nIl computer ha vinto!\n";
                    cout << "Premi un tasto per continuare...";
                    vittorieComputer++;
                    SalvaStatistiche(vittorieComputer, vittorieUtente, parita);
                    break;
                }

                system("CLS");
                g.Crea();
                cout << "\nInserire una coordinata:\n";
                cin >> coordinata;

                if (!g.ControllaMossa(coordinata))
                {
                    cout << "Mossa non valida!\n";
                    i--;
                    cout << "Premi un tasto per riprovare...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                }
                else
                {
                    g.AggiungiSimbolo("X", coordinata);

                    if (g.ControllaVittoria("X") != "-1")
                    {
                        system("CLS");
                        g.Crea();
                        cout << "\nHAI VINTO!\n";
                        cout << "Premi un tasto per continuare...";
                        vittorieUtente++;
                        SalvaStatistiche(vittorieComputer, vittorieUtente, parita);
                        break;
                    }
                    else if (g.TuttoPieno())
                    {
                        system("CLS");
                        g.Crea();
                        cout << "\nPARI!\n";
                        cout << "Premi un tasto per continuare...";
                        parita++;
                        SalvaStatistiche(vittorieComputer, vittorieUtente, parita);
                        break;
                    }

                    g.MossaComputer();
                    system("CLS");
                    g.Crea();
                    cout << "\nHai inserito: " + coordinata + "\n";
                    cout << "Premi un tasto per continuare...";
                }
            }
            break;
        case 2:
            system("CLS");
            cout << "Totale partite: " << (tot);
            cout << "\nVittorie Utente: " << vittorieUtente << " (" << perc << "%)";
            cout << "\nVittorie Computer: " << vittorieComputer;
            cout << "\nParita': " << parita;
            cout << "\nPremi un tasto per tornare indietro.";
            break;
        case 3:
            system("CLS");
            cout << "Sei sicuro? S/N\n";
            string sino;
            cin >> sino;
            if (sino == "S" || sino == "s")
            {
                EliminaStatistiche();
                vittorieComputer = 0;
                vittorieUtente = 0;
                parita = 0;
            }
            else if (sino == "N" || sino == "n")
            {
                cout << "\nPremi un tasto per tornare indietro.";
            }
            else
            {
                cout << "";
            }
            break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        system("CLS");

    }


    return 0;
}