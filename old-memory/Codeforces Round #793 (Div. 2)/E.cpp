#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int a[maxn],nxt[maxn];
set<int>s[maxn];
map<pii,int>mp;
queue<int>q;
vector<int>ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)nxt[i]=a[i];
	for(int i=1;i<=m;i++){
		int x,y,idx=i;
		scanf("%d%d",&x,&y);
		s[y].insert(x);
		s[x].insert(y);
		mp[{x,y}]=mp[{y,x}]=idx;
		if(nxt[x]==y)q.push(x);
		if(nxt[y]==x)q.push(y);
	}
	while(!q.empty()){
		int p=q.front();q.pop();
		printf("%d %d\n",p,nxt[p]);
		if(nxt[p]==p)continue;
		ans.push_back(mp[{p,nxt[p]}]);
		s[p].erase(nxt[p]);
		int temp=nxt[p];
		nxt[p]=nxt[nxt[p]];
		nxt[nxt[p]]=temp;
		if(s[p].count(nxt[p]))q.push(p);
	}
	for(auto x:ans)printf("%d ",x);
	return 0;
}