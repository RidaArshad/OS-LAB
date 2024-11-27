#include <stdio.h> 
 
int arr[10], bur[10], rt[10], n, pr[10], t = 0, ft[10], wt[10], tat[10], pos, total = 0, ttat = 0, twt = 0; 
float avgtat, avgwt; 
 
int main()  
{ 
    int comp = 0, i; 
 
    
    printf("\nEnter the number of processes: "); 
    scanf("%d", &n); 
 
     
    for (i = 0; i < n; i++) 
    { 
        printf("\nEnter the arrival and burst time for process %d: ", i + 1); 
        scanf("%d %d", &arr[i], &bur[i]); 
        pr[i] = i + 1; 
	} 
 
     
    for (i = 0; i < n; i++) 
        rt[i] = bur[i]; 
 
 
     
    while (comp < n) 
    { 
         
        pos = -1; 
 
        for (i = 0; i < n; i++)  
        { 
            if (arr[i] <= t && rt[i] > 0)  
            {  
                if (pos == -1 || rt[i] < rt[pos])  
				{  
                    pos = i; 
                } 
            } 
        } 
 
        
        if (pos == -1)  
		{ 
            t++; 
            continue; 
        } 
 
         
        rt[pos]--; 
        t++; 
 
        
        if (rt[pos] == 0)  
		{ 
            comp++; 
            ft[pos] = t; 
            tat[pos] = ft[pos] - arr[pos];  
            wt[pos] = tat[pos] - bur[pos]; 
        } 
    } 
 
    
    for (i = 0; i < n; i++)  
	{ 
        ttat += tat[i]; 
        twt += wt[i]; 
    } 
 
    
    avgtat = (float)ttat / n; 
    avgwt = (float)twt / n; 
 
    
    printf("\nProcess\tBT\tAT\tTAT\tWT\n"); 
    for (i = 0; i < n; i++) 
 	{ 
        printf("%d\t%d\t%d\t%d\t%d\n", pr[i], bur[i], arr[i], tat[i], wt[i]); 
	} 
	printf("Avg TAT = %.2f\nAvg WT = %.2f\n", avgtat, avgwt); 
	return 0; 
}
