#include "head.h"

void Worker::expcompare(Worker a, Worker b) const
{
	if (a.experience > b.experience)
		cout<<endl<<a.name<<" has more experience than "<<b.name;
	else if (b.experience > a.experience)
		cout<<endl<<b.name<<" has more experience than "<<a.name;
	else cout<<endl<<a.name<<" and "<<b.name<<" has equal years of experience";
	cout<<endl;
}