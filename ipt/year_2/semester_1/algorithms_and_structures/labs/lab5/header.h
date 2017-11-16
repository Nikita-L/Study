#include <iostream>
#include <string>
#include <conio.h>

#define usi unsigned short

using namespace std;

struct TreeElement
{
	char key;
	TreeElement *left, *right;
};

void mainMenu();
void treeGetElement(TreeElement**);
void treeAddElement (char, TreeElement**);
void treeShow (TreeElement*, usi);
void treeDelete (TreeElement**);
void treeGetDeleteElement (TreeElement**);
TreeElement* treeDeleteElement (char, TreeElement*);
TreeElement* treeMinimum (TreeElement*);
void treeGetDeleteRepeatElement (TreeElement**);
bool treeConsistElement (char tempKey, TreeElement*);
string treeRepeatElement (TreeElement*, string*, string);
string treeToString (TreeElement*, string*);
void treePostfixShow (TreeElement*, usi);