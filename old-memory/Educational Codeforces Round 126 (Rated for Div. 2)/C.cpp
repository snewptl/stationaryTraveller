#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=3e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,mx;
int h[maxn];
void init(){
	mx=0;
}
vector<ll>vec;
bool check(ll x){
	ll cnt0=(x+1)/2,cnt1=x-cnt0;
	for(auto cur:vec){
		ll temp=min(cur/2,cnt1);
		cur-=temp*2,cnt1-=temp;
		temp=min(cur,cnt0);
		cur-=temp,cnt0-=temp;
		if(cur)return false;
	}
	return true;
}
ll solve(int x){
	ll res=1e18;
	vec.clear();
	for(int i=1;i<=n;i++){
		vec.push_back((ll)x-h[i]);
	}
	ll l=0,r=1e18;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid))res=min(res,mid),r=mid-1;
		else l=mid+1;
	}
	return res;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&h[i]);
			mx=max(h[i],mx);
		}
		printf("%lld\n",min(solve(mx),solve(mx+1)));
	}


	return 0;
}