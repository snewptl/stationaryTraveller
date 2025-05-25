#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,c[maxn],ans[maxn];
vector<int>vec[maxn];
void init(){
	for(int i=1;i<=n;i++)vec[i].clear();
	for(int i=1;i<=n;i++)ans[i]=0;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
			vec[c[i]].push_back(i);
		}
		for(int i=1;i<=n;i++){
			if(vec[i].size()==0)continue;
			int pre=vec[i][0]-1;
			for(auto j:vec[i]){
				if((j-pre-1)%2==0)ans[i]++;
				pre=j;
			}
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}


	return 0;
}