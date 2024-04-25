#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
void solve(){
    ll cnt0=0,cnt1=0,ans=0;
    for(int i=1;i<=n;i++){
        ll temp=abs(a[i]);
        if(a[i]<0){//cnt0 ->a[i]
            cnt1+=temp;
            ll mn=min(temp,cnt0);
            temp-=mn;
            cnt0-=mn;
            ans+=temp;
        }
        else if(a[i]>0){//cnt1 ->a[i]
            cnt0+=temp;
            ll mn=min(temp,cnt1);
            temp-=mn;
            cnt1-=mn;
            ans+=temp;
        }
    }
    printf("%lld\n",ans);
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        solve();
	}


	return 0;
}