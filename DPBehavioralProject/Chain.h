#pragma once
#include <iostream>

class Receiver
{
	bool bankTransfer;
	bool cashTransfer;
	bool payTransfer;
public:
	bool& BankTransfer() { return bankTransfer; }
	bool& CashTransfer() { return cashTransfer; }
	bool& PayTransfer() { return payTransfer; }

	Receiver(bool bankTransfer, bool cashTransfer, bool payTransfer)
		: bankTransfer{ bankTransfer },
		cashTransfer{ cashTransfer },
		payTransfer{ payTransfer } {}
};

class PaymentHandler
{
	PaymentHandler* successor = nullptr;
public:
	PaymentHandler*& Successor() { return successor; }
	
	void Add(PaymentHandler* s)
	{
		if (successor)
			successor->Add(s);
		else
			successor = s;
	}

	virtual void Handle(Receiver* receiver) = 0;
};

class BankPaymentHandler : public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->BankTransfer())
			std::cout << "Bank transfer is ok!\n";
		else if (Successor())
		{
			std::cout << "Bank transfer is crash\n";
			Successor()->Handle(receiver);
		}
	}
};

class CashPaymentHandler : public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->CashTransfer())
			std::cout << "Cash transfer is ok!\n";
		else if (Successor())
		{
			std::cout << "Cash transfer is crash\n";
			Successor()->Handle(receiver);
		}
	}
};

class PayPaymentHandler : public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->PayTransfer())
			std::cout << "Pay transfer is ok!\n";
		else if (Successor())
		{
			std::cout << "Pay transfer is crash\n";
			Successor()->Handle(receiver);
		}
	}
};