#include<iostream>
using namespace std;
enum we{
    january, february, march, april, may, june, july, august, september, octtober, november, december
};
int main(){
    for(int i = january; i <= december; i++){
        cout<<i+1<<" ";
    }
    cout<<"\n";

    int ch;
    cout<<"Enter your choice (use number of months: like for january - 1, february - 2...): "<<endl;
    cin>>ch;
    switch (ch)
    {
    case 1:
        cout<<"January: "<<january+1<<endl;
        break;

    case 2:
        cout<<"February: "<<february+1<<endl;
        break;

    case 3:
        cout<<"March: "<<march+1<<endl;
        break;
        
    case 4:
        cout<<"April: "<<april+1<<endl;
        break;
        
    case 5:
        cout<<"May: "<<may+1<<endl;
        break;
        
    case 6:
        cout<<"June: "<<june+1<<endl;
        break;
        
    case 7:
        cout<<"July: "<<july+1<<endl;
        break;
        
    case 8:
        cout<<"August: "<<august+1<<endl;
        break;
        
    case 9:
        cout<<"September: "<<september+1<<endl;
        break;
        
    case 10:
        cout<<"October: "<<octtober+1<<endl;
        break;
        
    case 11:
        cout<<"November: "<<november+1<<endl;
        break;
        
    case 12:
        cout<<"December: "<<december+1<<endl;
        break;
    
    default:
        cout<<"Invalid Input"<<endl;
        break;
    }

    return 0;
}