#ifndef WORDMANAGER_H
#define WORDMANAGER_H

#include <string>
#include <vector>

using namespace std;

/**
 * @class WordManager
 * @brief Klasa odpowiedzialna za zarządzanie bazą haseł.
 * * Klasa wczytuje słowa z podanego pliku tekstowego, przechowuje wektor
 * dostępnych słów i udostępnia metodę pozwalającą na wylosowanie jednego z nich.
 */
class WordManager {
private:
    vector<string> words; ///< Baza słów wykorzystywanych w grze.

public:
    WordManager(string fileName);
    string drawWord();
};

#endif