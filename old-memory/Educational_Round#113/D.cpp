#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
typedef pair<int,int>pii;
int n,m,k;
int a[maxn],b[maxn];
struct Node{
	int x,y,tag;
}nd[maxn];
int vy[maxn],vx[maxn];
ll ans;
unordered_map<int,int>mp;
void init(){
	
	ans=0;
	for(int i=1;i<=n;i++)vx[a[i]]=0;
	for(int i=1;i<=m;i++)vy[b[i]]=0;
}
bool cmpy(Node a,Node b){
	return a.y<b.y;
}
bool cmpx(Node a,Node b){
	return a.x<b.x;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
		init();
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&b[i]);
		sort(a+1,a+n+1);sort(b+1,b+m+1);
		for(int i=1;i<=n;i++)vx[a[i]]=1;
		for(int i=1;i<=m;i++)vy[b[i]]=1;
		for(int i=1;i<=k;i++){
			int x,y,tag=0;
			scanf("%d%d",&x,&y);
			if(vx[x]&&vy[y])tag=3;
			else if(vx[x])tag=1;
			else if(vy[y])tag=2;
			nd[i]={x,y,tag};
		}
		b[m+1]=a[n+1]=1e9;
		mp.clear();
		sort(nd+1,nd+k+1,cmpy);
		int cur=1,pos=0,cnt=0;
		for(int i=1;i<=k;i++){
			if(nd[i].tag!=1)continue;
			pos=nd[i].y;
			while(b[cur]<=pos){
				cnt=0,cur++;
				mp.clear();
			}
			ans+=cnt-mp[nd[i].x];
			cnt++,mp[nd[i].x]++;
		}
		mp.clear();
		sort(nd+1,nd+k+1,cmpx);
		cur=1;pos=0,cnt=0;
		for(int i=1;i<=k;i++){
			if(nd[i].tag!=2)continue;
			pos=nd[i].x;
			while(a[cur]<=pos){
				cnt=0,cur++;
				mp.clear();
			}
			ans+=cnt-mp[nd[i].y];
			cnt++,mp[nd[i].y]++;
		}
		printf("%lld\n",ans);
    }
    return 0;
}