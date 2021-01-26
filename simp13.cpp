#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double f(double x)
{
    return x*x*x;
}
double simp13(double a,double b,int n)
{
    double I=0.0,J=0.0;
    double h=(b-a)/n;
    int i;
    for(i=1;i<n;i+=2)
    {
        I+=f(a+i*h);
    }
    for(i=2;i<n;i+=2)
    {
        J+=f(a+i*h);
    }
    double A;
    A=(h/3)*(f(a)+4*I+2*J+f(b));
    return A;
}
int main()
{
    double a=0,b=M_PI/2;
    //ofstream fout("hudai.dat");
    int n;
    cout<<"n= ";
    cin>>n;
    /*for(int i=1;i<=100;i++)
    {
        fout<<i<<" "<<f(i)<<" "<<simp13(-2,i,n)<<endl;
    }*/
    cout<<"result: "<<simp13(a,b,n)<<endl;
    return 0;
}
