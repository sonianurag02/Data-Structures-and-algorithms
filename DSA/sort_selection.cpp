#include<iostream>
using namespace std;

void printArray(int* A, int n){
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

void selectionSort(int* A, int n){
    cout<<"Running Selection Sort..."<<endl;
    int indexOfMin, temp;
    for(int i = 0; i < n-1; i++){
        indexOfMin = i;
        for(int j = i+1; j < n; j++){
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        // Swap 
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main(){
    int A[] = {3, 5, 2, 13, 12};
    int siz = 5;

    cout<<"Printing array before sorting: "<<endl;
    printArray(A, siz);

    selectionSort(A, siz);

    cout<<"Printing array after sorting: "<<endl;
    printArray(A, siz);
}