#include "header.h"

void treeGetElement (TreeElement** tree)
{
	system("CLS");
	char tempKey;
	for (usi i = 0; i != 1;)
	{
		tempKey = getch();
		if (tempKey >= 97 && tempKey <= 122)
		{
			putchar(tempKey);
			treeAddElement(tempKey, tree);
		}
		else if (tempKey == 13)
			return;
	}
}
void treeAddElement (char tempKey, TreeElement** tree)
{
	if (! *tree)
	{
		*tree = new TreeElement;
		(*tree)->key = tempKey;
		(*tree)->left = (*tree)->right = nullptr;
	}
	else
	{
		if (tempKey <= (*tree)->key)
			treeAddElement(tempKey, &(*tree)->left);
		else
			treeAddElement(tempKey, &(*tree)->right);

	}
}
void treeShow (TreeElement* tree, usi level)
{
	if (tree)
	{
		treeShow(tree->right, level + 1);
		for(int i = 0; i< level; i++) 
			cout << " ";
		cout << tree->key << endl;
		treeShow(tree->left, level + 1);
	}
}
void treeDelete (TreeElement** tree)
{
	if (*tree)
	{
		treeDelete (&((*tree)->left));
		treeDelete (&((*tree)->right));
	}
	delete *tree;
	*tree = nullptr;
}
void treeGetDeleteElement (TreeElement** tree)
{
	system("CLS");
	if (*tree)
	{
		for (usi i = 0; i != 1;)
		{
			char tempKey;
			tempKey = getch();
			if (tempKey >= 97 && tempKey <= 122)
			{
				putchar(tempKey);
				(*tree) = treeDeleteElement(tempKey, (*tree));
				return;
			}
		}
	}
	cout << "Дерево пустое";
}
TreeElement* treeDeleteElement (char tempKey, TreeElement* tree)
{
	if (tree == nullptr)
		return tree;
	if (tempKey < tree->key)
		tree->left = treeDeleteElement (tempKey, tree->left);
	else if (tempKey > tree->key)
		tree->right = treeDeleteElement (tempKey, tree->right);
	else if (tree->left != nullptr && tree->right != nullptr)
	{
		tree->key = treeMinimum(tree->right)->key;
		tree->right = treeDeleteElement(tree->key, tree->right);
	}
	else
	{
		if (tree->left != nullptr)
		{
			TreeElement* temp1 = tree;
			tree = tree->left;
			delete temp1;
		}
		else
		{
			TreeElement* temp1 = tree;
			tree = tree->right;
			delete temp1;
		}
	}
	return tree;
}
TreeElement* treeMinimum (TreeElement* tree)
{
	if (tree->left == nullptr)
		return tree;
	return treeMinimum (tree->left);
}
void treeGetDeleteRepeatElement (TreeElement** tree)
{
	system("CLS");
	if (*tree)
	{
		string treeString;
		string repeatElements;
		treeString = treeToString(*tree, &treeString);
		repeatElements = treeRepeatElement(*tree, &repeatElements, treeString);
		if (!repeatElements.size())
		{
			cout << "Нет повторяющихся";
			getch();
			return;
		}
		for (usi i = 0; i < repeatElements.size(); i++)
		{
			char tempKey = repeatElements[i];
			bool check = treeConsistElement(tempKey, *tree);
			while (check)
			{
				(*tree) = treeDeleteElement(tempKey, (*tree));
				if (*tree)
					check = treeConsistElement(tempKey, *tree);
				else
					return;
			}
		}
		return;
	}
	cout << "Дерево пустое";
	getch();
}
bool treeConsistElement (char tempKey, TreeElement* tree)
{
	if (tempKey == tree->key)
		return 1;
	if (!tree->left && !tree->right)
		return 0;
	else if (tree->left && !tree->right)
	{
		if (!treeConsistElement(tempKey, tree->left))
			return 0;
		else
			return 1;
	}
	else if (tree->right && !tree->left)
	{
		if (!treeConsistElement(tempKey, tree->right))
			return 0;
		else
			return 1;
	}
	else
	{
		if (!treeConsistElement(tempKey, tree->left) && !treeConsistElement(tempKey, tree->right))
			return 0;
		else
			return 1;
	}
}
string treeRepeatElement (TreeElement* tree, string* repeatElements, string str)
{
	for (usi i = 0; i < str.size() - 1; i++)
		for (usi j = i + 1; j < str.size(); j++)
			if (str[i] == str[j])
				(*repeatElements).push_back(str[i]);
	if ((*repeatElements).size())
	{
		return *repeatElements;
	}
	else
		return "";
}
string treeToString (TreeElement* tree, string* str)
{
	if (tree)
	{
		(*str).push_back(tree->key);
		treeToString(tree->left, str);
		treeToString(tree->right, str);
	}
	return *str;
}
void treePostfixShow (TreeElement* tree, usi level)
{
	if (tree)
	{
		treePostfixShow(tree->left, level + 1);
		treePostfixShow(tree->right, level + 1);
		for(int i = 0; i< level; i++) 
			cout << " ";
		cout << tree->key << endl;
	}
}