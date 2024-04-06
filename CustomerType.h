#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "queueAsArray.h"
using namespace std;

class CustomerType
{
private:
	int custID;
	int arriveTime;
	int waitingTime;
	int transactionTime;
public:
	CustomerType(int cNum = 0, int arrTime = 0, int waitTime = 0, int tranTime = 0);

	void setCustomerInfo(int cNum = 0, int arrTime = 0, int waitTime = 0, int tranTime = 0);
	int GetCustID();
	int getWaitTime();
	void setWaitTime(int waitTime);
	void incWaitTime();
	int getArrTime();
	int getTranTime();
	/*void SetCustomerID();
	string GetCustomerID();
	void UpdateTime();
	int getTime();*/
};

class ServerType
{
private:
	CustomerType currCustomer;
	string status;
	int tranTime;


	//how to include customer object
public:
	ServerType();
	bool isFree();
	void setBusy();
	void setFree();
	void setTranTime(int time);
	void setTranTime();
	int getRemainingTransTime();
	void decreaseTranTime();
	void setCurrCust(CustomerType customer);
	int getCurrCustID();
	int getCurrCustArrTime();
	int getCurrCustWaitTime();
	int getCurrCustTranTime();



	/*void setServID();
	string getServID();
	void setServStatus();
	bool getServStatus();
	void setTranTime();
	int getTranTime();
	void UpdateTranTime();
	int getWaitTime();
	string getCustID();
	void ServeCust();*/
};

class serverListType
{
private:
	int numofServs;
	ServerType* servs;
public:
	serverListType(int num = 1);
	~serverListType();
	int getFreeServID();
	int getNumofBusyServ();
	void setServBusy(int servID, CustomerType currCustomer,
					int time);
	void setServBusy(int servID, CustomerType currCustomer);
	void updateServ();

	/*void addServ();
	int findServ();
	void assignServ();
	void UpdateBusyTimes();
	int getCustServed();
	int getCustwaitTime();*/
};

class waitingCustomerQueueType : public queueType<CustomerType>
{
public:
	waitingCustomerQueueType(int size = 100);
	void updateWaitQueue();
};
