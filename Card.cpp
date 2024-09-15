#include <iostream>
using namespace std;

class PaymentMethod {
public:
	virtual void processPayment(double amount) = 0;

	virtual ~PaymentMethod() {};
};

class CreditCard : public PaymentMethod {
	int cardNumber;
	int expirationDate;
	string cardHolderName;
public:
	void processPayment(double amount)override {
		cout << "Credit card payment of " << amount << " was successful" << endl;
	};
};


class PayPal : public PaymentMethod {
	string email;
public:
	void processPayment(double amount)override {
		cout << "PayPal payment of " << amount << " was successful" << endl;
	};
};

class BankTransfer :public   PaymentMethod {
	int bankAccountNumber;
	string bankName;
public:
	void processPayment(double amount)override {
		cout << "Bank transfer payment of " << amount << " was successful" << endl;
	};
};
int main()
{
	PaymentMethod* paymentMethods[3];

	paymentMethods[0] = new CreditCard();
	paymentMethods[1] = new PayPal();
	paymentMethods[2] = new BankTransfer();

	paymentMethods[0]->processPayment(100.50);
	paymentMethods[1]->processPayment(300.75);
	paymentMethods[2]->processPayment(500.00);

	for (int i = 0; i < 3; ++i) {
		paymentMethods[i]->processPayment(100.50);
		delete paymentMethods[i];  
	}
}
