#ifndef INPUTPROTECT_HPP
#define INPUTPROTECT_HPP

#include <iostream>
using namespace std;

#include "komunikaty.hpp"

int your_choice();//you can choose 1,2,3,4,5 or 6 mode (save to make impossible to choose any other than these which i said)
int getInt(const string &msg);//here can be typped only int one (also not empty, so enter will not pass)
string getString(const string &msg);//here can be typped only string one (also not empty, so enter will not pass)

#endif //INPUTPROTECT_HPP