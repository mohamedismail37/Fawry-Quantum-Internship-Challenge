#include <iostream>
#include "Cart.h"
#include "Checkout.h"
#include "Customer.h"
#include "Product.h"
using namespace std;

int main()
{
	clsProduct ScratchCard("Scratch Card", 30, 100, false); // (Name, Price, Quantitiy, IsExpirable)
	clsProduct Cheese("Cheese", 100, 50, true, 200); // (Name, Price, Quantity, IsExpirable, Weight)
	clsProduct Biscuits("Biscuits", 150, 150, true, 700);
	clsProduct TV("TV", 8000, 7, false, 5000);
	clsProduct Mobile("Mobile", 5000, 10, false, 100);

	clsCart Cart;
	clsCustomer Customer(5500); // -> Customer's (balance)

	Cart.Add(Cheese,2);
	Cart.Add(Biscuits, 1);
	clsCheckout::Checkout(Customer, Cart);

	system("pause>0");
}