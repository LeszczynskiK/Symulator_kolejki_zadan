#include "iostream"
using namespace std;

#include "kolejka_szablon.hpp"//template of queue functionality
#include "komunikaty.hpp"
#include "zadania.hpp"

int main()
{
    first_info();
    while(true)
    {
        choose_mode();//this is only information display
        chooseMode();//here we choose which function we want to use




    }





    szablon_kolejki<int, string> queue1;//T1 is in type(time) , T2 is string type(name of task)
    queue1.addTask(2, 3,"task 1");//priority, duration, name of task
    queue1.addTask(1, 5,"taks 2");
    queue1.addTask(3, 2,"task 3");
    queue1.display();


    return 0;
}