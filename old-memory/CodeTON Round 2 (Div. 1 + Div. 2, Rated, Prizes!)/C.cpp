#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,a[maxn];
vector<int>vec;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)scanf("%d",&a[i]);
		sort(a+1,a+m+1);
		vec.clear();
		for(int i=2;i<=m;i++){
			vec.push_back(a[i]-a[i-1]-1);
		}
		vec.push_back(a[1]+n-a[m]-1);
		sort(vec.begin(),vec.end());
		reverse(vec.begin(),vec.end());
		int ans=0;
		int cur=0;
		for(int i=0;i<vec.size();i++){
			vec[i]-=cur;
			vec[i]=max(vec[i],0);
			if(!vec[i])break;
			if(vec[i]<=2){
				cur+=2;
				ans+=1;
			}			
			else {
				ans+=vec[i]-1;
				cur+=4;
			}
		}
		printf("%d\n",n-ans);
	}


	return 0;
}