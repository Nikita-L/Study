#include <iostream>
#include <string>

using namespace std;

template <class type>
class Worker
{
protected:
	string			name;
	type			age;
	string			post;
	type			experience;
public:
	Worker() : name("Vasiliy"), age(18), post("recruit"), experience(0) 
	{	}
	Worker(string n, type a, string p, type exp) : name(n), age(a), post(p), experience(exp) 
	{	}
	Worker(const Worker<type> & w) 
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
	void expcompare(Worker<type>, Worker<type>);
};

template <class type>
void Worker<type>::show()
{
	cout<<endl<<"Name: "<<name;
	cout<<endl<<"Age: "<<age;
	cout<<endl<<"Post: "<<post;
	cout<<endl<<"Experience: "<<experience;
	cout<<endl;
}

template <class type>
void Worker<type>::get()
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

template <class type>
void Worker<type>::expcompare(Worker<type> a, Worker<type> b)
{
	if (a.experience > b.experience)
		cout<<endl<<a.name<<" has more experience than "<<b.name;
	else if (b.experience > a.experience)
		cout<<endl<<b.name<<" has more experience than "<<a.name;
	else cout<<a.name<<" and "<<b.name<<" has equal years of experience";
	cout<<endl;
}

template <class type>
void Worker<type>::postchange()
{
	cout<<endl<<"Present "<<name<<" post: "<<post;
	cout<<endl<<"Enter new post: ";
	cin>>post;
}



template <class type>
class PrimeWorker : public Worker<type>
{
private:
	unsigned int	quantity;
	string*			bonus; 
public:
	PrimeWorker<type>(): quantity(0), bonus(0)
	{	}
	PrimeWorker<type>(string n, type a, string p, type exp, unsigned int q):Worker(n, a, p, exp), quantity(q)
	{	
		bonus = new string[quantity];
	}
	PrimeWorker<type>(const PrimeWorker<type> & w):Worker(w)
	{
		quantity = w.quantity;
		bonus=new string[w.quantity];
		for (int i=0;i<w.quantity;i++) 
			bonus[i]=w.bonus[i];
		
	}
	~PrimeWorker<type>()
	{
		delete [] bonus;
	}
	void get();
	void show();
	void postchange();
	void expcompare(PrimeWorker<type>, PrimeWorker<type>);
	void getbonus();
};

template <class type>
void PrimeWorker<type>::get()
{
	Worker::get();
	cout<<endl<<"Bonus quantity: ";
	cin>>quantity;
}

template <class type>
void PrimeWorker<type>::show()
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

template <class type>
void PrimeWorker<type>::expcompare(PrimeWorker<type> a, PrimeWorker<type> b)
{
	Worker<type>::expcompare(a, b);
}

template <class type>
void PrimeWorker<type>::postchange()
{
	Worker<type>::postchange();
}

template <class type>
void PrimeWorker<type>::getbonus()
{
	delete [] bonus;
	bonus = new string[quantity];
	if (quantity!=0)
	{
		string h;
		for (int i=0; i<quantity; i++)
		{
			cout<<endl<<"Enter name of "<<i+1<<" bonus: ";
			cin>> h;
			bonus[i]=h;
		}
	}
	else cout<<endl;
}

