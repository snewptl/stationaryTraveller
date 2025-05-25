#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=4e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,cnt;
vector<int>vec[maxn];
int ans,vis[maxn];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<pii>a;
bool check(int x,int y){
	if(vec[x][y]==1)return true;
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(nx<0||nx>=n)continue;
		if(ny<0||ny>=m)continue;
		if(vec[nx][ny]<vec[x][y])return true;
	}
	return false;
}
bool OK(int x,int y){
	vector<pii>b=a;
	b.push_back({x,y});
	for(auto p:b){
		if(!check(p.first,p.second))return false;
		for(int i=0;i<4;i++){
			int nx=dx[i]+p.first;
			int ny=dy[i]+p.second;
			if(nx<0||nx>=n)continue;
			if(ny<0||ny>=m)continue;
			if(!check(nx,ny))return false;
		}
	}	
	return true;
}
bool solve(){
	vector<pii>b;
	for(auto it:a){
		b.push_back(it);
		for(int i=0;i<4;i++){
			int nx=dx[i]+it.first;
			int ny=dy[i]+it.second;
			if(nx<0||nx>=n)continue;
			if(ny<0||ny>=m)continue;
			b.push_back({nx,ny});
		}		
	}
	a=b;
	sort(a.begin(),a.end());
	int sz=unique(a.begin(),a.end())-a.begin();
	for(int t=0;t<sz;t++){
		int x=a[t].first,y=a[t].second;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(i==x&&y==j)continue;
				swap(vec[i][j],vec[x][y]);
				if(OK(i,j)){
					cnt++;
				}
				swap(vec[i][j],vec[x][y]);
			}
		}
	}
	if(cnt)return true;
	return false;
}
int main(){
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			vec[i].push_back(x);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vec[i][j]==1)continue;
			if(!check(i,j))a.push_back({i,j});
		}
	}
	
	if(a.size()==0)puts("0");
	else if(a.size()>2)puts("2");
	else if(!solve())puts("2");
	else {
		printf("1 %d\n",cnt/2);
	}


	return 0;
}