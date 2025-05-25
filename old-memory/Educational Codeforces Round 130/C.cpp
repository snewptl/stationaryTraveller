#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
char s[2][maxn];
int n;
vector<pair<char,int>> a,b;
void init(){
	a.clear();
	b.clear();
}
bool solve(){
	if(a.size()!=b.size())return false;
	for(int i=0;i<a.size();i++){
		if(a[i].first!=b[i].first)return false;
		if(a[i].first=='a'){
			if(a[i].second>b[i].second)return false;
		}
		else {
			if(a[i].second<b[i].second)return false;
		}
	}
	return true;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,s[0],s[1]);
		init();
		for(int i=0;i<n;i++){
			if(s[0][i]!='b')a.push_back({s[0][i],i});
			if(s[1][i]!='b')b.push_back({s[1][i],i});
		}
		if(solve())puts("YES");
		else puts("NO");
		
	}


	return 0;
}