/**
 * @file wisielec.cpp
 * @brief Konsolowa gra w Wisielca zrealizowana w podejściu obiektowym.
 * @author Woźniak Antoni, Beniamin Hosumbek
 * @date 25.04.2026
 * * Plik zawiera pełną implementację gry, w tym zarządzanie bazą słów
 * oraz główną logikę rozgrywki.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <algorithm>

using namespace std;

/**
 * @class WordManager
 * @brief Klasa odpowiedzialna za zarządzanie bazą haseł.
 * * Klasa przechowuje wektor dostępnych słów i udostępnia metodę
 * pozwalającą na wylosowanie jednego z nich.
 */
class WordManager {
private:
    vector<string> slowa; ///< Baza słów wykorzystywanych w grze.

public:
    /**
     * @brief Konstruktor inicjalizujący bazę słów.
     */
    WordManager() {
        slowa = {"programowanie", "komputer", "algorytm", "klawiatura", "internet"};
        srand(static_cast<unsigned int>(time(0))); // Inicjalizacja generatora liczb losowych
    }

    /**
     * @brief Losuje hasło z dostępnej bazy słów.
     * @return Zwraca wylosowane słowo w postaci ciągu znaków (string).
     */
    string losujHaslo() {
        int index = rand() % slowa.size();
        return slowa[index];
    }
};

/**
 * @class HangmanGame
 * @brief Klasa zarządzająca stanem i logiką gry w Wisielca.
 * * Odpowiada za wyświetlanie interfejsu w konsoli, weryfikację
 * podawanych przez gracza liter oraz sprawdzanie warunków końca gry.
 */
class HangmanGame {
private:
    string haslo;                 ///< Prawidłowe hasło do odgadnięcia.
    string ukryte_haslo;          ///< Hasło zamaskowane znakami podkreślenia.
    int zycia;                    ///< Liczba pozostałych błędów do popełnienia.
    vector<char> zgadywane_litery; ///< Lista liter, które gracz już sprawdził.

    /**
     * @brief Sprawdza, czy gracz już wcześniej podał daną literę.
     * @param litera Znak do sprawdzenia.
     * @return true Jeśli litera znajduje się już na liście zgadywanych.
     * @return false Jeśli litera pojawia się po raz pierwszy.
     */
    bool czyBylaPodana(char litera) {
        return find(zgadywane_litery.begin(), zgadywane_litery.end(), litera) != zgadywane_litery.end();
    }

    /**
     * @brief Wyświetla aktualny stan gry (ukryte hasło i liczbę żyć).
     */
    void wyswietlStatus() {
        cout << "\n=====================================" << endl;
        cout << "Haslo: " << ukryte_haslo << endl;
        cout << "Pozostale zycia: " << zycia << endl;
        cout << "Podaj litere: ";
    }

public:
    /**
     * @brief Konstruktor klasy gry.
     * @param wylosowane_haslo Słowo, które zostało wylosowane dla obecnej partii.
     */
    HangmanGame(string wylosowane_haslo) {
        haslo = wylosowane_haslo;
        ukryte_haslo = string(haslo.length(), '_');
        zycia = 6;
    }

    /**
     * @brief Rozpoczyna główną pętlę rozgrywki.
     * * Pętla działa do momentu odgadnięcia hasła lub utraty wszystkich żyć.
     */
    void start() {
        cout << "--- WITAJ W GRZE WISIELEC ---" << endl;
        cout << "Masz " << zycia << " szans na pomylke." << endl;

        while (zycia > 0 && ukryte_haslo != haslo) {
            wyswietlStatus();
            
            char litera;
            cin >> litera;
            litera = tolower(litera); // Zamiana na małą literę

            if (czyBylaPodana(litera)) {
                cout << "Ta litera zostala juz sprawdzona! Sprobuj innej." << endl;
                continue;
            }

            zgadywane_litery.push_back(litera);
            sprawdzLitere(litera);
        }

        zakonczGre();
    }

    /**
     * @brief Weryfikuje, czy podana litera znajduje się w haśle.
     * * Aktualizuje zamaskowane hasło w przypadku trafienia, lub 
     * zmniejsza liczbę żyć w przypadku błędu.
     * * @param litera Znak wprowadzony przez gracza.
     */
    void sprawdzLitere(char litera) {
        bool trafienie = false;
        for (size_t i = 0; i < haslo.length(); i++) {
            if (haslo[i] == litera) {
                ukryte_haslo[i] = litera; // Odsłonięcie litery
                trafienie = true;
            }
        }

        if (trafienie) {
            cout << "Dobrze! Litera '" << litera << "' znajduje sie w hasle." << endl;
        } else {
            cout << "Pudlo! Brak litery '" << litera << "' w hasle." << endl;
            zycia--;
        }
    }

    /**
     * @brief Wyświetla ekran końcowy podsumowujący wynik gry.
     */
    void zakonczGre() {
        cout << "\n-----------------------------" << endl;
        if (ukryte_haslo == haslo) {
            cout << "GRATULACJE! Odgadles haslo: " << haslo << endl;
        } else {
            cout << "KONIEC GRY! Zostales powieszony." << endl;
            cout << "Prawidlowe haslo to: " << haslo << endl;
        }
    }
};

/**
 * @brief Główna funkcja programu.
 * * Inicjalizuje zarządzanie słowami, losuje hasło i uruchamia logikę gry.
 * @return 0 w przypadku poprawnego zakończenia działania programu.
 */
int main() {
    WordManager menedzerSlow;
    string hasloDoGry = menedzerSlow.losujHaslo();
    
    HangmanGame gra(hasloDoGry);
    gra.start();

    return 0;
}