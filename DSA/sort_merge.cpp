#include <iostream>
using namespace std;

void printArray(int* A, int n){
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

void merge(int A[], int mid, int low, int high){
    int i, j, k, B[100];
    i = low;
    j = mid+1;
    k = low;

    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        B[k] = A[i];
        i++;
        k++;
    }
    while ((j <= high))
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for(int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);

        merge(A, mid, low, high);
    }
}

int main(){
    int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int siz = 9;

    cout<<"Printing array before sorting: "<<endl;
    printArray(A, siz);

    cout<<"Running Merge Sort..."<<endl;
    mergeSort(A, 0, siz-1);

    cout<<"Printing array after sorting: "<<endl;
    printArray(A, siz);
}