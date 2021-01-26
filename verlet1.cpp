//Verlet Algorithm
#include<iostream>
#include<cmath>
#include<fstream>
#define h .01
#define k 150
#define m 7.2
using namespace std;
double t=0,x=0.5,v=4;
double f(double t,double x,double v)
{
    return -2*v-(k/m)*x;
}

void verlet(double t0,double x0,double v0)
{
    double x=x0,v=v0,t;
    ofstream fout("var.dat");
    for(t=0;t<=100;t+=h)
    {
        fout<<t<<" " <<x<<" "<<v<<endl;
        double x_old=x;
        x+=h*v+(h*h/2)*f(t,x,v);
        v+=(h/2)*(f(t,x,v)+f(t,x_old,v));
    }
}
int main()
{
    verlet(t,x,v);
    return 0;
}
