#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {int x;
        cin >> x;
        double sum=0;
        for(int i=1;i<=x;i++)
        {
            double sqr = pow(i,2);
            sum += i/((sqr+i+1)*(sqr-i+1));
        }cout << fixed<<setprecision(5) << sum << endl;
    }
}
