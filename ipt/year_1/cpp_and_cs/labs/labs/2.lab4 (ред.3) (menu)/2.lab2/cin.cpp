#include "head.h"

istream& operator>>(istream& c, Worker& w)
{
	
	cout<<endl<<"Name: ";
	c>>w.name;
	for (int i=0; i<=5;)
	{
		for (int j=0; j<w.name.size();)
		{
			if ((w.name.at(j)=='1')||(w.name.at(j)=='2')||(w.name.at(j)=='3')||(w.name.at(j)=='4')||(w.name.at(j)=='5')||(w.name.at(j)=='6')||(w.name.at(j)=='7')||(w.name.at(j)=='8')||(w.name.at(j)=='9')||(w.name.at(j)=='0'))
			{
				system ("CLS");
				cout<<endl<<"Name ("<<5-i<<" tries left): ";
				c>>w.name;
				j=w.name.size();
				i++;
				if (i==6)
				{
					w.name="1";
					return c;
				}
			}
			else if (j==(w.name.size()-1)) 
			{
				i=6;
				j=w.name.size();
				system ("CLS");
				cout<<endl<<"Name: "<<w.name<<endl;
			}
			else j++;
		}
	}

	cout<<"Age: ";
	c>>w.age;
	for (int i=0; i<=5;)
	{
		if ((c.fail())||(w.age<=0))
		{
			
			system ("CLS");
			c.clear();
			c.sync();
			cout<<endl<<"Name: "<<w.name<<endl;
			cout<<"Age ("<<5-i<<" tries left): ";
			c>>w.age;
			i++;
			if (i==6)
			{
				w.name="1";
				return c;
			}
		}
		else 
		{
			i=6;
			system ("CLS");
			cout<<endl<<"Name: "<<w.name<<endl;
			cout<<"Age: "<<w.age<<endl;
		}
	}
	
	cout<<"Post: ";
	c>>w.post;
	
	cout<<"Experience: ";
	c>>w.experience;
	for (int i=0; i<=5;)
	{
		if (c.fail()||(w.experience>=w.age)||(w.experience<0))
		{
			system("CLS");
			c.clear();
			c.sync();
			cout<<endl<<"Name: "<<w.name<<endl;
			cout<<"Age: "<<w.age<<endl;
			cout<<"Post: "<<w.post<<endl;
			cout<<"Experience ("<<5-i<<" tries left): ";
			c>>w.experience;
			i++;
			if (i==6)
			{
				w.name="1";
				return c;
			}
		}
		else 
		{
			i=6;
			system("CLS");
			cout<<endl<<"Name: "<<w.name<<endl;
			cout<<"Age: "<<w.age<<endl;
			cout<<"Post: "<<w.post<<endl;
			cout<<"Experience: "<<w.experience<<endl;
		}
	}
	return c;
}

istream& operator>>(istream& c, PrimeWorker& w)
{
	cout<<endl<<"Name: ";
	c>>w.name;
	for (int i=0; i<=5;)
	{
		for (int j=0; j<w.name.size();)
		{
			if ((w.name.at(j)=='1')||(w.name.at(j)=='2')||(w.name.at(j)=='3')||(w.name.at(j)=='4')||(w.name.at(j)=='5')||(w.name.at(j)=='6')||(w.name.at(j)=='7')||(w.name.at(j)=='8')||(w.name.at(j)=='9')||(w.name.at(j)=='0'))
			{
				system ("CLS");
				cout<<endl<<"Name ("<<5-i<<" tries left): ";
				c>>w.name;
				j=w.name.size();
				i++;
				if (i==6)
				{
					w.name="1";
					return c;
				} 
			}
			else if (j==(w.name.size()-1)) 
			{
				i=6;
				j=w.name.size();
				system ("CLS");
				cout<<endl<<"Name: "<<w.name<<endl;
			}
			else j++;
		}
	}

	cout<<"Age: ";
	c>>w.age;
	for (int i=0; i<=5;)
	{
		if ((c.fail())||(w.age<=0))
		{
			system ("CLS");
			c.clear();
			c.sync();
			cout<<endl<<"Name: "<<w.name<<endl;
			cout<<"Age ("<<5-i<<" tries left): ";
			c>>w.age;
			i++;
			if (i==6)
			{
				w.name="1";
				return c;
			}
		}
		else 
		{
			i=6;
			system ("CLS");
			cout<<endl<<"Name: "<<w.name<<endl;
			cout<<"Age: "<<w.age<<endl;
		}
	}

	cout<<"Post: ";
	c>>w.post;

	cout<<"Experience: ";
	c>>w.experience;
	for (int i=0; i<=5;)
	{
		if ((c.fail())||(w.experience>=w.age)||(w.experience<0))
		{
			system("CLS");
			c.clear();
			c.sync();
			cout<<endl<<"Name: "<<w.name<<endl;
			cout<<"Age: "<<w.age<<endl;
			cout<<"Post: "<<w.post<<endl;
			cout<<"Experience ("<<5-i<<" tries left): ";
			c>>w.experience;
			i++;
			if (i==6)
			{
				w.name="1";
				return c;
			}
		}
		else 
		{
			i=6;
			system("CLS");
			cout<<endl<<"Name: "<<w.name<<endl;
			cout<<"Age: "<<w.age<<endl;
			cout<<"Post: "<<w.post<<endl;
			cout<<"Experience: "<<w.experience<<endl;
		}
	}

	cout<<"Bonus quantity: ";
	c>>w.quantity;
	for (int i=0; i<=5;)
	{
		if ((c.fail())||(w.quantity<0))
		{
			system("ClS");
			c.clear();
			c.sync();
			cout<<endl<<"Name: "<<w.name<<endl;
			cout<<"Age: "<<w.age<<endl;
			cout<<"Post: "<<w.post<<endl;
			cout<<"Experience: "<<w.experience<<endl;
			cout<<"Bonus quantity ("<<5-i<<" tries left): ";
			c>>w.quantity;
			i++;
			if (i==6)
				{
				w.name="1";
				return c;
			}
		}
		else
		{
			i=6;
			system("ClS");
			cout<<endl<<"Name: "<<w.name<<endl;
			cout<<"Age: "<<w.age<<endl;
			cout<<"Post: "<<w.post<<endl;
			cout<<"Experience: "<<w.experience<<endl;
			cout<<"Bonus quantity: "<<w.quantity<<endl;
		}
	}

	//delete [] w.bonus;
	if (w.quantity!=0)
	{
		delete [] w.bonus;
		w.bonus = new string[w.quantity];
		string h;
		cout<<endl;
		for (int i=0; i<w.quantity; i++)
		{
			cout<<"Enter name of "<<i+1<<" bonus: ";
			c>> h;
			w.bonus[i]=h;
		}
	}
	else cout<<endl;
	return c;
}