#include<stdio.h> 
#include<stdlib.h> 
struct J 
{ 
  	int bt,tat,wt,at,ft; 
} job[100]; 
void scheduler(struct J job[],int n,int q) 
{ 
 	int burst[100],t=0,done=0,curr=-1,diff=q,i=0; 
 	float tat_sum=0,wt_sum=0; 
 	for(i=0;i<n;i++) 
  		burst[i]=job[i].bt; 
 
 	while(done<n) 
 	{ 
    	while(1) 
   		{ 
    		curr=(curr+1)%n; 
    		if(job[curr].bt!=0) 
     			break; 
   		} 
   		diff=(q<=job[curr].bt)?q:job[curr].bt; 
 
  		job[curr].bt-=diff; 
  		t+=diff; 
  		if(job[curr].bt==0) 
  		{ 
   			done++; 
   			job[curr].ft=t; 
  		} 
 	} 
  	printf("RR Scheduling Details are \n"); 
 	for(i=0;i<n;i++) 
 	{ 
   		job[i].bt=burst[i]; 
   		job[i].tat=job[i].ft-job[i].at; 
   		job[i].wt=job[i].tat-job[i].bt; 
   		tat_sum+=job[i].tat; 
   		wt_sum+=job[i].wt; 
 	} 
 	printf("Job\tBT\tAT\tTAT\tWT\n"); 
 	for(i=0;i<n;i++) 
  		printf("%d\t%d\t%d\t%d\t%d\n",i+1,job[i].bt,job[i].at,job[i].tat,job[i].wt); 
 	printf("Avg TAT=%f\nAvg WT=%f\n",tat_sum/n,wt_sum/n); 
} 
void main() 
{ 
 	int n,q,c,i; 
 	printf("Enter the number of processes:\n"); 
 	scanf("%d",&n); 
 	printf("Enter the arrival time and burst time\n"); 
 	for(i=0;i<n;i++) 
 	{ 
  		printf("Job%d: ",i+1); 
  		scanf("%d%d",&job[i].at,&job[i].bt); 
 	} 
 
    printf("Enter time quantum: "); 
    scanf("%d",&q); 
    scheduler(job,n,q); 
} 
