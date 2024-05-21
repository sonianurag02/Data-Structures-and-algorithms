#include<iostream>
using namespace std;

void TOH(int n, char beg, char aux, char con){
    if(n >= 1){
        TOH(n-1,beg,con,aux);
        cout<<beg<<" to "<<con<<endl;
        TOH(n-1,aux,beg,con);
    }
}
int main(){
    char A, B, C;
    TOH(10 , 'A', 'B', 'C');
}