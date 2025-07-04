#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "Product.h"
#include "Customer.h"
#include "ShippingService.h"
using namespace std;

class clsCart
{
private:
	vector <clsProduct> _vOfProducts;
	vector <int> _vOfProductsQuantity;

	bool _IsThereShippment()
	{
		if (_vOfProducts.size() == 1 && _vOfProducts[0].getName() == "Scratch Card")
		{
			return false;
		}
		else
			return true;
	}

	void _PrintShippmentNotice()
	{
		if (!_IsThereShippment())
		{
			cout << "\nNo shipping for chosen items\n";
			return;
		}

		cout << "** Shipment notice **\n";

		double TotalQuantityInKG = 0;

		for (int i = 0; i < _vOfProducts.size(); i++)
		{
			if (_vOfProducts[i].getName() == "Scratch Card")
				continue;

			cout << _vOfProductsQuantity[i] << "x " << _vOfProducts[i].getName() << setw(18 - _vOfProducts[i].getName().size()) << right
				<< _vOfProducts[i].getWeight() << "g" << endl;

			TotalQuantityInKG += (_vOfProducts[i].getWeight() * _vOfProductsQuantity[i]);
		}

		TotalQuantityInKG = TotalQuantityInKG / 1000;

		cout << "Total package weight " << TotalQuantityInKG << "Kg\n";

	}

	bool _IsBalanceSufficient(double CustomerBalance, double Amount)
	{
		if (CustomerBalance >= Amount)
			return true;
		else
			return false;
	}

	void _PrintCheckoutReceipt(clsCustomer Customer)
	{
		cout << "\n** Checkout receipt **\n";

		double SubTotal = 0,Shipping = 30, Amount = 0;

		for (int i = 0; i < _vOfProducts.size(); i++)
		{
			cout << _vOfProductsQuantity[i] << "x " << _vOfProducts[i].getName() << setw(18 - _vOfProducts[i].getName().size()) << right
				<< _vOfProducts[i].GetPrice() << endl;

			SubTotal += (_vOfProducts[i].GetPrice() * _vOfProductsQuantity[i]);
		}
		cout << "---------------------\n";
		cout << "Subtotal" << setw(12) << right << SubTotal << endl;
		cout << "Shipping" << setw(12) << Shipping << endl;
		Amount = SubTotal + Shipping;
		cout << "Amount" << setw(14) << Amount << endl;

		if (!_IsBalanceSufficient(Customer.GetBalance(), Amount))
		{
			cout << "\nerror : Customer's balance is insufficient.\n";
			return;
		}

		Customer.SetBalance(Customer.GetBalance() - Amount);
		cout << "Current balance after payment : " << Customer.GetBalance();

	}

	bool _IsQuantityOfProductAvalible(clsProduct Product, int Quantity)
	{
		if (Product.GetQuantity() < Quantity)
			return false;
		else
			return true;
	}

	bool _IsCartEmpty()
	{
		if (_vOfProducts.empty())
			return true;
		else
			return false;
	}

public:
	void Add(clsProduct Product,int Quantity)
	{
		if (!_IsQuantityOfProductAvalible(Product, Quantity))
		{
			cout << "\nerror : can't add this Quantity of " << Product.getName() << endl << endl;
			return;
		}

		_vOfProducts.push_back(Product);
		_vOfProductsQuantity.push_back(Quantity);

		Product.SetQuantity(Product.GetQuantity() - Quantity);
	}

	void PrintWholeReceipt(clsCustomer Customer)
	{
		if (_IsCartEmpty())
		{
			cout << "\nerror : Cart is Empty\n";
			return;
		}


		_PrintShippmentNotice();

		_PrintCheckoutReceipt(Customer);
	}

};