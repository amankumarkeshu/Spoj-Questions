#include<stdio.h>
#include<math.h>
#include<string.h>
long long int mod_pow(long long int num, long long int pw)
{
    long long int test;
    for(test = 1; pw; pw >>= 1)
    {
        if (pw & 1)
        test = (test * num);
        num = (num * num);
    }

    return test;

}
int main()
{
long long int t,z,i,c,r;
char s[101];
long long int n;
scanf("%lld",&t);
while(t--)
{
char s[101];
z=0;
scanf("%lld",&n);
n=n-1;
while(1)
{
z++;
if((n-mod_pow(5,z))>=0)
n=n-mod_pow(5,z);
else
break;
}
c=0;
//printf("z=%d n=%lld\n",z,n);
while(n>0)
{
r=n%5;
if(r==0)
s[c]='m';
else if(r==1)
s[c]='a';
else if(r==2)
s[c]='n';
else if(r==3)
s[c]='k';
else if(r==4)
s[c]='u';
c++;
n=n/5;
}
for(i=1;i<=z-c;i++)
printf("m");
for(i=c-1;i>=0;i--)
printf("%c",s[i]);
printf("\n");
}
return(0);
}
