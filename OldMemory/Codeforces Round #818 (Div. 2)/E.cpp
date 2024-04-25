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
    if(n<=k)printf("%lld\n",bin[n]);
    else printf("%lld\n",(1ll*(2*k-1)*(n-1)+1)%mod);


	return 0;
}