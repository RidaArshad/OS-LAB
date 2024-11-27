#include <stdio.h> 
 
void displayMatrix(int matrix[][10], int rows, int cols) 
{ 
    for(int i = 0; i < rows; i++) 
	{ 
        for (int j = 0; j < cols; j++) 
		{ 
            printf("%d ", matrix[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
int main() 
{ 
	int Max[10][10], alloc[10][10], need[10][10], avail[10], completed[10], safeSequence[10]; 
    int p, r, i, j, process, count = 0; 
 
    
    do 
 	{ 
        printf("Enter the number of processes (max 10): "); 
        scanf("%d", &p); 
    } while (p <= 0 || p > 10); 
 
    
    do 
 	{ 
        printf("Enter the number of resources (max 10): "); 
        scanf("%d", &r); 
    } while (r <= 0 || r > 10); 
 
    
    for (i = 0; i < p; i++) 
        completed[i] = 0; 
 
   
    printf("Enter the Max Matrix for each process:\n"); 
    for (i = 0; i < p; i++) 
 	{ 
        printf("For process %d: ", i + 1); 
        for (j = 0; j < r; j++) 
            scanf("%d", &Max[i][j]); 
    } 
 
 
 
 
   
    printf("Enter the allocation for each process:\n"); 
    for (i = 0; i < p; i++)  
	{ 
        printf("For process %d: ", i + 1); 
        for (j = 0; j < r; j++) 
            scanf("%d", &alloc[i][j]); 
    } 
 
    
    printf("Enter the Available Resources:\n"); 
    for (i = 0; i < r; i++) 
        scanf("%d", &avail[i]); 
 
     
    for (i = 0; i < p; i++) 
        for (j = 0; j < r; j++) 
            need[i][j] = Max[i][j] - alloc[i][j]; 
 
    
    printf("\nMax Matrix:\n"); 
    displayMatrix(Max, p, r); 
 
    printf("\nAllocation Matrix:\n"); 
    displayMatrix(alloc, p, r); 
 
    printf("\nNeed Matrix:\n"); 
    displayMatrix(need, p, r); 
 
    
    Do 
	{ 
        process = -1; 
 
        for (i = 0; i < p; i++) 
 		{ 
            if (completed[i] == 0)  
			{ 
                process = i; 
 
                for (j = 0; j < r; j++) 
 				{ 
                    if (avail[j] < need[i][j])  
					{ 
                        process = -1; 
                        break; 
                    } 
                } 
            }
			if (process != -1) 
                break; 
        } 
 
        if (process != -1)  
		{ 
            printf("\nProcess %d runs to completion!", process + 1); 
 
             
            for (j = 0; j < r; j++) 
 			{ 
                avail[j] += alloc[process][j]; 
                alloc[process][j] = 0; 
                Max[process][j] = 0; 
            } 
 
            
            completed[process] = 1; 
 
             
            safeSequence[count] = process + 1; 
            count++; 
        } 
    } while (count != p && process != -1); 
  
    if (count == p)  
	{ 
        printf("\nThe system is in a safe state!!\n"); 
        printf("Safe Sequence : < "); 
        for (i = 0; i < p; i++) 
            printf("%d ", safeSequence[i]); 
            printf(">\n"); 
    }  
	else 
        printf("\nThe system is in an unsafe state!!\n"); 
        return 0; 
}
