#include "head.h"

void menu()
{
	cout << "///////////////////////////////////////////" << endl
		<< "                                         //" << endl
		<< "                                         //" << endl 
		<< "                                         //" << endl
		<< "                                         //" << endl 
		<< "                Welcome!                 //" << endl 
		<< "                                         //" << endl 
		<< "                                         //" << endl
		<< "                                         //" << endl
		<< "                                         //" << endl
		<< "                                         //" << endl
		<< "///////////////////////////////////////////" << endl;
	Sleep(2500);
	Base A;
	void sf();
	void ss();
	int t=0;
	while (t!=-1)
	{
		//t++;
		system("CLS");
		cout << "///////////////////////////////////////////" << endl
			<< "                                         //" << endl
			<< "Choose the action:                       //" << endl 
			<< "1. Create new account                    //" << endl
			<< "2. Edit account                          //" << endl 
			<< "3. Show information of the worker        //" << endl 
			<< "4. Chage the post of the worker          //" << endl 
			<< "5. Compare experience of the workers     //" << endl
			<< "6. Show all workers                      //" << endl
			<< "0. Exit                                  //" << endl
			<< "                                         //" << endl
			<< "///////////////////////////////////////////" << endl
			<< endl <<"Your choice: ";
		string ans;
		cin.clear();
		cin.sync();
		//ans.clear();
		cin>>ans;
		if (ans=="1")
		{
			if (A.getBase()==1)
			{
				sf();
			}
			else
			{
				ss();
			}
		}
		else if (ans=="2")
		{
			if (A.editBase()==1)
			{
				sf();
			}
			else
			{
				ss();
			}
		}
		else if (ans=="3")
		{
			if (A.showBase()==1)
			{
				sf();
			}
			else
			{
				ss();
			}
		}
		else if (ans=="4")
		{
			if (A.postBase()==1)
			{
				sf();
			}
			else
			{
				ss();
			}
		}
		else if (ans=="5")
		{
			if (A.compareBase()==1)
			{
				sf();
			}
			else
			{
				ss();
			}
		}
		/*else if (ans=="6")
		{
		if (A.compareBase()==1)
		{
		sf();
		}
		else
		{
		ss();
		}
		}*/
		else if (ans=="0")
		{
			system("CLS");
			cout << "///////////////////////////////////////////" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl 
				<< "                                         //" << endl
				<< "                                         //" << endl 
				<< "     Thank you for using my program!     //" << endl 
				<< "                                         //" << endl 
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "///////////////////////////////////////////" << endl;
			Sleep(2500);
			t=-1;
		}
	}
}

void sf()
{
	system("CLS");
	cout << "///////////////////////////////////////////" << endl
		<< "                                         //" << endl
		<< "                                         //" << endl 
		<< "                                         //" << endl
		<< "                                         //" << endl 
		<< "             Back to menu                //" << endl 
		<< "                                         //" << endl 
		<< "                                         //" << endl
		<< "                                         //" << endl
		<< "                                         //" << endl
		<< "                                         //" << endl
		<< "///////////////////////////////////////////" << endl;
	Sleep(2000);
}
void ss()
{
	system("CLS");
	cout << "///////////////////////////////////////////" << endl
		<< "                                         //" << endl
		<< "                                         //" << endl 
		<< "                                         //" << endl
		<< "                                         //" << endl 
		<< "          Successful operation           //" << endl 
		<< "                                         //" << endl 
		<< "                                         //" << endl
		<< "                                         //" << endl
		<< "                                         //" << endl
		<< "                                         //" << endl
		<< "///////////////////////////////////////////" << endl;
	Sleep(2000);
}

string Worker::infoname() const
{
	return name;
}
int Worker::infoage() const
{
	return age;
}
string Worker::infopost() const
{
	return post;
}
int Worker::infoexperience() const
{
	return experience;
}
void Worker::getinfoname(string s)
{
	name=s;
}
void Worker::getinfoage(int i)
{
	age=i;
}
void Worker::getinfopost(string s)
{
	post=s;
}
void Worker::getinfoexperience(int i)
{
	experience=i;
}

int PrimeWorker::infoquantity() const
{
	return quantity;
}
string* PrimeWorker::infobonus() const
{
	return bonus;
}
void PrimeWorker::getinfoquantity(int i)
{
	quantity=i;
}
void PrimeWorker::getinfobonus(string s, int i)
{
	bonus[i]=s;
}
void PrimeWorker::getinfoquantity1()
{
	quantity++;
}
void PrimeWorker::deleteinfobonus()
{
	delete [] bonus;
}
void PrimeWorker::getmass()
{
	bonus = new string[quantity];
}

bool Base::getBase()
{
	int p=0;

	system("CLS");
	workersinbase++;
	pworkersinbase++;
	if (workersinbase!=1)
	{
		Worker* temp;
		temp = new Worker[workersinbase-1];
		for (int i=0; i<workersinbase-1; i++)
		{
			temp[i]=baseofworkers[i];
		}
		delete [] baseofworkers;
		baseofworkers = new Worker[workersinbase];
		for (int j=0; j<workersinbase-1; j++)
		{
			baseofworkers[j]=temp[j];
		}
		delete [] temp;
	}
	else 
	{
		baseofworkers = new Worker[workersinbase];
	}
	cin>>baseofworkers[workersinbase-1];
	if (baseofworkers[workersinbase-1].infoname()=="1")
	{
		delete [workersinbase-1] baseofpworkers;
		workersinbase--;
		return 1;
	}
	while(p!=-1)
	{
		system("CLS");
		cout << "///////////////////////////////////////////" << endl
			<< "                                         //" << endl
			<< "Do you want to enter bonuses (yes/no)?   //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "0. Exit                                  //" << endl
			<< "                                         //" << endl
			<< "///////////////////////////////////////////" << endl
			<< endl <<"Your choice: ";
		string ans1;
		cin>>ans1;
		//pworkersinbase++;
		if (workersinbase!=1)
		{
			PrimeWorker* temp;
			temp = new PrimeWorker[workersinbase-1];
			for (int j=0; j<workersinbase-1; j++)
			{
				temp[j]=baseofpworkers[j];
				/*if (baseofpworkers[i].infoquantity()!=0)
				{
				string* a=temp[i].infobonus();
				a = new string[baseofpworkers[i].infoquantity()];
				for (int o=0; o<baseofpworkers[i].infoquantity();o++)
				{
				temp[i].getinfobonus(baseofpworkers[i].infobonus()[o], o);
				}
				baseofpworkers[i].deleteinfobonus();
				}*/
			}
			delete [] baseofpworkers;
			/*temp=baseofpworkers;
			for (int i=0; (i<(pworkersinbase-1)); i++)
			{
			for (int j=0; j<baseofpworkers[i].infoquantity(); j++)
			baseofpworkers[i].deleteinfobonus();
			}*/
			//delete [] baseofpworkers;

			baseofpworkers = new PrimeWorker[workersinbase];
			for (int j=0; j<workersinbase-1; j++)
			{
				baseofpworkers[j]=temp[j];
				//if (temp[j].infoquantity()!=0)
				//{
				//	string* b=baseofpworkers[j].infobonus();
				//	b = new string[temp[j].infoquantity()];
				//	//baseofpworkers[j].infobonus() = new string[temp[j].infoquantity()];
				//	for (int o=0; o<temp[j].infoquantity();o++)
				//	{
				//		baseofpworkers[j].getinfobonus(temp[j].infobonus()[o], o);
				//	}
				//	temp[j].deleteinfobonus();
				//}

			}
			delete [] temp;
			//baseofpworkers=temp;
			//			for (int i=0; (i<(pworkersinbase-1)); i++)
			//{
			//	for (int j=0; j<(baseofpworkers[i].infoquantity()-1); j++)
			//		temp[i].deleteinfobonus();
			//}
			//delete [] temp;
		}
		else
		{
			baseofpworkers = new PrimeWorker[workersinbase];
		}
		baseofpworkers[pworkersinbase-1].getinfoname(baseofworkers[workersinbase-1].infoname());
		baseofpworkers[pworkersinbase-1].getinfoage(baseofworkers[workersinbase-1].infoage());
		baseofpworkers[pworkersinbase-1].getinfopost(baseofworkers[workersinbase-1].infopost());
		baseofpworkers[pworkersinbase-1].getinfoexperience(baseofworkers[workersinbase-1].infoexperience());
		if (ans1=="yes")
		{

			//pworkersinbase++;
			//baseofpworkers = new PrimeWorker[pworkersinbase];
			//baseofpworkers[pworkersinbase-1].getinfoname(baseofworkers[workersinbase-1].infoname());
			//baseofpworkers[pworkersinbase-1].getinfoage(baseofworkers[workersinbase-1].infoage());
			//baseofpworkers[pworkersinbase-1].getinfopost(baseofworkers[workersinbase-1].infopost());
			//baseofpworkers[pworkersinbase-1].getinfoexperience(baseofworkers[workersinbase-1].infoexperience());
			baseofworkers[workersinbase-1].getinfoname("2");
			int y=0;
			while (y!=-1)
			{
				system("CLS");
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl
					<< "1. Enter first bonus                     //" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "0. Exit                                  //" << endl
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl
					<< endl <<"Your choice: ";
				string ans2;
				cin>> ans2;

				if (ans2=="1")
				{
					int i=0;
					//while (i!=-1)
					//{
					//int j=0;
					//while (j!=-1)
					//{
					baseofpworkers[workersinbase-1].getinfoquantity1(); //quantity++
					baseofpworkers[workersinbase-1].deleteinfobonus();
					baseofpworkers[workersinbase-1].getmass(); //baseofpworkers[workersinbase-1].infobonus() = new string[baseofpworkers[workersinbase-1].infoquantity()];
					system("CLS");
					cout<<endl<<"Name of "<< baseofpworkers[workersinbase-1].infoquantity() <<" bonus: ";
					string gb;
					cin>> gb; //baseofpworkers[workersinbase-1].bonus[baseofpworkers[workersinbase-1].infoquantity()];
					baseofpworkers[workersinbase-1].getinfobonus(gb, (baseofpworkers[workersinbase-1].infoquantity()-1));
					int j=0;
					while (j!=-1)
					{
						system("CLS");
						cout << "///////////////////////////////////////////" << endl
							<< "                                         //" << endl
							<< "1. Enter one more bonus                  //" << endl
							<< "                                         //" << endl
							<< "                                         //" << endl
							<< "                                         //" << endl
							<< "                                         //" << endl
							<< "                                         //" << endl
							<< "                                         //" << endl
							<< "0. Exit                                  //" << endl
							<< "                                         //" << endl
							<< "///////////////////////////////////////////" << endl
							<< endl <<"Your choice: ";
						string ans3;
						cin>>ans3;
						if (ans3=="1")
						{
							baseofpworkers[workersinbase-1].getinfoquantity1(); //quantity++

							string* temp1;
							temp1 = new string[baseofpworkers[workersinbase-1].infoquantity()-1];
							for (int j=0; j<baseofpworkers[workersinbase-1].infoquantity()-1; j++)
							{
								temp1[j]=baseofpworkers[workersinbase-1].infobonus()[j];
								/*if (baseofpworkers[i].infoquantity()!=0)
								{
								string* a=temp[i].infobonus();
								a = new string[baseofpworkers[i].infoquantity()];
								for (int o=0; o<baseofpworkers[i].infoquantity();o++)
								{
								temp[i].getinfobonus(baseofpworkers[i].infobonus()[o], o);
								}
								baseofpworkers[i].deleteinfobonus();
								}*/
							}
							baseofpworkers[workersinbase-1].deleteinfobonus();
							/*temp=baseofpworkers;
							for (int i=0; (i<(pworkersinbase-1)); i++)
							{
							for (int j=0; j<baseofpworkers[i].infoquantity(); j++)
							baseofpworkers[i].deleteinfobonus();
							}*/
							//delete [] baseofpworkers;

							baseofpworkers[workersinbase-1].getmass();
							//baseofpworkers[workersinbase-1].infobonus() = new string[baseofpworkers[workersinbase-1].infoquantity()];
							//baseofpworkers = new PrimeWorker[workersinbase];
							for (int j=0; j<baseofpworkers[workersinbase-1].infoquantity()-1; j++)
							{
								baseofpworkers[workersinbase-1].infobonus()[j]=temp1[j];
								//if (temp[j].infoquantity()!=0)
								//{
								//	string* b=baseofpworkers[j].infobonus();
								//	b = new string[temp[j].infoquantity()];
								//	//baseofpworkers[j].infobonus() = new string[temp[j].infoquantity()];
								//	for (int o=0; o<temp[j].infoquantity();o++)
								//	{
								//		baseofpworkers[j].getinfobonus(temp[j].infobonus()[o], o);
								//	}
								//	temp[j].deleteinfobonus();
								//}

							}
							delete [] temp1;


							//baseofpworkers[workersinbase-1].deleteinfobonus();

							//baseofpworkers[workersinbase-1].getmass(); //baseofpworkers[workersinbase-1].infobonus() = new string[baseofpworkers[workersinbase-1].infoquantity()];
							system("CLS");
							cout<<endl<<"Name of "<< baseofpworkers[workersinbase-1].infoquantity() <<" bonus: ";
							string gb;
							cin>> gb; //baseofpworkers[workersinbase-1].bonus[baseofpworkers[workersinbase-1].infoquantity()];
							baseofpworkers[workersinbase-1].getinfobonus(gb, (baseofpworkers[workersinbase-1].infoquantity()-1));
							//i++;
							//j=-1;
							//j++;
						}
						else if (ans3=="0")
							return 0;
						else
						{
							j++;
							system("CLS");
							cout << "///////////////////////////////////////////" << endl
								<< "                                         //" << endl
								<< 5-j <<" tries left                             //" << endl
								<< "                                         //" << endl
								<< "                                         //" << endl
								<< "                                         //" << endl
								<< "                                         //" << endl
								<< "You are avaliable to enter just:         //" << endl
								<< "1                                        //" << endl
								<< "0                                        //" << endl
								<< "                                         //" << endl
								<< "///////////////////////////////////////////" << endl;
							cin.get();
							cin.get();
							if (j==5)
							{
								//workersinbase--;
								//delete [] baseofpworkers[pworkersinbase].bonus;
								//baseofpworkers[pworkersinbase].~PrimeWorker();
								//baseofpworkers[pworkersinbase].deleteinfobonus();
								//pworkersinbase--;
								return 1;
							}
						}
					}
					//}
				}
				else if (ans2=="0")
				{
					return 0;
				}
				else
				{
					y++;
					system("CLS");
					cout << "///////////////////////////////////////////" << endl
						<< "                                         //" << endl
						<< 5-y <<" tries left                             //" << endl
						<< "                                         //" << endl
						<< "                                         //" << endl
						<< "                                         //" << endl
						<< "                                         //" << endl
						<< "You are avaliable to enter just:         //" << endl
						<< "1                                        //" << endl
						<< "0                                        //" << endl
						<< "                                         //" << endl
						<< "///////////////////////////////////////////" << endl;
					cin.get();
					cin.get();
					if (y==5)
					{
						return 1;
					}
				}
			}
		}
		else if (ans1=="no"||ans1=="0")
		{
			baseofpworkers[workersinbase-1].getinfoname("2");
			return 0;
		}
		else
		{
			p++;
			system("CLS");
			cout << "///////////////////////////////////////////" << endl
				<< "                                         //" << endl
				<< 5-p <<" tries left                             //" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "You are avaliable to enter just:         //" << endl
				<< "yes                                      //" << endl
				<< "no                                       //" << endl
				<< "0                                        //" << endl
				<< "                                         //" << endl
				<< "///////////////////////////////////////////" << endl;
			cin.get();
			cin.get();
			if (p==5)
			{
				return 1;
			}
		}
		//return 0;
	}
	return 0;
}
bool Base::editBase()
{
	system("CLS");
	if (workersinbase==0)
	{
		cout<< "///////////////////////////////////////////" << endl
			<< "                                         //" << endl
			<< "Base of workers is emprty                //" << endl 
			<< "                                         //" << endl
			<< "                                         //" << endl 
			<< "                                         //" << endl 
			<< "                                         //" << endl 
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "///////////////////////////////////////////" << endl;
		cin.get();
		cin.get();
		return 1;
	}
	else
	{
		cout<<endl<<"Enter the post of the worker: ";
		string p;
		cin>>p;
		bool one=0;
		bool two=0;
		for (int i=0; i<workersinbase; i++)
		{
			if ((baseofworkers[i].infopost()==p)&&(baseofworkers[i].infoname()!="2"))
			{
				system("CLS");
				cout<<baseofworkers[i];
				cout<<endl<<"Sure to edit (yes/no): ";
				string ans1;
				cin>>ans1;
				if (ans1=="yes")
				{
					system("CLS");
					cin>>baseofworkers[i];

					cout<<"Bonus quantity: ";
					int q=0;
					cin>>q;
					for (int u=0; u<=5;)
					{
						if ((cin.fail())||(q<0))
						{
							system("ClS");
							cin.clear();
							cin.sync();
							cout<<endl<<"Name: "<<baseofworkers[i].infoname()<<endl;
							cout<<"Age: "<<baseofworkers[i].infoage()<<endl;
							cout<<"Post: "<<baseofworkers[i].infopost()<<endl;
							cout<<"Experience: "<<baseofworkers[i].infopost()<<endl;
							cout<<"Bonus quantity ("<<5-u<<" tries left): ";
							cin>>q;
							u++;
							if (i==6)
							{
								baseofworkers[i].getinfoname("1");
								//w.name="1";
								return 1;
							}
						}
						else
						{
							u=6;
							system("ClS");
							cout<<endl<<"Name: "<<baseofworkers[i].infoname()<<endl;
							cout<<"Age: "<<baseofworkers[i].infoage()<<endl;
							cout<<"Post: "<<baseofworkers[i].infopost()<<endl;
							cout<<"Experience: "<<baseofworkers[i].infopost()<<endl;
							cout<<"Bonus quantity: "<<q<<endl;
						}
					}
					if (q!=0)
					{
						baseofpworkers[i].getinfoname(baseofworkers[i].infoname());
						baseofpworkers[i].getinfoage(baseofworkers[i].infoage());
						baseofpworkers[i].getinfopost(baseofworkers[i].infopost());
						baseofpworkers[i].getinfoexperience(baseofworkers[i].infoexperience());

						baseofworkers[i].getinfoname("2");

						//baseofpworkers[i].deleteinfobonus();	//delete [] w.bonus;
						if (baseofpworkers[i].infoquantity() != 0)
							baseofpworkers[i].deleteinfobonus();

						baseofpworkers[i].getinfoquantity(q);

						baseofpworkers[i].getmass();  //baseofpworkers[i].infobonus() = new string[q];
						string h;
						cout<<endl;
						for (int l=0; l<q; l++)
						{
							cout<<"Enter name of "<<l+1<<" bonus: ";
							cin>> h;
							baseofpworkers[i].infobonus()[l]=h;//w.bonus[i]=h;
						}

						cout<<endl;

					}

					if (baseofworkers[workersinbase-1].infoname()=="1")
					{
						//workersinbase--;
						return 1;
					}
					return 0;
				}
				else if (ans1=="no")
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			else
			{
				one=1;
			}
			if ((baseofpworkers[i].infopost()==p)&&(baseofpworkers[i].infoname()!="2"))
			{
				system("CLS");
				cout<<baseofpworkers[i];
				cout<<endl<<"Sure to edit (yes/no): ";
				string ans2;
				cin>>ans2;
				if (ans2=="yes")
				{
					system("CLS");
					//baseofpworkers[i].deleteinfobonus();
					cin>>baseofpworkers[i];
					if (baseofpworkers[i].infoquantity()==0)
					{
						baseofworkers[i].getinfoname(baseofpworkers[i].infoname());
						baseofworkers[i].getinfoage(baseofpworkers[i].infoage());
						baseofworkers[i].getinfopost(baseofpworkers[i].infopost());
						baseofworkers[i].getinfoexperience(baseofpworkers[i].infoexperience());
						//baseofpworkers[i].getinfoname(baseofworkers[i].infoname());
						baseofpworkers[i].getinfoname("2");

						//baseofpworkers[i].deleteinfobonus();
						if (baseofpworkers[i].infoquantity()!=0)
							baseofpworkers[i].deleteinfobonus();

					}
					if (baseofpworkers[workersinbase-1].infoname()=="1")
					{
						//delete [workersinbase-1] baseofpworkers;
						//workersinbase--;
						return 1;
					}
					return 0;
				}
				else if (ans2=="no")
				{
					return 0;
				}
				else
				{
					return 1;
				}
				//baseofpworkers[i].deleteinfobonus();
				//cin>>baseofpworkers[i];
			}
			else
			{
				two=1;
			}
		}
		if ((one==1)&&(two==1))
		{
			system("CLS");
			cout<< "///////////////////////////////////////////" << endl
				<< "                                         //" << endl
				<< "There is no such worker                  //" << endl 
				<< "                                         //" << endl
				<< "                                         //" << endl 
				<< "                                         //" << endl 
				<< "                                         //" << endl 
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "///////////////////////////////////////////" << endl;
			cin.get();
			cin.get();
			return 1;
		}

		//Worker* temp1;
		//temp1 = new Worker[j];
		//PrimeWorker* temp2;
		//temp2 = new PrimeWorker[k];
		//for (int i=0; i<workersinbase; i++)
		//{
		//	if (baseofworkers[i].infoname()==n)
		//	{
		//		j++;
		//		temp1[j-1]=baseofworkers[i];
		//	}
		//	if (baseofworkers[i].infoname()==n)
		//	{
		//		k++;
		//		temp2[k-1]=baseofpworkers[i];
		//	}
		//}
	}
	return 0;
}
bool Base::showBase()
{
	system("CLS");
	if (workersinbase==0)
	{
		cout<< "///////////////////////////////////////////" << endl
			<< "                                         //" << endl
			<< "Base of workers is emprty                //" << endl 
			<< "                                         //" << endl
			<< "                                         //" << endl 
			<< "                                         //" << endl 
			<< "                                         //" << endl 
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "///////////////////////////////////////////" << endl;
		cin.get();
		cin.get();
		return 1;
	}
	cout<<endl<<"Enter the post of the worker: ";
	string p;
	cin>>p;
	bool one=0;
	bool two=0;
	for (int i=0; i<workersinbase; i++)
	{
		if ((baseofworkers[i].infopost()==p)&&(baseofworkers[i].infoname()!="2"))
		{
			system("CLS");
			cout<<baseofworkers[i];
			cin.get();
			cin.get();
			return 0;
		}
		else
		{
			one=1;
		}
		if (baseofpworkers[i].infopost()==p&&(baseofpworkers[i].infoname()!="2"))
		{
			system("CLS");
			cout<<baseofpworkers[i];
			cin.get();
			cin.get();
			return 0;
		}
		else
		{
			two=1;
		}
	}
	if ((one==1)&&(two==1))
	{
		system("CLS");
		cout<< "///////////////////////////////////////////" << endl
			<< "                                         //" << endl
			<< "There is no such worker                  //" << endl 
			<< "                                         //" << endl
			<< "                                         //" << endl 
			<< "                                         //" << endl 
			<< "                                         //" << endl 
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "///////////////////////////////////////////" << endl;
		cin.get();
		cin.get();
		return 1;
	}

}
bool Base::postBase()
{
	system("CLS");
	if (workersinbase==0)
	{
		cout<< "///////////////////////////////////////////" << endl
			<< "                                         //" << endl
			<< "Base of workers is emprty                //" << endl 
			<< "                                         //" << endl
			<< "                                         //" << endl 
			<< "                                         //" << endl 
			<< "                                         //" << endl 
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "                                         //" << endl
			<< "///////////////////////////////////////////" << endl;
		cin.get();
		cin.get();
		return 1;
	}
	else
	{
		cout<<endl<<"Enter the post of the worker: ";
		string p;
		cin>>p;
		bool one=0;
		bool two=0;
		for (int i=0; i<workersinbase; i++)
		{
			if ((baseofworkers[i].infopost()==p)&&(baseofworkers[i].infoname()!="2"))
			{
				system("CLS");
				cout<<endl<<"Enter new post of the worker: ";
				string np1;
				cin>>np1;
				baseofworkers[i].getinfopost(np1);
			}
			else
			{
				one=1;
			}
			if (baseofpworkers[i].infopost()==p&&(baseofpworkers[i].infoname()!="2"))
			{
				system("CLS");
				cout<<endl<<"Enter new post of the worker: ";
				string np2;
				cin>>np2;
				baseofpworkers[i].getinfopost(np2);
			}
			else
			{
				two=1;
			}
		}
		if ((one==1)&&(two==1))
		{
			system("CLS");
			cout<< "///////////////////////////////////////////" << endl
				<< "                                         //" << endl
				<< "There is no such worker                  //" << endl 
				<< "                                         //" << endl
				<< "                                         //" << endl 
				<< "                                         //" << endl 
				<< "                                         //" << endl 
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "///////////////////////////////////////////" << endl;
			cin.get();
			cin.get();
			return 1;
		}
	}
	return 0;
}