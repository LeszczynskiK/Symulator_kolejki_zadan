#ifndef KOLEJKA_SZABLON_HPP
#define KOLEJKA_SZABLON_HPP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//struct which will represent single tast(priority of tast, time to finish task and name of task)
template <typename T1, typename T2>
struct Task {
    //public fields(this is structure)
    int priority; //task priority
    T1 duration;  //time to finish task
    T2 name;      //name of task

    Task(int p, T1 d, T2 n) : priority(p),duration(d), name(n) {}//constructos (initualise fields in Task structure)
};



//T1 is time of task format
//T2 is "name" of task format
template<typename T1,typename T2> class szablon_kolejki
{
    public:
    vector<Task<T1, T2>> queue;//task representation (based on structure named Task)->with template base(T1 and T2)

    void addTask(int priority,T1 duration, T2 name) //add task to queue(priority,time to finish task, name of task)
    {
        queue.emplace_back(priority,duration,name);//emplace is better than push, becouse push firsly create object and then copy or move to vector
        //emplace create in vector inside so we skip part of coppying or moving
    }

    void display() //display fields of queue 
    {
        cout << "Kolejka: "<<endl;
        for ( auto& task : queue) //reference to object(work on original)- iterate throw vector 
        {//and display fields of structure(1 object of queue on iteration)
            cout << "Priorytet: " << task.priority << ", Czas: " << task.duration << ", Nazwa: " << task.name << endl;//task is local variable to iterate throw queue
        }
        if (queue.empty()) //if queue is empty
        {
            cout << "Kolejka jest pusta"<<endl;
        }
    }

};


#endif //SKOLEJKA_SZABLON_HPP