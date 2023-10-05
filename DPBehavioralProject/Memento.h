#pragma once
#include <iostream>
#include <stack>

// Memento
class PlayerMemento
{
	int points;
	int level;
public:
	int& Points() { return points; }
	int& Level() { return level; }

	PlayerMemento(int points, int level)
		: points{ points }, level{ level } {}
};

// Originator
class Player
{
	int points;
	int level;
	int value;
public:
	Player() : points{}, level{ 1 } {};

	void Play()
	{
		int p = rand() % 5;
		points += p;

		int l = rand() % 2;
		level += l;

		std::cout << "current player state. points: "
			<< points << ", level: " << level << "\n";
	}

	PlayerMemento* Save()
	{
		std::cout << "save player state. points: "
			<< points << ", level: " << level << "\n";
		return new PlayerMemento(points, level);
	}

	void Load(PlayerMemento* memento)
	{
		points = memento->Points();
		level = memento->Level();
		std::cout << "load player state. points: "
			<< points << ", level: " << level << "\n";
	}
};

// Caretaker
class GameHistory
{
	std::stack<PlayerMemento*> history;
public:
	std::stack<PlayerMemento*>& History() { return history; }

	void Save(PlayerMemento* memento)
	{
		history.push(memento);
	}

	PlayerMemento* Load()
	{
		PlayerMemento* memento = history.top();
		history.pop();
		return memento;
	}
};
