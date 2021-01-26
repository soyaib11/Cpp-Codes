#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double k=150, m=7.2, t=0, x=0.5, v=4, h=0.01;
double f(double t,double x,double v)
{
    return -(k*x)/m;
}
void verlet(double t0,double x0,double v)
{
    ofstream fout("var1.dat");
    for(t=t0;t<=5;t+=h)
    {
        x0=x;
        fout<<t<<" "<<x<<" "<<v<<endl;
        x+=(h*v)+((h*h)/2)*(f(t,x,v));
        v+=(h/2)*(f(t,x,v)+f(t,x0,v));
    }
}
int main()
{
    verlet(t,x,v);
    return 0;
}
