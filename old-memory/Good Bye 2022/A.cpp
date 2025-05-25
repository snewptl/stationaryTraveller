#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int a[maxn],b[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&m);
        multiset<int>s;
        ll ans=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),s.insert(a[i]);
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
            s.erase(s.begin());
            s.insert(b[i]);
        }
        for(auto it:s)ans+=it;
        printf("%lld\n",ans);
	}


	return 0;
}