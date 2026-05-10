# Hangman C++ Project 🎮

Prosta, konsolowa implementacja klasycznej gry **Wisielec** napisana w języku C++.

## 🚀 Funkcje
- **Logika obiektowa**: Podział na klasy odpowiedzialne za mechanikę gry (`HangmanGame`) oraz zarządzanie danymi (`WordManager`).
- **Dynamiczna baza haseł**: Gra wczytuje słowa z zewnętrznego pliku tekstowego `slowa.txt`.
- **System Fallback**: W przypadku braku pliku, gra posiada wbudowaną bazę awaryjną, co zapobiega awarii programu.
- **Walidacja wejścia**: Program ignoruje powtarzające się litery i obsługuje błędne znaki.
- **Zarządzanie stanem**: Licznik żyć (domyślnie 6) oraz dynamiczne maskowanie hasła.

## 🛠️ Wymagania
- Kompilator C++ wspierający standard **C++11** lub nowszy (np. GCC, Clang, MSVC).
- System operacyjny: Windows, Linux lub macOS.

## 🏗️ Struktura projektu
- **main.cpp** - Punkt wejścia aplikacji i główna pętla programu.
- **HangmanGame.h/.cpp** - Klasa kontrolująca przebieg rozgrywki, stan żyć i weryfikację liter.
- **WordManager.h/.cpp** - Klasa odpowiedzialna za obsługę plików I/O i losowanie haseł.
- **slowa.txt** - Plik tekstowy zawierający bazę słów.

