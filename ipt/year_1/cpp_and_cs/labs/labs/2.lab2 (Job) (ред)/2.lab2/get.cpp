#include "head.h"

void Worker::get()
{
	cout<<endl<<"Name: ";
	cin>>name;
	cout<<endl<<"Age: ";
	cin >> age;
	cout << endl << "Post: ";
	cin >> post;
	cout << endl << "Experience: ";
	cin >> experience;	
}

void PrimeWorker::get()
{
	Worker::get();
	cout<<endl<<"Bonus quantity: ";
	cin>>quantity;
}