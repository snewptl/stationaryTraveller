#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
int a[1005][1005];
int vis[1005][1005];
struct node{
	int i,j,c;
};
queue<pii>q;
vector<node>vec;
void check(int i,int j){
	int flag=1,x=0;
	for(int h=0;h<2;h++){
		for(int r=0;r<2;r++){
			if(vis[i+h][j+r]!=1){
				x=a[i+h][j+r];
			}
		}
	}
	if(!x)return;
	for(int h=0;h<2;h++){
		for(int r=0;r<2;r++){
			if(x!=a[i+h][j+r]&&vis[i+h][j+r]!=1)flag=0;
		}
	}
	if(flag){
		vec.push_back({i,j,x});
		for(int h=0;h<2;h++){
			for(int r=0;r<2;r++){
				if(!vis[i+h][j+r])q.push({i+h,j+r});
				vis[i+h][j+r]=1;
			}
		}		
	}
}
void solve(){
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m-1;j++){
			int x=a[i][j],flag=1;
			for(int h=0;h<2;h++){
				for(int r=0;r<2;r++){
					if(x!=a[i+h][j+r])flag=0;
				}
			}
			if(flag){	
				vec.push_back({i,j,a[i][j]});
				for(int h=0;h<2;h++){
					for(int r=0;r<2;r++){
						if(!vis[i+h][j+r])q.push({i+h,j+r});
						vis[i+h][j+r]=1;
					}
				}
			}	
		}
	}		
	while(!q.empty()){
		auto p=q.front();q.pop();
		int sx=p.first,sy=p.second;
		for(int h=-1;h<=0;h++){
			for(int r=-1;r<=0;r++){
				int px=h+sx,py=r+sy;
				if(px<1)continue;
				if(py<1)continue;
				check(px,py);
			}
		}
	}
	int sgn=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(!vis[i][j])sgn=0;
	}
	if(sgn){
		reverse(vec.begin(),vec.end());
		printf("%d\n",vec.size());
		for(auto p:vec){
			printf("%d %d %d\n",p.i,p.j,p.c);
		}
	}
	else printf("-1\n");	
	
}
void init(){
	vec.clear();
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	}
	solve();
	return 0;
}