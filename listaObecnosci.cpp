#include <iostream>
#include <string>
using namespace std;

const int MAX = 3;

// 1. dodawanie osoby
void dodajOsobe(string *imiona, string *nazwiska, int *indeksy, int *licznik,
                string imie, string nazwisko, int indeks){
    if (*licznik < MAX) {
        imiona[*licznik] = imie;
        nazwiska[*licznik] = nazwisko;
        indeksy[*licznik] = indeks;
        (*licznik)++;
    }
}

// 2. ustawianie obecności
void sprawdzObecnosc(bool *obecnosc, int indeks){
    char x;
    do {
        cin >> x;
    } while (x != 't' && x != 'n');

    obecnosc[indeks] = (x == 't');
}

// 3. wyświetlanie
void wyswietlListe(string *imiona, string *nazwiska, int *indeksy,
                   bool *obecnosc, int licznik){
    for (int i = 0; i < licznik; i++)
    {
        cout << i << ". " << imiona[i] << " " << nazwiska[i]
             << " (indeks: " << indeksy[i] << ") - ";

        if (obecnosc[i])
            cout << "obecny";
        else
            cout << "nieobecny";

        cout << endl;
    }
}

// 4. edycja danych
void edytujOsobe(string *imiona, string *nazwiska, int *indeksy, int licznik){
    int i;
    cout << "Podaj numer osoby do edycji: ";
    cin >> i;

    if (i >= 0 && i < licznik) {
        cout << "Nowe imie: ";
        cin >> imiona[i];
        cout << "Nowe nazwisko: ";
        cin >> nazwiska[i];
        cout << "Nowy numer indeksu: ";
        cin >> indeksy[i];
    } else {
        cout << "Nieprawidlowy numer!" << endl;
    }
}

// 5. usuwanie osoby
void usunOsobe(string *imiona, string *nazwiska, int *indeksy,
               bool *obecnosc, int *licznik){
    int i;
    cout << "Podaj numer osoby do usuniecia: ";
    cin >> i;

    if (i >= 0 && i < *licznik) {
        for (int j = i; j < *licznik - 1; j++)
        {
            imiona[j] = imiona[j + 1];
            nazwiska[j] = nazwiska[j + 1];
            indeksy[j] = indeksy[j + 1];
            obecnosc[j] = obecnosc[j + 1];
        }
        (*licznik)--;
    } else {
        cout << "Nieprawidlowy numer!" << endl;
    }
}

int main(){
    string imiona[MAX];
    string nazwiska[MAX];
    int indeksy[MAX];
    bool obecnosc[MAX];
    char x;

    int licznik = 0;

    // dodawanie danych
    for (int i = 0; i < MAX; i++)
    {
        string imie, nazwisko;
        int indeks;

        cout << "Podaj imie: ";
        cin >> imie;
        cout << "Podaj nazwisko: ";
        cin >> nazwisko;
        cout << "Podaj numer indeksu: ";
        cin >> indeks;

        dodajOsobe(imiona, nazwiska, indeksy, &licznik, imie, nazwisko, indeks);

        cout << "Czy ta osoba byla obecna? (t/n): ";
        sprawdzObecnosc(obecnosc, i);
    }

    wyswietlListe(imiona, nazwiska, indeksy, obecnosc, licznik);

    // edycja
    do {
    cout << "Czy chcesz edytowac jakas osobe? (t/n): ";
    cin >> x;
    if (x == 'n')
    {
        break;
    }
    edytujOsobe(imiona, nazwiska, indeksy, licznik);
    } while(x != 't' && x != 'n');

    // usuwanie
    do {
    cout << "Czy chcesz usunac jakas osobe? (t/n): ";
    cin >> x;
    if (x == 'n')
    {
        break;
    }
    usunOsobe(imiona, nazwiska, indeksy, obecnosc, &licznik);
    } while(x != 't' && x != 'n');
    

    cout << "\nPo zmianach:\n";
    wyswietlListe(imiona, nazwiska, indeksy, obecnosc, licznik);

    return 0;
}