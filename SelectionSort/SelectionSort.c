#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000

void SelectionSort(int* a,int len){
    int i,j,k;
    i = j = k = 0;
    int temp;
    
    for(i=0;i<len;i++){
        k=i;
        for(j=i+1;j<len;j++){
            if(a[j]<a[k])
                k = j;
        }
        
        if(k!=i){
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    	}
    }
    
}

int main() {
	char file_name[20];
	sprintf(file_name,"SelectionSort %d.txt",SIZE);
	FILE *fp = fopen(file_name,"w");
	
    double sum = 0;
    
    int i;
    int arr[SIZE];
    clock_t start_time, end_time;
    float total_time;
    unsigned seed;
    seed = (unsigned)time(NULL);
    srand(seed);  
    
    
    int count = 0;
    
    while(count!=25){
    	for(i=0;i<25;i++)
    		arr[i] = 0;
    	
    	total_time = 0;
    	
    	for(i=0;i<SIZE;i++){
	        arr[i] = rand()%SIZE;
	    }
	    
	    start_time = clock();
	    SelectionSort(arr, SIZE);
	    end_time = clock();
	    total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC;
	    printf("Time : %f sec \n", total_time);
	    fprintf(fp,"%lf\r\n", total_time);

  		sum += total_time;
	    count++;
	}
	fprintf(fp,"SelectionSort %d , Avg : %lf",SIZE,sum/25);

    return 0;
}
