#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
const double pi=acos(-1);
int n;
struct node{
	int x,y;
}a[maxn];
vector<double>vec;
ll cal(ll x){
	if(x<3)return 0;
	ll res=0;
	res=x*(x-1)*(x-2)/6;
	return res;
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[i]={x,y};
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			vec.clear();
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				vec.push_back(atan2(1.0*(a[j].y-a[i].y),1.0*(a[j].x-a[i].x)));
			}
			sort(vec.begin(),vec.end());
			for(int j=0;j<n-1;j++){
				int temp1=0,temp2=0;
				if(vec[j]<0){
					temp2=lower_bound(vec.begin(),vec.end(),pi+vec[j])-vec.begin()+1;
					temp1=lower_bound(vec.begin(),vec.end(),vec[j])-vec.begin()+1;
					ans+=cal(temp2-1-temp1);
				}
				else {
					temp2=lower_bound(vec.begin(),vec.end(),vec[j]-pi)-vec.begin();
					temp1=n-(lower_bound(vec.begin(),vec.end(),vec[j])-vec.begin()+1);
					ans+=cal(temp2+temp1);
				}
			}
		}
		printf("%lld\n",n*1ll*(n-1)*(n-2)*(n-3)*(n-4)/24-ans);
	}


	return 0;
}