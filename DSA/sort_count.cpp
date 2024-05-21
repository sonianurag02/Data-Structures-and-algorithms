#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;

void printArray(int* A, int n){
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

int maximum(int A[], int n){
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(max < A[i]){
            max = A[i];
        }
    }
    return max;
}

void countSort(int A[], int n){
    int i, j;
    int max = maximum(A, n);

    // Create the count array
    int *count = (int *)malloc((max+1)*sizeof(int));

    // Initialize all elements to zero
    for(i = 0; i < max+1; i++){
        count[i] = 0;
    }
    // Increment the corresponding index in the count array
    for(i = 0; i < n; i++){
        count[A[i]] = count[A[i]]+1;
    }

    i = 0; // Counter for count array
    j = 0; // Counter for given array

    while(i <= max){
        if(count[i] > 0){
            A[j] = i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
    }
}

int main(){
    int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int siz = 9;

    cout<<"Printing array before sorting: "<<endl;
    printArray(A, siz);

    cout<<"Running Count Sort..."<<endl;
    countSort(A, siz);

    cout<<"Printing array after sorting: "<<endl;
    printArray(A, siz);
}