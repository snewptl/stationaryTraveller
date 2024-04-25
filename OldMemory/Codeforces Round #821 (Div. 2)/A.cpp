#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
ll a[maxn];
ll b[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int i=0;i<k;i++)b[i]=0;
        for(int i=1;i<=n;i++){
            b[i%k]=max(b[i%k],a[i]);
        }
        ll res=0;
        for(int i=0;i<k;i++){
            res+=b[i];
        }
        printf("%lld\n",res);
	}


	return 0;
}