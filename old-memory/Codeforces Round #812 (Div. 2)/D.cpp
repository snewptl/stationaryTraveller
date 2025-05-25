#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
vector<int>vec,temp;
int ask(int sgn,int u,int v){
	if(!sgn)printf("? %d %d\n",vec[u],vec[v]);
	else printf("? %d %d\n",temp[u],temp[v]);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
int inv(int x){
	return x^1;
}
void solve(int sz){
	if(sz==1){
		printf("! %d\n",vec[0]);
		fflush(stdout);
		return ;		
	}
	if(sz==2){
		int res=ask(0,0,1);
		if(res==1)printf("! %d\n",vec[0]);
		else printf("! %d\n",vec[1]);
		fflush(stdout);
		return ;
	}
	temp.clear();
	for(int i=0;i<sz;i+=4){
		int l=i,r=i+2;
		int res=ask(0,l,r);
		if(res==0){
			temp.push_back(vec[inv(l)]);
			temp.push_back(vec[inv(r)]);
		}
		else if(res==1){
			temp.push_back(vec[l]);
			temp.push_back(vec[inv(r)]);
		}
		else {
			temp.push_back(vec[inv(l)]);
			temp.push_back(vec[r]);
		}
	}
	vec.clear();
	for(int i=0;i<temp.size();i+=2){
		int l=i,r=i+1;
		int res=ask(1,l,r);
		if(res==1)vec.push_back(temp[l]);
		else vec.push_back(temp[r]);
	}
	solve(vec.size());
	
}
int main(){
	// srand(time(0));
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		n=(1<<n);
		vec.clear();
		for(int i=1;i<=n;i++)
			vec.push_back(i);
		solve(n);
	}


	return 0;
}