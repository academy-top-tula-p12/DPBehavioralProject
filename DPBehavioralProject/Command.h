#pragma once
#include <iostream>
#include <stack>

// interface Command
class ICommand
{
public:
	virtual void Execute() = 0;
	virtual void Undo() = 0;
	virtual bool CanExecute() = 0;
};

// receiver
class Television
{
	bool isPower;
	int soundVolume;
	const int maxVolume{ 5 };
public:
	Television() : isPower{ false }, soundVolume{} {}
	
	void PowerOn()
	{
		std::cout << "Tv power on\n";
		isPower = true;
	}

	void PowerOff()
	{
		std::cout << "Tv power off\n";
		isPower = false;
	}

	void SoundAdd()
	{
		std::cout << "Tv sound add, volume = " << ++soundVolume << "\n";
	}

	void SoundDel()
	{
		std::cout << "Tv sound del, volume = " << --soundVolume << "\n";
	}

	bool IsPower() { return isPower; }
	int SoundVolume() { return soundVolume; }
	int MaxVolume() { return maxVolume; }
};

// concrete Command
class TvOnCommand : public ICommand
{
	Television* tv;
public:
	TvOnCommand(Television* tv) : tv{ tv } {}

	void Execute() override
	{
		tv->PowerOn();
	}

	void Undo() override
	{
		tv->PowerOff();
	}

	bool CanExecute()
	{
		return !tv->IsPower();
	}
};

// concrete Command
class TvOffCommand : public ICommand
{
	Television* tv;
public:
	TvOffCommand(Television* tv) : tv{ tv } {}

	void Execute() override
	{
		tv->PowerOff();
	}

	void Undo() override
	{
		tv->PowerOn();
	}

	bool CanExecute()
	{
		return tv->IsPower();
	}
};

// concrete Command
class TvSoundUpCommand : public ICommand
{
	Television* tv;
public:
	TvSoundUpCommand(Television* tv) : tv{ tv } {}

	void Execute() override
	{
		tv->SoundAdd();
	}

	void Undo() override
	{
		tv->SoundDel();
	}

	bool CanExecute()
	{
		return tv->IsPower() && (tv->SoundVolume() < tv->MaxVolume());
	}
};

// concrete Command
class TvSoundDownCommand : public ICommand
{
	Television* tv;
public:
	TvSoundDownCommand(Television* tv) : tv{ tv } {}

	void Execute() override
	{
		tv->SoundDel();
	}

	void Undo() override
	{
		tv->SoundAdd();
	}

	bool CanExecute()
	{
		return tv->IsPower() && (tv->SoundVolume() > 0);
	}
};

// Invoker
class Controller
{
	ICommand* power;
	ICommand* soundUp;
	ICommand* soundDown;
	bool powerAction;

	std::stack<ICommand*> history;
public:
	Controller(ICommand* power,
		ICommand* soundUp,
		ICommand* soundDown)
		: power{ power },
		soundUp{ soundUp },
		soundDown{ soundDown },
		powerAction{ false } {}

	void ButtonPower()
	{
		if (!powerAction)
			power->Execute();
		else
			power->Undo();
		powerAction = !powerAction;
	}

	void ButtonVolumePlus()
	{
		if (soundUp->CanExecute())
		{
			soundUp->Execute();
			history.push(soundUp);
		}
	}

	void ButtonVolumeMinus()
	{
		if (soundDown->CanExecute())
		{
			soundDown->Execute();
			history.push(soundDown);
		}
	}

	void ButtonUndo()
	{
		if (history.size() > 0)
		{
			history.top()->Undo();
			history.pop();
		}
	}
};

// Invoker
class MobileController
{
	ICommand* powerOn;
	ICommand* powerOff;
	ICommand* soundUp;
	ICommand* soundDown;
	bool powerAction;

	std::stack<ICommand*> history;
public:
	MobileController(ICommand* powerOn,
		ICommand* powerOff,
		ICommand* soundUp,
		ICommand* soundDown)
		: powerOn{ powerOn },
		powerOff{ powerOff },
		soundUp{ soundUp },
		soundDown{ soundDown },
		powerAction{ false } {}

	void MenuItemPowerOn()
	{
		if (!powerAction && powerOn->CanExecute())
		{
			powerOn->Execute();
			history.push(powerOn);
		}		
		powerAction = true;
	}

	void MenuItemPowerOff()
	{
		if (powerAction && powerOff->CanExecute())
		{
			powerOff->Execute();
			history.push(powerOff);
		}
		powerAction = false;
	}

	void MenuItemVolumePlus()
	{
		if (soundUp->CanExecute())
		{
			soundUp->Execute();
			history.push(soundUp);
		}
	}

	void MenuItemVolumeMinus()
	{
		if (soundDown->CanExecute())
		{
			soundDown->Execute();
			history.push(soundDown);
		}
	}

	void MenuItemUndo()
	{
		if (history.size() > 0)
		{
			history.top()->Undo();
			history.pop();
		}
	}
};

