#pragma once
#include <iostream>
#include "queueADT.h"
#include "CustomerType.h"
class CustomerQueue: public CustomerType
{
private:
	queueADT<CustomerType> custQueue;
	queue<int> testqueue;
public:

};

