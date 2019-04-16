#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct process{
	char name[5]; //process name
	int bt; //burst-time
	int at; //arrival-time
	int prt; //priority
	int wt,ta; //wait-time,turn-around time
	int flag; //random parameter to store the flag value
}processes; //object


void b_sort(processes temp[],int n)
{
	processes t;
	int i,j;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++){
			if(temp[j].at > temp[j+1].at){
				t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}
}

int accept(processes P[]){
	int i,n;
	printf("\n Enter total no. of processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\n PROCESS [%d]",i+1);
		printf(" Enter process ID : ");
		scanf("%s",&P[i].name);
		printf(" Enter Arrival time : ");
		scanf("%d",&P[i].at);
		printf(" Enter Burst time : ");
		scanf("%d",&P[i].bt);
		printf(" Enter Priority : ");
		scanf("%d",&P[i].prt);
	}
	printf("\n PROCESS.\tBURST TIME.\tARRIVAL TIME.\tPRIORITY");
	for(i=0;i<n;i++)
		printf("\n %s\t\t%d\t\t%d\t%d",P[i].name,P[i].bt,P[i].at,P[i].prt);
	printf("\n\nNow select the algorithm by opting option 2 to perform the Task");
	return n;
}

//Round Robin Scheduling
void RR(processes P[],int n)
{
	int pflag=0,t,tcurr=0,k,i,Q=0;
	int sumw=0,sumt=0;
	float avgwt=0.0,avgta=0.0;
	processes temp1[10],temp2[10];	

	for(i=0;i<n;i++)
		temp1[i]=P[i];

	b_sort(temp1,n);
	
	for(i=0;i<n;i++)
		temp2[i]=temp1[i];
	
	printf("\n Enter The Time Quantum : ");
	scanf("%d",&Q);
	
	for(k=0;;k++){
		if(k>n-1)
			k=0;
		if(temp1[k].bt>0)
			printf("  %d  %s",tcurr,temp1[k].name);
		t=0;
		while(t<Q && temp1[k].bt > 0){
			t++;
			tcurr++;
			temp1[k].bt--;
		}  
		if(temp1[k].bt <= 0 && temp1[k].flag != 1){
			temp1[k].wt = tcurr - temp2[k].bt - temp1[k].at;
			temp1[k].ta = tcurr - temp1[k].at;
			pflag++;
			temp1[k].flag = 1;
			sumw+=temp1[k].wt; //sum of the all waiting times
			sumt+=temp1[k].ta; //sum of the all turn-around times
		}
		if(pflag == n)
			break;
	}
	printf("  %d",tcurr); //printing the order of process with respect to their priority
	avgwt = (float)sumw/n;
	avgta = (float)sumt/n;
	printf("\n\n Average Waiting time = %0.2f\n Average Turn-Around time= %0.2f.",avgwt,avgta);
}

int main(){
	
	processes P[10];
	int ch,n;
	do{
		printf("\n\n SIMULATION OF CPU SCHEDULING ALGORITHM\n");
		printf("\n Options:");
		printf("\n 1. Enter Process Data");
		printf("\n 2. Round Robin Algorithm");
		printf("\n 3. Exit\n ");
		printf("Note : Please dont select Round Robin at first instance. First enter the data and select the algorithm\n");
		printf("\nPlease Select an option :\t");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				n=accept(P);
				break;
			case 2:
				RR(P,n);
				break;
			case 3:exit(0);
			default: printf("Invalid Option Selected");
		}
	}while(ch != 2);
	getch();
	return 0;
}
