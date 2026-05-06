#include "WordManager.h"
#include "HangmanGame.h"

/**
 * @brief Główna funkcja programu.
 * * Inicjalizuje zarządzanie słowami (z pliku), losuje hasło i uruchamia logikę gry.
 * @return 0 w przypadku poprawnego zakończenia działania programu.
 */
int main() {
    /**
    * Inicjalizacja menedżera z podaniem nazwy pliku źródłowego
    */
    WordManager wordManager("slowa.txt");
    string gameWord = wordManager.drawWord();

    HangmanGame game(gameWord);
    game.start();

    return 0;
}