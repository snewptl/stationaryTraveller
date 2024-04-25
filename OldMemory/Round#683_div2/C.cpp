#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll w;
int n;
ll a[maxn];
int b[maxn];
vector <pair<ll,int>>v;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%lld",&n,&w);
		v.clear();
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			v.push_back(make_pair(a[i],i));
		}
		sort(v.begin(),v.end());
		int pos;
		for(pos=0;pos<n;pos++){
			if(v[pos].first>=(w+1)/2)break;
		}
		if(pos<n&&v[pos].first<=w){
			printf("1\n");
			printf("%d\n",v[pos].second);
			continue;
		}
		n=min(pos-1,n-1);
		ll ans=0;
		for(pos=n;pos>=0;pos--){
			ans+=v[pos].first;
			if(ans>=(w+1)/2){
				printf("%d\n",n-pos+1);
				for(int i=pos;i<=n;i++){
					printf("%d ",v[i].second);
				}
				printf("\n");
				break;
			}
		}
		if(ans<(w+1)/2)printf("-1\n");
    }

    return 0;
}