#include "head.h"

istream& operator>>(istream& c, Worker& w)
{
	cout<<endl<<"Name: ";
	c>>w.name;
	for (int i=0; i<=5;)
	{
		cout<<endl<<"Age: ";
		c>>w.age;

		if (c.fail())
		{
			c.clear();
			c.sync();
			cout<<endl<<"ERORR: bad input ("<<5-i<<") "<<endl;
			i++;
			if (i==6)
				return c;
		}
		else i=6;
	}

	cout<<endl<<"Post: ";
	c>>w.post;

	for (int i=0; i<=5;)
	{
		cout<<endl<<"Experience: ";
		c>>w.experience;
		if (c.fail())
		{
			c.clear();
			c.sync();
			cout<<endl<<"ERORR: bad input ("<<5-i<<") "<<endl;
			i++;
			if (i==6)
				return c;
		}
		else i=6;
	}

	return c;
}

istream& operator>>(istream& c, PrimeWorker& w)
{
	cout<<endl<<"Name: ";
	c>>w.name;

	for (int i=0; i<=5;)
	{
		cout<<endl<<"Age: ";
		c>>w.age;
		if (c.fail())
		{
			c.clear();
			c.sync();
			cout<<endl<<"ERORR: bad input ("<<5-i<<") "<<endl;
			i++;
			if (i==6)
				return c;
		}
		else i=6;
	}

	cout<<endl<<"Post: ";
	c>>w.post;

	for (int i=0; i<=5;)
	{
		cout<<endl<<"Experience: ";
		c>>w.experience;
		if (c.fail())
		{
			c.clear();
			c.sync();
			cout<<endl<<"ERORR: bad input ("<<5-i<<") "<<endl;
			i++;
			if (i==6)
				return c;
		}
		else i=6;
	}

	for (int i=0; i<=5;)
	{
		cout<<endl<<"Bonus quantity: ";
		c>>w.quantity;
		if (c.fail())
		{
			c.clear();
			c.sync();
			cout<<endl<<"ERORR: bad input ("<<5-i<<") "<<endl;
			i++;
			if (i==6)
				return c;
		}
		else i=6;
	}

	delete [] w.bonus;
	w.bonus = new string[w.quantity];
	if (w.quantity!=0)
	{
		string h;
		for (int i=0; i<w.quantity; i++)
		{
			cout<<endl<<"Enter name of "<<i+1<<" bonus: ";
			c>> h;
			w.bonus[i]=h;
		}
	}
	else cout<<endl;
	return c;
}