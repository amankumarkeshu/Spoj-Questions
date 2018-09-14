#include<stdio.h>
#include<math.h>
int main()
{
 long long a,b,c=1,d,i,j,t,n;
 scanf("%lld",&t);
 while(t--){
  scanf("%lld",&n);
    if(n<3)
    {
       a=0;
    }
  else
    {
   b=sqrt(n);
   while(1)
   {
    if(b*(b+2)<=n)
    {
     a=b;
     break;
    }
  else{
     b--;
    }
   }
  }
  printf("Case %lld: %lld\n",c,a);
  c++;
 }
 return 0;
}
