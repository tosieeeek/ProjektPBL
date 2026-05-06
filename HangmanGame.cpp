#include "HangmanGame.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * @brief Sprawdza, czy gracz już wcześniej podał daną literę.
 * @param letter Znak do sprawdzenia.
 * @return true Jeśli litera znajduje się już na liście zgadywanych.
 * @return false Jeśli litera pojawia się po raz pierwszy.
 */
bool HangmanGame::wasEntered(char letter) {
    return find(guessed_letters.begin(), guessed_letters.end(), letter) != guessed_letters.end();
}

/**
 * @brief Wyświetla aktualny stan gry (ukryte hasło i liczbę żyć).
 */
void HangmanGame::displayStatus() {
    cout << "\n=====================================" << endl;
    cout << "Haslo: " << hidden_word << endl;
    cout << "Pozostale zycia: " << lives << endl;
    cout << "Podaj litere: ";
}

/**
 * @brief Konstruktor klasy gry.
 * @param drawn_word Słowo, które zostało wylosowane dla obecnej partii.
 */
HangmanGame::HangmanGame(string drawn_word) {
    word = drawn_word;
    hidden_word = string(word.length(), '_');
    lives = 6;
}

/**
 * @brief Rozpoczyna główną pętlę rozgrywki.
 * * Pętla działa do momentu odgadnięcia hasła lub utraty wszystkich żyć.
 */
void HangmanGame::start() {
    cout << "--- WITAJ W GRZE WISIELEC ---" << endl;
    cout << "Masz " << lives << " szans na pomylke." << endl;

    while (lives > 0 && hidden_word != word) {
        displayStatus();

        char letter;
        cin >> letter;
        letter = tolower(letter); // Zamiana na małą literę

        if (wasEntered(letter)) {
            cout << "Ta litera zostala juz sprawdzona! Sprobuj innej." << endl;
            continue;
        }

        guessed_letters.push_back(letter);
        checkLetter(letter);
    }

    endGame();
}

/**
 * @brief Weryfikuje, czy podana litera znajduje się w haśle.
 * * Aktualizuje zamaskowane hasło w przypadku trafienia, lub
 * zmniejsza liczbę żyć w przypadku błędu.
 * * @param letter Znak wprowadzony przez gracza.
 */
void HangmanGame::checkLetter(char letter) {
    bool hit = false;
    for (size_t i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            hidden_word[i] = letter; // Odsłonięcie litery
            hit = true;
        }
    }

    if (hit) {
        cout << "Dobrze! Litera '" << letter << "' znajduje sie w hasle." << endl;
    } else {
        cout << "Pudlo! Brak litery '" << letter << "' w hasle." << endl;
        lives--;
    }
}

/**
 * @brief Wyświetla ekran końcowy podsumowujący wynik gry.
 */
void HangmanGame::endGame() {
    cout << "\n-----------------------------" << endl;
    if (hidden_word == word) {
        cout << "GRATULACJE! Odgadles haslo: " << word << endl;
    } else {
        cout << "KONIEC GRY! Zostales powieszony." << endl;
        cout << "Prawidlowe haslo to: " << word << endl;
    }
}