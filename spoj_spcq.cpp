#include<iostream>
#define ll long long
using namespace std;

int main()
{
    ll t,n,x,m,sum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        m=n;
        while(1)
        {
            m=n;
            sum=0;
            while(m>0)
            {
                x=m%10;
                sum+=x;
                m=m/10;
            }
            if(n%sum==0)
            {
                cout << n << endl;
                break;
            }
            else
                n++;
        }
    }
    return 0;
}
