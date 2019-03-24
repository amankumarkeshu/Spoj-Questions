#include<stdio.h>
int main(){
 long long t,a,ar[200000],i,n,v;
 scanf("%lld",&t);
 while(t--){
  v=0;
  scanf("%lld",&n);
  for(i=0;i<n;i++){
   scanf("%lld",&ar[i]);
   if(ar[i]>i){
    v=1;
   }
  }
  if(v==1){
   printf("NO\n");
  }else{
   printf("YES\n");
  }
 }
 return 0;
}
