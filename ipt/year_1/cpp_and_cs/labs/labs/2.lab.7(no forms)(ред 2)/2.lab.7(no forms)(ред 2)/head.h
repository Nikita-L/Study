#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <sstream>

using namespace std;

class Lock
{
private:
	bool unlocked;
public:
	Lock(): unlocked(false)
	{	}
	bool IsLocked() const;
	void LockDoor();
	void UnlockDoor();
};

class Window
{
private:
	bool closed;
	int position;
public:
	Window(): closed(true), position(100)
	{	}
	bool IsClosed() const;
	void WindowUp();
	void WindowDown();
};

class Door
{
private:
	bool closed;
	Lock* lock;
	Window* window;
public:
	Door(): closed(true)
	{
		lock = new Lock[1];
		window = new Window[1];
	}
	~Door()
	{
		//free (lock);
		//free (window);
		delete [] lock;
		delete [] window;
	}
	bool IsClosed() const;
	void DoorClose();
	void DoorOpen();
	Window* WinAccess() const;
	Lock* LockAccess() const;
};

class Engine
{
private:
	bool readytogo;
	bool working;
public:
	Engine(): readytogo(false), working(false)
	{	}
	bool IsReadyToGo() const;
	void EngineCheck();
	bool IsWorking() const;
	void TurnOn();
	void TurnOff();
};

class AirCond
{
private:
	bool heat;
	bool freeze;
public:
	AirCond(): heat(false), freeze(false)
	{	}
	void HeatOn();
	void FreezeOn();
	void HeatOff();
	void FreezeOff();
	bool IsHeat() const;
	bool IsFreeze() const;
};

class TemperatureDetect
{
private:
	double t;
public:
	TemperatureDetect(): t(0)
	{	}
	double Temperature() const;
};

class Computer
{
protected:
	bool switchedon;
public:
	virtual bool IsSwitchedOn() const;
	virtual void TurnOn();
	virtual void TurnOff();
};

class Button
{
private:
	bool waspushed;
public:
	Button(): waspushed(false)
	{	}
	bool WasPushedInfo();
};

class Screen
{
private:
	bool switchedon;
public: 
	Screen(): switchedon(0)
	{	}
	void TurnOn();
	void TurnOff();
	void ShowOnScreen(string);
};

class Machines
{
protected:
	bool hasanengine;
};

class Car : Machines
{
private:
	Door *d;
	Engine *e;
	AirCond *ac;
	TemperatureDetect *t;
public:
	Car()
	{
		hasanengine = true;
		d = new Door[4];
		e = new Engine[1];
		ac = new AirCond[1];
		t = new TemperatureDetect[2];
	}
	~Car()
	{
		delete [] e;
		delete [] ac;
		delete [] t;
		delete [] d;
	}
	TemperatureDetect* Temperature() const;
	AirCond* AC() const;
	Door* DoorAccess() const;
};

class CarComp : Computer
{
private:
	Car *car;
	Screen *screen;
	Button *windowopen, *windowclose, *showtemperatureIn, *showtemperatureOut, *acheaton, *acfreezeon, *acoff, *acauto, *turnoff, *carlock, *carunlock;
public:
	CarComp()
	{
		switchedon = false;
		car = new Car[1];
		screen = new Screen[1];
		windowopen = new Button[4];
		windowclose = new Button[4];
		showtemperatureIn = new Button[1];
		showtemperatureOut = new Button[1];
		acheaton = new Button[1];
		acfreezeon = new Button[1];
		acoff = new Button[1];
		turnoff = new Button[1];
		carlock = new Button[1];
		carunlock = new Button[1];
	}
	~CarComp()
	{
		delete [] screen;
		delete [] windowopen;
		delete [] windowclose;
		delete [] showtemperatureIn;
		delete [] showtemperatureOut;
		delete [] acheaton;
		delete [] acfreezeon;
		delete [] acoff;
		delete [] turnoff;
		delete [] carlock;
		delete [] carunlock;
		delete [] car;
	}
	void TurnOn();
	void windowopenClick1();
	void windowopenClick2();
	void windowopenClick3();
	void windowopenClick4();
	void windowcloseClick1();
	void windowcloseClick2();
	void windowcloseClick3();
	void windowcloseClick4();
	void showtemperatureInClick();
	void showtemperatureOutClick();
	void acheatonClick();
	void acfreezeonClick();
	void acoffClick();
	void acautoClick();
	void turnoffClick();
	void carlockClick ();
	void carunlockClick ();
};
