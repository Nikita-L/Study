#include "head.h"

short mass()
{
	system("CLS");
	cout << "///////////////////////////////////////////" << endl
		<< "                                         //" << endl
		<< "      Enter 100 small latin letters,     //" << endl 
		<< "         end text with a point!          //" << endl 
		<< "     (Push \"0\" to exit the program)      //" << endl
		<< "     (Push \"9\" to get to the menu)       //" << endl
		<< "                                         //" << endl
		<< "///////////////////////////////////////////" << endl;
	Sleep(1500);
	system("CLS");
	unsigned char a;
	char mass_text[101];
	bool good = 1;
	bool good1 = 1;
	unsigned int size = 0;

	for (int i=0; i<100; ) 
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
				return 5;
			else if (a == 57) // Back to menu
				return 0;
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
					Sleep(1500);
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
					Sleep(1500);
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
					if (good5==0)
					{
						for (int q=m; q<size; q++)
							mass_text[q]=mass_text[q+1];
					}
					i=100;
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
	short t = mass_menu_1(mass_text, size);
	if (t == 9)
	{
		return 0;
	}
	if (t == 0)
	{
		return 5;
	}
}