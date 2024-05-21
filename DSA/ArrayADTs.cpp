#include <iostream>
using namespace std;

class ArrayADTs
{
private:
    int array_size;
    int used_size;
    int *ptr;

public:
    void createArray(class ArrayADTs *data, int a_size, int u_size)
    {
        data->array_size = a_size;
        data->used_size = u_size;
        data->ptr = new int[data->array_size];
    }
    void setData(class ArrayADTs *data)
    {
        int n;
        for (int i = 0; i < data->used_size; i++)
        {
            cout << "Enter element for index " << i << endl;
            cin >> n;
            (data->ptr)[i] = n;
        }
    }
    // Array Traversal
    void showData(class ArrayADTs *data)
    {
        for (int i = 0; i < data->used_size; i++)
        {
            cout<<(data->ptr)[i]<<endl;
        }
    }
    // Insertion
    int indexInsertion(class ArrayADTs *data, int element, int index){
        if(data->used_size >= data->array_size){
            return -1;
        }
        for(int i = data->used_size; i >= index; i--){
            (data->ptr)[i+1] = (data->ptr)[i];
        }
        (data->ptr)[index] = element;
        data->used_size = data->used_size + 1;
        return 1;
    }
    // Deletion
    int indexDeletion(class ArrayADTs *data, int index){
        if(data->used_size < index){
            return -1;
        }
        for(int i = index; i < data->used_size - 1; i++){
            (data->ptr)[i] = (data->ptr)[i+1];
        }
        data->used_size = data->used_size - 1;
        return 1;
    }
    // Linear search
    int linearSearch(class ArrayADTs *data, int element){
        for(int i = 0; i < data->used_size; i++){
            if((data->ptr)[i] == element){
                return ((data->ptr)[i]);
            }
        }
        return -1;
    }
    // Binary search
    int binarySearch(class ArrayADTs *data, int element){
        int low, high, mid;
        low = 0;
        high = (data->ptr)[used_size-1];
        while(low<high){
            mid = (high + low)/2;
            if(data->ptr[mid] == element){
                return mid;
            }
            if((data->ptr)[mid] < element){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ArrayADTs a1;
    int element, index, ch, array_size, used_size, inst, dltn;

    cout<<"Enter a size you want to create an array of: "<<endl;
    cin>>array_size;
    cout<<"Enter a size of an array you want to use which is less than array size: "<<endl;
    cin>>used_size;

    if(used_size <= array_size){
        cout<<"Creating an array"<<endl;
        a1.createArray(&a1, array_size, used_size);

        cout<<"Setting values: "<<endl;
        a1.setData(&a1);
    }
    else{
        cout<<"Memory Limit Exceeded!!"<<endl;
        return 1;
    }

    while(1){
        cout<<"Enter your choice:\n"
            <<"1. Show Values of an array\n"
            <<"2. Insert a value on an array\n"
            <<"3. Delete a value from an array\n"
            <<"4. Linear Search\n"
            <<"5. Binary Search\n"
            <<"6. Exit"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Showing values: "<<endl;
            a1.showData(&a1);
            break;

        case 2:
            cout<<"Enter an index at which you want to insert an element: "<<endl;
            cin>>index;
            cout<<"Enter an element: "<<endl;
            cin>>element;
            inst = a1.indexInsertion(&a1, element, index);

            if(inst == -1){
                cout<<"Insertion Failed"<<endl;
            }
            else{
                cout<<"Insertion Successfull!"<<endl;
                a1.showData(&a1);
            }
            break;

        case 3:
            cout<<"Enter an index at which you want to delete an element: "<<endl;
            cin>>index;
            dltn = a1.indexDeletion(&a1, index);

            if(dltn == -1){
                cout<<"Deletion Failed"<<endl;
            }
            else{
                cout<<"Deletion Successfull!"<<endl;
                a1.showData(&a1);
            }
            break;

        case 4:
            cout<<"Enter an element you want to search in an array using linear search: "<<endl;
            cin>>element;
            index = a1.linearSearch(&a1, element);
            cout<<"Element was found at index "<<index<<endl;
            break;

        case 5:
            int element,index;
            cout<<"Enter an element you want to search in an array using binary search: "<<endl;
            cin>>element;
            index = a1.binarySearch(&a1, element);
            cout<<"Element was found at index "<<index<<endl;
            break;

        case 6:
            cout<<"Successfully terminatedd!!"<<endl;
            exit(0);
            break;
        
        default:
            cout<<"Invalid choice! Enter your choice again."<<endl;
            break;
        }
    }
}