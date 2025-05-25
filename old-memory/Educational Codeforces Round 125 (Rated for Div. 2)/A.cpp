#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int dis[55][55];
bool check(int x){
	for(int i=1;i<=100;i++){
		if(i*i==x)return true;
	}
	return false;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=abs(x),y=abs(y);
		if(max(x,y)==0)puts("0");
		else if(check(x*x+y*y))puts("1");
		else puts("2");
	}


	return 0;
}