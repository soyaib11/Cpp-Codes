#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

double f(double x)
{
    return pow(x,3);
}

double trap(double a,double b,int n)
{
    double I=0.0;
    double h=(b-a)/n;
    for(int i=1;i<n;i++)
    {
        I+=f(a+i*h);
    }
    return (h/2)*(f(a)+2*I+f(b));
}

int main()
{
    double a=0,b=M_PI/2;
    int n;
    /*cout<<"Lower limit: ";
    cin>>a;
    cout<<"Upper limit: ";
    cin>>b; */
    cout<<"No. of sample point: ";
    cin>>n;
    cout<<"The value of integration is: "<<trap(a,b,n)<<endl;
    return 0;
}
