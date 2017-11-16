#include "head.h"

Worker& Worker:: operator =(const Worker& a)
{
	if (this == &a) return *this;
	name = a.name;
	age = a.age;
	post = a.post;
	experience = a.experience;
	return *this;
}

PrimeWorker& PrimeWorker:: operator =(const PrimeWorker& a)
{
	if (this == &a) return *this;
	delete [] bonus;
	Worker::operator=(a);
	quantity = a.quantity;
	bonus=new string[a.quantity];
	for (int i=0; i<a.quantity; i++)
	bonus[i]=a.bonus[i];
	return *this;
}