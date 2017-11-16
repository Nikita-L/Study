#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

class Point
{
protected:
	double	x, y;
public:
	Point() : x(0), y(0) // Конструктор по умолчанию
	{	}
	Point(double xp, double yp) : x(xp), y(yp) // Конструктор с параметрами
	{	}
	Point(Point & p) // Конструктор копирования
	{
		x=p.x;
		y=p.y;
	}
	~Point() // Деструктор
	{	};
	void Distance (Point, Point);
	void Plus (Point, Point);
	void getPoint();
	void showPoint();
	void IdentityCheck(Point, Point);
};

class ExtraPoint : Point
{
protected:
	string color;
public:
	ExtraPoint():Point(), color("black")
	{	}
	ExtraPoint(double xp, double yp, string s):Point(xp, yp), color(s)
	{	}
	ExtraPoint(ExtraPoint & p):Point()
	{
		color=p.color;
	}
	~ExtraPoint()
	{	}
	void getPoint()
	{
		Point::getPoint();
		cout<<endl<<"Color: ";
		cin>>color;
	}
	void showPoint()
	{
		Point::showPoint();
		cout<<color<<endl;
	}
	void Distance(ExtraPoint p1, ExtraPoint p2)
	{
		Point::Distance(p1, p2);
	}
	void Plus(ExtraPoint p1, ExtraPoint p2)
	{
		Point::Plus(p1, p2);
	}
	void IdentityCheck (ExtraPoint p1, ExtraPoint p2)
	{
		if (p1.x==p2.x && p1.y==p2.y && p1.color==p2.color)
			cout<<endl<<"Points are identical"<<endl;
		else cout<<endl<<"Points are not identical"<<endl;
	}

};