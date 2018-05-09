#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void BubbleSort(int *a,int len){
	int i,j,k,temp;
	
	for(i=0;i<len-1;i++){
		for(j=len-1;j>i;j--){
			if(a[j-1]>a[j]){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	} 
} 

int main(){
	char file_name[20];
	sprintf(file_name,"BubbleSort %d.txt",SIZE);
	FILE *fp = fopen(file_name,"w");
	
	double sum = 0;
	clock_t start_time, end_time;
    float total_time = 0;
	int arr[SIZE],i;
	
	srand(time(NULL));

    
    int count = 0;
    
    while(count!=25){
    	for(i=0;i<25;i++)
    		arr[i] = 0;
    		
    	total_time = 0;
    	
    	for(i=0;i<SIZE;i++){
	        arr[i] = rand()%SIZE;
	    }
	    
	    start_time = clock();
    	BubbleSort(arr,SIZE);
	    end_time = clock();
	    total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC;
	    printf("Time : %f sec \n", total_time);
	    fprintf(fp,"%lf\r\n", total_time);
	    sum += total_time;
	    count++;
	}
	fprintf(fp,"BubbleSort %d , Avg : %lf",SIZE,sum/25);
	
	return 0;
}











