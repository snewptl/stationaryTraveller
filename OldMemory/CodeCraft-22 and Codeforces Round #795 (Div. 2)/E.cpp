#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
set<pii,greater<pii>>s[2];
vector<pii>vec;
int ri[2][maxn];
struct Seg{
	int c,l,r;
}seg[maxn];
bool cmp(Seg x,Seg y){
	return x.l==y.l?x.r<y.r:x.l<y.l;
}
void init(){
	for(int t=0;t<2;t++){
		s[t].clear();
		for(int i=1;i<=n;i++)ri[t][i]=0;
	}
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			int l,r,c;
			scanf("%d%d%d",&c,&l,&r);
			seg[i]={c,l+1,r+1};
		}
		sort(seg+1,seg+n+1,cmp);
		
		for(int i=1;i<=n;i++){
			int t=seg[i].c;
			ri[t][i]=seg[i].r;
			ri[(t^1)][i]=0;
			vec.clear();
			for(auto it:s[t^1]){
				if(it.first>=seg[i].l)vec.push_back(it);
				else break;
			}
			for(auto it:vec){
				int idx=it.second;
				for(int j=0;j<2;j++){
					ri[j][i]=max(ri[j][idx],ri[j][i]);
					s[j].erase({ri[j][idx],idx});
				}
			}
			for(int j=0;j<2;j++)
				s[j].insert({ri[j][i],i});
		}
		printf("%d\n",s[0].size());
	}


	return 0;
}
