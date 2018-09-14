#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll a[4], c[4];
void init(){
	a[0] = a[1] = a[2] = 1;
	a[3] = 0;
	c[0] = c[3] = 1;
	c[1] = c[2] = 0;
}

void sq(){
	ll temp[4];
	temp[0] = ((a[0] * a[0]) % MOD + (a[1] * a[2]) % MOD) % MOD;
	temp[1] = ((a[0] * a[1]) % MOD + (a[1] * a[3]) % MOD) % MOD;
	temp[2] = ((a[2] * a[0]) % MOD + (a[3] * a[2]) % MOD) % MOD;
	temp[3] = ((a[2] * a[1]) % MOD + (a[3] * a[3]) % MOD) % MOD;
	memcpy(a, temp, sizeof(ll) * 4);
}

void mult(){
	ll temp[4];
	temp[0] = ((c[0] * a[0]) % MOD + (c[1] * a[2]) % MOD) % MOD;
	temp[1] = ((c[0] * a[1]) % MOD + (c[1] * a[3]) % MOD) % MOD;
	temp[2] = ((c[2] * a[0]) % MOD + (c[3] * a[2]) % MOD) % MOD;
	temp[3] = ((c[2] * a[1]) % MOD + (c[3] * a[3]) % MOD) % MOD;
	memcpy(c, temp, sizeof(ll) * 4);
}
ll fib(ll n){
	if(n == 1)
		return(a[0] + a[1]);
	int flag = 1;
	while(n > 0){
		if(flag == 1)
			flag = 0;
		else
			sq();
		//printf("%lld %lld %lld %lld \n", a[0], a[1], a[2], a[3]);
		if(n % 2 == 1){
			mult();
		}
		//printf("%lld %lld %lld %lld \n", c[0], c[1], c[2], c[3]);
		n /= 2;
	}
	return (c[0] + c[1]);
}
int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	while(t--){
		init();
		ll num, ans;
		scanf("%lld", &num);
		if(num == 1){
			printf("0\n");
			continue;
		}
		if(num == 2){
			printf("1\n");
			continue;
		}
		ans = fib(num - 2);
		ans %= MOD;
		printf("%lld\n", ans);
	}

	return 0;
}
