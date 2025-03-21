#include "zadania.hpp"

extern szablon_kolejki<int, string> queue1;

void dodaj_zadanie(szablon_kolejki<int, string>& queue1)//add new task to vector
{
    int priority;
    int duration;
    string name;

    cout << "Podaj priorytet zadania: ";
    cin >> priority;
    cout<<endl;

    cout << "Podaj czas wykonania zadania: ";
    cin >> duration;
    cout<<endl;

    cout << "Podaj nazwe zadania: ";
    cin.ignore();//ignore new line char after cin(becouse we are using getline, i wanr want new line on the beginning of line)
    getline(cin, name); // get full name of task

    //add fask if function made in template (kolejka_szablon.hpp)
    queue1.addTask(priority, duration, name);//put values to vector which is given by argument typping 
    cout << "Zadanie dodane!" << endl;
}


void usun_zadanie(szablon_kolejki<int, string>& queue1) 
{
    if (queue1.queue.empty()) //if queue1(argument) . queue(template vector, from szablon_kolejki) is empty
    {
        cout << "Kolejka jest pusta, nie ma czego usunac!" << endl;
        return;
    }

    //we will work on 3 values to create task based on...
    int priority;
    int duration;
    string name;

    cout<<endl;
    cout << "Aktualne zadania:" << endl;
    queue1.display();
    cout<<endl<<endl;

    cout << "Podaj dane zadania do usuniecia:" << endl;
    cout << "Priorytet: ";//put values to variable(we will look for tast chich fields have these values)
    cin >> priority;
    cout << "Czas wykonania: ";
    cin >> duration;
    cout << "Nazwa zadania: ";
    cin.ignore();
    getline(cin, name);;//ignore new line after cin - becouse as line from getline we want to skip part of \n
    cout<<endl;

    // look for task with typped in parmeters
    for (auto it = queue1.queue.begin(); it != queue1.queue.end(); ++it) //iterate from begin of vector till the end..
    {//iterate throw queue(template - this is type), queue(this is oryginal queue variable type to work on)
        if (it->priority == priority && it->duration == duration && it->name == name) //it-> is iterator , we connect it with variable one to get proper value of what we want
        {//if it(iterator) value is equal to out search one
            queue1.queue.erase(it);//erase it(this task which is what we were looking for)
            cout << "Zadanie usuniete!" << endl;
            return;
        }
    }
    cout << "Nie znaleziono zadania o podanych parametrach!" << endl;//if not found
}

void edytuj_zadanie(szablon_kolejki<int, string>& queue1) 
{
    if (queue1.queue.empty()) 
    {//if queue is empty
        cout << "Kolejka jest pusta, nie ma czego edytowac!" << endl;
        return;
    }

    //we will work on 3 values to create task based on...(here we are looking for typped values to compare with vector which has all tasks inside)
    int priority;
    int duration;
    string name;

    cout << "Aktualne zadania:" << endl;
    queue1.display();
    cout<<endl<<endl;

    cout << "Podaj dane zadania do edycji:" << endl;
    cout << "Priorytet: ";
    cin >> priority;//put values to variable(we will look for tast chich fields have these values)
    cout << "Czas wykonania: ";
    cin >> duration;
    cout << "Nazwa zadania: ";
    cin.ignore();//ignore new line after cin - becouse as line from getline we want to skip part of \n
    getline(cin, name);
    cout<<endl;

    //look for tast with typped parameters
    for (auto& task : queue1.queue) 
    { //reference becouse we want to modify original one
        if (task.priority == priority && task.duration == duration && task.name == name) //iterate throw queue(template - this is type), queue(this is oryginal queue variable type to work on)
        {
            //put new values(which will replace the old ones)
            cout << "Podaj nowe dane zadania:" << endl;
            cout << "Nowy priorytet: ";
            cin >> task.priority;//becouse its reference auto& task, we will replace value in original variavle
            cout << "Nowy czas wykonania: ";
            cin >> task.duration;
            cout << "Nowa nazwa zadania: ";
            cin.ignore();
            getline(cin, task.name);;//ignore new line after cin - becouse as line from getline we want to skip part of \n
            cout << "Zadanie zaktualizowane!" << endl;
            return;
        }
    }
    cout << "Nie znaleziono zadania o podanych parametrach!" << endl;
}

void wypisz_zadania(szablon_kolejki<int, string>& queue1) {
    queue1.display();//use function which is created in kolejka_szablon.hpp

    //after display of tasks, make quick break(when use want to go to nex part, have to click ANY button)
    cout << endl << endl << endl;
    cout << "Czy chcesz przejsc dalej?" << endl;
    cout << "Nacisnij dowolny przycisk..." << endl;
    
    //wait for input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//ignore all chars in input buffor  till you get new line char or get  max number of chars(in practive, find \n)
    cin.get(); //wait for any button click to continue
    system("clear");
}


void koniecSymulacji()//exit app
{
    cout << "Koniec symulacji!" << endl;
    exit(0);//quit app
}

int temp1;        // temp choice variable
void chooseMode() // choos which function you want to call
{
    cout << endl;
    cout << "Wybor: ";
    cin >> temp1;//type value to choose option from 1 to 5 (tasks manager)

    if (temp1 > 0 && temp1 < 6)//if number is out of option range
    {
        opcje();//put temp1 to switch case and run functions which fit case number
    }
    else
    {
        cout << "Nie ma takiego wyboru...";
        cout << "Wybor: ";
        cin >> temp1;//put again value to temp1
        opcje();//run function wih new temp1 value..
    }
}

//queue1 if from exter variable
void opcje()
{
    switch (temp1)
    {

    //pause adding is to simulate time which sth need to fullfil and add quick breaks between next information to make id readable by user
    //system("clear") is used to avoid creating unreadable list with informaiton for human
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

        system("clear");//if choosed any option except correct ones, show info
        cout << "Nie ma takiej opcji do wyboru!" << endl;
        cout << "Powrot to menu wyboru ... " << endl;
        cout << "Wcisnij DOWOLNY przycisk by przejsc........" << endl;
        break;
    }
}
