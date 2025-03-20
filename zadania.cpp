#include "zadania.hpp"

    //initialise queue here
extern szablon_kolejki<int, string> queue1;//T1 is in type(time) , T2 is string type(name of task)

void dodaj_zadanie(szablon_kolejki<int, string> queue)//add new task to vector
{
    //add task is created in template file kolejka_szablon.hpp
    queue.addTask(2, 3,"task 1");//priority, duration, name of task
    queue.addTask(1, 5,"taks 2");
    queue.addTask(3, 2,"task 3");
}


void usun_zadanie(szablon_kolejki<int, string> queue)//delete existing tast from vector
{


}


void edytuj_zadanie(szablon_kolejki<int, string> queue)//edit existing fast from vector
{


}


void wypisz_zadania(szablon_kolejki<int, string> queue)//display all working tasks with is counting time to finish etc...
{
    //display tasks is created in template file kolejka_szablon.hpp
    queue.display();
}


void koniecSymulacji()//exit app
{



}

int temp1;        // temp choice variable
void chooseMode() // choos which function you want to call
{
    cout << endl;
    cout << "Wybor: ";
    cin >> temp1;

    if (temp1 > 0 && temp1 < 6)
    {
        opcje();
    }
    else
    {
        cout << "Nie ma takiego wyboru...";
        cout << "Wybor: ";
        cin >> temp1;
        opcje();
    }
}

void opcje()
{
    switch (temp1)
    {
    case 1:
        system("clear");
        cout << "Wybrano: ";
        cout << "1. Wprowadz zadanie" << endl;
        dodaj_zadanie(queue1); // call function to add task
        pause_add();
        system("clear");

        break;
    case 2:
        system("clear");
        cout << "Wybrano: ";
        cout << "2. Usun zadanie" << endl;
        usun_zadanie(queue1); // call function to delete task
        pause_add();
        system("clear");

        break;

    case 3:
        system("clear");
        cout << "Wybrano: ";
        cout << "3. Edytuj istniejace zadanie" << endl;
        edytuj_zadanie(queue1); // call function to edit task
        pause_add();
        system("clear");

        break;

    case 4:
        system("clear");
        cout << "Wybrano: ";
        cout << "4. Wypisz dzialajace zadania" << endl;
        wypisz_zadania(queue1); // call function to display working tasks
        pause_add();
        system("clear");

        break;

    case 5:
        system("clear");
        cout << "Wybrano: ";
        cout << "5. Wyjdz z programu" << endl;

        // count 3,2,1 and then quit
        pause_add();
        cout << "3" << endl;
        pause_add();
        cout << "2" << endl;
        pause_add();
        cout << "1" << endl;
        pause_add();
        exit(0);

        break;

    default:

        system("clear");
        cout << "Nie ma takiej opcji do wyboru!" << endl;
        cout << "Powrot to menu wyboru ... " << endl;
        cout << "Wcisnij DOWOLNY przycisk by przejsc........" << endl;
        break;
    }
}
