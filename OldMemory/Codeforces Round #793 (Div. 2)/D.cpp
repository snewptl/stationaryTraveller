#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,mn,mx;
char s[maxn];
int h[2][maxn],frt[2],ed[2];
vector<pii>ans;
void clear(){
	for(int i=0;i<2;i++)frt[i]=1,ed[i]=0;
	ans.clear();
	mn=1,mx=n;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		clear();
		for(int i=1;i<=n;i++){
			if(s[i]=='1')h[1][++ed[1]]=i;
			else h[0][++ed[0]]=i;
		}
		if(ed[1]==0||ed[1]%2!=0)puts("NO");
		else {
			while(ed[1]>=frt[1]){
				int v=h[1][frt[1]++];
				int u=v+1;
				if(u>mx){
					u=mn;
					if()
				}
				else {

				}
			}
			puts("YES");
			for(auto it:ans){
				printf("%d %d\n",it.first,it.second);
			}
		}
	}


	return 0;
}