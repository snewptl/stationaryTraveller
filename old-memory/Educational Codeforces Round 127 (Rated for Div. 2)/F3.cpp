#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll g[13][12][12];
void solve(int n){
	vector<int>vec(n);
	iota(vec.begin(),vec.end(),1);
	do {
		int k=0,x=0,flag=1,mx=vec[0];
		if(mx==1)flag=0;
		for(int i=1;i<n;i++){
			mx=max(mx,vec[i]);
			if(vec[i]<vec[i-1])x++;
			for(int j=0;j<i;j++)
				if(vec[j]>vec[i])k++;
			if(mx==i+1&&i!=n-1)flag=0;
			if(!flag||x>11)break;
		}
		if(x<=11&&k<=11&&flag)
			g[n][k][x]++;
	}while(next_permutation(vec.begin(),vec.end()));
}
int main(){
	freopen("f.out","w",stdout);
	for(int i=1;i<=12;i++){
		solve(i);
	}
	for(int i=1;i<=12;i++){
		for(int j=1;j<=11;j++){
			for(int k=1;k<=11;k++){
				printf("c[%d][%d][%d]=%lld,\n",i,j,k,g[i][j][k]);
			}
		}
	}
	
	

	return 0;
}