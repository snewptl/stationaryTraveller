#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e6+5;
const ll mod=998244353;
const double eps=1e-10;
int a[maxn];
int l,r;
int cnt[30][2];
int vis[30][2];
int b[maxn];
int solve(int l,int r,int dep){
	int x=0;
	if(!dep){
		if(l%2!=a[l]%2)return 1;
		else return 0;
	}
	for(int i=0;i<=dep;i++){
		cnt[i][0]=cnt[i][1]=0;
		vis[i][0]=vis[i][1]=0;
	}
	for(int i=l;i<=r;i++){
		for(int j=0;j<dep;j++){
			int temp=((1<<j)&i);
			if(temp)cnt[j][1]++;
			else cnt[j][0]++;
		}
	}
	for(int i=l;i<=r;i++){
		for(int j=0;j<dep;j++){
			int temp=((1<<j)&a[i]);
			if(temp)vis[j][1]++;
			else vis[j][0]++;
		}
	}		
	int pos=dep;
	for(int i=0;i<dep;i++){
		if(cnt[i][1]!=cnt[i][0]){
			if(vis[i][1]!=cnt[i][1])x+=1<<i;
			pos=min(pos,i);
		}
	}
	if(pos<=0)return x;
	else {
		for(int i=l;i<=r;i++)a[i]^=x;
		int ad=1<<(pos-1);
		if(l%ad!=0){
			int cur=l%ad;
			for(int i=l;i<=r;i++){
				if(a[i]/ad==l/ad)b[cur++]=a[i];
			}
			for(int i=l%ad;i<cur;i++)a[i]=b[i];
			
			return x+solve(l%ad,cur-1,pos-1);
		}
		else if(r%ad!=ad-1){
			int cur=0;
			for(int i=l;i<=r;i++){
				if(a[i]/ad==r/ad)b[cur++]=a[i];
			}
			for(int i=0;i<cur;i++)a[i]=b[i];
			return x+solve(0,cur-1,pos-1);
		}
		else return x;
	}
}
int main(){
	int T=1;scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++){
			scanf("%d",&a[j]);
		}	
		printf("%d\n",solve(l,r,17));
	}


	return 0;
}