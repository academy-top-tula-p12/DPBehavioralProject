#pragma once
#include <iostream>


class Education //TemplateMethod
{
public:
	virtual void TemplateMethod()
	{
		Enter();
		Study();
		PassExam();
		GetDocument();
	}

	virtual void Enter() = 0;
	virtual void Study() = 0;
	virtual void PassExam()
	{
		std::cout << "Pass Examen\n";
	}
	virtual void GetDocument() = 0;
};


class School : public Education
{
public:
	void Enter() override
	{
		std::cout << "enter to first class\n";
	}
	void Study() override
	{
		std::cout << "go to school\n";
		std::cout << "make homeworks\n";
	}
	void GetDocument() override
	{
		std::cout << "get attestat\n";
	}
};

class Universitet : public Education
{
public:
	void Enter() override
	{
		std::cout << "input exam\n";
		std::cout << "eneter on first course\n";
	}
	void Study() override
	{
		std::cout << "go to universitet\n";
		std::cout << "practic\n";
	}
	void GetDocument() override
	{
		std::cout << "get diplome\n";
	}

	void PassExam() override
	{
		std::cout << "pass special examen\n";
	}
};

