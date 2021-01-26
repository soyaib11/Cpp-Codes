#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double fact(int n)
{
    double prod=1;
    for(int i=1;i<=n;i++)
         prod*=i;
         return prod;
}
double f(double z,double theta,int n)
{
    double a=pow(z,n);
    double b=a/(pow(2,(n+1))*fact(n));
    double c=cos(z*cos(theta));
    double d=c*pow(sin(theta),((2*n)+1));
    return b*d;
}
double bessel(int n,double z)
{
    double a=0,b=M_PI;
    double I=0.0;
    int N=100;
    double h=(b-a)/N;
    for(int i=1;i<N;i++)
    {
        I+=f(z,a+i*h,n);
    }
    return (h/2)*(f(z,a,n)+2*I+f(z,b,n));
}
double ff(double z)
{
    return 0.5*bessel(0,z)*sqrt(z);
}
double fresnel(double x)
{
    double a=0,b=x,I=0.0;
    int N=1000;
    double h=(b-a)/N;
    int i;
    for(i=1;i<N;i++)
    {
        I+=ff(a+i*h);
    }
    return (h/2)*(ff(a)+2*I+ff(b));
}
int main()
{
    ofstream fout("bessel.dat");
    ofstream file("fres.dat");
    for(double z=0;z<=25;z+=0.01)
    {
        fout<<z<<" "<<bessel(0,z)<<" "<<bessel(1,z)<<" "<<bessel(2,z)<<" "<<bessel(3,z)<<endl;
    }
    for(double x=0;x<=20;x+=0.1)
    {
        file<<x<<" "<<fresnel(x)<<endl;
    }
    return 0;
}
