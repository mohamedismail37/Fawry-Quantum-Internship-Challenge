#pragma once
#include <iostream>
using namespace std;

class clsCustomer
{
protected:
	double _Balance;

public:
	clsCustomer(double Balance)
	{
		_Balance = Balance;
	}

	double GetBalance()
	{
		return _Balance;
	}
	void SetBalance(double NewBalance)
	{
		_Balance = NewBalance;
	}
};