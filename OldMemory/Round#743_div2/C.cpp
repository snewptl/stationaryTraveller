#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,ans;
vector<int>e[maxn];
int in[maxn];
priority_queue<int,vector<int>,greater<int>>q1,q2;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n;
		scanf("%d",&n);
		ans=0;
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n;i++)in[i]=0;
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);
			for(int j=1;j<=x;j++){
				int y;scanf("%d",&y);
				e[y].push_back(i);
				in[i]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(!in[i])q2.push(i);
		}

		while(!q2.empty()){
			ans++;
			while(!q2.empty()){
				q1.push(q2.top());
				q2.pop();
			}
			while(!q1.empty()){
				int p=q1.top();q1.pop();
				for(auto v:e[p]){
					in[v]--;
					if(!in[v]){
						if(v>p)q1.push(v);
						else q2.push(v);
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(in[i])ans=-1;
		}
		printf("%d\n",ans);
    }


    return 0;
}