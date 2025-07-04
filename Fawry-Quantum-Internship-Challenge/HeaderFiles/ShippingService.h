#pragma once
#include <iostream>
using namespace std;

class clsShippingService
{
	virtual string getName() = 0;
	virtual double getWeight() = 0;
};