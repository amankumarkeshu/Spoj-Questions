#include<bits/stdc++.h>

#define ll long long

#define ld long double

#define vll vector<ll>

#define vvll vector< vll >

#define pll pair<ll ,ll >

#define vpll vector< pll >

#define mp make_pair

#define pb push_back

#define MOD 1000000007



#define all(v) v.begin(),v.end()

#define rall(v) v.rbegin(),v.rend()

#define fst first

#define scd second



#define fr(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))

#define fr1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))

#define frr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))

#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))



#define mst(A) memset( (A) , 0 , sizeof(A) );



using namespace std;

void read(ll &x){

	scanf("%lld",&x);

}

void read(ll &x,ll &y){

	scanf("%lld%lld",&x,&y);

}

void read(vll &oneD){

	for(ll i=0;i<oneD.size();i++){

		read(oneD[i]);

	}

}
void write(vll &oneD){

	for(ll i=0;i<oneD.size();i++){

		printf("%lld ",oneD[i]);

	}

	printf("\n");

}

int main()
{
    ll i,j,t,nm,ng,a,best,sum=0;

    read(t);
    while(t--)
    {
        best=0;sum=0;
        read(ng);
        vll v1(ng);
        vll v2(ng);
        read(v1);
        read(v2);
        for(i=0;i<ng;i++)
        {
            sum= max(v1[i]+sum,v1[i]);
            best=max(sum,best);

        }
        cout<<best<<endl;


    }
return 0;
}

