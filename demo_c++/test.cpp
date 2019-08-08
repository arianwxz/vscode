#include <iostream>
#include <algorithm>
using namespace std;

BiTree *ROOT=NULL;
BiTree *currentNode;
#define LENGTH 10


struct BiTree
{
	int data;
	BiTree *lchild;
	BiTree *rchild;
	BiTree *father;
	BiTree(int x):data(x),lchild(NULL),rchild(NULL),father(NULL){};
};

void makeTree(BiTree *newNode)
{
	if(ROOT==NULL) 
	{
		ROOT=newNode;
		currentNode=ROOT;
	}
	else
	{
		if (currentNode->lchild==NULL)
		{
			currentNode->lchild=newNode;
            newNode->father=currentNode;
		}
        else
        {
            currentNode->rchild=newNode;
            newNode->father=currentNode;
        }
        
			
	}
}


void inOrder(BiTree *T)
{
	if(T!=NULL)
	{
		inOrder(T->lchild);
		cout<<T->data<<" ";
		inOrder(T->rchild);
	}
}

int main()
{
	int temp;
	for (int i=0;i<LENGTH;i++)
	{
		cin>>temp;
		BiTree *newNode= new BiTree(temp);
	}
	return 0;
}

