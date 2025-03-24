#include "symulacja.hpp"

extern szablon_kolejki<int, string> queue1; 

void executeTasks(szablon_kolejki<int, string>& queue1) //function to simulate tasks working in queue
{

    //why queue1.queue ?? - queue1 is object of szablon_kolejki class,
    //queue is is part of this class(single element) defined in szablon_kolejki
    //it is defined vector<Task<T1, T2>> queue; thats why i type queue1.queue...


    cout << endl;

    if (queue1.empty()) //if there are nos tasks in queue...(object is empty)
    {
        cout << "Kolejka jest pusta, nie ma zadan do wykonania!" << endl;
        pause_add();
        return;
    }

    //sort by priority - lower priority is more important(will execute quicker)
    stable_sort(queue1.queue.begin(), queue1.queue.end(), 
        [](const Task<int, string>& a, const Task<int, string>& b) {
            return a.priority < b.priority;
        });

    
    //simulation of tasks working...
    while (!queue1.empty())//while queue is not empty 
    {

        //there is no needment for iteraton throw all of the class elements, becouse
        //it naturally go throw them all becouse of erasing element is duration<0
        //so if element is deleted from vector, it naturally go to next one
        //to 1st element we get like : .front()

        auto& currentTask = queue1.queue.front();//reference to 1st task(to work on oryginal)

        //task with values before decrementation time(when loaded task from queue)
        cout << "Wykonywanie zadania: " << currentTask.name << "|Priorytet: " << currentTask.priority << "|Pozostaly czas: " << currentTask.duration << endl;

        //this is for element of szablon_kolejki object
        while (currentTask.duration > 0) //if time of task (to finish) is more than 0
        {
            this_thread::sleep_for(chrono::seconds(1)); //pause for 1 sec(main thread delay)
            currentTask.duration--;//decrease by 1 sec(duration of task)

            //actualise etiquette by new time(becouse task is executing and time is getting lower...)
            cout << "Wykonywanie zadania: " << currentTask.name << "|Priorytet: " << currentTask.priority << "|Pozostaly czas: " << currentTask.duration << endl;
        }

        //if task time <0, means task finished...
        cout<<endl;
        cout << "Zadanie " << currentTask.name << " zakonczone!" << endl;
        cout << "------------------------------------------------------------------" << endl;
        queue1.queue.erase(queue1.queue.begin()); //delete from queue, becouse task finished
        long_pause(3);
        cout<<endl<<endl;
    }

    //if vector empty, means all tasks completed...
    cout<<endl;
    cout << "Wszystkie zadania zostaly wykonane!" << endl;

    long_pause(5);
    system("clear");
}