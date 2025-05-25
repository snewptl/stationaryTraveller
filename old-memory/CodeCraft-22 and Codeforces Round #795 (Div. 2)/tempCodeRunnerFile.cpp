#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
ll sum[maxn],mx[maxn];
vector<int>vec;
void init(){
	vec.clear();
}
bool solve(){
	init();
	for(int i=1;i<=n;i++){
		sum[i]=mx[i]=a[i];
		while(vec.size()&&a[i]>=a[vec.back()]){
			mx[i]=max(mx[i],mx[vec.back()]+sum[i]);
			if(mx[i]-sum[i]>0){
				puts("NO");
				return false;
			}
			sum[i]+=sum[vec.back()];
			vec.pop_back();
		}
		vec.push_back(i);
	}	
	return true;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		vec.clear();
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(solve()){
			reverse(a+1,a+n+1);
			if(solve())puts("YES");			
		}

	}


	return 0;
}