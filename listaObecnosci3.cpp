#include <iostream>
#include <string>
using namespace std;

class Osoba {
private:
    string imie;
    string nazwisko;
    string nr_indeksu;

public:
    void setImie(string x);
    void setNazwisko(string x);
    void setNrIndeksu(string x);

    string getImie();
    string getNazwisko();
    string getNrIndeksu();

    void wyswietl();
};

void Osoba::setImie(string x)      { if (x.length() > 2) imie = x; }
void Osoba::setNazwisko(string x)  { if (x.length() > 2) nazwisko = x; }
void Osoba::setNrIndeksu(string x) { if (!x.empty()) nr_indeksu = x; }

string Osoba::getImie()      { return imie; }
string Osoba::getNazwisko()  { return nazwisko; }
string Osoba::getNrIndeksu() { return nr_indeksu; }

void Osoba::wyswietl() {
    cout << nr_indeksu << " | " << imie << " " << nazwisko;
}

class ListaObecnosci {
private:
    Osoba* osoby[10];
    bool obecnosc[10];

public:
    ListaObecnosci();

    void dodajStudenta(Osoba* student, int miejsce);
    void usunStudenta(int miejsce);
    void ustawObecnosc(int miejsce, bool stan);
    Osoba* getOsoba(int miejsce);
    void wyswietlListe();
};

ListaObecnosci::ListaObecnosci() {
    for (int i = 0; i < 10; i++) {
        osoby[i] = nullptr;
        obecnosc[i] = false;
    }
}

void ListaObecnosci::dodajStudenta(Osoba* student, int miejsce) {
    if (miejsce < 0 || miejsce >= 10) return;
    osoby[miejsce] = student;
    obecnosc[miejsce] = false;
}

void ListaObecnosci::usunStudenta(int miejsce) {
    if (miejsce < 0 || miejsce >= 10) return;
    osoby[miejsce] = nullptr;
    obecnosc[miejsce] = false;
}

void ListaObecnosci::ustawObecnosc(int miejsce, bool stan) {
    if (miejsce >= 0 && miejsce < 10 && osoby[miejsce] != nullptr)
        obecnosc[miejsce] = stan;
}

Osoba* ListaObecnosci::getOsoba(int miejsce) {
    if (miejsce >= 0 && miejsce < 10)
        return osoby[miejsce];
    return nullptr;
}

void ListaObecnosci::wyswietlListe() {
    for (int i = 0; i < 10; i++) {
        if (osoby[i] != nullptr) {
            cout << "[" << i << "] ";
            osoby[i]->wyswietl();
            if (obecnosc[i])
                cout << " | Obecny";
            else
                cout << " | Nieobecny";
            cout << endl;
        }
    }
}

class Interfejs {
private:
    ListaObecnosci analiza1;
    ListaObecnosci ppo1;
    ListaObecnosci* lista;

    void wybierzListe();
    void wyswietlMenu();
    void akcjaDodajOsobe();
    void akcjaUsunOsobe();
    void akcjaUstawObecnosc();
    void akcjaZmienImie();
    void akcjaZmienNazwisko();
    void akcjaZmienIndeks();

public:
    Interfejs();
    void uruchom();
};

Interfejs::Interfejs() : lista(nullptr) {}

void Interfejs::wybierzListe() {
    int wybor;
    cout << "Wybierz liste:\n";
    cout << "1. Analiza 1\n";
    cout << "2. PPO 1\n";
    cout << "Wybor: ";
    cin >> wybor;
    lista = (wybor == 2) ? &ppo1 : &analiza1;
}

void Interfejs::wyswietlMenu() {
    cout << "\n=============================\n";
    cout << "  MENU LISTY OBECNOSCI\n";
    cout << "=============================\n";
    cout << "1. Dodaj osobe\n";
    cout << "2. Usun osobe\n";
    cout << "3. Ustaw obecnosc\n";
    cout << "4. Zmien imie osoby\n";
    cout << "5. Zmien nazwisko osoby\n";
    cout << "6. Zmien numer indeksu osoby\n";
    cout << "7. Wyswietl liste\n";
    cout << "0. Wyjscie\n";
    cout << "Wybor: ";
}

void Interfejs::akcjaDodajOsobe() {
    int miejsce;
    string imie, nazwisko, indeks;

    cout << "Podaj miejsce na liscie (0-9): ";
    cin >> miejsce;
    cin.ignore();

    cout << "Imie: ";
    getline(cin, imie);
    cout << "Nazwisko: ";
    getline(cin, nazwisko);
    cout << "Numer indeksu: ";
    getline(cin, indeks);

    Osoba* nowa = new Osoba();
    nowa->setImie(imie);
    nowa->setNazwisko(nazwisko);
    nowa->setNrIndeksu(indeks);

    lista->dodajStudenta(nowa, miejsce);
    cout << "Osoba dodana na miejscu " << miejsce << ".\n";
}

void Interfejs::akcjaUsunOsobe() {
    int miejsce;
    cout << "Podaj miejsce osoby do usuniecia (0-9): ";
    cin >> miejsce;

    Osoba* osoba = lista->getOsoba(miejsce);
    if (osoba == nullptr) {
        cout << "Brak osoby na podanym miejscu.\n";
        return;
    }

    lista->usunStudenta(miejsce);
    delete osoba;
    cout << "Osoba usunieta z miejsca " << miejsce << ".\n";
}

void Interfejs::akcjaUstawObecnosc() {
    int miejsce;
    char stan;

    cout << "Podaj miejsce osoby (0-9): ";
    cin >> miejsce;

    if (lista->getOsoba(miejsce) == nullptr) {
        cout << "Brak osoby na podanym miejscu.\n";
        return;
    }

    cout << "Obecnosc (t = obecny, n = nieobecny): ";
    cin >> stan;

    lista->ustawObecnosc(miejsce, stan == 't' || stan == 'T');
    cout << "Obecnosc zaktualizowana.\n";
}

void Interfejs::akcjaZmienImie() {
    int miejsce;
    string noweImie;

    cout << "Podaj miejsce osoby (0-9): ";
    cin >> miejsce;
    cin.ignore();

    Osoba* osoba = lista->getOsoba(miejsce);
    if (osoba == nullptr) {
        cout << "Brak osoby na podanym miejscu.\n";
        return;
    }

    cout << "Nowe imie: ";
    getline(cin, noweImie);
    osoba->setImie(noweImie);
    cout << "Imie zmienione.\n";
}

void Interfejs::akcjaZmienNazwisko() {
    int miejsce;
    string noweNazwisko;

    cout << "Podaj miejsce osoby (0-9): ";
    cin >> miejsce;
    cin.ignore();

    Osoba* osoba = lista->getOsoba(miejsce);
    if (osoba == nullptr) {
        cout << "Brak osoby na podanym miejscu.\n";
        return;
    }

    cout << "Nowe nazwisko: ";
    getline(cin, noweNazwisko);
    osoba->setNazwisko(noweNazwisko);
    cout << "Nazwisko zmienione.\n";
}

void Interfejs::akcjaZmienIndeks() {
    int miejsce;
    string nowyIndeks;

    cout << "Podaj miejsce osoby (0-9): ";
    cin >> miejsce;
    cin.ignore();

    Osoba* osoba = lista->getOsoba(miejsce);
    if (osoba == nullptr) {
        cout << "Brak osoby na podanym miejscu.\n";
        return;
    }

    cout << "Nowy numer indeksu: ";
    getline(cin, nowyIndeks);
    osoba->setNrIndeksu(nowyIndeks);
    cout << "Numer indeksu zmieniony.\n";
}

void Interfejs::uruchom() {
    wybierzListe();
    int wybor;

    do {
        wyswietlMenu();
        cin >> wybor;

        switch (wybor) {
            case 1: akcjaDodajOsobe();    break;
            case 2: akcjaUsunOsobe();     break;
            case 3: akcjaUstawObecnosc(); break;
            case 4: akcjaZmienImie();     break;
            case 5: akcjaZmienNazwisko(); break;
            case 6: akcjaZmienIndeks();   break;
            case 7:
                cout << "\n--- Lista obecnosci ---\n";
                lista->wyswietlListe();
                break;
            case 0:
                cout << "Zamykanie...\n";
                break;
            default:
                cout << "Nieznana opcja.\n";
        }

    } while (wybor != 0);
}

// -------------------------------------------------------

int main() {
    Interfejs interfejs;
    interfejs.uruchom();
    return 0;
}