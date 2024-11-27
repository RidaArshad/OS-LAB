#include <stdio.h> 
int n, pg[30], fr[10]; 
void fifo(); 
 
int main()  
{ 
    int i; 
 
    printf("Enter total number of pages: "); 
    scanf("%d", &n); 
 
    printf("Enter page sequence:\n"); 
    for (i = 0; i < n; i++) 
        scanf("%d", &pg[i]); 
 
    fifo(); 
 
    return 0; 
} 
 
void fifo()  
{ 
    int i, f = 0, r = 0, s = 0, count = 0, flag = 0, num, psize; 
 
    printf("Enter the size of page frame: "); 
    scanf("%d", &psize); 
 
    for (i = 0; i < psize; i++) 
        fr[i] = -1; 
 
 
    while (s < n) 
 	{ 
        flag = 0; 
        num = pg[s]; 
 
        for (i = 0; i < psize; i++) 
 		{ 
            if (num == fr[i])  
           { 
                s++; 
                flag = 1; 
                break; 
            } 
  		} 
 
        if (flag == 0)  
		{ 
            if (r < psize)  
         	{ 
                fr[r] = pg[s]; 
                r++; 
                s++; 
                count++; 
            }  	
			else  
        	{ 
            	if (f < psize)  
            	{ 
                	fr[f] = pg[s]; 
                	s++; 
                	f++; 
                	count++; 
            	} 
    		}
    	}
 		else 
		{ 
            f = 0; 
        } 
    } 

 
    printf("\nPage Frame: "); 
    for (i = 0; i < psize; i++) 
        printf("%d ", fr[i]); 
    printf("\nPage Faults: %d\n", count); 
}
