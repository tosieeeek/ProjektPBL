#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <string>
#include <vector>

using namespace std;

/**
 * @class HangmanGame
 * @brief Klasa zarządzająca stanem i logiką gry w Wisielca.
 * * Odpowiada za wyświetlanie interfejsu w konsoli, weryfikację
 * podawanych przez gracza liter oraz sprawdzanie warunków końca gry.
 */
class HangmanGame {
private:
    string word;                 ///< Prawidłowe hasło do odgadnięcia.
    string hidden_word;          ///< Hasło zamaskowane znakami podkreślenia.
    int lives;                    ///< Liczba pozostałych błędów do popełnienia.
    vector<char> guessed_letters; ///< Lista liter, które gracz już sprawdził.

    bool wasEntered(char letter);
    void displayStatus();

public:
    HangmanGame(string drawn_word);
    void start();
    void checkLetter(char letter);
    void endGame();
};

#endif