#pragma once
#include <iostream>
#include <vector>

class MarketInfo;

class IObserver
{
public:
	virtual void Update(MarketInfo* info) = 0;
};

class IObservable
{
public:
	virtual void AddObserver(IObserver* observer) = 0;
	virtual void RemoveObserver(IObserver* observer) = 0;
	virtual void NotifyObserver() = 0;
};

class MarketInfo
{
	int usd = 0;
	int euro = 0;
public:
	int& Usd() { return usd; }
	int& Euro() { return euro; }
};

class Market : public IObservable
{
	MarketInfo* info;
	std::vector<IObserver*> observers;
public:
	Market() : info{ new MarketInfo() } {}

	void AddObserver(IObserver* observer) override
	{
		observers.push_back(observer);
	}

	void RemoveObserver(IObserver* observer) override
	{
		auto it = find(observers.begin(), observers.end(), observer);
		if (it != observers.end())
			observers.erase(it);
	}

	void NotifyObserver() override
	{
		for (auto o : observers)
			o->Update(info);
	}

	void Bidding()
	{
		info->Euro() = 70 + rand() % 30;
		info->Usd() = 40 + rand() % 20;

		std::cout << "Market Usd: " << info->Usd() << "\n";
		std::cout << "Market Euro: " << info->Euro() << "\n";

		NotifyObserver();
	}
};

class Broker : public IObserver
{
	std::string name;
	IObservable* market;
public:
	Broker(std::string name, IObservable* market)
		: name{ name }, market{ market } {}
	std::string Name() { return name; }

	void Update(MarketInfo* info) override
	{
		if (info->Usd() > 50)
			std::cout << "Broker " << name << " saled usd at " << info->Usd() << "\n";
		else
			std::cout << "Broker " << name << " byed usd at " << info->Usd() << "\n";
	}

	void StopMarket()
	{
		market->RemoveObserver(this);
	}
};

class Bank : public IObserver
{
	std::string name;
	IObservable* market;
public:
	Bank(std::string name, IObservable* market)
		: name{ name }, market{ market } {}
	std::string Name() { return name; }

	void Update(MarketInfo* info) override
	{
		if (info->Euro() > 85)
			std::cout << "Bank " << name << " saled euro at " << info->Euro() << "\n";
		else
			std::cout << "Bank " << name << " byed euro at " << info->Euro() << "\n";
	}

	void StopMarket()
	{
		market->RemoveObserver(this);
	}
};
