#include "CustomerType.h"

void CustomerType::setCustomerInfo(int custNum, int arrTime, int waitTime, int tranTime)
{
	custID = custNum;
	arriveTime = arrTime;
	waitingTime = waitTime;
	transactionTime = tranTime;
}
CustomerType::CustomerType(int custNum, int arrTime, int waitTime, int tranTime)
{
	setCustomerInfo(custNum, arrTime, waitTime, tranTime);
}
int CustomerType::getWaitTime()
{
	return waitingTime;
}
void CustomerType::incWaitTime()
{
	waitingTime++;
}
void CustomerType::setWaitTime(int time)
{
	waitingTime = time;
}
int CustomerType::getArrTime()
{
	return arriveTime;
}
int CustomerType::getTranTime()
{
	return transactionTime;
}
int CustomerType::GetCustID()
{
	return custID;
}

//Server Type fucntions
ServerType::ServerType()
{
	status = "free";
	tranTime = 0;
}
bool ServerType::isFree()
{
	return (status == "free");
}
void ServerType::setBusy()
{
	status = "busy";
}
void ServerType::setFree()
{
	status = "free";
}
void ServerType::setTranTime(int time)
{
	tranTime = time;
}
void ServerType::setTranTime()
{
	int time;
	time = currCustomer.getTranTime();
	tranTime = time;
}
void ServerType::decreaseTranTime()
{
	tranTime--;
}
int ServerType::getRemainingTransTime()
{
	return tranTime;
}
void ServerType::setCurrCust(CustomerType customer)
{
	currCustomer = customer;
}
int ServerType::getCurrCustID()
{
	return currCustomer.GetCustID();
}
int ServerType::getCurrCustArrTime()
{
	return currCustomer.getArrTime();
}
int ServerType::getCurrCustWaitTime()
{
	return currCustomer.getWaitTime();
}
int ServerType::getCurrCustTranTime()
{
	return currCustomer.getTranTime();
}

//ServerListType functions

serverListType::serverListType(int nums)
{
	numofServs = nums;
	servs = new ServerType[nums];
}

serverListType::~serverListType()
{
	delete[] servs;
}

int serverListType::getFreeServID()
{
	int servID = -1;

	for (int i = 0; i < numofServs; i++)
	{
		if (servs[i].isFree())
		{
			servID = i;
			break;
		}
		return servID;
	}
}

int serverListType::getNumofBusyServ()
{
	int busyServs = 0;
	for (int i = 0; i < numofServs; i++)
		if (!servs[i].isFree())
			busyServs++;
	return busyServs;
}

void serverListType::setServBusy(int servID, CustomerType customer, int time)
{
	servs[servID].setBusy();
	servs[servID].setTranTime(time);
	servs[servID].setCurrCust(customer);
}

void serverListType::setServBusy(int servID, CustomerType customer)
{
	int time;

	time = customer.getTranTime();

	servs[servID].setBusy();
	servs[servID].setTranTime(time);
	servs[servID].setCurrCust(customer);
}

void serverListType::updateServ()
{
	for (int i = 0; i < numofServs; i++)
		if (!servs[i].isFree())
		{
			servs[i].decreaseTranTime();
			if (servs[i].getRemainingTransTime() == 0)
			{
				cout << "From server number " << (i + 1)
					<< " customer number"
					<< servs[i].getCurrCustID()
					<< "\n		departed at time unit"
					<< servs[i].getCurrCustArrTime() +
					servs[i].getCurrCustWaitTime() +
					servs[i].getCurrCustTranTime() << endl;
				servs[i].setFree();
			}
		}
}

//waitQueue

waitingCustomerQueueType::waitingCustomerQueueType(int size) :queueType<CustomerType>(size)
{

}


void waitingCustomerQueueType::updateWaitQueue()
{
	CustomerType customer;

	customer.setWaitTime(-1);
	int wTime = 0;

	addQueue(customer);

	while (wTime != -1)
	{
		customer = front();
		deleteQueue();

		wTime = customer.getWaitTime();
		if (wTime == -1)
			break;
		customer.incWaitTime();
		addQueue(customer);
	}
}