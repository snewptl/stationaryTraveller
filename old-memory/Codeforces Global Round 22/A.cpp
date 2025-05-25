#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int a[maxn],b[maxn],n;
vector<int>p,q;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){ 
        scanf("%d",&n);
        int cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt+=a[i];
        }
        cnt=min(cnt,n-cnt);
        q.clear();p.clear();
        ll ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            if(a[i])p.push_back(-b[i]);
            else q.push_back(-b[i]);
            ans+=b[i];
        }
        sort(p.begin(),p.end());
        sort(q.begin(),q.end());
        for(int i=0;i<cnt;i++){
            ans+=-(p[i]+q[i]);
        }
        if(cnt*2==n)ans-=min(-p.back(),-q.back());
        printf("%lld\n",ans);
	}


	return 0;
}