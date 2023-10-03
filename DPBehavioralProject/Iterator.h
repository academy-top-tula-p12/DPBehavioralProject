#pragma once
#include <iostream>

class Iterator;
class VectorIterator;

class Vector
{
	int* array = nullptr;
	int size = 0;
public:
	int Size() { return size; }
	void PushBack(int value)
	{
		int* arrayNew = new int[size + 1];
		for (int i = 0; i < size; i++)
			arrayNew[i] = array[i];
		arrayNew[size] = value;

		delete[] array;
		array = arrayNew;
		size++;
	}

	int At(int index)
	{
		return array[index];
	}

	void Print()
	{
		for (int i = 0; i < size; i++)
			std::cout << array[i] << " ";
		std::cout << "\n";
	}

	Iterator* GetIterator();
};

class Iterator
{
public:
	virtual void Begin() = 0;
	virtual bool Next() = 0;
	virtual int Current() = 0;
};

class VectorIterator : public Iterator
{
	Vector* myVector;
	int index;
public:
	VectorIterator(Vector* myVector) 
		: myVector{ myVector },
		index{} {};

	void Begin() override
	{
		index = -1;
	}

	bool Next() override
	{
		if (index < myVector->Size() - 1)
		{
			index++;
			return true;
		}
		return false;
	}
	int Current() override
	{
		return myVector->At(index);
	}
};

Iterator* Vector::GetIterator()
{
	return new VectorIterator(this);
}


