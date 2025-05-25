#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
map<int,int>mp;
void init(){
	mp.clear();
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		for(auto &it:mp){
			if(it.second==1){
				it.second++;
				break;
			}
		}
		int len=0,cnt=0;
		for(auto &it:mp){
			if(it.second==1)cnt++;
			else len++;
		}
		len+=cnt/2;
		printf("%d\n",len);
	}


	return 0;
}