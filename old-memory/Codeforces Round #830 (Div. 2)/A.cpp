#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int d=a[1];
        for(int i=2;i<=n;i++)d=__gcd(d,a[i]);
        // if(__gcd(d,n)==1)puts("1");
        // else puts("2");
        if(d==1)puts("0");
        else if(__gcd(d,n)==1)puts("1");
        else if(__gcd(d,n-1)==1)puts("2");
        else puts("3");
	}


	return 0;
}