#include "head.h"

istream& operator>>(istream& c, Worker& w)
{
	for (int i=0; i<=5;)
	{
		cout<<endl<<"Name: ";
		c>>w.name;
		for (int j=0; j<w.name.size();)
		{
			if ((w.name.at(j)=='1')||(w.name.at(j)=='2')||(w.name.at(j)=='3')||(w.name.at(j)=='4')||(w.name.at(j)=='5')||(w.name.at(j)=='6')||(w.name.at(j)=='7')||(w.name.at(j)=='8')||(w.name.at(j)=='9')||(w.name.at(j)=='0'))
			{
				cout<<endl<<"ERORR: bad input ("<<5-i<<") "<<endl;
				j=w.name.size();
				i++;
				if (i==6)
					return c; 
			}
			else if (j==(w.name.size()-1)) 
			{
				i=6;
				j=w.name.size();
			}
			else j++;
		}
	}

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

	for (int i=0; i<=5;)
	{
		cout<<endl<<"Post: ";
		c>>w.post;
		for (int j=0; j<w.post.size();)
		{
			if ((w.post.at(j)=='1')||(w.post.at(j)=='2')||(w.post.at(j)=='3')||(w.post.at(j)=='4')||(w.post.at(j)=='5')||(w.post.at(j)=='6')||(w.post.at(j)=='7')||(w.post.at(j)=='8')||(w.post.at(j)=='9')||(w.post.at(j)=='0'))
			{
				cout<<endl<<"ERORR: bad input ("<<5-i<<") "<<endl;
				j=w.post.size();
				i++;
				if (i==6)
					return c; 
			}
			else if (j==(w.post.size()-1)) 
			{
				i=6;
				j=w.post.size();
			}
			else j++;
		}
	}

	for (int i=0; i<=5;)
	{
		cout<<endl<<"Experience: ";
		c>>w.experience;
		if (c.fail()||(w.experience>=w.age))
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
	for (int i=0; i<=5;)
	{
		cout<<endl<<"Name: ";
		c>>w.name;
		for (int j=0; j<w.name.size();)
		{
			if ((w.name.at(j)=='1')||(w.name.at(j)=='2')||(w.name.at(j)=='3')||(w.name.at(j)=='4')||(w.name.at(j)=='5')||(w.name.at(j)=='6')||(w.name.at(j)=='7')||(w.name.at(j)=='8')||(w.name.at(j)=='9')||(w.name.at(j)=='0'))
			{
				cout<<endl<<"ERORR: bad input ("<<5-i<<") "<<endl;
				j=w.name.size();
				i++;
				if (i==6)
					return c; 
			}
			else if (j==(w.name.size()-1)) 
			{
				i=6;
				j=w.name.size();
			}
			else j++;
		}
	}

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

	for (int i=0; i<=5;)
	{
		cout<<endl<<"Post: ";
		c>>w.post;
		for (int j=0; j<w.post.size();)
		{
			if ((w.post.at(j)=='1')||(w.post.at(j)=='2')||(w.post.at(j)=='3')||(w.post.at(j)=='4')||(w.post.at(j)=='5')||(w.post.at(j)=='6')||(w.post.at(j)=='7')||(w.post.at(j)=='8')||(w.post.at(j)=='9')||(w.post.at(j)=='0'))
			{
				cout<<endl<<"ERORR: bad input ("<<5-i<<") "<<endl;
				j=w.post.size();
				i++;
				if (i==6)
					return c; 
			}
			else if (j==(w.post.size()-1)) 
			{
				i=6;
				j=w.post.size();
			}
			else j++;
		}
	}

	for (int i=0; i<=5;)
	{
		cout<<endl<<"Experience: ";
		c>>w.experience;
		if (c.fail()||(w.experience>=w.age))
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