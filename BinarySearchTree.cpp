#include<iostream>
using namespace std;
class Node
{
	public:
		
	int Data;
	Node *Left;
	Node *Right;
	
	Node(int Data)
	{
		this->Data=Data;
		this->Left= NULL;
		this->Right= NULL;	
	}
	
};
void InOrder(Node* data)
{
	if(data == NULL)
	{
		return;
	}
	InOrder(data->Left);
	cout<<data->Data<<"\t";
	InOrder(data->Right);
}
void PreOrder(Node* data)
{
	if(data == NULL)
	{
		return;
	}
	cout<<data->Data<<"\t";
	InOrder(data->Left);
	InOrder(data->Right);
}
void PostOrder(Node* data)
{
	if(data == NULL)
	{
		return;
	}
	InOrder(data->Left);
	InOrder(data->Right);
	cout<<data->Data<<"\t";
}
Node* Insert(Node*RootNode,int data)
{
	Node* NewNode=new Node(data);
	Node* Object1=RootNode;
	Node* Object2=NULL;
	while(Object1!=NULL)
	{
		Object2=Object1;
		if(data<Object1->Data)
		{
			Object1=Object1->Left;
		}
		else
		{
			Object1=Object1->Right;
		}
	}
	if(Object2==NULL)
	{
		Object2=NewNode;
	}
	else if(data<Object2->Data)
	{
		Object2->Left=NewNode;
	}
	else
	{
		Object2->Right=NewNode;
	}
	return Object2;
}
int main()
{
	Node* RootNode=NULL;
	RootNode=Insert(RootNode,5);
	Insert(RootNode,3);
	Insert(RootNode,7);
	Insert(RootNode,4);
	Insert(RootNode,2);
	Insert(RootNode,6);
	Insert(RootNode,20);

		
	cout<<"--------------InOrder Traversal---------------"<<endl;
	InOrder(RootNode);
	cout<<endl<<"--------------PreOrder Traversal---------------"<<endl;
	PreOrder(RootNode);
	cout<<endl<<"--------------PostOrder Traversal---------------"<<endl;
	PostOrder(RootNode);
	return 0;
}
