#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
vector<int>vec;
bool solve(int k){
	vec.clear();
	for(int i=1;i<=n;i++){
		if(a[i]==k)continue;
		vec.push_back(a[i]);
	}
	for(int i=0;i<vec.size()/2;i++){
		if(vec[i]!=vec[vec.size()-i-1])return false;
	}
	return true;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int flag=1;
		for(int i=1;i<=n/2;i++){
			if(a[i]!=a[n+1-i]){
				if(!solve(a[i])&&!solve(a[n+1-i]))flag=0;
				break;
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}


	return 0;
}