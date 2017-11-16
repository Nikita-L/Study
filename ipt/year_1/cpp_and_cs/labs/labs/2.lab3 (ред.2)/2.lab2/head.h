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
	virtual Worker& operator =(const Worker& a);
	virtual Worker& operator ==(const Worker& a);
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
	void get();
	void show();
	void getbonus();
	PrimeWorker& operator =(const PrimeWorker& a);
	PrimeWorker& operator ==(const PrimeWorker& a);
};
