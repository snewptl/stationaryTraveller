#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
typedef long long ll;
int n;
ll a[55],b[55];
pair<ll,int>mp[55];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			mp[i]=make_pair(a[i],i);
		}
		sort(mp+1,mp+n+1);
		int p=mp[1].second;
		b[p]=mp[1].first;
		for(int i=2;i<=n;i++){
			ll s=(mp[i].first-1)/2+1;
			ll t=(mp[i].first*3)/2;
			if(b[p]>=s)b[mp[i].second]=b[p];
			else {
				ll tmp=(s-1)/b[p]+1;
				b[mp[i].second]=tmp*b[p];
			}
			p=mp[i].second;
		}
		for(int i=1;i<=n;i++)printf("%lld ",b[i]);
		printf("\n");
    }


    return 0;
}