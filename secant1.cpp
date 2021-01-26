#include <iostream>
#include <cmath>
using namespace std;
#define e 0.000001

double f(double x)
{
    return x*exp(x) - 1;
}

double secant(double x1, double x2)
{
    double x0, xm, c;
    int n;

    if(f(x1)*f(x2) < 0)
    {
        do
        {
            x0 = (x1*f(x2) - x2*f(x1))/(f(x2) - f(x1));
            c = f(x1)*f(x0);
            //update
            x1 = x2;
            x2 = x0;
            n++;
            if(f(c) == 0)
            break;
            else 
            xm = (x1*f(x2) - x2*f(x1))/(f(x2) - f(x1));
        } while (abs(xm - x0) >= e);
        return x0;
    }
    else 
    cout<<"Can't find a root in this interval\n";
    exit(1);
}

int main()
{
    double a, b;
    cout<<"Enter the interval [a, b] : \n";
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;
    double x = secant(a,b);
    cout<<"The root is: "<< x <<endl;
    return 0;
}