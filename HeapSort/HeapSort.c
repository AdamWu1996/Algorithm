#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 150000

void HeapSort(int a[],int n){
    int i,j,h,k,t;
    i=j=h=k=t=0;
    for(i=n/2-1;i>=0;i--){
        while (2*i+1<n) {
            j=2*i+1;
            if((j+1)<n){
                if(a[j]<a[j+1])
                    j++;
            }
            if(a[i]<a[j]){
                t = a[i];
                a[i] = a[j];
                a[j] = t;
                i = j;
            }
            else{
                break;
            }
        }
    }


    
    for(i=n-1;i>0;i--){
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        k = 0;
        while (2*k+1<i) {
            j=2*k+1;
            if((j+1)<i){
                if(a[j]<a[j+1])
                    j++;
            }
            if(a[k]<a[j]){
                t = a[k];
                a[k] = a[j];
                a[j] = t;
                k = j;
            }
            else{
                break;
            }
        }

    }
}

int main() {
    char file_name[20];
	sprintf(file_name,"HeapSort %d.txt",SIZE);
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
	    HeapSort(arr, SIZE);
	    end_time = clock();
	    total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC;
	    printf("Time : %f sec \n", total_time);
	    fprintf(fp,"%lf\r\n", total_time);
	    sum += total_time;
	    count++;
	}
	fprintf(fp,"HeapSort %d , Avg : %lf",SIZE,sum/25);
    return 0;
}
