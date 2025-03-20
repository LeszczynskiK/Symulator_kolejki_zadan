#ifndef ZADANIA_HPP
#define ZADANIA_HPP

#include <iostream>

#include "kolejka_szablon.hpp"
#include "komunikaty.hpp"

using namespace std;

void chooseMode();//choos which function you want to call
void opcje();//all case options

void dodaj_zadanie(szablon_kolejki<int, string>);//add new task to vector
void usun_zadanie(szablon_kolejki<int, string>);//delete existing tast from vector
void edytuj_zadanie(szablon_kolejki<int, string>);//edit existing fast from vector
void wypisz_zadania(szablon_kolejki<int, string>);//display all working tasks with is counting time to finish etc...
void koniecSymulacji();//exit app


#endif //ZADANIA_HPP