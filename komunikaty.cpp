#include "komunikaty.hpp"

void pause_add()//pause based on for loop
{
    for(int w=0;w<999;w++)
    {
        for(int n=0;n<999;n++)
        {
            //empty - only base on looping
        }
    }
}

void long_pause(int i)//pause_add period multiplied by i
{

    for(int j=0;j<i;j++)//i times called pause_add() function so multiply time of pause by i
    {
        pause_add();
    }
}

void first_info()//first message(information about application)
{
    cout<<"------------------------------------------------"<<endl<<endl;
    cout<<"Witaj w symulatorze kolejkowania zadan"<<endl;
    cout<<"Za chwile wprowadz twoje zadania, ktore beda skladac sie z 3 czesci"<<endl;
    cout<<"1. Priorytet"<<endl;
    cout<<"2. Czas wykonania zadania"<<endl;
    cout<<"3. Opis zadania"<<endl<<endl;
    cout<<"------------------------------------------------"<<endl<<endl;
}

void choose_mode()
{
    cout<<"1. Wprowadz zadanie"<<endl;
    cout<<"2. Usun zadanie"<<endl;
    cout<<"3. Edytuj istniejace zadanie"<<endl;
    cout<<"4. Wypisz dzialajace zadania"<<endl;
    cout<<"5. Wyjdz z programu"<<endl;

}