#include "head.h"

void PrimeWorker::showbonus()
{
	if (quantity!=0)
	{
		cout<<endl<<name<<" has bonuses:"<<endl;
		for (int i=0; i<quantity; i++)
		{
			cout<<i+1<<". "<<bonus[i]<<endl;
		}
	}
	else cout<<endl<<name<<" has no bonuses"<<endl;
}