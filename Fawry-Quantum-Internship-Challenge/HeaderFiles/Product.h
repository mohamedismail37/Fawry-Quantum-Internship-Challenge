#pragma once
#include <iostream>
#include "ShippingService.h"
using namespace std;

class clsProduct : public clsShippingService
{
protected:
	string _Name;
	double _Price;
	int _Quantity;
	bool _IsExpirable;
	// We can also add (string _ExpirbaleDate) as a feature if needed.
	double _Weight; 

public:

	clsProduct(string Name, double Price, int Quantity, bool IsExpirable,double Weight = 0) // Weight = 0 as defualt parameter for costructor, means that its not a shippable product.
	{
		_Name = Name;
		_Price = Price;
		_Quantity = Quantity;
		_IsExpirable = IsExpirable;
		_Weight = Weight;
	}

	string getName()
	{
		return _Name;
	}
	void SetName(string NewName)
	{
		_Name = NewName;
	}

	double GetPrice()
	{
		return _Price;
	}
	void SetPrice(double NewPrice)
	{
		_Price = NewPrice;
	}

	int GetQuantity()
	{
		return _Quantity;
	}
	void SetQuantity(int NewQuantity)
	{
		_Quantity = NewQuantity;
	}

	bool GetExpirablity()
	{
		return _IsExpirable;
	}
	void SetExpirablity(bool NewExpirablity)
	{
		_IsExpirable = NewExpirablity;
	}

	double getWeight()
	{
		return _Weight;
	}
	void SetWeight(double NewWeight)
	{
		_Weight = NewWeight;
	}

};