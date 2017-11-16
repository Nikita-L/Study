#include "head.h"
#include "math.h"
void Point::Distance(Point p1, Point p2)
{
	cout<<endl<<"Distance = "<<sqrt(pow((p2.x - p1.x),2)+pow((p2.y-p1.y),2))<<endl;
}