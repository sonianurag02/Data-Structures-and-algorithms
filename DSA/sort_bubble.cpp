#include<iostream>
using namespace std;

void printArray(int* A, int n){
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

void bubbleSortAdaptive(int* A, int n){
    int temp;
    int isSorted = 0;
    for(int i = 0; i < n-1; i++){ // For Number of Passes  
        cout<<"Working on pass number "<<i+1<<endl;
        isSorted = 1;
        for(int j = 0; j < n-i-1; j++){ // For comparision
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted) return;
    }
    cout<<"\n";
}

void bubbleSort(int* B, int n){
    int temp;
    for(int i = 0; i < n-1; i++){ // For Number of Passes  
        for(int j = 0; j < n-i-1; j++){ // For comparision
            if(B[j]>B[j+1]){
                temp = B[j];
                B[j] = B[j+1];
                B[j+1] = temp;
            }
        }
    }
    cout<<"\n";
}

int main(){
    int A[] = {12, 54, 65, 7, 23, 9};
    // int A[] = {1, 2, 3, 4, 5, 6};
    int B[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    int siz = 6, siz2 = 10;

    cout<<"Printing Array before sorting: "<<endl;
    printArray(A, siz);
    bubbleSort(A, siz);
    cout<<"Printing Array after sorting: "<<endl;
    printArray(A, siz);

    cout<<"Printing Array before sorting: "<<endl;
    printArray(B, siz2);
    bubbleSortAdaptive(B, siz2);
    cout<<"Printing Array after adaptive sorting: "<<endl;
    printArray(B, siz2);

    return 0;
}