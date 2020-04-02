#include<stdio.h>
#include<conio.h>
int main()
{
int Max[20][20], need[20][20], alloc[20][20], avail[20], completed[20], safeSeq[20];
int pro, res, m, n, process, count;
count = 0;

printf("Enter the no . of processes : ");
scanf("%d", &pro);

for(m = 0; m< pro; m++)
	completed[m] = 0;
	 
printf("\n\nEnter the no . of resources : ");
scanf("%d", &res);

printf("\n\nEnter the Max values for each process : ");
for(m = 0; m < pro; m++)
{
	printf("\nFor process %d : ", m + 1);
	for(n = 0; n < res; n++)
		scanf("%d", &Max[m][n]);
}

printf("\n\nEnter the Allocation values for each process : ");
for(m = 0; m < pro; m++)
{
	printf("\nFor process %d : ",m + 1);
	for(n = 0; n < res; n++)
		scanf("%d", &alloc[m][n]);	
}

printf("\n\nEnter the Available Resources : ");
for(m = 0; m < res; m++)
		scanf("%d", &avail[m]);	


	for(m = 0; m < pro; m++)
		for(n = 0; n < res; n++)
			need[m][n] = Max[m][n] - alloc[m][n];
		
do
{
	printf("\n Max table:\tAllocation table:\n");
	for(m = 0; m < pro; m++)
	{
		for( n = 0; n < res; n++)
			printf("%d  ", Max[m][n]);
		printf("\t\t\t");
		for( n = 0; n < res; n++)
			printf("%d  ", alloc[m][n]);
		printf("\n");
	}

	process = -1;

	for(m = 0; m < pro; m++)
	{
		if(completed[m] == 0)//if not completed
		{
			process = m ;
			for(n = 0; n < res; n++)
			{
				if(avail[n] < need[m][n])
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
		printf("\nProcess %d runs to completion!", process + 1);
		safeSeq[count] = process + 1;
		count++;
		for(n = 0; n < res; n++)
		{
			avail[n] += alloc[process][n];
			alloc[process][n] = 0;
			Max[process][n] = 0;
			completed[process] = 1;
		}
	}
}while(count != pro && process != -1);

if(count == pro)
{
	printf("\nThe system is in a safe state!!\n");
	printf("Safe Sequence : < ");
	for( m = 0; m < pro; m++)
			printf("%d ", safeSeq[m]);
	printf(">\n");
}
else
	printf("\nThe system is in an unsafe state!!");
getch();
}
