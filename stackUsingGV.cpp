#include<iostream>
using namespace std;
 
int mystack[4];
int peek = -1;
int stack_size = 4;
 
bool isempty()
{
    if(peek<0) {
        return true;
    }
    return false;
}
 
bool isfull()
{
    if(peek == stack_size-1) {
        return true;
    }
    return false;
}
 
void push(int data)
{
    if(isfull()==false) {
        peek++;
        mystack[peek] = data;
    }
    else {
        cout<<"stack is full"<<endl;
    }
}
 
void pop()
{
    if(isempty()==false) {
        peek--;
    }
    else {
        cout<<"stack is empty"<<endl;
    }
}
 
int peek_value()
{
    if(isempty()==false)
        return mystack[peek];
}
 
int main()
{
    for(int i=0;i<3;i++) {
        push(i+1);
        cout<<peek_value()<<endl;
    }
}
