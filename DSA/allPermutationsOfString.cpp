#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void swap(char *x, char *y){
    char ch;
    ch = *x;
    *x = *y;
    *y = ch;
}
void permutation(string s, int start, int end){
    static int count;
    // int j;
    if(start == end){
        count++;
        cout<<count<<": "<<s<<endl;
    }
    else{
        for(int j = start; j <= end; j++){
            swap((s[start]),(s[j]));
            permutation(s,start+1,end);
            swap((s[start]),(s[j])); //Backtracking
        }
    }
}
int main(){
    string name;
    cout<<"Enter a string: "<<endl;
    cin>>name;
    int start = 0, len = name.length();
    permutation(name, start, len-1);
    return 0;
}