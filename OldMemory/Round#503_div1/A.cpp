#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e3+10;
typedef pair<int,int>pii;
int n,m;
ll ans=1e18,temp;
vector<int>p[maxn];
int vis[maxn],mx;
int a[maxn],tot;
void check(int x){
	int k=0;tot=0;
	for(int i=2;i<=m;i++){
		int up=p[i].size()-x;
		for(int j=0;j<up;j++){
			temp+=p[i][j];
			k++;
		}
		for(int j=max(up,0);j<p[i].size();j++)
			a[++tot]=p[i][j];
	}
	sort(a+1,a+tot+1);
	int pos=1;
	while(k+vis[1]<=x){
		k++;temp+=a[pos];pos++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int pi,co;
		scanf("%d%d",&pi,&co);
		p[pi].push_back(co);
		vis[pi]++;
	}
	for(int i=1;i<=m;i++){
		sort(p[i].begin(),p[i].end());
	}
	for(int i=n;i>=0;i--){
		check(i);
		ans=min(ans,temp);
		// printf("%d\n",temp);
		temp=0;
	}
	printf("%lld\n",ans);
    return 0;
}