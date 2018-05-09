#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50000

void InsertionSort(int* a,int len){
    int i,j,t,h;
    i=j=t=h=0;
    for(i=1;i<len;i++){
        t = a[i];
        j = i-1;
        while (j>=0 && t<a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
    }
}

int main() {
	char file_name[20];
	sprintf(file_name,"InsertionSort %d.txt",SIZE);
	FILE *fp = fopen(file_name,"w");
	
    double sum = 0;
	clock_t start_time, end_time;
    float total_time = 0;
    int arr[SIZE],i;
    unsigned seed;
    seed = (unsigned)time(NULL);
    srand(seed);

    
    int count = 0;
    
    while(count!=25){
    		
    	total_time = 0;

    	for(i=0;i<SIZE;i++){
	        arr[i] = rand()%SIZE;
	    }
	    
	    start_time = clock();
	    InsertionSort(arr, SIZE);
	    end_time = clock();
	    total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC;
	    printf("Time : %f sec \n", total_time);
	    fprintf(fp,"%lf\r\n", total_time);
	    sum += total_time;
	    count++;
	}
	fprintf(fp,"InsertionSort %d , Avg : %lf",SIZE,sum/25);
    
    return 0;
}
