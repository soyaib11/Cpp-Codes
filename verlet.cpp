#include<iostream>
#include<cmath>
#include<fstream>
#define h .01
#define k 150
#define m 7.2
using namespace std;
double f(double t,double x,double v)
{return -2*v-(k/m)*x;}
double verlet(double t0,double x0,double v0)
{double x=x0;double v=v0;double t;
ofstream file("od.dat");
for(t=t0;t<=10;t+=h)
{//cout<<t<<"	"<<x<<"		"<<v<<endl;
file<<t<<"	"<<x<<"		"<<v<<endl;
double x_old=x;
x+=h*v+h*h/2*f(t,x,v);
v+=h/2*(f(t,x,v)+f(t,x_old,v));}}
int main()
{verlet(0,.5,4);
return 0;}


