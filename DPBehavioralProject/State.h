#pragma once
#include <iostream>
#include <stack>

class Product 
{
public:
	int Price = 100;
};

class Machine;

class IMachineState
{
protected:
	Machine* context;
public:
	/*IMachineState(Machine* context = nullptr) 
		: context{ context } {}*/
	Machine*& Context() { return context; }

	virtual void PayPush(int cash) = 0;
	virtual Product ProductPop() = 0;
	virtual int ChangePop() = 0;
};

class EmptyMachineState;
class FullChangeMachineState;
class FullNoMoneyMachineState;

class Machine
{
	std::stack<Product> products;
	IMachineState* state;
public:
	Machine(IMachineState* state, int size)
		:state{ state }
	{
		for (int i = 0; i < size; i++)
			products.push(Product());
	}

	IMachineState*& State() { return state; }
	std::stack<Product> Products() { return products; }

	int ProductPrice()
	{
		return products.top().Price;
	}

	void Start(int cash)
	{
		state->PayPush(cash);
		state->ProductPop();
		state->ChangePop();
	}
};



class FullPayMachineState : public IMachineState
{
public:
	void PayPush(int cash) override
	{
		if (cash > context->ProductPrice())
		{
			context->State() = new FullChangeMachineState();
			return;
		}
		if (cash < context->ProductPrice())
		{
			context->State() = new FullNoMoneyMachineState();
			return;
		}
		std::cout << "Get Cash!\n";
	}

	Product ProductPop() override
	{
		if (context->Products().size() <= 0)
		{
			context->State() = new EmptyMachineState();
			return Product();
		}

		Product p = context->Products().top();
		context->Products().pop();
		std::cout << "Get Product!\n";
		return p;
	}

	int ChangePop() override
	{
		std::cout << "No Change!\n";
		return 0;
	}

};

class FullChangeMachineState : public IMachineState
{
public:
	void PayPush(int cash) override
	{
		std::cout << "Get Cash!\n";
	}

	Product ProductPop() override
	{
		if (context->Products().size() <= 0)
		{
			context->State() = new EmptyMachineState();
			return Product();
		}

		Product p = context->Products().top();
		context->Products().pop();
		std::cout << "Get Product!\n";
		return p;
	}

	int ChangePop() override
	{
		std::cout << "Get Change!\n";
		return 10;
	}

};


class FullNoMoneyMachineState : public IMachineState
{
public:
	void PayPush(int cash) override
	{
		std::cout << "No get Cash!\n";
	}

	Product ProductPop() override
	{
		std::cout << "No get Product!\n";
		return Product();
	}

	int ChangePop() override
	{
		std::cout << "get Change!\n";
		return 10;
	}

};

class EmptyMachineState : public IMachineState
{
public:
	void PayPush(int cash) override
	{
		std::cout << "No get Cash!\n";
	}

	Product ProductPop() override
	{
		std::cout << "No get Product!\n";
		return Product();
	}

	int ChangePop() override
	{
		std::cout << "No get Change!\n";
		return 0;
	}

};

