#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double f(double theta,double A)
{
    double a=0.5*(A*cos(theta)+1)*sin(theta);
    b=pow((A*A+2*A*cos(theta)+1),2);
    return a/b;
}
double sc_angle(double A)
{
    double a=0,b=M_PI;
    int i,n=0;
    double I=0.0,J=0.0;
    double h=(b-a)/n;
    for(i=1;i<n;i+=2)
    {
        I+=f(a+i*h,A);
    }
    for(i=2;i<n;i+=2)
    {
        J+=f(a+i*h,A);
    }
    return (h/3)*(f(a,A)+4*I+2*J+f(b,A));
}
int main()
{
    ofstream fout("scatter.dat");
for(double A=2;A<=20;A+=0.01)
{
    fout<<A<<" "<<sc_angle(A)<<endl;
}
return 0;
}
