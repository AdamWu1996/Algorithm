#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 800000

void QuickSort(int* arr,int left,int right){
    int f,t;
    int rtemp,ltemp;
    double sum = 0;
    
    ltemp = left;
    rtemp = right;
    f = arr[(left+right)/2];
    while (ltemp<rtemp) {
        while (arr[ltemp]<f) {
            ++ltemp;
        }
        while (arr[rtemp]>f) {
            rtemp--;
        }
        if(ltemp<=rtemp){
            t = arr[ltemp];
            arr[ltemp] = arr[rtemp];
            arr[rtemp] = t;
            --rtemp;
            ++ltemp;
        }
    }
    if(ltemp == rtemp){
        ltemp++;
    }
    if(left<rtemp){
        QuickSort(arr, left, ltemp-1);
    }
    if(ltemp<right){
        QuickSort(arr, rtemp+1, right);
    }
}

int main() {
	char file_name[20];
	sprintf(file_name,"QuickSort %d.txt",SIZE);
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
	    QuickSort(arr, 0, SIZE-1);
	    end_time = clock();
	    total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC;
	    printf("Time : %f sec \n", total_time);
	    fprintf(fp,"%lf\r\n", total_time);
	    sum += total_time;
	    count++;
	}
	fprintf(fp,"QuickSort %d , Avg : %lf",SIZE,sum/25);

    return 0;
}

