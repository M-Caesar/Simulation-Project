// Simulation Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CustomerType.h"

void setSimParams(int sTime, int numServs, int tranTime, int custArrivalTimeInterval);

void runSim();

int main()
{
    runSim();
    std::cout << "Hello World!\n";
}

void setSimParams(int sTime, int numServs, int tranTime, int custArrivalTimeInterval)
{
    cout << "Enter the simulation time: ";
    cin >> sTime;
    cout << endl;

    cout << "Enter the number of servers: ";
    cin >> numServs;
    cout << endl;

    cout << "Enter the transaction time: ";
    cin >> tranTime;
    cout << endl;

    cout << "Enter the time between customer arrivals: ";
    cin >> custArrivalTimeInterval;
    cout << endl;

    serverListType servList(numServs);
    
}

void runSim()
{
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
