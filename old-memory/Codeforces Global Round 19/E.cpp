#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=3e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int a[maxn];
map<int,int>mp;
map<pii,int>chk;
vector<int>vec[maxn];
vector<int>kd,kd1;
void init(){
	mp.clear();
	chk.clear();
	kd.clear();
	kd1.clear();
	for(int i=0;i<=n;i++)vec[i].clear();
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			chk[{x,y}]=1;
			chk[{y,x}]=1;
		}
		for(auto p:mp){
			vec[p.second].push_back(p.first);
			kd.push_back(p.second);
		}
		sort(kd.begin(),kd.end());
		kd1.push_back(kd[0]);
		for(int i=1;i<kd.size();i++)if(kd[i]!=kd[i-1])kd1.push_back(kd[i]);
		for(int i=1;i<=n;i++)
			sort(vec[i].begin(),vec[i].end(),cmp);
		ll mx=0;
		for(auto i:kd1){
			// if(i==kd[0])break;
			for(auto j:kd1){
				// if(j==kd[0])break;
				for(int fst=0;fst<vec[i].size();fst++){
					int flag=0;
					int num0=vec[i][fst];
					int st=0;
					if(j==i)st=fst+1;
					for(int scd=st;scd<vec[j].size();scd++){
						if(flag)break;
						int num1=vec[j][scd];
						if(chk.count({num0,num1}))continue;
						else {
							flag=1;
							mx=max(1ll*(num0+num1)*(i+j),mx);
						}
					}
				}
			}
		}
		printf("%lld\n",mx);

	}


	return 0;
}