#pragma once
#include <iostream>
using std::string;

class ServerType
{
private:
	string servID;
	bool servStatus;
	int servTranTime;

	//how to include customer object
public:
	void setServID();
	string getServID();
	void setServStatus();
	bool getServStatus();
	void setTranTime();
	int getTranTime();
	void UpdateTranTime();
	int getWaitTime();
	string getCustID();
	void ServeCust();
};

