#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct process																							//Structure to store the detail about process 
{
	int pNo;																						// stores the process no
	int at;																							// stores arrival time
	int bt;																							// stores burst time
	int wt;																							// stores burts time
	bool life;																						// status of process  T = if not processed
																									//					  F = if processed
	int pr;																							// stores the priority of a process 
};
struct process p[10];																					
int n;																									// stores the no of processes
void print()																							//print the details about process
{
	int i;
	printf(" *******************************************************************\n");
	printf(" Process name      Arrival Time        Burst time    Waiting Time\n");
	for( i=0 ; i<n ; i++ )
	{
	printf(" %d                 %d                   %d             %d    \n",p[i].pNo,p[i].at,p[i].bt);
	}
}
void input()																			//to take the input about the process
{
	int i;
	for( i=0 ; i<n ; i++)
	{
		p[i].pNo=i;
		printf("Enter Arrival time of process %d : ",i);
		scanf("%d",&p[i].at);
		printf("Enter  Burst  time of process %d : ",i);
		scanf("%d",&p[i].bt);
	}
}
void sort()																						// sorting it according to Process arrival time																									
{
	int i,j;
	struct process temp;
	for ( i = 0 ; i < n ; i++ )
	{
		for( j=i ; j < n-1 ; j++ )
		{
			if ( p[j].at > p [j+1].at )
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1] = temp;
			}
		}
	}
}
int cal(int i,int t)																			//to calculate the value of priority with formula 1 + (waiting time)/(burst time)
{
	p[i].pr = 1 + (t-p[i].at)/p[i].bt;
}
int allocation()
{
	int clck;																					// stores the current time
	int i,j;
	int ptemp, nextP;
	for( i =0 ; i<n ; i++)
	{
		
	}
}
int main()
{
	printf(" ENTER NO OF PROCESS : \n");
	scanf("%d",&n);																			
	input();
	print();
	sort();
	print();
	cal(1,3);
	printf("%d     %d", p[0].pr, p[1].pr);
}