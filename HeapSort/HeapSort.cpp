#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define LEN 300000
#define OFFSET 1
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

void heapSort(int*, int len, int(*)(int, int));
void heapTree(int*, int, int(*)(int, int)); 
void selectFromHeap(int*, int, int(*)(int, int)); 

void bubbleLeaf(int*, int, int(*)(int, int));
int isBubbleable(int*, int, int, int(*)(int, int));

void bubbleRoot(int*, int, int(*)(int, int));
int idxFromChilds(int*, int, int, int(*)(int, int));
int isRightLeafSuitable(int*, int, int, int(*)(int, int));

void print(int*, int len);
int ascending(int, int);
int descending(int, int);

int main(void) { 

srand(time(NULL));
	double sum = 0;
	char file_name[20];
	sprintf(file_name,"HeapSort %d.txt",LEN);
	FILE *fp = fopen(file_name,"w");
    int num[LEN] = {0};
	int i;
	
	clock_t start_time, end_time;
    float total_time = 0;
	unsigned seed;
    seed = (unsigned)time(NULL);
    srand(seed);
//    heapSort(num, LEN, descending); 
//    print(num, LEN);

    int count = 0;
    
    while(count!=25){
	
    	total_time = 0;
    	for(i=0;i<LEN;i++)
			num[i] = rand();
	    
	    start_time = clock();
	    heapSort(num, LEN, ascending);
	    end_time = clock();
	    total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC;
	    printf("Time : %f sec \n", total_time);
	    fprintf(fp,"%lf\r\n", total_time);
	    sum += total_time;
	    count++;
	}
	fprintf(fp,"HeapSort %d , Avg : %lf",LEN,sum/25);

     
//    print(num, LEN);


    return 0; 
}

void heapSort(int* num, int len, int(*compar)(int, int)) {
    heapTree(num, len, compar);
    selectFromHeap(num, len, compar); 
}

void heapTree(int* num, int len, int(*compar)(int, int)) { 
    int i, end;
    for(i = 1, end = len + 1; i < end; i++) { bubbleLeaf(num, i, compar); }
}

void selectFromHeap(int* num, int len, int(*comp)(int, int)) {
    int end;
    for(end = len; end > OFFSET; end--) {
        SWAP(num[1 - OFFSET], num[end - OFFSET]);
        bubbleRoot(num, end, comp);
    }
}

void bubbleLeaf(int* num, int eleIdx, int(*compar)(int, int)) {
    int childIdx, parentIdx;
    for(childIdx = eleIdx, parentIdx = eleIdx / 2;
        isBubbleable(num, childIdx, parentIdx, compar);
        childIdx = parentIdx, parentIdx = childIdx / 2) {
         SWAP(num[parentIdx - OFFSET], num[childIdx - OFFSET]); 
    }
}

int isBubbleable(int* num, int childIdx, 
                 int parentIdx, int(*compar)(int, int)) {
    return childIdx > OFFSET && 
           compar(num[parentIdx - OFFSET], num[childIdx - OFFSET]) < 0;
}

void bubbleRoot(int* num, int end, int(*comp)(int, int)) {
    int parentIdx, childIdx;
    for(parentIdx = 0 + OFFSET, 
        childIdx = idxFromChilds(num, parentIdx, end, comp);
        childIdx < end && 
        comp(num[childIdx - OFFSET], num[parentIdx - OFFSET]) > 0; 
        parentIdx = childIdx, 
        childIdx = idxFromChilds(num, parentIdx, end, comp)) {
        SWAP(num[parentIdx - OFFSET], num[childIdx - OFFSET]); 
    }    
}

int idxFromChilds(int* num, int parentIdx, int end, int(*comp)(int, int)) {
   int childIdx = parentIdx * 2;
   return isRightLeafSuitable(num, childIdx, end, comp) ? 
              childIdx + 1 : childIdx;
}

int isRightLeafSuitable(int* num, int childIdx, 
                        int end, int(*comp)(int, int)) {
    return childIdx < end - 1 && 
           comp(num[childIdx + 1 - OFFSET], num[childIdx - OFFSET]) > 0;
}

void print(int* arr, int len) {
    int i;
    for(i = 0; i < len; i++) { printf("%d ", arr[i]); } 
    printf("\n");
}

int ascending(int a, int b) { return a - b; }
int descending(int a, int b) { return -ascending(a, b); }
