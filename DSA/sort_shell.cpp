#include <iostream>
#include <vector>
using namespace std;

// Function to perform Shell sort
void shellSort(vector<int>& arr) {
    int n = arr.size();
    
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already in gapped order.
        // Keep adding one more element until the entire array is gap sorted.
        for (int i = gap; i < n; i += 1) {
            // Save arr[i] in temp and make a hole at position i
            int temp = arr[i];
            
            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

// Utility function to print an array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 34, 54, 2, 3};
    cout << "Array before sorting: ";
    printArray(arr);
    
    shellSort(arr);
    
    cout << "Array after sorting: ";
    printArray(arr);
    
    return 0;
}
