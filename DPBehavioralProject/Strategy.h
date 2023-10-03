#pragma once
#include <iostream>

class ICompression
{
public:
	virtual void Compress(std::string file) = 0;
	virtual ~ICompression() {}
};

class Archiver
{
	ICompression* compression;
public:
	Archiver(ICompression* compression = nullptr)
		: compression{ compression } {}
	ICompression*& Compression() { return compression; }

	void Archiving(std::string file)
	{
		compression->Compress(file);
	}
};

class RarCompression : public ICompression
{
public:
	void Compress(std::string file) override
	{
		std::cout << "File " << file
			<< " compress with Rar algorithm\n";
	}
};

class ArjCompression : public ICompression
{
public:
	void Compress(std::string file) override
	{
		std::cout << "File " << file
			<< " compress with Arj algorithm\n";
	}
};

class ZipCompression : public ICompression
{
public:
	void Compress(std::string file) override
	{
		std::cout << "File " << file
			<< " compress with Zip algorithm\n";
	}
};