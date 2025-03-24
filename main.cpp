#include "iostream"
using namespace std;

#include "kolejka_szablon.hpp" //template of queue functionality
#include "komunikaty.hpp"
#include "zadania.hpp"

// create queue
szablon_kolejki<int, string> queue1; // T1 is in type(time) , T2 is string type(name of task)

int main()
{

    system("clear");
    first_info();
    while (true)
    {
        choose_mode(); // this is only information display
        chooseMode();  // here we choose which function we want to use
        opcje();//run choosed option in chooseMode()
    }

    return 0;
}