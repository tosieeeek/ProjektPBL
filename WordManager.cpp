#include "WordManager.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief Konstruktor inicjalizujący bazę słów z pliku.
 * @param fileName Nazwa pliku .txt, z którego zostaną wczytane hasła.
 * * Jeśli plik nie zostanie znaleziony lub będzie pusty, klasa załaduje
 * domyślną, awaryjną bazę słów.
 */
WordManager::WordManager(string fileName) {
    ifstream file(fileName);
    string loadedWord;

    if (file.is_open()) {
        while (file >> loadedWord) {
            words.push_back(loadedWord);
        }
        file.close();
    }

    /**
     * Zabezpieczenie na wypadek braku pliku
     */
    if (words.empty()) {
        cerr << "Ostrzezenie: Nie udalo sie wczytac slow z pliku " << fileName
             << ". Uzywam bazy domyslnej." << endl;
        words = {"programowanie", "komputer", "algorytm", "klawiatura", "internet"};
    }

    srand(static_cast<unsigned int>(time(0))); ///< Inicjalizacja generatora liczb losowych
}

/**
 * @brief Losuje hasło z dostępnej bazy słów.
 * @return Zwraca wylosowane słowo w postaci ciągu znaków (string).
 */
string WordManager::drawWord() {
    int index = rand() % words.size();
    return words[index];
}