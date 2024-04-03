#pragma once
#include "ServerType.h"
class ServerListType :
    public ServerType
{
private:
public:
    void addServ();
    int findServ();
    void assignServ();
    void UpdateBusyTimes();
    int getCustServed();
    int getCustwaitTime();

};
