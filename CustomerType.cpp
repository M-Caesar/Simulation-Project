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