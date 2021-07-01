#include<iostream>
using namespace std;
 
double cube(double x)
{
    x = x*x*x;
    return x;
}
 
void cube2(double &x){
    x = x*x*x;
}
 
void cube3(double *x) {
    *x = (*x)*(*x)*(*x);
}
 
int main()
{
    double y=10;
    cout<<y<<endl;
    cube(y);
    cout<<y<<endl;
    cube2(y);
    cout<<y<<endl;
    cube3(&y);
    cout<<y<<endl;

    return 0;
}
