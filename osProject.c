#include<stdio.h>
#include<stdlib.h>
struct process
{
	int pNo;
	int artm;
	int brtm;
	int wtm;
	
};
struct process p[10];
void print(int n)
{
	int i;
	printf(" *******************************************************************\n");
	printf(" Process name      Arrival Time        Burst time    Waiting Time\n");
	for( i=0 ; i<n ; i++ )
	{
	printf(" %d                 %d                   %d             %d    \n",p[i].pNo,p[i].artm,p[i].brtm,p[i].wtm);
	}
}
void input(int n)
{
	int i;
	for( i=0 ; i<n ; i++)
	{
		p[i].pNo=i;
		printf("Enter Arrival time of process %d : ",i);
		scanf("%d",&p[i].artm);
		printf("Enter  Burst  time of process %d : ",i);
		scanf("%d",&p[i].brtm);
	}
}
int main()
{
	input(2);
	print(2);
}
