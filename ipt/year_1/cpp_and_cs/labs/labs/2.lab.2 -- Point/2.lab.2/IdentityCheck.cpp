#include "head.h"

void Point::IdentityCheck(Point p1, Point p2)
{
	if (p1.x==p2.x && p1.y==p2.y)
		cout<<endl<<"Points are identical"<<endl;
	else cout<<endl<<"Points are not identical"<<endl;
}