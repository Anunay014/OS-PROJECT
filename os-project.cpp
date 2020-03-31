#include<stdio.h> // Including all the required header files
#include<stdlib.h>
#include<conio.h> 
 
int main() 
{ 
 
  int count,i,j,m=0,n,y=0; // Declaring variables
  int time,remain=0,min,flag=0; 
  int wait_time=0,turn_a_time=0,a_time[10],b_time[10],p[10],z[10]; // Declaring vaiables for turnaround time,waiting time,and queue
  float k=0,x=0; 
  printf("Enter number of Process:  "); // Number of processes entered
  scanf("%d",&n); 
  printf("\n #Arrival time should be Greater than 3(CPU remains idle for First 3 seconds) \n");// Condition applied as specified in question
  printf("\n #Burst time should be less than 10 \n\n");
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);// Enter the values for arrival time and burst time 
    scanf("%d",&a_time[count]); 
    scanf("%d",&b_time[count]);  
  } // COMPLEXITY=O(n)

for(i=0;i<n;i++)
{
	if(a_time[i]==0)
	{
		printf("\n INVALID ARRIVAL TIME \n");// For INVALID arrival time
		getch();
		exit(1);
	}
} // COMPLEXITY=O(n)
for(i=0;i<n;i++)
{
	if(a_time[i]<3)
	{
		printf("\n Invalid Arrival Time it should be greater than 3 \n");
		getch();
		exit(1);
	}
} // COMPLEXITY=O(n)
  printf("\n\n\tProcess\t|Turnaround Time|Waiting Time\n"); // Table created for displaying process,turnaround time and waiting time 
  printf("\t===========================================\n");
for(i=0;i<n;i++)
{ 
	m=m+b_time[i];
} // COMPLEXITY=O(n)
min=m;
time=m;
for(i=0;i<n;i++)
{
	if(a_time[i]<time)
	{
		time=a_time[i];
	}
} // COMPLEXITY=O(n)
for(i=time;i<=m;i=i+b_time[j])
{
	min=m;
	remain=0;
	flag=0;

	for(count=0;count<n;count++)
	{
	
		if(a_time[count]<=i)
		{

			if(b_time[count]<min)
			{

				min = b_time[count];
				j=count;
				flag=1;
			}
			remain=1;	 
		}
	} // COMPLEXITY=O(n)
	if(flag==1&&remain==1)
	{
		wait_time=i-a_time[j];
		turn_a_time=wait_time+b_time[j];
		printf("\tP[%d]\t|\t%d\t|\t%d\n",j+1,turn_a_time,wait_time); 
		k=k+wait_time;
		x=x+turn_a_time;
	
		a_time[j]=m+1;
		p[y]=j+1;
		z[y]=i;
		y++;
	} 
} // The output is displayed below
printf("\n\n\nAverage Waiting Time= %.2f\n",k/n); 
printf("Avg Turnaround Time = %.2f",x/n); 
printf("\n\n\nTotal time taken by processor to complete all the jobs : %d",m);  
printf("\n\n\nQueue  for order of execution: ");
printf("\n\nProcess		");

for(i=0;i<n;i++)
{
	printf(" P[%d]   ",p[i]);
	if(i==(n-1))
	{
		printf("End");
	}
} // COMPLEXITY=O(n)
 

  return 0; 
}
