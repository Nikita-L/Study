#include "head.h"

void part2_data_get(li* A, li* B, li* C, li* D, li* E, li* F)
{
	usi i = 0;
	bool check;
	string temp;
	system("CLS");
	while (!i)
	{
		cout << "A = ";
		cin >> temp;
		check = 0;
		for (usi j=0; j < temp.length(); j++)
			if (temp[j] < 48 || temp[j] > 57)
				check = 1;
		if (!check)
		{
			i = 1;
			*A = stoi(temp);
		}
		system("CLS");
	}
	i = 0;
	while (!i)
	{
		cout << "A = " << *A << endl << "B = ";
		cin >> temp;
		check = 0;
		for (usi j=0; j < temp.length(); j++)
			if (temp[j] < 48 || temp[j] > 57)
				check = 1;
		if (!check)
		{
			i = 1;
			*B = stoi(temp);
		}
		system("CLS");
	}
	i = 0;
	while (!i)
	{
		cout << "A = " << *A << endl << "B = " << *B << endl << "C = ";
		cin >> temp;
		check = 0;
		for (usi j=0; j < temp.length(); j++)
			if (temp[j] < 48 || temp[j] > 57)
				check = 1;
		if (!check)
		{
			i = 1;
			*C = stoi(temp);
		}
		system("CLS");
	}
	i = 0;
	while (!i)
	{
		cout << "A = " << *A << endl << "B = " << *B << endl << "C = " << *C << endl << "D = ";
		cin >> temp;
		check = 0;
		for (usi j=0; j < temp.length(); j++)
			if (temp[j] < 48 || temp[j] > 57)
				check = 1;
		if (!check)
		{
			i = 1;
			*D = stoi(temp);
		}
		system("CLS");
	}
	i = 0;
	while (!i)
	{
		cout << "A = " << *A << endl << "B = " << *B << endl << "C = " << *C << endl << "D = " << *D << endl << "E = ";
		cin >> temp;
		check = 0;
		for (usi j=0; j < temp.length(); j++)
			if (temp[j] < 48 || temp[j] > 57)
				check = 1;
		if (!check)
		{
			i = 1;
			*E = stoi(temp);
		}
		system("CLS");
	}
	i = 0;
	while (!i)
	{
		cout << "A = " << *A << endl << "B = " << *B << endl << "C = " << *C << endl << "D = " << *D << endl << "E = " << *E<< endl << "F = ";
		cin >> temp;
		check = 0;
		for (usi j=0; j < temp.length(); j++)
			if (temp[j] < 48 || temp[j] > 57)
			{
				system("CLS");
				check = 1;
			}
			if (!check)
			{
				i = 1;
				*F = stoi(temp);
			}
	}
}
void part2_formula1(li A, li B, li C, li D, li E, li F)
{
	partsList stack_list;
	if (D == 0)
	{
		system("CLS");
		cout << "Нельзя делить на 0";
		getch();
		part2_menu();
		return;
	}
	string s_A = part2_inttostr(A);
	string s_B = part2_inttostr(B);
	string s_C = part2_inttostr(C);
	string s_D = part2_inttostr(D);
	string s_E = part2_inttostr(E);
	string s_F = part2_inttostr(F);
	stack_list.part2_stack_add(s_A);
	stack_list.part2_stack_add(s_B);
	stack_list.part2_stack_add("-");
	stack_list.part2_stack_add(s_C);
	stack_list.part2_stack_add("-");
	stack_list.part2_stack_add(s_D);
	stack_list.part2_stack_add("/");
	stack_list.part2_stack_add(s_E);
	stack_list.part2_stack_add(s_F);
	stack_list.part2_stack_add("*");
	stack_list.part2_stack_add("-");
	stack_list.part2_stack_show();
	stack_list.~partsList();
}
void part2_formula2(li A, li B, li C, li D, li E, li F)
{
	partsList stack_list;
	if (F == 0)
	{
		system("CLS");
		cout << "Нельзя делить на 0";
		getch();
		part2_menu();
		return;
	}
	string s_A = part2_inttostr(A);
	string s_B = part2_inttostr(B);
	string s_C = part2_inttostr(C);
	string s_D = part2_inttostr(D);
	string s_E = part2_inttostr(E);
	string s_F = part2_inttostr(F);
	stack_list.part2_stack_add(s_A);
	stack_list.part2_stack_add(s_B);
	stack_list.part2_stack_add("+");
	stack_list.part2_stack_add(s_C);
	stack_list.part2_stack_add("*");
	stack_list.part2_stack_add(s_D);
	stack_list.part2_stack_add(s_E);
	stack_list.part2_stack_add("+");
	stack_list.part2_stack_add(s_F);
	stack_list.part2_stack_add("/");
	stack_list.part2_stack_add("-");
	stack_list.part2_stack_show();
	stack_list.~partsList();
}
void part2_formula3(li A, li B, li C, li D, li E, li F)
{
	partsList stack_list;
	if (B == C)
	{
		system("CLS");
		cout << "Нельзя делить на 0";
		getch();
		part2_menu();
		return;
	}
	string s_A = part2_inttostr(A);
	string s_B = part2_inttostr(B);
	string s_C = part2_inttostr(C);
	string s_D = part2_inttostr(D);
	string s_E = part2_inttostr(E);
	string s_F = part2_inttostr(F);
	stack_list.part2_stack_add(s_A);
	stack_list.part2_stack_add(s_B);
	stack_list.part2_stack_add(s_C);
	stack_list.part2_stack_add("-");
	stack_list.part2_stack_add("/");
	stack_list.part2_stack_add(s_D);
	stack_list.part2_stack_add(s_E);
	stack_list.part2_stack_add(s_F);
	stack_list.part2_stack_add("-");
	stack_list.part2_stack_add("*");
	stack_list.part2_stack_add("+");
	stack_list.part2_stack_show();
	stack_list.~partsList();
}
void part2_formula4(li A, li B, li C, li D, li E, li F)
{
	partsList stack_list;
	if (E == 0 || D == 0)
	{
		system("CLS");
		cout << "Нельзя делить на 0";
		getch();
		part2_menu();
		return;
	}
	string s_A = part2_inttostr(A);
	string s_B = part2_inttostr(B);
	string s_C = part2_inttostr(C);
	string s_D = part2_inttostr(D);
	string s_E = part2_inttostr(E);
	string s_F = part2_inttostr(F);
	stack_list.part2_stack_add(s_A);
	stack_list.part2_stack_add(s_B);
	stack_list.part2_stack_add("*");
	stack_list.part2_stack_add(s_C);
	stack_list.part2_stack_add("+");
	stack_list.part2_stack_add(s_D);
	stack_list.part2_stack_add("/");
	stack_list.part2_stack_add(s_F);
	stack_list.part2_stack_add(s_E);
	stack_list.part2_stack_add("/");
	stack_list.part2_stack_add("-");
	stack_list.part2_stack_show();
	stack_list.~partsList();
}
void partsList::part2_stack_add(string key)
{
	stringstream ss;
	data_str *temp = new data_str;
	if (key[0] < 48 || key[0] > 57)
	{
		if (key[0] == 45) // -
		{
			temp->key = part2_inttostr(stol(end_str->prev->key) - stol(end_str->key));
			if (end_str->prev == begin_str)
			{
				delete end_str->prev;
				delete end_str;
				begin_str = temp;
				begin_str->prev = nullptr;
				begin_str->next = nullptr;
				end_str = begin_str;
				return;
			}
			end_str->prev->prev->next = temp;
			temp->prev = end_str->prev->prev;
			temp->next = nullptr;
			delete end_str->prev;
			delete end_str;
			end_str = temp;
			return;
		}
		else if (key[0] == 43) // +
		{
			temp->key = part2_inttostr(stol(end_str->prev->key) + stol(end_str->key));
			if (end_str->prev == begin_str)
			{
				delete end_str->prev;
				delete end_str;
				begin_str = temp;
				begin_str->prev = nullptr;
				begin_str->next = nullptr;
				end_str = begin_str;
				return;
			}
			end_str->prev->prev->next = temp;
			temp->prev = end_str->prev->prev;
			temp->next = nullptr;
			delete end_str->prev;
			delete end_str;
			end_str = temp;
			return;
		}
		else if (key[0] == 47) // /
		{
			temp->key = part2_inttostr(stol(end_str->prev->key) / stol(end_str->key));
			if (end_str->prev == begin_str)
			{
				delete end_str->prev;
				delete end_str;
				begin_str = temp;
				begin_str->prev = nullptr;
				begin_str->next = nullptr;
				end_str = begin_str;
				return;
			}
			end_str->prev->prev->next = temp;
			temp->prev = end_str->prev->prev;
			temp->next = nullptr;
			delete end_str->prev;
			delete end_str;
			end_str = temp;
			return;
		}
		else if (key[0] == 42) // *
		{
			temp->key = part2_inttostr(stol(end_str->prev->key) * stol(end_str->key));
			if (end_str->prev == begin_str)
			{
				delete end_str->prev;
				delete end_str;
				begin_str = temp;
				begin_str->prev = nullptr;
				begin_str->next = nullptr;
				end_str = begin_str;
				return;
			}
			end_str->prev->prev->next = temp;
			temp->prev = end_str->prev->prev;
			temp->next = nullptr;
			delete end_str->prev;
			delete end_str;
			end_str = temp;
			return;
		}
	}
	if (!begin_str)
	{
		temp->key = key;
		temp->next = nullptr;
		temp->prev = nullptr;
		begin_str = temp;
		end_str = temp;
		return;
	}
	temp->key = key;
	end_str->next = temp;
	temp->prev = end_str;
	temp->next = nullptr;
	end_str = temp;
}
void partsList::part2_stack_show()
{
	system("CLS");
	if (begin_str)
	{
		data_str *temp = begin_str;
		while (temp)
		{
			cout << temp->key;
			temp = temp->next;
		}
	}
	getch();
}
string part2_inttostr(li elem)
{
	stringstream ss;
	ss << elem;
	string s_elem;
	ss >> s_elem;
	return s_elem;
}