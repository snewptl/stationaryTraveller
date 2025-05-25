#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
struct Stu{
	int dn,up,idx;
}stu[maxn];
int ans;
bool check(int x){
	int pre=x-1,nxt=0;
	for(int i=n;i>=1;i--){
		if(stu[i].dn>=pre&&stu[i].up>=nxt){
			pre--,nxt++;
		}
		else continue;
	}
	if(pre<0)return true;
	else return false;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int up,dn;
			scanf("%d%d",&up,&dn);
			int idx=i;
			stu[i]={dn,up,i};
		}
		ans=0;
		int l=0,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)){
				ans=max(ans,mid);l=mid+1;
			}
			else r=mid-1;
		}
		printf("%d\n",ans);
	}


	return 0;
}