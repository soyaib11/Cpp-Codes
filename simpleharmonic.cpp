#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
const double g=9.8;
const double L=1;
double t=0,theta=0,omega=1,omega_old,dt=0.1;
void euler(double t,double theta,double omega,double dt)
{
    ofstream fout("newharmonic.dat");
    for(int i=0;t<=50;i++)
    {
        omega_old=omega;
        omega-=(g/L)*theta*dt;
        theta+=omega_old*dt;
        t+=dt;
        fout<<t<<" "<<theta<<" "<<omega<<endl;
    }
}
int main()
{
    euler(t,theta,omega,dt);
    return 0;
}
