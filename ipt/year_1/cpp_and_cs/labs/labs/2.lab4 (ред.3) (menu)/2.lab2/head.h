#include <iostream>
#include <string>
#include <typeinfo>
#include <windows.h>
#include <typeinfo>

using namespace std;

void menu();

class Worker
{
protected:
	string			name;
	int				age;
	string			post;
	int				experience;
public:
	Worker() : name("UNKNOWN"), age(0), post("UNKNOWN"), experience(0) 
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
	virtual ~Worker() 
	{	};
	virtual void get();
	virtual void show() const;
	void postchange();
	void expcompare(Worker, Worker) const;
	friend ostream& operator <<(ostream& c, Worker& a);
	friend istream& operator >>(istream& c, Worker& a);
	string infoname() const;
	int infoage() const;
	string infopost() const;
	int infoexperience() const;
	void getinfoname(string);
	void getinfoage(int);
	void getinfopost(string);
	void getinfoexperience(int);
	virtual Worker& operator =(const Worker& a);

};

class PrimeWorker : public Worker
{
private:
	int				quantity;
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
		delete [] bonus;
		bonus=new string[w.quantity];
		for (int i=0;i<w.quantity;i++) 
			bonus[i]=w.bonus[i];

	}
	~PrimeWorker()
	{
		delete [] bonus;
	}
	void get();
	void show() const;
	void getbonus();
	friend ostream& operator<<(ostream& c, PrimeWorker& w);
	friend istream& operator>>(istream& c, PrimeWorker& w);
	int infoquantity() const;
	string* infobonus() const;
	void getinfoquantity(int);
	void getinfobonus(string, int);
	void getinfoquantity1();
	void deleteinfobonus();
	void getmass();
	PrimeWorker& operator =(const PrimeWorker& a);
};

class Base
{
private:
	int				workersinbase;
	Worker*			baseofworkers;
	int				pworkersinbase;
	PrimeWorker*	baseofpworkers;
public:
	Base(): workersinbase(0), pworkersinbase(0), baseofworkers(0), baseofpworkers(0)
	{
		//baseofworkers = new Worker[0];
		//baseofpworkers = new PrimeWorker[0];
	}
	Base (const Base & b)
	{
		workersinbase=b.workersinbase;
		delete [] baseofworkers;
		baseofworkers = new Worker[workersinbase];
		for (int i=0; i<workersinbase; i++)
			baseofworkers[i]=b.baseofpworkers[i];
		pworkersinbase=b.pworkersinbase;
		for (int i=0; i<pworkersinbase; i++)
		{
			for (int j=0; j<baseofpworkers[i].infoquantity(); j++)
				baseofpworkers[i].deleteinfobonus();
		}
		delete [] baseofpworkers;
		for (int i=0; i<pworkersinbase; i++)
		{
			for (int j=0; j<baseofpworkers[i].infoquantity(); j++)
				baseofpworkers[i].getinfobonus(b.baseofpworkers[i].infobonus()[j], j);
			//baseofpworkers[i].bonus[j]=b.baseofpworkers[i].bonus[j];
		}
		baseofpworkers=b.baseofpworkers;
	}
	~Base()
	{
		delete [] baseofworkers;
		//for (int i=0; i<pworkersinbase; i++)
		//{
		//	for (int j=0; j<baseofpworkers[i].infoquantity(); j++)
		//		baseofpworkers[i].deleteinfobonus();
		//	//delete [] baseofpworkers[i].bonus;
		//}
		delete [] baseofpworkers;
	}
	bool getBase();
	bool editBase();
	bool showBase();
	bool postBase();
	//bool compareBase()
	//{

	//		cout<<endl<<baseofworkers[0];
	//		system("pause");
	//*
	//	system("CLS");
	//	if (workersinbase==0)
	//	{
	//		cout<< "///////////////////////////////////////////" << endl
	//			<< "                                         //" << endl
	//			<< "Base of workers is emprty                //" << endl 
	//			<< "                                         //" << endl
	//			<< "                                         //" << endl 
	//			<< "                                         //" << endl 
	//			<< "                                         //" << endl 
	//			<< "                                         //" << endl
	//			<< "                                         //" << endl
	//			<< "                                         //" << endl
	//			<< "                                         //" << endl
	//			<< "///////////////////////////////////////////" << endl;
	//		cin.get();
	//		cin.get();
	//		return 1;
	//	}
	//	else if (workersinbase==1)
	//	{
	//		cout<< "///////////////////////////////////////////" << endl
	//			<< "                                         //" << endl
	//			<< "There is just one worker in the base     //" << endl 
	//			<< "                                         //" << endl
	//			<< "                                         //" << endl 
	//			<< "                                         //" << endl 
	//			<< "                                         //" << endl 
	//			<< "                                         //" << endl
	//			<< "                                         //" << endl
	//			<< "                                         //" << endl
	//			<< "                                         //" << endl
	//			<< "///////////////////////////////////////////" << endl;
	//		cin.get();
	//		cin.get();
	//		return 1;
	//	}
	//	else
	//	{
	//		cout<<endl<<"Enter the post of the first worker: ";
	//		string p1;
	//		cin>>p1;
	//		bool one=0;
	//		bool two=0;
	//		Worker A1;
	//		PrimeWorker B1;
	//		int co=-1;
	//		for (int i=0; i<workersinbase; i++)
	//		{
	//			if ((baseofworkers[i].infopost()==p1)&&(baseofworkers[i].infoname()!="2"))
	//			{
	//				//system("CLS");
	//				A1=baseofworkers[i];
	//				co=0;
	//				i=workersinbase;
	//			}
	//			else
	//			{
	//				one=1;
	//			}
	//			if ((baseofpworkers[i].infopost()==p1)&&(baseofpworkers[i].infoname()!="2"))
	//			{
	//				//system("CLS");
	//				B1=baseofpworkers[i];
	//				co=1;
	//				i=workersinbase;
	//			}
	//			else
	//			{
	//				two=1;
	//			}
	//		}
	//		//if (B1.infoname()=="UNKNOWN")
	//		//{
	//		//	Worker Q1=A1;
	//		//}
	//		//else if (B1.infoname()!="UNKNOWN")
	//		//{
	//		//	PrimeWorker Q1=B1;
	//		//}

	//		cout<<A1;
	//		system("pause");

	//		if ((one==1)&&(two==1))
	//		{
	//			system("CLS");
	//			cout<< "///////////////////////////////////////////" << endl
	//				<< "                                         //" << endl
	//				<< "There is no such worker                  //" << endl 
	//				<< "                                         //" << endl
	//				<< "                                         //" << endl 
	//				<< "                                         //" << endl 
	//				<< "                                         //" << endl 
	//				<< "                                         //" << endl
	//				<< "                                         //" << endl
	//				<< "                                         //" << endl
	//				<< "                                         //" << endl
	//				<< "///////////////////////////////////////////" << endl;
	//			cin.get();
	//			cin.get();
	//			return 1;
	//		}
	//		cout<<endl<<"Enter the post of the second worker: ";
	//		string p2;
	//		cin>>p2;
	//		bool one1=0;
	//		bool two1=0;
	//		Worker A2;
	//		PrimeWorker B2;
	//		int co1=-2;
	//		for (int i=0; i<workersinbase; i++)
	//		{
	//			if ((baseofworkers[i].infopost()==p2)&&(baseofworkers[i].infoname()!="2"))
	//			{
	//				//system("CLS");
	//				A2=baseofworkers[i];
	//				co1=0;
	//			}
	//			else
	//			{
	//				one1=1;
	//			}
	//			if ((baseofpworkers[i].infopost()==p2)&&(baseofpworkers[i].infoname()!="2"))
	//			{
	//				//system("CLS");
	//				B2=baseofpworkers[i];
	//				co1=1;
	//				//baseofpworkers[i].deleteinfobonus();
	//				//cin>>baseofpworkers[i];
	//			}
	//			else
	//			{
	//				two1=1;
	//			}
	//		}
	//		//if (B2.infoname()=="UNKNOWN")
	//		//{
	//		//	Worker Q2=A2;
	//		//}
	//		//else if (B1.infoname()!="UNKNOWN")
	//		//{
	//		//	PrimeWorker Q2=B2;
	//		//}
	//		if ((one1==1)&&(two1==1))
	//		{
	//			system("CLS");
	//			cout<< "///////////////////////////////////////////" << endl
	//				<< "                                         //" << endl
	//				<< "There is no such worker                  //" << endl 
	//				<< "                                         //" << endl
	//				<< "                                         //" << endl 
	//				<< "                                         //" << endl 
	//				<< "                                         //" << endl 
	//				<< "                                         //" << endl
	//				<< "                                         //" << endl
	//				<< "                                         //" << endl
	//				<< "                                         //" << endl
	//				<< "///////////////////////////////////////////" << endl;
	//			cin.get();
	//			cin.get();
	//			return 1;
	//		}
	//		system("CLS");
	//		if ((co==co1)&&(co==0))
	//		{
	//			Worker T;
	//			T.expcompare(A1, A2);
	//			return 0;
	//		}
	//		else if ((co==co1)&&(co==1))
	//		{
	//			PrimeWorker T1;
	//			T1.expcompare(B1, B2);
	//			return 0;
	//		}
	//		else
	//		{
	//			if (A1.infoname()!="UNKNOWN")
	//			{

	//				if (A1.infoexperience() > B2.infoexperience())
	//					cout<<endl<<A1.infoname()<<" has more experience than "<<B2.infoname();
	//				else if (A1.infoexperience() > B2.infoexperience())
	//					cout<<endl<<B2.infoname()<<" has more experience than "<<A1.infoname();
	//				else cout<<endl<<A1.infoname()<<" and "<<B2.infoname()<<" has equal years of experience";
	//				cout<<endl;
	//				return 0;
	//			}
	//			else if (A1.infoname()=="UNKNOWN")
	//			{
	//				if (B1.infoexperience() > A2.infoexperience())
	//					cout<<endl<<B1.infoname()<<" has more experience than "<<A2.infoname();
	//				else if (B1.infoexperience() > A2.infoexperience())
	//					cout<<endl<<A2.infoname()<<" has more experience than "<<B1.infoname();
	//				else cout<<endl<<B1.infoname()<<" and "<<A2.infoname()<<" has equal years of experience";
	//				cout<<endl;
	//				return 0;
	//			}
	//		}
	//	}*/
	//	return 0;
	//}
	bool compareBase();
	bool showallBase();
};