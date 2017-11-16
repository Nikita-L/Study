#include <iostream>
#include <string>

using namespace std;

class Worker
{
protected:
	string			name;
	unsigned int	age;
	string			post;
	unsigned int	experience;
public:
	Worker() : name("Vasiliy"), age(18), post("recruit"), experience(0) 
	{	}
	Worker(string n, unsigned int a, string p, unsigned int exp) : name(n), age(a), post(p), experience(exp) 
	{	}
	Worker(Worker & w) 
	{
		name=w.name;
		age=w.age;
		post=w.post;
		experience=w.experience;
	}
	~Worker() 
	{	};
	void get();
	void show();
	void postchange();
	void expcompare(Worker, Worker);
};

class PrimeWorker : Worker
{
protected:
	unsigned int	quantity;
	string*			bonus; 
public:
	PrimeWorker():Worker(), quantity(0), bonus(0)
	{	}
	PrimeWorker(string n, unsigned int a, string p, unsigned int exp, unsigned int q):Worker(n, a, p, exp), quantity(q)
	{	
		bonus = new string[quantity];
	}
	PrimeWorker(PrimeWorker & w):Worker(w)
	{
		quantity = w.quantity;
		bonus = w.bonus;
	}
	~PrimeWorker()
	{
		delete [] bonus;
	}
	void get()
	{
		Worker::get();
		cout<<endl<<"Bonus quantity: ";
		cin>>quantity;
	}
	void show()
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
	void postchange()
	{
		Worker::postchange();
	}
	void expcompare(PrimeWorker a, PrimeWorker b)
	{
		Worker::expcompare(a, b);
	}
	void getbonus();
};