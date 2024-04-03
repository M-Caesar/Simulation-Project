#pragma once
#include <iostream>
using std::string;

class CustomerType
{
private:
	string custID;
	int time;
public:
	void SetCustomerID();
	string GetCustomerID();
	void UpdateTime();
	int getTime();
};

