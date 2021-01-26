#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;
double t=0, x=0, v=1, dt=0.1, v0;

void euler(double t,double x,double v,double dt)
{
    ofstream fout("oscillator.dat");
    for(int i=0;i<100;i++)
    {
        v0=v;
        v+=(1-x*x)*v0*dt-x*dt;
        x+=v0*dt;
        t+=dt;
        fout<<t<<" "<<x<<" "<<v<<endl;
    }
}
int main()
{
    euler(t,x,v,dt);
    return 0;
}
