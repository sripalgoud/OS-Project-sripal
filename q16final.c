#include<stdio.h> 
 
int main() 
{ 
 
  int count,j,n,time,remain,flag=0,time_quantum; //
  int wait_time=0,turnaround_time=0,art[10],brt[10],rt[10]; // art->arrival time, brt->burst time, rt->run time
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); //n-> total no of processes
  remain=n; 
  for(count=0;count<n;count++) //count->process count
  { 
    printf("Enter Arrival Time and Burst Time for Process  P%d :",count+1); //Displaying processing ID while asking the details of the process
    scanf("%d",&art[count]); //input for arrival time 
    scanf("%d",&brt[count]); //input for burst time
    rt[count]=brt[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); //Input for time quantum
  printf("Process ID | \tArrival Time\t | Burst Time\n");
  for(count=0;count<n;count++) //count->process count
  { 
    printf("P%d\t\t |",count+1); //Displaying processing ID while asking the details of the process
    printf("\t%d\t |",art[count]); //input for arrival time 
    printf("%d\n",brt[count]); //input for burst time 
  } 
  
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); //Headings
  for(time=0,count=0;remain!=0;) 
  { 
  //for(count=1;count<=n;count++)
  //{
  
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1;
//	  printf("P%d",count); 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum;
//	  printf("P%d",count);  
    }

//}
    if(rt[count]==0 && flag==1) 
    { 
      remain--; //Process execution and decrementing the process count
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-art[count],time-art[count]-brt[count]); 
      wait_time+=time-art[count]-brt[count]; 
      turnaround_time+=time-art[count]; 
      flag=0; 
    }

    if(count==n-1) 
      count=0; 
    else if(art[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}
