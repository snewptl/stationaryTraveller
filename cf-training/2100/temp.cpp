#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
struct abc{
	int value,num,id;
};
int du[200010];
vector<int>v[200010];
abc a[200010];
int mmn[200010];
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].value;
		a[i].id=i;
		a[i].num=0;
		du[i]=0;
		v[i].clear();
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		du[y]++;
	}
	queue<int>q;
	vector<pair<int,int>>o;
	for(int i=1;i<=n;i++){
		if(!du[i]){
			q.push(i);
			a[i].num=0;
			o.push_back({a[i].value,i});
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i:v[x]){
			a[i].num=max(a[i].num,a[x].num+(a[i].value>=a[x].value?0:1));
			du[i]--;
			if(!du[i])q.push(i);
		}
	}
	int mx=0,mn=inf;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i].num*k+a[i].value);
		mn=min(mn,a[i].num*k+a[i].value);
	}
	int res=mx-mn;
	sort(o.begin(),o.end());
	for(int i=0;i<o.size()-1;i++){
		mmn[i]=a[o[i+1].second].num*k+a[o[i+1].second].value;
	}
	for(int y=0;y<o.size()-1;y++){
		mn=mmn[y];
		int i=o[y].second;
		queue<int>q;
		q.push(i);
		a[i].num=1;
		mx=max(mx,k+a[i].value);
		while(!q.empty()){
			int x=q.front();
			q.pop();
			for(int j:v[x]){
				int now=a[x].num+(a[j].value>=a[x].value?0:1);
				if(now>a[j].num){
					a[j].num=now;
					mx=max(mx,a[j].num*k+a[j].value);
					q.push(j);
				}
			}
		}
		res=min(res,mx-mn);
	}
	cout<<res<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)solve();
 	return 0;
}