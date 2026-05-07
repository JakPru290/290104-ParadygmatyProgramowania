#include <iostream>
#include <string>
using namespace std;

class Osoba {
private:
    string imie;
    string nazwisko;
    string nr_indeksu;
    bool istnieje = false;

public:
    void setImie(string);
    string getImie();

    void setNazwisko(string);
    string getNazwisko();

    void setNr_indeksu(string);
    string getNr_indeksu();

    void setIstnieje(bool);
    bool getIstnieje();

    void wyswietlDane(bool *);
};

void Osoba::setImie(string _imie) {
    if (_imie.length() > 2) {
        imie = _imie;
    }
}

string Osoba::getImie() {
    return imie;
}

void Osoba::setNazwisko(string _nazwisko) {
    if (_nazwisko.length() > 2) {
        nazwisko = _nazwisko;
    }
}

string Osoba::getNazwisko() {
    return nazwisko;
}

void Osoba::setNr_indeksu(string _nr_indeksu) {
    if (_nr_indeksu.length() > 0) {
        nr_indeksu = _nr_indeksu;
    }
}

string Osoba::getNr_indeksu() {
    return nr_indeksu;
}

void Osoba::setIstnieje(bool _istnieje) {
    istnieje = _istnieje;
}

bool Osoba::getIstnieje() {
    return istnieje;
}

void Osoba::wyswietlDane(bool *obecnosc) {
    cout << nr_indeksu << " | " << imie << " " << nazwisko;

    if (*obecnosc)
        cout << " | Obecny";
    else
        cout << " | Nieobecny";

    cout << endl;
}


// Funkcje menu

void dodajOsobe(Osoba &os) {
    if (os.getIstnieje()) {
        cout << "Osoba juz istnieje. Usun ja przed dodaniem nowej." << endl;
        return;
    }

    string imie, nazwisko, nr;

    cout << "Podaj imie: ";
    cin >> imie;

    cout << "Podaj nazwisko: ";
    cin >> nazwisko;

    cout << "Podaj numer indeksu: ";
    cin >> nr;

    os.setImie(imie);
    os.setNazwisko(nazwisko);
    os.setNr_indeksu(nr);
    os.setIstnieje(true);

    cout << "Osoba dodana." << endl;
}

void ustawIndeks(Osoba &os) {
    if (!os.getIstnieje()) {
        cout << "Brak osoby. Najpierw dodaj osobe." << endl;
        return;
    }

    string nr;
    cout << "Podaj nowy numer indeksu: ";
    cin >> nr;

    os.setNr_indeksu(nr);
    cout << "Indeks zaktualizowany." << endl;
}

void ustawImie(Osoba &os) {
    if (!os.getIstnieje()) {
        cout << "Brak osoby. Najpierw dodaj osobe." << endl;
        return;
    }

    string imie;
    cout << "Podaj nowe imie: ";
    cin >> imie;

    os.setImie(imie);
    cout << "Imie zaktualizowane." << endl;
}

void zmienNazwisko(Osoba &os) {
    if (!os.getIstnieje()) {
        cout << "Brak osoby. Najpierw dodaj osobe." << endl;
        return;
    }

    string nazwisko;
    cout << "Podaj nowe nazwisko: ";
    cin >> nazwisko;

    os.setNazwisko(nazwisko);
    cout << "Nazwisko zaktualizowane." << endl;
}

void ustawObecnosc(bool *obecnosc) {
    int wybor;

    cout << "1 - Obecny" << endl;
    cout << "0 - Nieobecny" << endl;
    cout << "Wybor: ";
    cin >> wybor;

    if (wybor == 1) {
        *obecnosc = true;
        cout << "Ustawiono: obecny." << endl;
    }
    else if (wybor == 0) {
        *obecnosc = false;
        cout << "Ustawiono: nieobecny." << endl;
    }
    else {
        cout << "Nieprawidlowy wybor." << endl;
    }
}

void usunOsobe(Osoba &os) {
    if (!os.getIstnieje()) {
        cout << "Brak osoby do usuniecia." << endl;
        return;
    }

    os = Osoba();
    cout << "Osoba usunieta." << endl;
}

void wyswietlMenu() {
    cout << "\n=== MENU ===" << endl;
    cout << "1. Dodaj osobe" << endl;
    cout << "2. Ustaw numer indeksu" << endl;
    cout << "3. Ustaw imie" << endl;
    cout << "4. Zmien nazwisko" << endl;
    cout << "5. Ustaw obecnosc" << endl;
    cout << "6. Usun osobe" << endl;
    cout << "7. Wyswietl dane" << endl;
    cout << "0. Wyjdz" << endl;
    cout << "Wybor: ";
}

int main() {
    Osoba os;
    bool obecnosc = false;
    int wybor;

    do {
        wyswietlMenu();
        cin >> wybor;

        switch (wybor) {
            case 1:
                dodajOsobe(os);
                break;

            case 2:
                ustawIndeks(os);
                break;

            case 3:
                ustawImie(os);
                break;

            case 4:
                zmienNazwisko(os);
                break;

            case 5:
                ustawObecnosc(&obecnosc);
                break;

            case 6:
                usunOsobe(os);
                break;

            case 7:
                if (os.getIstnieje())
                    os.wyswietlDane(&obecnosc);
                else
                    cout << "Brak danych do wyswietlenia." << endl;
                break;

            case 0:
                cout << "Do widzenia!" << endl;
                break;

            default:
                cout << "Nieprawidlowy wybor." << endl;
        }

    } while (wybor != 0);

    return 0;
}