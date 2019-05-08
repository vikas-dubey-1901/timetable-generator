#include<iostream>
#include<vector>
#include <list>
#include <iterator>
#include <utility>
#include<bits/stdc++.h>
#define V 82
using namespace std;
struct node
{
    int a;
    int b;
    struct node *next;
};
struct node1
{
    int a;
    int b;
    int c;
    struct node1 *next;
};
typedef struct table
{
    int a[5];
    int b[5];
    int index;
}table;
struct node1 *prev2,*head2,*p2;
string s[6]={"NULL","ankita verma","heam N","deepti","taj","akash"};
void printSolution(int color[],struct node * head);

bool isSafe (int v, bool graph[V][V], int color[], int c,int room[])
{
	for (int i = 0; i < V; i++)
	{
		if (graph[v][i] && c == color[i])
			return false;
		if(room[color[i]-1]>4)
			return false;	
}
	return true;
}


bool graphColoringUtil(bool graph[V][V], int m, int color[], int v,int room[])
{

	if (v == V)
		return true;


	for (int c = 1; c <= m; c++)
	{

		if (isSafe(v, graph, color, c,room))
		{
		color[v] = c;

		room[color[v]-1]++;
		if (graphColoringUtil (graph, m, color, v+1,room) == true)
			return true;

		color[v] = 0;
		}
		room[color[v]-1]--;
	}

	return false;
}


bool graphColoring(bool graph[V][V], int m,struct node * head)
{
	int *color = new int[V];
	int room[m];
	for(int i=0;i<m;i++)
	{
		room[i]=0;
	}
	for (int i = 0; i < V; i++)
	color[i] = 0;

	if (graphColoringUtil(graph, m, color, 0,room) == false)
	{
	printf("Solution does not exist");
	return false;
	}

	printSolution(color,head);
	return true;
}

void printSolution(int color[],struct node * head)
{
    head2=NULL;

	for (int i = 0; i < V; i++)
	{
	    int a= head->a;
	    int b=head->b;
	    cout<<"x "<<a+1<<" and "<<"y "<<b+1<<" "<<color[i]<<endl;
        head=head->next;
        p2=(node1*)malloc(sizeof(struct node1));
        p2->a=a+1;
        p2->b=b+1;
        p2->c=color[i];
        p2->next=NULL;
        if(head2==NULL)
            head2=p2;
        else
            prev2->next=p2;
        prev2=p2;
	}
	printf("\n");
}
void print(int m)
{
    table sol[m];
        for(int j=0;j<m;j++)
        {
            sol[j].index=-1;
        }
int co=0;
    while(head2!=NULL)
    {

        sol[head2->c-1].index++;
        sol[head2->c-1].a[sol[head2->c-1].index]=head2->a;
        sol[head2->c-1].b[sol[head2->c-1].index]=head2->b;
        head2=head2->next;
    }
    for(int i=0;i<5;i++)
    {
        cout<<i<<"\n";
    for(int j=0;j<5;j++)
    {
        for(int k=i;k<30;k=k+5)
        {
            if(sol[k].index>=j)
        cout<<sol[k].a[j]<<" "<<sol[k].b[j]<<"\t";
        else
            cout<<"NULL"<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n\n\n\n";
    }
}

int main()
{
	int a[4][5]={5,5,5,5,5,
				3,4,4,4,4,
				4,4,2,4,4,
				4,4,4,4,4};

	struct node *prev,*head,*p;
	head=NULL;
	int index=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
		    for(int k=0;k<a[i][j];k++)
            {
		    index++;
		    p=(node*)malloc(sizeof(struct node));
        p->a=i;
        p->b=j;
        p->next=NULL;
        if(head==NULL)
            head=p;
        else
            prev->next=p;
        prev=p;
		}
		}

	}
	cout<<index<<endl;
	struct node *t;
	t=head;

	struct node *q,*w;
	q=head;
	int i=0;

	bool b[V][V];
	while(q!=NULL)
    {
       int  j=0;
        w=head;
        while(w!=NULL)
        {
            if(i==j)
            {
                b[i][j]=0;
            }
            else
            {
                if(q->a==w->a)
                {
                    b[i][j]=1;
                }
                else
                    if(q->b==w->b)
                {
                    b[i][j]=1;
                }
                else
                {
                    b[i][j]=0;
                }
            }
            w=w->next;
            j++;

        }
        q=q->next;
        i++;
    }
    for(int i=0;i<index;i++)
    {
        for(int j=0;j<index;j++)
        {
            //cout<<b[i][j]<<" ";
        }
        //cout<<endl;
    }
    int m = 30;
    graphColoring (b, m,head);
     print(m);
}
