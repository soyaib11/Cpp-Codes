#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double f(double phi,double theta_M)
{
    double a=pow(sin(theta_M/2.0),2.0);
    double b=pow(sin(phi),2);
    double c=4*sqrt(0.0253)*(1/sqrt(1-a*b));
    return c;
}
double period(double theta_M)
{
    double a=0,b=M_PI/2;
    int i,n=100;
    double I=0.0;
    double h=(b-a)/n;
    for(i=1;i<n;i++)
    {
        I+=f(a+i*h,theta_M);
    }
    return (h/2)*(f(a,theta_M)+2*I+f(b,theta_M));
}
int main()
{
    ofstream fout("pendulum.dat");
    for(double theta_M=0;theta_M<=M_PI/2.0;theta_M+=M_PI/1000)
    {
        fout<<theta_M<<" "<<period(theta_M)<<endl;
    }
    return 0;
}
