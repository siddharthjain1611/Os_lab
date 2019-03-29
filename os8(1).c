#include<stdio.h>
void main()
{
	int pid, bt[100],n,i,j,turn_around_time=0,waiting_time=0,sum=0,avg_turn_around_time,avg_waiting_time,sum1=0;
	
	printf("enter no. of processes\n");
	scanf("%d",&n);
	printf("enter burst time for processes");  
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n-1;i++)
	{
		waiting_time=0;
		for(j=0;j<=i;j++)
		{
			waiting_time=waiting_time+bt[j];
		}
		sum=sum+waiting_time;
	}
	avg_waiting_time=sum/n;
	printf("Average waiting time is %d \n",avg_waiting_time);
	for(i=0;i<n;i++)
	{
		turn_around_time=0;
		for(j=0;j<=i;j++)
		{
			turn_around_time=turn_around_time+bt[j];
		}
		sum1=sum1+turn_around_time;
	}
	avg_turn_around_time=sum1/n;
	printf("Average turn around time is %d \n",avg_turn_around_time);
}
