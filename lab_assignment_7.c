#include <stdio.h>

#define SIZE 9
#define MAX 100

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b; 
    *b = temp;
}

void selectionSort(int array[], int s) {
    int freq[MAX];
    int f;
    for(int f = 0; f < MAX; f++) {
        freq[f] = 0;
    }
    int swaps = 0;

    int i, j, min_idx, temp;
    for(i = 0; i < s-1; i++){
        min_idx = i;
        for(j = i+1; j<s; j++) 
            if(array[j]<array[min_idx]) {
                min_idx = j;
                
            }
        
            if(min_idx != i) {
            swaps++;
            freq[(array[i])]++;
            freq[(array[min_idx])]++;
            swap(&(array[i]), &(array[min_idx]));
            }
        }
    
    for(int r = 0; r < SIZE; r++) {
        for(int k = 0; k < MAX; k++) {
            if(array[r] == k) {
                printf("%d: # of times %d is swapped: %d\n", array[r],array[r], freq[k]);
            }
        }
    } 
    printf("Total # of swaps: %d\n", swaps);
  
}
void bubbleSort(int array[], int s) {
    int freq[MAX];
    int f;
    for(int f = 0; f < MAX; f++) {
        freq[f] = 0;
    }
    int swaps = 0;
    int i, j, temp;
    for(i = 0; i < SIZE-1; i++) {
        for(j = 0; j < SIZE-i-1; j++) {
            if(array[j] > array[j+1]) {
                swap(&(array[j]), &(array[j+1]));
                freq[(array[j])]++; //to reduce swaps
                freq[(array[j+1])]++;
                swaps++;
            }  
        }
    }

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < MAX; j++) {
            if(array[i] == j) {
                printf("%d: # of times %d is swapped: %d\n", array[i],array[i], freq[j]);
            }
        }
    }
    printf("Total # of swaps: %d\n", swaps);
}

int main() {
    int arrayB1[] = {97,16,45,63,13,22,7,58,72};
    int arrayB2[] = {90,80,70,60,50,40,30,20,10};
    

    printf("\nBubble sort of array 1:\n");
    bubbleSort(arrayB1,SIZE);

    printf("\nBubble sort of array 2:\n");
    bubbleSort(arrayB2,SIZE);
    //create arrays again because the others are sorted now
    int arrayS1[] = {97,16,45,63,13,22,7,58,72};
    int arrayS2[] = {90,80,70,60,50,40,30,20,10};

    printf("\nSelection sort of array 1:\n");
    selectionSort(arrayS1,SIZE);

     printf("\nSelection sort of array 2:\n");
    selectionSort(arrayS2,SIZE);

    return 0;
}