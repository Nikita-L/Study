#include "head.h"

Worker& Worker:: operator ==(const Worker& a)
{
	cout << endl;
	if (name == a.name)
		cout << "Workers (" << name << ", " << a.name << ") " << "have identical names" << endl;
	if (age == a.age)
		cout << "Workers (" << name << ", " << a.name << ") " << "are the same age" << endl;
	if (post == a.post)
		cout << "Workers (" << name << ", " << a.name << ") " << "have the same post" << endl;
	if (experience == a.experience)
		cout << "Workers (" << name << ", " << a.name << ") " << "have equal experience" << endl;
	return *this;
}

PrimeWorker& PrimeWorker:: operator ==(const PrimeWorker& a)
{
	Worker::operator==(a);
	if (quantity == a.quantity)
		cout << "Workers (" << name << ", " << a.name << ") " << "have equal quantity of bonuses" << endl;
	unsigned int k = 0;
	for (int i = 0; i<quantity; i++)
	{
		for (int j = 0; j<a.quantity; j++)
		{
			if ((a.bonus[j] == bonus[i]) && (bonus[i] != "UNKNOWN"))
			{
				k++;
			}
		}
	}

	if (k>0)
	{
		int l = 0;
		string* z = new string[k];
		for (int i = 0; i<quantity; i++)
		{
			for (int j = 0; j<a.quantity; j++)
			{
				if ((a.bonus[j] == bonus[i]) && (bonus[i] != "UNKNOWN"))
				{
					z[l] = bonus[i];
					l++;
				}
			}
		}
		cout << "Workers (" << name << ", " << a.name << ") " << "have the same bonuses: ";
		for (int i = 0; i<k; i++)
		{
			if ((i + 1) == k)
				cout << "\"" << z[i] << "\"";
			else cout << "\"" << z[i] << "\"; ";
		}
		cout << endl;
	}

	return *this;
}