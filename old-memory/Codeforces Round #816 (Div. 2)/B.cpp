#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k,b;
ll s;
ll a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d%d%lld",&n,&k,&b,&s);
        for(int i=1;i<=n;i++)a[i]=0;
        if(1ll*k*b>s||s>1ll*k*b+1ll*n*(k-1)){
            puts("-1");
            continue;
        }
        a[n]=1ll*b*k;
        s-=a[n];
        for(int i=1;i<=n;i++){
            if(!s)break;
            ll temp=min(s,1ll*(k-1));
            a[i]+=temp;
            s-=temp;
        }
        for(int i=1;i<=n;i++)printf("%lld ",a[i]);
        puts("");
        
	}


	return 0;
}