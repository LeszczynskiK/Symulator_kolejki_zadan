#ifndef SYMULACJA_HPP
#define SYMULACJA_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <thread>
#include <chrono>

#include "kolejka_szablon.hpp"
#include "komunikaty.hpp"

using namespace std;

void executeTasks(szablon_kolejki<int, string>& queue);//function to simulate tasks working in queue

#endif