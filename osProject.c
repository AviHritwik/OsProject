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
	float pr;
	int tat;																							// stores the priority of a process 
};
struct process p[10];																					
int n;																									// stores the no of processes
void print()																							//print the details about process
{
	int i;
	printf("\t\t\t\t************************************************\n");
	printf("\t\t\t\tProcess name\tArrival Time\tBurst time\n");
	for( i=0 ; i<n ; i++ )
	{
	printf("\t\t\t\t\t%d\t\t%d\t\t%d\n",p[i].pNo,p[i].at,p[i].bt);
	}
	printf("\t\t\t\t************************************************\n");
}
void fprint()																							//print the details about process
{
	int i;
	printf("\t\t********************************************************************************\n");
	printf("\t\t\tProcess name\tArrival Time\tBurst time\tWaiting Time\tTurnAround Time\n");
	for( i=0 ; i<n ; i++ )
	{
	printf("\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pNo,p[i].at,p[i].bt,p[i].wt,p[i].tat);
	}
	printf("\t\t********************************************************************************\n");
}
void input()																			//to take the input about the process
{
	int i;
	for( i=0 ; i<n ; i++)
	{
		
		p[i].pNo=i+1;
		printf("\t\t\t\tPROCESS P%d : \n",i+1);
		printf("\t\t\t\t\tArrival  time : ",i+1);
		scanf("%d",&p[i].at);
		printf("\t\t\t\t\tBurst    time : ",i+1);
		scanf("%d",&p[i].bt);
		p[i].life = true;
		system("@cls||clear");
	}
}
void sort()																						// sorting it according to Process arrival time																									
{
	int i,j;
	struct process temp;
	for ( i = 0 ; i < n-1 ; i++ )																//  bubble sort
	{
		for( j=0 ; j < n-i-1 ; j++ )
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
int cal(int i,int clck)																			//to calculate the value of priority with formula 1 + (waiting time)/(burst time)
{
	//printf("^^^^  for p%d  : %d  %d ^^^^^^^",p[i].pNo,p[i].wt,clck);
	p[i].pr = 1.0 + (float)p[i].wt/(float)p[i].bt;
	//printf(" for p%d  : %f",p[i].pNo,p[i].pr);
}
int allocation()
{
	int clck=0 ;																					// stores the current time
	int i,j;
	int nextP;
	float ptemp;
	printf("\t\t\t\tProcess\t:\tStart\tEndTime\n");
	for( i =0 ; i<n ; i++)
	{
		nextP=-1;
		ptemp=-1.0;
		for( j=0 ; j<n ; j++)
		{
			if(clck >= p[j].at && p[j].life == true)
			{
				//printf("   for  i = %d  & j = %d \n  ",i,j);
				p[j].wt=clck - p[j].at;
				cal(j,clck);
				
				if( ptemp< p[j].pr )
				{
					nextP=j;
					ptemp=p[j].pr;
				}
				else
					if( ptemp == p[j].pr && p[j].bt<p[nextP].bt )
					{
						nextP = j ;
					}
			}
		}
		if(nextP==-1)
		{
			printf("\t\t\t\tIDLE\t:\t%d\t%d\n",clck,p[i].at);
			clck=p[i].at;
			i--;
		}
		else
		{
			p[nextP].life= false;
			printf("\t\t\t\tP%d\t:\t%d\t%d\n",p[nextP].pNo,clck,clck+p[nextP].bt);
			clck=clck+p[nextP].bt;
			p[nextP].tat=clck;
		}
	}
}
int main()
{
	char c;
	printf("\t\t\t\tENTER NO OF PROCESS : ");
	scanf("%d",&n);
	fflush(stdin);
 x: system("@cls||clear");																			
	input();
	printf("\t\t\t\tEntered information is          : \n");
	print();
	printf("\t\t\t\tAfter Sorting (by arrival time) :\n");
	sort();
	print();
	printf("\n\n\n\n\t\t\t\tIs there a mistake.. ? To Enter new info Press \"Y\"  Or press any other key  : ");
	fflush(stdin);
	scanf("%c",&c);
	if(c=='y' || c=='Y')
	{
		goto x;
	}
	system("@cls||clear");
	allocation();
	printf("\n\n\n");	
	fprint();
}
