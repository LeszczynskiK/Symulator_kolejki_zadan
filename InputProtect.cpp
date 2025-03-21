#include "InputProtect.hpp"

bool your_choice_bool = false;//bool type to tell if we are in choice function currently

int your_choice()//you can choose 1,2,3,4,5 or 6 mode (save to make impossible to choose any other than these which i said)
{
    your_choice_bool = true;//we are in choice funciton now
    int choice;//option value
    bool valid = false;//if typped value is okey?

    do {
        choice = getInt("Wybor: ");
        if (choice < 1 || choice > 6) //choice is between possible options to choose
        {//choice is wrong
            system("clear");
            choose_mode();//display possibilities to use
        } else {
            valid = true;//eys, input is number 1,2,3,4,5 or 6
        }
    } while (!valid);//do while input is not valid...

    your_choice_bool = false;//we are leaving choice funciton now
    return choice;//return choice(choice is corret type becouse leave inputProtect method...)
}

int getInt(const string &msg) //argument is message value to display
{
    int value;//input converted to int
    string input;//input in stirng(later converted by stoi)
    bool valid = false;

    do {
        cout << msg;//cout message from argument typped to function
        getline(cin, input);//get input here and cave in string variable

        try //try to run functions
        {
            size_t pos;
            value = stoi(input, &pos);//string to int(input conver to int type vaved in value)
            if (pos != input.length()) 
            {//in pose will be saved value converted to int (if pos legnth is not equal to iput lenght - means that in input were not only numbers but also chars)
                throw invalid_argument("Nieprawidlowy format");
            }
            if (value < 0) {
                system("clear");
                cout << "Wartosc musi byc wprowadzona zgodnie z mozliwymi wyborami! Wprowadz ponownie." << endl;
                if (your_choice_bool)  //if we are in choice funciton right now, display possibilities...
                {
                    cout << "1. Wprowadz zadanie" << endl;
                    cout << "2. Usun zadanie" << endl;
                    cout << "3. Edytuj istniejace zadanie" << endl;
                    cout << "4. Wypisz dzialajace zadania" << endl;
                    cout << "5. Symulacja dzialania zadan w kolejce" << endl;
                    cout << "6. Wyjdz z programu" << endl;
                }
            } else 
            {
                valid = true;//input is valid...
            }
        } catch (...) //if input not okey
        {
            system("clear");
            cout << "Wartosc musi byc wprowadzona zgodnie z mozliwymi wyborami! Wprowadz ponownie." << endl;
            if (your_choice_bool) //if we are in choice funciton right now, display possibilities...
            {
                cout << "1. Wprowadz zadanie" << endl;
                cout << "2. Usun zadanie" << endl;
                cout << "3. Edytuj istniejace zadanie" << endl;
                cout << "4. Wypisz dzialajace zadania" << endl;
                cout << "5. Symulacja dzialania zadan w kolejce" << endl;
                cout << "6. Wyjdz z programu" << endl;
            }
        }
    } while (!valid);//run while input is not valid

    return value;//here we are sure that choice is correct...
}