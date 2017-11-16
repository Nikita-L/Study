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
	Worker(const Worker & w) 
	{
		name=w.name;
		age=w.age;
		post=w.post;
		experience=w.experience;
	}
	~Worker() 
	{	};
	virtual void get();
	virtual void show();
	void postchange();
	void expcompare(Worker, Worker);
	virtual Worker operator =(const Worker& a)
	{
		name=a.name;
		age=a.age;
		post=a.post;
		experience=a.experience;
		return *this;
	}
	virtual Worker operator ==(const Worker& a)
	{
		cout<<endl;
		if (name==a.name)
			cout<<"Workers ("<<name<<", "<<a.name<<") "<<"have identical names"<<endl;
		if (age==a.age)
			cout<<"Workers ("<<name<<", "<<a.name<<") "<<"are the same age"<<endl;
		if (post==a.post)
			cout<<"Workers ("<<name<<", "<<a.name<<") "<<"have the same post"<<endl;
		if (experience==a.experience)
			cout<<"Workers ("<<name<<", "<<a.name<<") "<<"have equal experience"<<endl;
		return *this;
	}
};

class PrimeWorker : public Worker
{
private:
	unsigned int	quantity;
	string*			bonus; 
public:
	PrimeWorker(): quantity(0), bonus(0)
	{	}
	PrimeWorker(string n, unsigned int a, string p, unsigned int exp, unsigned int q):Worker(n, a, p, exp), quantity(q)
	{	
		bonus = new string[quantity];
	}
	PrimeWorker(const PrimeWorker & w):Worker(w)
	{
		quantity = w.quantity;
		bonus=new string[w.quantity];
		for (int i=0;i<w.quantity;i++) 
			bonus[i]=w.bonus[i];
		
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
	void getbonus();
	PrimeWorker operator =(const PrimeWorker& a)
	{
		delete [] bonus;
		Worker::operator=(a);
		quantity = a.quantity;
		bonus=new string[a.quantity];
		for (int i=0; i<a.quantity; i++)
			bonus[i]=a.bonus[i];
		return *this;
	}
	PrimeWorker operator ==(const PrimeWorker& a)
	{
		Worker::operator==(a);
		if (quantity==a.quantity)
			cout<<"Workers ("<<name<<", "<<a.name<<") "<<"have equal quantity of bonuses"<<endl;
		//cout<<"Workers ("<<name<<", "<<a.name<<") "<<"have the same bonuses: ";
		unsigned int k = 0;	
		for (int i=0; i<quantity; i++)
		{
			for (int j=0; j<a.quantity; j++)
			{
				if ((a.bonus[j]==bonus[i])&&(bonus[i]!="UNKNOWN"))
				{
					k++;
				}
			}
		}

		if (k>0)
		{
			int l=0;
			string* z = new string[k];
			for (int i=0; i<quantity; i++)
			{
				for (int j=0; j<a.quantity; j++)
				{
					if ((a.bonus[j]==bonus[i])&&(bonus[i]!="UNKNOWN"))
					{
						z[l]=bonus[i];
						l++;
					}
				}
			}
			cout<<"Workers ("<<name<<", "<<a.name<<") "<<"have the same bonuses: ";
			for (int i=0; i<k; i++)
			{
				if ((i+1)==k)
					cout<<"\""<<z[i]<<"\"";
				else cout<<"\""<<z[i]<<"\"; ";
			}
			cout<<endl;
		}

		return *this;
	}
};
