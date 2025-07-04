#pragma once
#include <iostream>
#include "Customer.h"
#include "Cart.h"
using namespace std;

class clsCheckout
{
public:
	static void Checkout(clsCustomer Customer,clsCart Cart)
	{
		Cart.PrintWholeReceipt(Customer);
	}
};