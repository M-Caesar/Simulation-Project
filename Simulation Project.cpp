// Simulation Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CustomerType.h"
using namespace std;

//void setSimParams(int sTime, int numServs, int tranTime, int custArrivalTimeInterval);
double PoissonDis(int timeInterval);
void runSim(serverListType servList, waitingCustomerQueueType waitQueue, int sTime, int numServs, int tranTime, int custArrivalTimeInterval);

int main()
{
    int sTime;
    int numServs;
    int tranTime;
    int custArrivalTimeInterval;

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
    waitingCustomerQueueType waitQueue(500);
    waitQueue.initializeQueue();

    runSim(servList, waitQueue, sTime, numServs,tranTime, custArrivalTimeInterval );
    //std::cout << "Hello World!\n";
}

double getRandomNumber()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    //cout << "This is the random number: " << dis(gen) << endl;
    return dis(gen);
}

double PoissonDis(int timeInterval)
{
    double e = exp(-1.0 / timeInterval);
    //cout << "This is e: " << e << endl;
    return e;
}

void runSim(serverListType servList, waitingCustomerQueueType waitQueue, int sTime, int numServs, int tranTime, int custArrivalTimeInterval)
{
    int custTracker = 1;
    int custServed = 0;
    double overallWaitTime = 0;
    int custLeft = 0;
    int tranComplete = 0;
    for (int currTime = 0; currTime < sTime; currTime++)
    {
        tranComplete = tranComplete + servList.updateServ();
        //servList.updateServ();
        waitQueue.updateWaitQueue();

        //if (getRandomNumber() > PoissonDis(custArrivalTimeInterval))
        if (getRandomNumber() > PoissonDis(custArrivalTimeInterval))
        {
            CustomerType newcustomer;
            newcustomer.setCustomerInfo(custTracker, currTime, 0, tranTime);
            waitQueue.addQueue(newcustomer);
            cout << "Customer number: " << newcustomer.GetCustID() << " arrived at time unit: " << newcustomer.getArrTime() << endl;
            custTracker++;
            //cout << "Busy servs number: " << servList.getNumofBusyServ() << endl;
            //cout << "Free servs number: " << servList.getFreeServID() << endl;
        }
        if (servList.getFreeServID() != -1 && waitQueue.isEmptyQueue() == false)
        {
            CustomerType servCust = waitQueue.front();
            if (servCust.GetCustID() != 0)
            {
                int workServID = servList.getFreeServID();
                servList.setServBusy(workServID, servCust);
                cout << "Server: " << workServID + 1 << " is helping customer " << servCust.GetCustID() << endl;

                overallWaitTime = overallWaitTime + servCust.getWaitTime();
                
                cout << "----Cust " << servCust.GetCustID() << " wait time was " << servCust.getWaitTime() << endl;
                waitQueue.deleteQueue();
            }
        }
    }
    cout << "Number of customers left in the queue: " << (custTracker - 1) - tranComplete << endl;
    cout << "Number of customers that arrived: " << custTracker - 1 << endl;
    cout << "Number of customers who completed a transaction: " << tranComplete << endl;
    cout << "Average wait time for customers in the queue: " << overallWaitTime / custTracker << endl;
    
    

    /*
    //string testfile;
    //ostream& outFile = outFile;
   // string testfile;
    //cout << "Provide output file" << endl;
    //cin >> outFile;
    for (int i = 0; i < sTime; i++)
    {
        // need to fix this
        //CustomerType customer;
        servList.updateServ();
        waitQueue.updateWaitQueue();
        //cout << servList.getNumofBusyServ() << endl;
        //waitQueue.addQueue(customer);
        if (i % custArrivalTimeInterval == 0)
        {
            CustomerType customer;
            waitQueue.addQueue(customer);
        }
        if (servList.getNumofBusyServ() != numServs && waitQueue.isEmptyQueue() == false)
        {
            //servList.getFreeServID();
            servList.setServBusy(servList.getFreeServID(),waitQueue.front() );
            waitQueue.deleteQueue();
        }
        //servList.updateServ();
        //waitQueue.updateWaitQueue();
    }
    */

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
