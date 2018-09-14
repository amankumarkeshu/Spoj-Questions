#include<stdio.h>
void main()
{int x,t; scanf("%d",&t);
while(t--){
double i,s=0;
scanf("%d",&x);
for(i=1;i<=x;++i) s+=(i)/(i*i*i*i + i*i + 1);
printf("%.5lf\n",s);}}
