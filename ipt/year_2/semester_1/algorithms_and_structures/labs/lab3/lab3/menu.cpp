#include "head.h"

void menu()
{
	cout << "///////////////////////////////////////////" << endl
		<< "                                         //" << endl
		<< "                                         //" << endl 
		<< "                 Welcome!                //" << endl
		<< "                                         //" << endl 
		<< "                                         //" << endl 
		<< "                                         //" << endl
		<< "///////////////////////////////////////////" << endl;
	Sleep(500);
	system("CLS");
	int t=0;
	cout << "///////////////////////////////////////////" << endl
		<< "                                         //" << endl
		<< "Choose the action:                       //" << endl 
		<< "1. Create a text using massive           //" << endl
		<< "2. Create a text using list              //" << endl 
		<< "0. Exit the program                      //" << endl 
		<< "                                         //" << endl
		<< "///////////////////////////////////////////" << endl
		<< endl <<"Your choice: ";
	while (t!=5)
	{
		string ans;
		cin>> ans;
		if (ans == "1") // Create text using massive
		{
			t=mass();
			if (t==0)
			{
				system("CLS");
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl
					<< "Choose the action:                       //" << endl 
					<< "1. Create a text using massive           //" << endl
					<< "2. Create a text using list              //" << endl 
					<< "0. Exit the program                      //" << endl 
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl
					<< endl <<"Your choice: ";
			}
			else
			{
				system("CLS");
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl 
					<< "     Thank you for using my program!     //" << endl 
					<< "                                         //" << endl 
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl;
				Sleep(500);
				system("CLS");
			}
		}
		else if (ans=="2") // Create text using list
		{
			t=ls();
			if (t==0)
			{
				system("CLS");
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl
					<< "Choose the action:                       //" << endl 
					<< "1. Create a text using massive           //" << endl
					<< "2. Create a text using list              //" << endl 
					<< "0. Exit the program                      //" << endl 
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl
					<< endl <<"Your choice: ";
			}
			else
			{
				system("CLS");
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl 
					<< "     Thank you for using my program!     //" << endl 
					<< "                                         //" << endl 
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl;
				Sleep(500);
				system("CLS");
			}
		}
		else if (ans=="0") // Exit
		{
			system("CLS");
			cout << "///////////////////////////////////////////" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl 
				<< "     Thank you for using my program!     //" << endl 
				<< "                                         //" << endl 
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "///////////////////////////////////////////" << endl;
			Sleep(500);
			system("CLS");
			t=5;
		}
		else
		{
			system("CLS");
			t++;
			if (t==1)
			{
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl 
					<< "        You can enter 1, 2 or 0          //" << endl
					<< "                                         //" << endl 
					<< "                                         //" << endl 
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl;
				Sleep(1500);
				system("CLS");
			}
			if (t!=5)
			{
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl
					<< "Choose the action:                       //" << endl 
					<< "1. Create a text using massive           //" << endl
					<< "2. Create a text using list              //" << endl 
					<< "0. Exit the program                      //" << endl 
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl
					<< endl <<"Your choice ("<<5-t<<" tries left): ";
			}
			else
			{
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl 
					<< "     Thank you for using my program!     //" << endl 
					<< "                                         //" << endl 
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl;
				Sleep(500);
				system("CLS");
			}
		}
	}
}
