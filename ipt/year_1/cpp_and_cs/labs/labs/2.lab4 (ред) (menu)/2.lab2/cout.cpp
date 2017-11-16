#include "head.h"

ostream& operator <<(ostream& c, Worker& w)
{
	c<<endl<<"Name: "<<w.name;
	c<<endl<<"Age: "<<w.age;
	c<<endl<<"Post: "<<w.post;
	c<<endl<<"Experience: "<<w.experience;
	c<<endl;
	return c;
}

ostream& operator <<(ostream& c, PrimeWorker& w)
{
	c<<endl<<"Name: "<<w.name;
	c<<endl<<"Age: "<<w.age;
	c<<endl<<"Post: "<<w.post;
	c<<endl<<"Experience: "<<w.experience;
	c<<endl;
	c<<"Bonus quantity: "<<w.quantity;
	c<<endl;
	if (w.quantity!=0)
	{
		c<<endl<<w.name<<" has bonuses:"<<endl;
		for (int i=0; i<w.quantity; i++)
		{
			if (w.bonus[i]=="")
				c<<i+1<<". UNKNOWN"<<endl;
			else c<<i+1<<". "<<w.bonus[i]<<endl;
		}
	}
	else c<<w.name<<" has no bonuses"<<endl;
	return c;
}