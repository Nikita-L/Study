#include "head.h"

usi part1_stack()
{
	string	answer;
	usi		j, i = 1;
	part1_use_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // Использовать массив
		{
			j = part1_stack_mass();
			if (j == 1)
				part1_use_menu();
			else
				return 0;
		}
		else if (answer == "2") // Использовать список
		{
			j = part1_stack_list();
			if (j == 1)
				part1_use_menu();
			else
				return 0;
		}
		else if (answer == "0") // Назад
			return 1;
		else
			part1_use_menu();
	}
}
usi part1_stack_mass()
{
	string	answer;
	usi		i = 1;
	char	*stack_mass = nullptr;
	usi		size = 0;
	part1_stack_use_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // Добавить элемент
		{
			part1_stack_mass_add(&stack_mass, &size);
			part1_stack_use_menu();
		}
		else if (answer == "2") // Удалить элемент
		{
			part1_stack_mass_del(&stack_mass, &size);
			part1_stack_use_menu();
		}
		else if (answer == "3") // Просмотреть стэк
		{
			part1_stack_mass_show(stack_mass, size);
			part1_stack_use_menu();
		}
		else if (answer == "0") // Назад
		{
			mass_delete(stack_mass);
			return 1;
		}
		else
			part1_stack_use_menu();
	}
}
void part1_stack_mass_add(char** stack_mass, usi* size)
{
	system("CLS");
	if (*size == 0)
	{
		(*size)++;
		*stack_mass = new char [1];
		(*stack_mass)[0] = getch();
	}
	else
	{
		char* temp = new char [*size];
		for (usi i = 0; i < *size; i++)
			temp[i] = (*stack_mass)[i];
		delete [] (*stack_mass);
		(*size)++;
		*stack_mass = new char [*size];
		for (usi i = 0; i < (*size-1); i++)
			(*stack_mass)[i] = temp[i];
		delete [] temp;
		(*stack_mass)[*size-1] = getch();
	}
}
void part1_stack_mass_del(char** stack_mass, usi* size)
{
	if (*size == 0)
	{
		system("CLS");
		cout << "Стек пуст";
		getch();
	}
	else
	{
		(*size)--;
		if (*size == 0)
		{
			delete [] *stack_mass;
			*stack_mass = nullptr;
			return;
		}
		char* temp = new char [*size];
		for (usi i = 0; i < *size; i++)
			temp[i] = (*stack_mass)[i];
		delete [] *stack_mass;
		*stack_mass = new char [*size];
		for (usi i = 0; i < *size; i++)
			(*stack_mass)[i] = temp[i];
		delete [] temp;
	}
}
void part1_stack_mass_show(char* stack_mass, usi size)
{
	system("CLS");
	if (size != 0)
	{
		for (usi i = 0; i < size; i++)
			cout << stack_mass[i];
	}
	getch();
}
void mass_delete(char* mass)
{
	if (mass)
	{
		delete [] mass;
		mass = nullptr;
	}
}
usi part1_stack_list()
{
	string	answer;
	usi		i = 1;
	partsList stack_list;
	part1_stack_use_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // Добавить элемент
		{
			stack_list.part1_stack_list_add();
			part1_stack_use_menu();
		}
		else if (answer == "2") // Удалить элемент
		{
			stack_list.part1_stack_list_del();
			part1_stack_use_menu();
		}
		else if (answer == "3") // Просмотреть стэк
		{
			stack_list.part1_stack_list_show();
			part1_stack_use_menu();
		}
		else if (answer == "0") // Назад
		{
			stack_list.~partsList();
			return 1;
		}
		else
			part1_stack_use_menu();
	}
}
partsList::~partsList()
{
	if (begin)
	{
		while (end)
		{
			data *temp = end->prev;
			delete end;
			end = temp;
		}
	}
	if (begin_str)
		while (end_str)
		{
			data_str *temp_str = end_str->prev;
			delete end_str;
			end_str = temp_str;
		}
}
void partsList::part1_stack_list_add()
{
	system("CLS");
	if (!begin)
	{
		data *temp = new data;
		temp->key = getch();
		temp->next = nullptr;
		temp->prev = nullptr;
		begin = temp;
		end = temp;
		return;
	}
	data *temp = new data;
	temp->key = getch();
	end->next = temp;
	temp->prev = end;
	temp->next = nullptr;
	end = temp;
}
void partsList::part1_stack_list_del()
{
	if (!begin)
	{
		cout << "Стек пуст";
		getch();
		return;
	}
	if (!end->prev)
	{
		delete end;
		begin = nullptr;
		end = nullptr;
		return;
	}
	end = end->prev;
	delete end->next;
	end->next = nullptr;
}
void partsList::part1_stack_list_show()
{
	system("CLS");
	if (begin)
	{
		data *temp = begin;
		while (temp)
		{
			cout << temp->key;
			temp = temp->next;
		}
	}
	getch();
}
usi part1_queue()
{
	string	answer;
	usi		j, i = 1;
	part1_use_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // Использовать массив
		{
			j = part1_queue_mass();
			if (j == 1)
				part1_use_menu();
			else
				return 0;
		}
		else if (answer == "2") // Использовать список
		{
			j = part1_queue_list();
			if (j == 1)
				part1_use_menu();
			else
				return 0;
		}
		else if (answer == "0") // Назад
			return 1;
		else
			part1_use_menu();
	}
}
usi part1_queue_mass()
{
	string	answer;
	usi		i = 1;
	usi		size = 0, begin = 2, end = 2;
	char	*queue_mass = nullptr;
	part1_queue_use_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // Добавить элемент
		{
			part1_queue_mass_add(&queue_mass, &size, &begin, &end);
			part1_queue_use_menu();
		}
		else if (answer == "2") // Удалить элемент
		{
			part1_queue_mass_del(&queue_mass, &size, &begin, &end);
			part1_queue_use_menu();
		}
		else if (answer == "3") // Просмотреть очередь
		{
			part1_queue_mass_show(queue_mass, size, begin, end);
			part1_queue_use_menu();
		}
		else if (answer == "0") // Назад
		{
			mass_delete(queue_mass);
			return 1;
		}
		else
			part1_queue_use_menu();
	}
}
void part1_queue_mass_add(char** queue_mass, usi* size, usi* begin, usi* end)
{
	system("CLS");
	if (*size == 0)
	{
		*size = 5;
		*queue_mass = new char [5];
		(*queue_mass)[2] = getch();
		*end = 3;
		return;
	}
	if ((*end + 1) == *begin || ((*end + 1) == 5 && (*begin == 0)))
	{
		char *temp = new char [*size + 1];
		for (usi i = 0; i < *size; i++)
			temp[i] = (*queue_mass)[i];
		delete [] *queue_mass;
		if (*end != *size - 1)
		{
			for (usi i = *size - 1; i >= *begin; i--)
				temp[i+1] = temp[i];
			(*begin)++;
		}
		(*size)++;
		temp[*end] = getch();
		(*end)++;
		*queue_mass = new char [*size];
		for (usi i = 0; i < *size; i++)
			(*queue_mass)[i] = temp[i];
		delete [] temp;
	}
	else
	{
		(*queue_mass)[*end] = getch();
		*end == *size - 1 ? (*end) = 0 : (*end)++;
	}
}
void part1_queue_mass_del(char** queue_mass, usi* size, usi* begin, usi* end)
{
	if (*size == 0)
	{
		system("CLS");
		cout << "Очередь пуста";
		getch();
		return;
	}
	if (*begin + 1 == *end || (*begin + 1 == 5 && *end == 0))
	{
		delete [] *queue_mass;
		*queue_mass = nullptr;
		*begin = 2;
		*end = 2;
		*size = 0;
		return;
	}
	if (*size > 5)
	{
		if (*begin != *size - 1)
		{
			for (usi i = *begin; i < *size - 1; i++)
				(*queue_mass)[i] = (*queue_mass)[i+1];
			*end == 0 ? *end = *size - 2 : (*end)--;
		}
		else
			(*begin) = 0;
		(*size)--;
		char *temp = new char [*size];
		for (usi i = 0; i < *size; i++)
			temp[i] = (*queue_mass)[i];
		delete [] *queue_mass;
		*queue_mass = new char [*size];
		for (usi i = 0; i < *size; i++)
			(*queue_mass)[i] = temp[i];
		delete [] temp;
	}
	else
		*begin == *size - 1 ? *begin = 0 : (*begin)++;
}
void part1_queue_mass_show(char* queue_mass, usi size, usi begin, usi end)
{
	system("CLS");
	if (end != begin)
	{
		for (usi i = begin; i != end; )
		{
			cout << queue_mass[i];
			i == size - 1 ? i = 0 : i++;
		}
	}
	getch();
}
usi part1_queue_list()
{
	string	answer;
	usi		i = 1;
	partsList queue_list;
	part1_queue_use_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // Добавить элемент
		{
			queue_list.part1_stack_list_add();
			part1_queue_use_menu();
		}
		else if (answer == "2") // Удалить элемент
		{
			queue_list.part1_queue_list_del();
			part1_queue_use_menu();
		}
		else if (answer == "3") // Просмотреть очередь
		{
			queue_list.part1_stack_list_show();
			part1_queue_use_menu();
		}
		else if (answer == "0") // Назад
		{
			queue_list.~partsList();
			return 1;
		}
		else
			part1_queue_use_menu();
	}
}
void partsList::part1_queue_list_del()
{
	if (!begin)
	{
		system("CLS");
		cout << "Очередь пуста";
		getch();
		return;
	}
	if (!begin->next)
	{
		delete begin;
		begin = nullptr;
		end = nullptr;
		return;
	}
	begin = begin->next;
	delete begin->prev;
	begin->prev = nullptr;
}
usi part1_2stacks1mass()
{
	string	answer;
	usi		i = 1;
	usi		stack1_size = 0, stack2_size = 0;
	char	*stacks_mass = nullptr;
	part1_2stacks1mass_menu();
	while (i)
	{
		cin >> answer;
		if (answer == "1") // Добавить элемент в первый стэк
		{
			part1_2stacks1mass_stack1_add(&stacks_mass, &stack1_size, &stack2_size);
			part1_2stacks1mass_menu();
		}
		else if (answer == "2") // Удалить элемент из первого стэка
		{
			part1_2stacks1mass_stack1_del(&stacks_mass, &stack1_size, &stack2_size);
			part1_2stacks1mass_menu();
		}
		else if (answer == "3") // Добавить элемент во второй стэк
		{
			part1_2stacks1mass_stack2_add(&stacks_mass, &stack1_size, &stack2_size);
			part1_2stacks1mass_menu();
		}
		else if (answer == "4") // Удалить элемент из второго стэка
		{
			part1_2stacks1mass_menu();
			part1_2stacks1mass_stack2_del(&stacks_mass, &stack1_size, &stack2_size);
		}
		else if (answer == "5") // Просмотреть первый стэк
		{
			part1_2stacks1mass_stack1_show(stacks_mass, stack1_size);
			part1_2stacks1mass_menu();
		}
		else if (answer == "6") // Просмотреть второй стэк
		{
			part1_2stacks1mass_stack2_show(stacks_mass, stack1_size, stack2_size);
			part1_2stacks1mass_menu();
		}
		else if (answer == "7") // Просмотреть массив
		{
			part1_2stacks1mass_stacks_show(stacks_mass, stack1_size, stack2_size);
			part1_2stacks1mass_menu();
		}
		else if (answer == "0") // Назад
			return 1;
		else
			part1_2stacks1mass_menu();
	}
}
void part1_2stacks1mass_stack1_add(char** stacks_mass, usi* stack1_size, usi* stack2_size)
{
	system("CLS");
	if (!*stacks_mass)
	{
		(*stack1_size)++;
		*stacks_mass = new char [1];
		(*stacks_mass)[0] = getch();
		return;
	}
	char* temp = new char [*stack1_size + *stack2_size];
	for (usi i = 0; i < *stack1_size + *stack2_size; i++)
		temp[i] = (*stacks_mass)[i];
	delete [] (*stacks_mass);
	(*stack1_size)++;
	*stacks_mass = new char [*stack1_size + *stack2_size];
	for (usi i = 1; i < *stack1_size + *stack2_size; i++)
		(*stacks_mass)[i] = temp[i-1];
	delete [] temp;
	(*stacks_mass)[0] = getch();
}
void part1_2stacks1mass_stack1_del(char** stacks_mass, usi* stack1_size, usi* stack2_size)
{
	if (*stack1_size == 0)
	{
		system("CLS");
		cout << "Стек пуст";
		getch();
		return;
	}
	(*stack1_size)--;
	if (*stack1_size + *stack2_size == 0)
	{
		delete [] *stacks_mass;
		*stacks_mass = nullptr;
		return;
	}
	char* temp = new char [*stack1_size + *stack2_size];
	for (usi i = 1; i < *stack1_size + *stack2_size + 1; i++)
		temp[i-1] = (*stacks_mass)[i];
	delete [] *stacks_mass;
	*stacks_mass = new char [*stack1_size + *stack2_size];
	for (usi i = 0; i < *stack1_size + *stack2_size; i++)
		(*stacks_mass)[i] = temp[i];
	delete [] temp;
}
void part1_2stacks1mass_stack1_show(char* stacks_mass, usi stack1_size)
{
	system("CLS");
	if (stack1_size != 0)
	{
		for (short i = stack1_size - 1; i >= 0; i--)
			cout << stacks_mass[i];
	}
	getch();
}
void part1_2stacks1mass_stack2_add(char** stacks_mass, usi* stack1_size, usi* stack2_size)
{
	system("CLS");
	if (!*stacks_mass)
	{
		(*stack2_size)++;
		*stacks_mass = new char [1];
		(*stacks_mass)[0] = getch();
		return;
	}
	char* temp = new char [*stack1_size + *stack2_size];
	for (usi i = 0; i < *stack1_size + *stack2_size; i++)
		temp[i] = (*stacks_mass)[i];
	delete [] (*stacks_mass);
	(*stack2_size)++;
	*stacks_mass = new char [*stack1_size + *stack2_size];
	for (usi i = 0; i < (*stack1_size + *stack2_size - 1); i++)
		(*stacks_mass)[i] = temp[i];
	delete [] temp;
	(*stacks_mass)[*stack1_size + *stack2_size - 1] = getch();
}
void part1_2stacks1mass_stack2_del(char** stacks_mass, usi* stack1_size, usi* stack2_size)
{
	if (*stack2_size == 0)
	{
		system("CLS");
		cout << "Стек пуст";
		getch();
		return;
	}
	(*stack2_size)--;
	if (*stack1_size + *stack2_size == 0)
	{
		delete [] *stacks_mass;
		*stacks_mass = nullptr;
		return;
	}
	char* temp = new char [*stack1_size + *stack2_size];
	for (usi i = 0; i < *stack1_size + *stack2_size; i++)
		temp[i] = (*stacks_mass)[i];
	delete [] *stacks_mass;
	*stacks_mass = new char [*stack1_size + *stack2_size];
	for (usi i = 0; i < *stack1_size + *stack2_size; i++)
		(*stacks_mass)[i] = temp[i];
	delete [] temp;
}
void part1_2stacks1mass_stack2_show(char* stacks_mass, usi stack1_size, usi stack2_size)
{
	system("CLS");
	if (stack2_size != 0)
	{
		for (usi i = stack1_size; i < (stack1_size + stack2_size); i++)
			cout << stacks_mass[i];
	}
	getch();
}
void part1_2stacks1mass_stacks_show(char* stacks_mass, usi stack1_size, usi stack2_size)
{
	system("CLS");
	if (stack1_size + stack2_size != 0)
	{
		for (usi i = 0; i < stack1_size + stack2_size; i++)
			cout << stacks_mass[i];
	}
	getch();
}