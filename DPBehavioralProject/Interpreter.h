#pragma once
#include <iostream>
#include <map>

class Context
{
	std::map<std::string, double> variables;
public:
	double GetVariable(std::string name)
	{
		return variables[name];
	}

	void SetVariable(std::string name, double value)
	{
		if (variables.contains(name))
			variables[name] = value;
		else
			variables.insert(std::make_pair(name, value));
	}
};

class IExpression //Interpreter
{
public:
	virtual double Solve(Context* context) = 0;
};

// terminal expression
class NumberExpression : public IExpression
{
	std::string name;
public:
	NumberExpression(std::string name) : name{ name } {}
	double Solve(Context* context) override
	{
		return context->GetVariable(name);
	}
};

// nonterminal expression
class AddExpression : public IExpression
{
	IExpression* leftExpression;
	IExpression* rightExpression;
public:
	AddExpression(IExpression* leftExpression,
		IExpression* rightExpression)
		: leftExpression{ leftExpression },
		rightExpression{ rightExpression } {}

	double Solve(Context* context) override
	{
		return leftExpression->Solve(context) + rightExpression->Solve(context);
	}
};

// nonterminal expression
class MultExpression : public IExpression
{
	IExpression* leftExpression;
	IExpression* rightExpression;
public:
	MultExpression(IExpression* leftExpression,
		IExpression* rightExpression)
		: leftExpression{ leftExpression },
		rightExpression{ rightExpression } {}

	double Solve(Context* context) override
	{
		return leftExpression->Solve(context) * rightExpression->Solve(context);
	}
};

