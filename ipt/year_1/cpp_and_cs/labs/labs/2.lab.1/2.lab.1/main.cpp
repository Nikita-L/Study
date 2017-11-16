#include "head.h"

class Holiday
{
private:
	string name;
	string season;
public:
	void getINFO();
	void showINFO();
};
void Holiday::getINFO()
{
	cout<<"Enter name: ";
	cin>>name;
	cout<<"Enter season: ";
	cin>>season;
}
void Holiday::showINFO()
{
	cout<<"Name: "<<name<<endl;
	cout<<"Season: "<<season<<endl;
}
int main()
{
	Holiday num_1;   // 1 способ
	num_1.getINFO();
	cout<<endl;
	num_1.showINFO();
	cout<<endl<<endl;

	Holiday* num_2;  // 2 способ
	num_2=new Holiday;
	num_2->getINFO();
	cout<<endl;
	num_2->showINFO();

	cout<<endl;
	system("pause");
	return 0;
}