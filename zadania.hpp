#ifndef ZADANIA_HPP
#define ZADANIA_HPP

#include <iostream>

#include "kolejka_szablon.hpp"
#include "komunikaty.hpp"
#include "InputProtect.hpp"
#include "symulacja.hpp"

using namespace std;

void chooseMode(); // choos which function you want to call
void opcje();      // all case options

// argument is reference, becouse i want to work on oryginal
void dodaj_zadanie(szablon_kolejki<int, string> &);  // add new task to vector
void usun_zadanie(szablon_kolejki<int, string> &);   // delete existing tast from vector
void edytuj_zadanie(szablon_kolejki<int, string> &); // edit existing fast from vector
void wypisz_zadania(szablon_kolejki<int, string> &); // display all working tasks with is counting time to finish etc...
void startSimul();                                   // start simulation of tasks working in queue
void koniecSymulacji();                              // exit app

#endif // ZADANIA_HPP