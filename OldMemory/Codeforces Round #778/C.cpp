#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
set<ll>s;
map<ll,int>mp,cur;
queue<pair<ll,int>>q;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		while(!q.empty())q.pop();
		s.clear();
		mp.clear();
		cur.clear();
		scanf("%d",&n);
		ll sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
			mp[a[i]]++;
		}
		q.push({sum,1});
		while(!q.empty()){
			auto p=q.front().first;
			auto num=q.front().second;
			q.pop();
			int x=min(num,mp[p]);
			mp[p]-=x;
			num-=x;
			if(p!=1){
				cur[p/2]+=num;
				cur[(p+1)/2]+=num;
			}
			if(q.empty()){
				for(auto x:cur){
					if(x.second)q.push(x);
				}
				cur.clear();
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++)if(mp[a[i]])flag=1;
		if(flag)puts("NO");
		else puts("YES");
		
	}


	return 0;
}