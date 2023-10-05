#pragma once
#include <iostream>
#include <string>
#include <vector>

class Person;
class Company;

class IVisitor
{
public:
	virtual void VisitPerson(Person* accaunt) = 0;
	virtual void VisitCompany(Company* account) = 0;
};

class IAccount
{
public:
	virtual void Accept(IVisitor* visitor) = 0;
};

class Person : public IAccount
{
	std::string name;
	std::string number;
	int amount;
public:
	std::string& Name() { return name; }
	std::string& Number() { return number; }
	int& Amount() { return amount; }

	//

	void Accept(IVisitor* visitor) override
	{
		visitor->VisitPerson(this);
	}
};

class Company : public IAccount
{
	std::string title;
	std::string number;
	std::string license;
	int amount;
public:
	std::string& Title() { return title; }
	std::string& Number() { return number; }
	std::string& License() { return license; }
	int& Amount() { return amount; }

	//

	void Accept(IVisitor* visitor) override
	{
		visitor->VisitCompany(this);
	}
};

class Bank
{
	std::vector<IAccount*> accounts;
public:
	void Add(IAccount* account)
	{
		accounts.push_back(account);
	}

	void Remove(int index)
	{
		accounts.erase(accounts.begin() + index);
	}

	void Accept(IVisitor* visitor)
	{
		for (auto account : accounts)
			account->Accept(visitor);
	}
};

class XmlVisitor : public IVisitor
{
	void VisitPerson(Person* account)
	{
		std::string result = "<person>\n";
		result += "\t<name>" + account->Name() + "</name>\n";
		result += "\t<number>" + account->Number() + "</number>\n";
		result += "\t<amount>" + std::to_string(account->Amount()) + "</amount>\n";
		result += "</person>\n";

		std::cout << result << "\n";
	}

	void VisitCompany(Company* account) override
	{
		std::string result = "<company>\n";
		result += "\t<title>" + account->Title() + "</title>\n";
		result += "\t<number>" + account->Number() + "</number>\n";
		result += "\t<license>" + account->License() + "</license>\n";
		result += "\t<amount>" + std::to_string(account->Amount()) + "</amount>\n";
		result += "</company>\n";

		std::cout << result << "\n";
	}
};

class JsonVisitor : public IVisitor
{
	void VisitPerson(Person* account) 
	{
		std::string result = "{\n";
		result += "\tname: " + account->Name() + ",\n";
		result += "\tnumber: " + account->Number() + ",\n";
		result += "\tamount: " + std::to_string(account->Amount()) + ",\n";
		result += "}\n";

		std::cout << result << "\n";
	}
	void VisitCompany(Company* account) override
	{
		std::string result = "{\n";
		result += "\ttitle: " + account->Title() + ",\n";
		result += "\tnumber: " + account->Number() + ",\n";
		result += "\tlicense: " + account->License() + ",\n";
		result += "\tamount: " + std::to_string(account->Amount()) + ",\n";
		result += "}\n";

		std::cout << result << "\n";
	}
};
