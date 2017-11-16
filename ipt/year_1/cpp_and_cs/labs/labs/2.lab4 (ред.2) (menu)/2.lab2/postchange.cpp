#include "head.h"

void Worker::postchange()
{
	cout<<endl<<"Present "<<name<<" post: "<<post;
	cout<<endl<<"Enter new post: ";
	cin>>post;
}