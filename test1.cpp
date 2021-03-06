#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double f(double x)
{
    return x*x*x;
}
double simp(double a,double b,int n)
{
    double I=0.0,J=0.0,K=0.0;
    double h=(b-a)/n;
    int i;
    for(i=1;i<n;i+=3)
    {
        I+=f(a+i*h);
    }
    for(i=2;i<n;i+=3)
    {
        J+=f(a+i*h);
    }
    for(i=3;i<n;i+=3)
    {
        K+=f(a+i*h);
    }
    return (3*h/8)*(f(a)+(3*I)+(3*J)+(2*K)+f(b));
}
int main()
{
    double a=0,b=3;
    int n;
    cout<<"n= ";
    cin>>n;
    cout<<"Result: "<<simp(a,b,n)<<endl;
    return 0;
}

