#include "head.h"

int main()
{
	for (int i=0; i<=5;)
	{
		cout<<"////////////////////////"<<endl<<"1. Use class          //"<<endl<<"2. Use extra class    //"<<endl<<"0. Exit               //"<<endl<<"////////////////////////"<<endl;
		int choice1;
		cin>>choice1;
		switch (choice1)
		{
		case 1: // ~~~~~~~~~~ �������� ����� ~~~~~~~~~~
			{
				Point p1;	// ����������� �� ���������
				p1.showPoint();
				Point p2(1, 1); // ����������� � ����������
				Point p3=p2; // ����������� �����������
				p2.showPoint();
				p3.showPoint();
				Point p4(4, 5);
				p1.Distance(p1, p4); // ���������� ����� 2 �������
				p1.Plus(p3,p4); // ����� ���������
				Point p5;
				p5.getPoint(); // ����
				p5.showPoint(); // �����
				p1.IdentityCheck(p5, p4); // �������� ���������� 2 �����
			
				break;
			}
		case 2: // ~~~~~~~~~~ ����������� ����� ~~~~~~~~~~
			{
				ExtraPoint p6;	// ����������� �� ���������
				p6.showPoint();
				ExtraPoint p7(1, 1, "green"); // ����������� � ����������
				ExtraPoint p8=p7; // ����������� �����������
				p7.showPoint();
				p8.showPoint();
				ExtraPoint p9(4, 5, "white");
				p6.Distance(p6, p9); // ���������� ����� 2 �������
				p6.Plus(p8,p9); // ����� ���������
				ExtraPoint p10;
				p10.getPoint(); // ����
				p10.showPoint(); // �����
				p6.IdentityCheck(p10, p9); // �������� ���������� 2 �����
				
				break;
			}
		case 0:
			i=6;
			break;
		default:
			i++;
			break;
		}
	}

	



	
	

	cout<<endl;
	system("pause");
	return 0;
}