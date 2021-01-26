#include <iostream>
#include <cmath>
using namespace std;
double fact(int n)
{
    if(n<0)
        cout<<"n cannot be negative!"<<endl;
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
int main()
{
    cout<<fact(3)<<endl;
}
