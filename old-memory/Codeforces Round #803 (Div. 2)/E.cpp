#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,s;
int a[maxn],b[maxn],rk[maxn];
vector<int>vec;
ll ans=1;
void init(){
	vec.clear();
	for(int i=1;i<=n;i++)rk[i]=0;
	ans=1;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&s);
		
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
			if(b[i]!=-1)rk[b[i]]=i;
			else vec.push_back(a[i]);
		}
		sort(vec.begin(),vec.end());
		ll cnt=0;
		for(int i=n;i>=1;i--){
			while(vec.size()!=0&&vec.back()+s>=i)
				cnt++,vec.pop_back();
			if(rk[i]){
				if(a[rk[i]]+s<i)ans=0;
			}
			else {
				ans*=cnt,ans%=mod;cnt--;
			}
		}
		printf("%lld\n",ans);
	}


	return 0;
}