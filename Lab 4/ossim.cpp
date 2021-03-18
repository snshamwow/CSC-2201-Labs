//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1                     ossim.cs
//
//  (Shell) Operating system task scheduling simulation
//
//--------------------------------------------------------------------

// Simulates an operating system's use of a priority queue to regulate
// access to a system resource (printer, disk, etc.).

#include <iostream>
#include <cstdlib>
#include "Heap.cpp"
#include "PriorityQueue.cpp"
#include <time.h>

using namespace std;

//--------------------------------------------------------------------
//
// Declaration for the task data struct
//

struct TaskData
{
    int getPriorityHeap() const
        { return priorityTask; }     

int priorityTask,               
    arrivedTask;                 

};

//--------------------------------------------------------------------

int main()
{
    PriorityQueue<TaskData, int, Less<int>> taskPQ;   
    TaskData task;               
    int lengthSim,               
        minute,                 
        numPrtiyLevel,          
        numArrive,           
        j;                      

    srand((unsigned int) time(NULL) );

    cout << endl << "Enter amount of priority levels: ";
    cin >> numPrtiyLevel;

    cout << "Enter how long you want to run the simulator: ";
    cin >> lengthSim;

    for (minute = 0; minute < lengthSim; minute++)
    {
        if (!taskPQ.isEmpty())
        {
            task = taskPQ.dequeue();
            cout << "At " << minute << " dequeued : ";
            cout << task.priorityTask << " " << task.arrivedTask << " " <<
                (minute - task.arrivedTask) << endl;
        }

        switch (rand() % 4)
        {
            case 1:
                if (!taskPQ.isFull())
                {
                    task.priorityTask = rand() % numPrtiyLevel;
                    task.arrivedTask = minute;
                    taskPQ.enqueue(task);
                }
                break;
            case 2:
                for (j = 0; j < 2 && !taskPQ.isFull(); j++)
                {
                    task.priorityTask = rand() % numPrtiyLevel;
                    task.arrivedTask = minute;
                    taskPQ.enqueue(task);
                }
                break;
        }

    }

    return 0;
}

