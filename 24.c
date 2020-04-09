#include<stdio.h>
#include<conio.h>
int main()
{
int Max[20][20], need[20][20], alloc[20][20], avail[20], completed[20], safeSeq[20];
int pro, res, i, j, process, count;
count = 0;

printf("Enter the no.of processes given : ");//processes to be entered.
scanf("%d", &pro);

for(i = 0; i< pro; i++)//time complexity= O(n)
	completed[i] = 0;
	 
printf("\n\nEnter the no . of resources to be given : ");//resources to be taken
scanf("%d", &res);

printf("\n\nEnter the Max values for each process : ");// we have to enter maximum values
for(i = 0; i < pro; i++)//time complexity= O(n)
{
	printf("\nFor process %d : ", i + 1);
	for(j = 0; j < res; j++)//time complexity= O(n^2)
		scanf("%d", &Max[i][j]);
}

printf("\n\nEnter the Alloc values for each process : ");//allocate the values to table
for(i = 0; i < pro; i++)//time complexity= O(n)
{
	printf("\nFor process %d : ",m + 1);
	for(j = 0; j < res; j++)//time complexity= O(n^2)
		scanf("%d", &alloc[i][j]);	
}

printf("\n\nEnter the Avail Resources : ");//enter the available resources
for(i = 0; i < res; i++)//time complexity= O(n)
		scanf("%d", &avail[i]);	


	for(i = 0; i < pro; i++)//time complexity= O(n)
	{
		for(j = 0; j < res; j++)//time complexity= O(n^2)
			need[i][j] = Max[i][j] - alloc[i][j];
	}	
do
{
	printf("\n Max table:\t Allocation table:\n");//max and allocation tables are creted for testing
	for(i = 0; i < pro; i++)//time complexity= O(n)
	{
		for( j = 0; j < res; j++)//time complexity= O(n^2)
			printf("%d  ", Max[i][j]);
		printf("\t\t\t");
		for( j = 0; j < res; j++)//time complexity= O(n^2)
			printf("%d  ", alloc[i][j]);
		printf("\n");
	}

	process = -1;

	for(i = 0; i < pro; i++)//time complexity= O(n)
	{
		if(completed[i] == 0)//if not completed
		{
			process = i ;
			for(j = 0; j < res; j++)//time complexity= O(n^2)
			{
				if(avail[j] < need[i][j])
				{
					process = -1;
					break;
				}
			}
		}
		if(process != -1)
			break;
	}

	if(process != -1)
	{
		printf("\nProcess %d runs to completion!", process + 1);//if completed
		safeSeq[count] = process + 1;
		count++;
		for(j = 0; j < res; j++)//time complexity= O(n)
		{
			avail[j] += alloc[process][j];
			alloc[process][j] = 0;
			Max[process][j] = 0;
			completed[process] = 1;
		}
	}
}while(count != pro && process != -1);

if(count == pro)
{
	printf("\nThe system is in a safe state!!\n");
	printf("Safe Sequence : < ");//safe sequence will be printed
	for( i = 0; i < pro; i++)
			printf("%d ", safeSeq[i]);
	printf(">\n");
}
else
	printf("\nThe system is in an unsafe state!!");
getch();
}
