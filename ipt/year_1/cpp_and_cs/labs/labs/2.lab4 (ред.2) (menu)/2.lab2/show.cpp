#include "head.h"

void Worker::show() const
{
	cout<<endl<<"Name: "<<name;
	cout<<endl<<"Age: "<<age;
	cout<<endl<<"Post: "<<post;
	cout<<endl<<"Experience: "<<experience;
	cout<<endl;
}

void PrimeWorker::show() const
	{
		Worker::show();
		cout<<"Bonus quantity: "<<quantity;
		cout<<endl;
		if (quantity!=0)
		{
			cout<<endl<<name<<" has bonuses:"<<endl;
			for (int i=0; i<quantity; i++)
			{
				if (bonus[i]=="")
					cout<<i+1<<". UNKNOWN"<<endl;
				else cout<<i+1<<". "<<bonus[i]<<endl;
			}
		}
		else cout<<endl<<name<<" has no bonuses"<<endl;
	}