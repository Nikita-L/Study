#include "head.h"

unsigned int size (List* b)
{
	unsigned int i = 0;
	List* t = b;
	while (t)
	{
		i++;
		t=t->next;
	}
	return i;
}

void show (List* b)
{
	if (b)
	{
		List* t = b;
		while (t)
		{
			cout<<t->key;
			t=t->next;
		}
	}
}

void add_back (List** b, List** e, char key)
{
	List* t = new List;
	t->key = key;
	if (*e)
	{
		if (!arrow(*b))
		{
			putchar (key);
			t->next = nullptr;
			t->prev = *e;
			(*e)->next = t;
			*e = t;
		}
		else
		{
			List* temp = *b;
			while (temp)
			{
				if (temp->key=='<')
				{
					if (temp->prev != nullptr)
					{
						temp->prev->next = t;
						t->prev = temp->prev;
						t->next = temp;
						temp->prev = t;
					}
					else
					{
						*b = t;
						(*b)->prev = nullptr;
						(*b)->next = temp;
						temp->prev = *b;
					}
					system("CLS");
					show(*b);
					return;
				}
				else
					temp = temp->next;
			}
		}
	}
	else
	{
		putchar (key);
		t->next = nullptr;
		t->prev = nullptr;
		*b = t;
		*e = t;
	}
}

void remove_back (List** b, List** e, bool* check_1)
{
	if (!(*e))
	{
		if (!(*check_1))
		{
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
			*check_1 = 1;
		}
	}
	else
	{
		system("CLS");
		if (!arrow(*b))
		{
			if (size(*b)==1)
			{
				list_delete(b);
				*b = nullptr;
				*e = nullptr;
			}
			else
			{
				*e = (*e)->prev;
				delete (*e)->next;
				(*e)->next = nullptr;
				show(*b);
			}
		}
		else
		{
			List* temp = *b;
			while (temp)
			{
				if (temp->key=='<')
				{
					if (temp == *b)
					{
						if (!(*check_1))
						{
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
							*check_1 = 1;
						}
					}
					else
					{
						if (temp->prev != *b)
						{
							List* temp3 = temp->prev->prev;
							temp3->next = temp;
							delete temp->prev;
							temp->prev = temp3;
						}
						else
						{
							delete *b;
							*b = temp;
							(*b)->prev = nullptr;
						}
					}
					show(*b);
					return;
				}
				else
					temp = temp->next;
			}
		}
	}
}

bool arrow (List* b)
{
	if (b)
	{
		List* t = b;
		while (t)
		{
			if (t->key=='<')
				return 1;
			else
				t=t->next;
		}
		return 0;
	}
}

void arrow_left (List** b, List** e)
{
	if (size(*b)>1)
	{
		if (!arrow(*b))
		{
			List* temp = new List;
			temp->key = '<';
			temp->next = *e;
			temp->prev = (*e)->prev;
			(*e)->prev->next = temp;
			(*e)->prev = temp;
			*e = temp->next;
		}
		else
		{
			arrow_position_left (*b);
		}
		system("CLS");
		show (*b);
	}
}

void arrow_position_left (List* b)
{
	List* t = b;
	while (t)
	{
		if (t->key=='<')
		{
			if (t->prev != b)
			{
				t->key = t->prev->key;
				t->prev->key = '<';
			}
			return;
		}
		else
			t=t->next;
	}
}

void arrow_right (List** b, List** e)
{
	if (size(*b)!=0 && arrow(*b))
	{
		arrow_position_right (b, e);
		system("CLS");
		show (*b);
	}
}

void arrow_position_right (List** b, List** e)
{
	List* t = *b;
	while (t)
	{
		if (t->key=='<')
		{
			if (t->next != *e)
			{
				t->key = t->next->key;
				t->next->key = '<';
			}
			else
				hide_arrow (b);
			return;
		}
		else
			t=t->next;
	}
}

void hide_arrow (List** b)
{
	List* t = *b;
	while (t)
	{
		if (t->key=='<')
		{
			if (t->prev != nullptr)
			{
				t->prev->next = t->next;
				t->next->prev = t->prev;
			}
			else
			{
				*b = t->next;
				(*b)->prev = nullptr;
				if (t->next->next != nullptr)
				{
					t->next->next->prev = *b;
					(*b)->next = t->next->next;
				}
				else
					(*b)->next = nullptr;
			}
			return;
		}
		else
			t = t->next;
	}
}

int enter (List* b, bool* check3, bool* check4)
{
	bool check = 0;
	List* t = b;
	while (t)
	{
		if (t->key != ' ')
		{
			check = 1;
			t = nullptr;
		}
		else
			t = t->next;
	}
	if (b==nullptr)
	{
		if (!(*check3))
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
			*check3 = 1;
		}
		return 0;
	}
	else if (check == 0)
	{
		if (!(*check4))
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
			*check4 = 1;
		}
		return 0;
	}
	return 100;
}

void copy_list (List* b, List** b_t, List** e_t)
{
	if (b)
	{
		*b_t = new List;
		(*b_t)->key = b->key;
		(*b_t)->prev = nullptr;
		(*b_t)->next = nullptr;
		*e_t = *b_t;
		if (b->next)
		{
			List* t = b->next;
			List* h = *b_t;
			while (t)
			{
				List* temp = new List;
				temp->key = t->key;
				temp->next = nullptr;
				temp->prev = h;
				h->next = temp;
				h = h->next;
				*e_t = temp;
				(*e_t)->next = nullptr;
				t = t->next;
			}
		}
	}
	else
	{
		*b_t = nullptr;
		*e_t = nullptr;
	}
}

void list_delete (List** b)
{
	if (*b)
	{
		if ((*b)->next)
		{
			List* t = (*b)->next;
			while (t)
			{
				delete t->prev;
				t = t->next;
			}
			delete t;
		}
		else
		{
			delete *b;
		}
	}
	*b = nullptr;
}

void first_last_char_del (List** begin, List** end)
{
	List* temp1 = *begin;
	if (size(*begin) != 0)
	{
		while (temp1)
		{
			int i = 0;
			if (temp1->key != ' ')
			{
				if (temp1->next != nullptr)
				{
					List* temp2 = temp1->next;
					i++;
					while (temp2)
					{
						if (temp2->key == ' ')
						{
							if (i%2 != 0)
							{
								if (temp1 == *begin)
								{
									*begin = temp1->next;
									temp1 = temp1->next;
									delete temp1->prev;
									temp1->prev = nullptr;
									(*begin)->prev = nullptr;
								}
								else
								{
									temp1 = temp1->next;
									temp1->prev->prev->next = temp1;
									List* temp3 = temp1->prev->prev;
									delete temp1->prev;
									temp1->prev = temp3;
								}
								List* temp4 = temp2->prev->prev;
								temp4->next = temp2;
								delete temp2->prev;
								temp2->prev = temp4;
							}
							temp1 = temp2;
							temp2 = nullptr;
						}
						else if(temp2->next == nullptr && temp2->key != ' ')
						{
							i++;
							if (i%2 != 0)
							{
								if (temp1 == *begin)
								{
									*begin = temp1->next;
									temp1 = temp1->next;
									delete temp1->prev;
									temp1->prev = nullptr;
									(*begin)->prev = nullptr;
								}
								else
								{
									temp1 = temp1->next;
									temp1->prev->prev->next = temp1;
									List* temp3 = temp1->prev->prev;
									delete temp1->prev;
									temp1->prev = temp3;
								}
								*end = (*end)->prev;
								delete (*end)->next;
								(*end)->next = nullptr;
							}
							temp1 = nullptr;
							temp2 = nullptr;
						}
						else
						{
							i++;
							temp2 = temp2->next;
						}
					}
				}
				else
				{
					if (size(*begin)==1)
					{
						list_delete(begin);
						*begin = nullptr;
						*end = nullptr;
					}
					else
					{
						*end = (*end)->prev;
						delete (*end)->next;
						(*end)->next = nullptr;
					}
					temp1 = nullptr;
				}
			}
			else
				temp1 = temp1->next;
		}
	}
}

void disp_wrds_odd_char (List* begin)
{
	List* temp1 = begin;
	int i;
	while (temp1)
	{
		if (temp1->key != ' ')
		{
			if (temp1->next)
			{
				List* temp2 = temp1->next;
				i = 1;
				while (temp2)
				{
					if (temp2->key != ' ' && (temp2->next))
					{
						i++;
						temp2 = temp2->next;
					}
					else if (temp2->key == ' ' || (!temp2->next))
					{
						if (temp2->key != ' ')
							i++;
						if (i%2 != 0)
						{
							if (temp2->key == ' ')
							{
								while (temp1 != temp2)
								{
									cout << temp1->key;
									temp1 = temp1->next;
								}
								cout << " ";
							}
							else
							{
								cout << temp1->key;
								do
								{
									temp1 = temp1->next;
									cout << temp1->key;
								}
								while (temp1 != temp2);
								cout << " ";
								return;
							}
						}
						else
							if (temp2->key != ' ')
								return;
						temp1 = temp2;
						temp2 = nullptr;
					}
				}
			}
			else
			{
				cout<<temp1->key;
				return;
			}
		}
		else
			temp1 = temp1->next;
	}
}