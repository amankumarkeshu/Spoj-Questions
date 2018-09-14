
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
   long long int a[4],p;
   int j,i=1;
   while(scanf("%lld ",&a[0])!=EOF)
    {

        for(j=1;j<4;j++)
        {
            scanf("%lld",&a[j]);

        }
        sort(a,a+4);
        p=a[3]+a[2];
        printf("Case %d: %lld\n",i,p);
        i++;
    }
    return 0;
}
