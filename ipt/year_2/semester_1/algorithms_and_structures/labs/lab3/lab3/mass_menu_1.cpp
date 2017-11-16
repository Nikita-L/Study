#include "head.h"

short mass_menu_1 (char* mass_text, unsigned int size)
{
	unsigned int size_main= size;
	system ("CLS");
	cout << "///////////////////////////////////////////" << endl
		<< "Choose the action:                       //" << endl 
		<< "1. Show and edit text array              //" << endl 
		<< "2. Apply the function                    //" << endl
		<< "                                         //" << endl
		<< "9. Back to main menu                     //" << endl
		<< "0. Exit the program                      //" << endl
		<< "///////////////////////////////////////////" << endl
		<< endl <<"Your choice: ";
	for (int t1 = 0; t1 < 5; )
	{
		string ch;
		cin>>ch;
		if (ch == "9") // Back to main menu
			return 9;
		else if (ch == "0") // Exit
			return 0;
		else if (ch == "1") // Show and edit
		{
			system("CLS");
			cout << "///////////////////////////////////////////" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "      Push \"0\" to exit the program       //" << endl
				<< "      Push \"9\" to get to the menu        //" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "///////////////////////////////////////////" << endl;
			Sleep(1500);
			system("CLS");
			unsigned char a;
			bool good = 1;
			bool good1 = 1;
			bool good5 = 1;
			int m = 0;
			for (int o = 0; o < size + 1; o++)
			{
				if (mass_text[o] == '<')
				{
					good5 = 0;
					m = o;
				}
			}
			if (good5==0)
			{
				for (int q=m; q<size; q++)
					mass_text[q]=mass_text[q+1];
			}
			if (size==100)
			{
				system("CLS");
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "     You have entered 100 elements!      //" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl;
				Sleep(1500);
				system("CLS");
			}
			for (int k = 0; k<size; k++)
			{
				cout<<mass_text[k];
			}
			if (size<101)
			{
				int i=size;
				do
				{
					bool good5 = 1;
					int m = 0;
					for (int o = 0; o < size + 1; o++)
					{
						if (mass_text[o] == '<')
						{
							good5 = 0;
							m = o;
						}
					}
					a = getch();
					if (!kbhit())
					{
						if ((a>=97 && a<=122 || a==32 || a==46) && size<100) // Small latin letters
						{
							if (good5==1)
							{
								putchar (a);
								mass_text[i]=a;
								size++;
								i++;
								if (size==100)
								{
									bool non_space=1;
									for (int k=0; k<size; k++)
									{
										if (mass_text[k]!=32)
										{
											non_space=0;
										}
									}
									if (non_space==1)
									{
										system("CLS");
										cout << "///////////////////////////////////////////" << endl
											<< "                                         //" << endl
											<< "       You have to enter something!      //" << endl 
											<< "                                         //" << endl
											<< "     (Push \"0\" to exit the program)      //" << endl
											<< "     (Push \"9\" to get to the menu)       //" << endl
											<< "                                         //" << endl
											<< "///////////////////////////////////////////" << endl;
										Sleep(1500);
										system("CLS");
										i=0;
										size=0;
									}
									else
									{
										system("CLS");
										cout << "///////////////////////////////////////////" << endl
											<< "                                         //" << endl
											<< "                                         //" << endl
											<< "     You have entered 100 elements!      //" << endl
											<< "                                         //" << endl
											<< "                                         //" << endl
											<< "                                         //" << endl
											<< "///////////////////////////////////////////" << endl;
										Sleep(1500);
										system("CLS");
										if (good5==0)
										{
											for (int q=m; q<size; q++)
												mass_text[q]=mass_text[q+1];
										}
										i=100;
										system ("CLS");
										cout << "///////////////////////////////////////////" << endl
											<< "Choose the action:                       //" << endl 
											<< "1. Show and edit text array              //" << endl 
											<< "2. Apply the function                    //" << endl
											<< "                                         //" << endl
											<< "9. Back to main menu                     //" << endl
											<< "0. Exit the program                      //" << endl
											<< "///////////////////////////////////////////" << endl
											<< endl <<"Your choice: ";
									}
								}
							}
							else
							{
								size++;
								i=m;
								for (int g=size+1; g>=m; g--)
									mass_text[g+1]=mass_text[g];
								mass_text[i]=a;
								i++;
								system("CLS");
								for (int u=0; u<size+1; u++)
								{
									cout<<mass_text[u];
								}
							}
						}
						else if (a == 48) // Exit
							return 0;
						else if (a == 57) // Back to menu
						{
							size=size_main;
							t1=0;
							i=101;
							system ("CLS");
							cout << "///////////////////////////////////////////" << endl
								<< "Choose the action:                       //" << endl 
								<< "1. Show and edit text array              //" << endl 
								<< "2. Apply the function                    //" << endl
								<< "                                         //" << endl
								<< "9. Back to main menu                     //" << endl
								<< "0. Exit the program                      //" << endl
								<< "///////////////////////////////////////////" << endl
								<< endl <<"Your choice: ";
						}
						else if (a == 13) // Enter
						{
							bool non_space=1;
							for (int k=0; k<size; k++)
							{
								if (mass_text[k]!=32)
								{
									non_space=0;
								}
							}
							if (size==0)
							{

								system("CLS");
								cout << "///////////////////////////////////////////" << endl
									<< "                                         //" << endl
									<< "       You have to enter something!      //" << endl 
									<< "                                         //" << endl
									<< "     (Push \"0\" to exit the program)      //" << endl
									<< "     (Push \"9\" to get to the menu)       //" << endl
									<< "                                         //" << endl
									<< "///////////////////////////////////////////" << endl;
								Sleep(5000);
								system("CLS");
							}
							else if (non_space==1)
							{
								system("CLS");
								cout << "///////////////////////////////////////////" << endl
									<< "                                         //" << endl
									<< "       You have to enter something!      //" << endl 
									<< "                                         //" << endl
									<< "     (Push \"0\" to exit the program)      //" << endl
									<< "     (Push \"9\" to get to the menu)       //" << endl
									<< "                                         //" << endl
									<< "///////////////////////////////////////////" << endl;
								Sleep(5000);
								system("CLS");
								for (int j=0; j<size; j++)
								{
									cout<<mass_text[j];
								}
							}
							else
							{
								if (good5==0)
								{
									for (int q=m; q<size; q++)
										mass_text[q]=mass_text[q+1];
								}
								i=100;
								size_main=size;
								system ("CLS");
								cout << "///////////////////////////////////////////" << endl
									<< "Choose the action:                       //" << endl 
									<< "1. Show and edit text array              //" << endl 
									<< "2. Apply the function                    //" << endl
									<< "                                         //" << endl
									<< "9. Back to main menu                     //" << endl
									<< "0. Exit the program                      //" << endl
									<< "///////////////////////////////////////////" << endl
									<< endl <<"Your choice: ";
							}
						}
						else if (a == 8) // Delete
						{
							system("CLS");
							if (size==0 || i==0)
							{
								if (good1==1)
								{
									good1=0;
									cout << "///////////////////////////////////////////" << endl
										<< "                                         //" << endl
										<< "       You have nothing to delete!       //" << endl
										<< "                                         //" << endl 
										<< "     (Push \"0\" to exit the program)      //" << endl
										<< "     (Push \"9\" to get to the menu)       //" << endl
										<< "                                         //" << endl
										<< "///////////////////////////////////////////" << endl;
									Sleep(1500);
									system("CLS");
									bool good3=1;
									for (int o=0; o<size+1; o++)
									{
										if (mass_text[o]=='<')
										{
											for (int r=0; r<size+1; r++)
											{
												cout<<mass_text[r];
											}
											good3=0;
										}
									}
									if (good3)
									{
										for (int r=0; r<size; r++)
										{
											cout<<mass_text[r];
										}
									}
								}
								else
								{
									bool good3=1;
									for (int o=0; o<size+1; o++)
									{
										if (mass_text[o]=='<')
										{
											for (int r=0; r<size+1; r++)
											{
												cout<<mass_text[r];
											}
											good3=0;
										}
									}
									if (good3)
									{
										for (int r=0; r<size; r++)
										{
											cout<<mass_text[r];
										}
									}
								}
							}
							else
							{
								if (i==size)
								{
									i--;
									size--;
									for (int r=0; r<size; r++)
									{
										cout<<mass_text[r];
									}
								}
								else
								{
									for (int o=0; o<size+1; o++)
									{
										if (mass_text[o]=='<')
										{
											mass_text[o-1]='<';
											for (int t=o; t<size; t++)
												mass_text[t]=mass_text[t+1];
											o=size+1;
											i--;
											size--;
										}
									}
									for (int r=0; r<size+1; r++)
									{
										cout<<mass_text[r];
									}
								}
							}
						}
						else 
						{
							if (size==100)
							{
								system("CLS");
								cout << "///////////////////////////////////////////" << endl
									<< "                                         //" << endl
									<< "                                         //" << endl
									<< "     You have entered 100 elements!      //" << endl
									<< "                                         //" << endl
									<< "                                         //" << endl
									<< "                                         //" << endl
									<< "///////////////////////////////////////////" << endl;
								Sleep(1500);
								system("CLS");
								i=100;
								system ("CLS");
								cout << "///////////////////////////////////////////" << endl
									<< "Choose the action:                       //" << endl 
									<< "1. Show and edit text array              //" << endl 
									<< "2. Apply the function                    //" << endl
									<< "                                         //" << endl
									<< "9. Back to main menu                     //" << endl
									<< "0. Exit the program                      //" << endl
									<< "///////////////////////////////////////////" << endl
									<< endl <<"Your choice: ";
							}
							else
							{
								if (good==1)
								{
									good=0;
									system("CLS");
									cout << "///////////////////////////////////////////" << endl
										<< "                                         //" << endl
										<< "         You can enter just small        //" << endl 
										<< "              latin letters!             //" << endl
										<< "     (Push \"0\" to exit the program)      //" << endl
										<< "     (Push \"9\" to get to the menu)       //" << endl
										<< "                                         //" << endl
										<< "///////////////////////////////////////////" << endl;
									Sleep(1500);
									system("CLS");
									bool good4=1;
									for (int o=0; o<size+1; o++)
									{
										if (mass_text[o]=='<')
										{
											for (int r=0; r<size+1; r++)
											{
												cout<<mass_text[r];
											}
											good4=0;
										}
									}
									if (good4)
									{
										for (int r=0; r<size; r++)
										{
											cout<<mass_text[r];
										}
									}
								}
							}
						}
					}
					else if (kbhit() && ( a == 0x00 ||a == 0xE0 ))
					{
						a=getch();
						if (a == 'K') // Left
						{
							if (i!=1&&i!=0)
							{
								system("CLS");

								i--;
								mass_text[i+1]=mass_text[i];
								mass_text[i]='<';

								for (int u=0; u<size+1; u++)
								{
									cout<<mass_text[u];
								}
							}
						}
						else if (a == 'M') // Right
						{
							if (good5==0&&m!=size)
							{
								system("CLS");

								mass_text[i]=mass_text[i+1];
								i++;
								if (i<size)
								{
									mass_text[i]='<';
									for (int u=0; u<size+1; u++)
									{
										cout<<mass_text[u];
									}

								}
								else
								{
									for (int u=0; u<size; u++)
									{
										cout<<mass_text[u];
									}
								}
							}
						}
					}
				}
				while (i<100);
			}
		}
		else if (ch=="2") // Apply the function
		{
			bool good5 = 1;
			int m = 0;
			for (int o = 0; o < size + 1; o++)
			{
				if (mass_text[o] == '<')
				{
					good5 = 0;
					m = o;
				}
			}
			if (good5==0)
			{
				for (int q=m; q<size; q++)
					mass_text[q]=mass_text[q+1];
			}
			system("CLS");
			cout << "///////////////////////////////////////////" << endl
				<< "                                         //" << endl  
				<< "        Press Enter to get back,         //" << endl
				<< "         9 to get to main menu           //" << endl
				<< "               0 to exit                 //" << endl
				<< "                                         //" << endl
				<< "                                         //" << endl
				<< "///////////////////////////////////////////" << endl;
			Sleep(1500);
			system ("CLS");
			// Удаление первой и последней буквы в словах с непарным количеством букв
			int k=0;
			int len=0;
			for (int i=0; i<size; i++)
			{
				if (mass_text[i]==32 || i==size-1)
				{
					int j=i;
					do
					{
						j--;
						if (mass_text[j]==32 || j==0)
						{
							if (j==0 && mass_text[j]!=32)
								k=0;
							else
								k=j+1;
							if (i==size-1 && mass_text[i]!=32)
								i++;
							len=i-k;
							if (len==1)
							{
								for (int p=k; p<size-1; p++)
								{
									mass_text[p]=mass_text[p+1];
								}
								size--;
								i--;
							}
							else
							{
								if (len%2!=0)
								{
									for (int s=k; s<size-1; s++)
									{
										mass_text[s]=mass_text[s+1];
									}
									size--;
									i--;
									for (int s=i-1; s<size-1; s++)
									{
										mass_text[s]=mass_text[s+1];
									}
									size--;
									i--;
								}
							}
						}
					}
					while ( j>0 && mass_text[j]!=32);
				}
			}
			// Отображение слов с непарным количеством букв
			k=0;
			len=0;
			int e=0;
			for (int i=0; i<size; i++)
			{
				if (mass_text[i]==32 || i==size-1)
				{
					int j=i;
					do
					{
						j--;
						if (mass_text[j]==32 || j==0)
						{
							if (j==0 && mass_text[j]!=32)
								k=0;
							else
								k=j+1;
							if (i==size-1 && mass_text[i]!=32)
								e=i;
							else
								e=i-1;
							len=(e+1)-k;
							if (len%2!=0)
							{
								for (int s=k; s<=e; s++)
								{
									cout<<mass_text[s];
								}
								cout<<" ";
							}
						}
					}
					while ( j>0 && mass_text[j]!=32);
				}
			}
			/////////////////////////////////////////////////////////////////////////
			unsigned char ans;
			for (int r=0; r<5; )
			{
				ans = getch();
				if (ans == 13)
				{
					r=5;
					system ("CLS");
					cout << "///////////////////////////////////////////" << endl
						<< "Choose the action:                       //" << endl 
						<< "1. Show and edit text array              //" << endl 
						<< "2. Apply the function                    //" << endl
						<< "                                         //" << endl
						<< "9. Back to main menu                     //" << endl
						<< "0. Exit the program                      //" << endl
						<< "///////////////////////////////////////////" << endl
						<< endl <<"Your choice: ";
				}
				else if (ans == 57)
				{
					return 9;
				}
				else if (ans == 48)
				{
					return 0;
				}
			}
		}
		else
		{
			system("CLS");
			t1++;
			if (t1==1)
			{
				cout << "///////////////////////////////////////////" << endl
					<< "                                         //" << endl
					<< "                                         //" << endl 
					<< "      You can enter 1, 2, 9 or 0         //" << endl
					<< "                                         //" << endl 
					<< "                                         //" << endl 
					<< "                                         //" << endl
					<< "///////////////////////////////////////////" << endl;
				Sleep(1500);
				system("CLS");
			}
			if (t1!=5)
			{
				cout << "///////////////////////////////////////////" << endl
					<< "Choose the action:                       //" << endl 
					<< "1. Show and edit text array              //" << endl 
					<< "2. Apply the function                    //" << endl
					<< "                                         //" << endl
					<< "9. Back to main menu                     //" << endl
					<< "0. Exit the program                      //" << endl
					<< "///////////////////////////////////////////" << endl
					<< endl <<"Your choice ("<<5-t1<<" tries left): ";
			}
			else
				return 0;
		}
	}
}