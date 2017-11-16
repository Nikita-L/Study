#include "head.h"

usi additional_stack()
{
	string	answer;
	usi		i = 1;
	list<char> additional_list;
	part1_stack_use_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // �������� �������
		{
			system("CLS");
			additional_list.push_back(getch());
			part1_stack_use_menu();
		}
		else if (answer == "2") // ������� �������
		{
			if (!additional_list.empty())
				additional_list.pop_back();
			part1_stack_use_menu();
		}
		else if (answer == "3") // ����������� ����
		{
			system("CLS");
			copy(additional_list.begin(), additional_list.end(), ostream_iterator<char>(cout));
			getch();
			part1_stack_use_menu();
		}
		else if (answer == "0") // �����
			return 1;
		else
			part1_stack_use_menu();
	}
}
usi additional_queue()
{
	string	answer;
	usi		i = 1;
	list<char> additional_list;
	part1_queue_use_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // �������� �������
		{
			system("CLS");
			additional_list.push_back(getch());
			part1_queue_use_menu();
		}
		else if (answer == "2") // ������� �������
		{
			if (!additional_list.empty())
				additional_list.pop_front();
			part1_queue_use_menu();
		}
		else if (answer == "3") // ����������� �������
		{
			system("CLS");
			copy(additional_list.begin(), additional_list.end(), ostream_iterator<char>(cout));
			getch();
			part1_queue_use_menu();
		}
		else if (answer == "0") // �����
			return 1;
		else
			part1_queue_use_menu();
	}
}