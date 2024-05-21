#include<iostream>
using namespace std;

void printArray(int* A, int n){
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

void insertionSort(int* A, int n){
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n-1; i++)
    {   
        // Loop for each pass
        key = A[i];
        j = i-1;

        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    
}

int main(){
    int A[] = {12, 54, 65, 7, 23, 9};
    int siz = 6;

    cout<<"Printing array before sorting: "<<endl;
    printArray(A, siz);

    insertionSort(A, siz);

    cout<<"Printing array after sorting: "<<endl;
    printArray(A, siz);
}