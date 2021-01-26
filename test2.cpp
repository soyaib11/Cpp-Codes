#include <iostream>
#include <cmath>
using namespace std;
double f(int N)
{
    /*double prod=1;
    for(int i=1;i<=n;i++)
    {
        prod*=i;
    }
    return prod;*/
    if(N==0)
        return 0;
    else if(N==1)
        return 1;
    else
        return N*f(N-1);
}
int main()
{
    cout<<f(4)<<endl;
    return 0;
}
