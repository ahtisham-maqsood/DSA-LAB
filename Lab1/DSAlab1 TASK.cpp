#include<iostream>
using namespace std;
int main(){
    int num=10;
    int *ptr=&num;
    cout<<"Value of num"<<num<<endl;
    cout<<"Value of ptr is"<<*ptr<<endl;
    cout<<"Addrse "<<ptr<<endl;
    *ptr=67;
    cout<<"Updated value of num"<<num<<endl;
    cout<<"Updated value of *ptr"<<*ptr<<endl;
    cout<<"Addres "<< ptr<<endl;
    return 0;
}
