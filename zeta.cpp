#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double zeta(double s)
{
    double sum=0.0;
    for(int i=1;i<=30;i++)
    {
        sum+=pow(i,-s);
    }
    return sum;
}
double gamma(double s)
{
    double sum=0.0;
    for(int i=2;i<s;i++)
    {
        sum+=pow(-1,i)*zeta(i)/i;
    }
    return sum;
}
int main()
{
    ofstream fout("zeta.dat");
    ofstream file("gam.dat");
    for(int s=2;s<=20;s+=2)
    {
        fout<<s<<" "<<zeta(s)<<endl;
        file<<s<<" "<<gamma(s)<<endl;
    }
    return 0;
}
