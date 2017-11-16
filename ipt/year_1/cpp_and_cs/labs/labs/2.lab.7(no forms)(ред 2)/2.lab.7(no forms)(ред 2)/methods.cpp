#include "head.h"

// Lock
bool Lock::IsLocked() const
{
	return unlocked;
}
void Lock::LockDoor()
{
	unlocked = false;
}
void Lock::UnlockDoor()
{
	unlocked = true;
}

//Window
void Window::WindowUp()
{
	if (position != 100)
	{
		int op = position +1;
		position = op;
		if (position == 100)
			closed = true;
	}
}
void Window::WindowDown()
{
	closed = false;
	if (position != 0)
	{
		int cl = position -1;
		position = cl;
	}
}
bool Window::IsClosed() const
{
	return closed;
}

//Door
bool Door::IsClosed() const
{
	return closed;
}
void Door::DoorOpen()
{
	closed = false;
}
void Door::DoorClose()
{
	closed = true;
}
Window* Door::WinAccess() const
{
	return window;
}
Lock* Door::LockAccess() const
{
	return lock;
}
bool Engine::IsReadyToGo() const
{
	return readytogo;
}
void Engine::EngineCheck()
{	
	Sleep(3000);
}
bool Engine::IsWorking() const
{
	return working;
}
void Engine::TurnOn()
{
	working = true;
}
void Engine::TurnOff()
{
	working = false;
}

//Air Condition
void AirCond::HeatOn()
{
	heat = true;
	freeze = false;
}
void AirCond::FreezeOn()
{
	freeze = true;
	heat = false;
}
void AirCond::HeatOff()
{
	heat = false;
}
void AirCond::FreezeOff()
{
	freeze = false;
}
bool AirCond::IsHeat() const
{
	return heat;
}
bool AirCond::IsFreeze() const
{
	return freeze;
}

//Temperature Detecor
double TemperatureDetect::Temperature() const
{
	return t;
}

//Computers
bool Computer::IsSwitchedOn() const
{
	return switchedon;
}
void Computer::TurnOn()
{
	switchedon = true;
}
void Computer::TurnOff()
{
	switchedon = false;
}

//Button
bool Button::WasPushedInfo()
{
	return waspushed;
	waspushed = false;
}

//Screen
void Screen::TurnOn()
{
	switchedon = true;
}
void Screen::TurnOff()
{
	switchedon = false;
}
void Screen::ShowOnScreen(string s)
{
	Sleep(3000);
}

//Car computer
void CarComp::TurnOn()
{
	Computer::TurnOn();
	screen->TurnOn();
}
void CarComp::windowopenClick1()
{
	car[0].DoorAccess()[0].WinAccess()[0].WindowDown();
}
void CarComp::windowopenClick2()
{
	car[0].DoorAccess()[1].WinAccess()[0].WindowDown();
}
void CarComp::windowopenClick3()
{
	car[0].DoorAccess()[2].WinAccess()[0].WindowDown();
}
void CarComp::windowopenClick4()
{
	car[0].DoorAccess()[3].WinAccess()[0].WindowDown();
}
void CarComp::windowcloseClick1()
{
	car[0].DoorAccess()[0].WinAccess()[0].WindowUp();
}
void CarComp::windowcloseClick2()
{
	car[0].DoorAccess()[1].WinAccess()[0].WindowUp();
}
void CarComp::windowcloseClick3()
{
	car[0].DoorAccess()[2].WinAccess()[0].WindowUp();
}
void CarComp::windowcloseClick4()
{
	car[0].DoorAccess()[3].WinAccess()[0].WindowUp();
}
void CarComp::showtemperatureInClick()
{
	double t = car[0].Temperature()[0].Temperature();
	stringstream ss;
	ss<<t;
	string s;
	ss>>s;
	screen[0].ShowOnScreen(s);
}
void CarComp::showtemperatureOutClick()
{
	double t = car[0].Temperature()[1].Temperature();
	stringstream ss;
	ss<<t;
	string s;
	ss>>s;
	screen[0].ShowOnScreen(s);
}
void CarComp::acheatonClick()
{
	car[0].AC()[0].HeatOn();
}
void CarComp::acfreezeonClick()
{
	car[0].AC()[0].FreezeOn();
}
void CarComp::acoffClick()
{
	car[0].AC()[0].FreezeOff();
	car[0].AC()[0].HeatOff();
}
void CarComp::acautoClick()
{
	if (car[0].Temperature()[0].Temperature() < 18)
	{
		car[0].AC()[0].HeatOn();
	}
	else if (car[0].Temperature()[0].Temperature() > 24)
	{
		car[0].AC()[0].FreezeOn();
	}
	else
	{
		car[0].AC()[0].FreezeOff();
		car[0].AC()[0].HeatOff();
	}
}
void CarComp::turnoffClick()
{
	Computer::TurnOff();
	screen[0].TurnOff();
}
void CarComp::carlockClick ()
{
	car[0].DoorAccess()[0].LockAccess()[0].LockDoor();
	car[0].DoorAccess()[1].LockAccess()[0].LockDoor();
	car[0].DoorAccess()[2].LockAccess()[0].LockDoor();
	car[0].DoorAccess()[3].LockAccess()[0].LockDoor();
}
void CarComp::carunlockClick ()
{
	car[0].DoorAccess()[0].LockAccess()[0].UnlockDoor();
	car[0].DoorAccess()[1].LockAccess()[0].UnlockDoor();
	car[0].DoorAccess()[2].LockAccess()[0].UnlockDoor();
	car[0].DoorAccess()[3].LockAccess()[0].UnlockDoor();
}

//Car
Door* Car::DoorAccess() const
{
	return d;
}
TemperatureDetect* Car::Temperature() const
{
	return t;
}
AirCond* Car::AC() const
{
	return ac;
}