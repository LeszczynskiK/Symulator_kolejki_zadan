#ifndef ZADANIA_HPP
#define ZADANIA_HPP

#include <iostream>

#include "kolejka_szablon.hpp"
#include "komunikaty.hpp"

using namespace std;

void chooseMode();//choos which function you want to call

void dodaj_zadanie();//add new task to vector
void usun_zadanie();//delete existing tast from vector
void edytuj_zadanie();//edit existing fast from vector
void wypisz_zadania();//display all working tasks with is counting time to finish etc...
void koniecSymulacji();//exit app


#endif //ZADANIA_HPP