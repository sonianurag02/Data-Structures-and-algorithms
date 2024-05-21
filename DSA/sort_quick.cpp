#include<iostream>
using namespace std;

void printArray(int* A, int n){
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

int partition(int* A, int low, int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;

    do{
        while(A[i] <= pivot){
            i++;
        }
        while(A[j] > pivot){
            j--;
        }
        if(i<j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i < j);

    // Swap
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(int* A, int low, int high){
    int partitionIdx; //Index of pivot after partition

    if(low < high){
        partitionIdx = partition(A, low, high);
        printArray(A, 9);
        quickSort(A, low, partitionIdx-1); // sort left subarray
        quickSort(A, partitionIdx+1, high); // sort right subarray
    }
}

int main(){
    int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int siz = 9;

    cout<<"Printing array before sorting: "<<endl;
    printArray(A, siz);

    cout<<"Running Quick Sort..."<<endl;
    quickSort(A, 0, siz-1);

    cout<<"Printing array after sorting: "<<endl;
    printArray(A, siz);
}