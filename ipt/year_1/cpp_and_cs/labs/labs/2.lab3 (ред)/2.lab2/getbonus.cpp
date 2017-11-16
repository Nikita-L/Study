#include "head.h"

void PrimeWorker::getbonus()
{
	delete [] bonus;
	bonus = new string[quantity];
	if (quantity!=0)
	{
		string h;
		for (int i=0; i<quantity; i++)
		{
			cout<<endl<<"Enter name of "<<i+1<<" bonus: ";
			cin>> h;
			bonus[i]=h;
		}
	}
	else cout<<endl;
}