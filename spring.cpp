#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double k=3.5, g=9.81, m=0.2, L=1;
void cromer(double l0,double v0,double theta0,double w0,double dt)
{
    double l=l0, v=v0, theta=theta0, w=w0;
    ofstream fout("coupled-cromer.dat");
    for(double t=0;t<=10;t+=dt)
    {
        fout<<t<<" "<<l<<" "<<v<<" "<<theta<<" "<<w<<endl;
        v+= ((L+1)*w*w-(k/m)*l+g*cos(theta))*dt;
        l+=v*dt;
        w+=-(1/(L+1))*(g*sin(theta)+2*v*theta)*dt;
        theta+=w*dt;
        t+=dt;
    }
}
int main()
{
    cromer(0,1,0,0.3,0.01);
    return 0;
}
