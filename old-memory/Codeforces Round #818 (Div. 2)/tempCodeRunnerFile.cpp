#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=1e9+7;
const double eps=1e-10;
ll bin[maxn];
int main(){
    bin[0]=1;
    for(int i=1;i<maxn;i++)bin[i]=bin[i-1]*2,bin[i]%=mod;
    int n,k;
    scanf("%d%d",&n,&k);
    int t=max(0,n-k);
    printf("%lld\n",(bin[n]+mod-bin[t]+1)%mod);


	return 0;
}