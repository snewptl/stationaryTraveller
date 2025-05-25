#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
vector<int>vec[maxn];
int n;
int u[maxn],s[maxn];
ll sum;
ll pre[maxn];
ll ans[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);sum=0;
		for(int i=1;i<=n;i++)vec[i].clear();
		for(int i=1;i<=n;i++)scanf("%d",&u[i]);
		for(int i=1;i<=n;i++){
			scanf("%d",&s[i]);
			vec[u[i]].push_back(s[i]);
		}
		for(int i=1;i<=n;i++)ans[i]=0;
		for(int i=1;i<=n;i++){
			sort(vec[i].begin(),vec[i].end());
			int len=vec[i].size();
			for(int j=1;j<=len;j++){
				pre[j]=pre[j-1]+vec[i][j-1];
			}
			for(int j=1;j<=len;j++){
				ans[j]+=pre[len]-pre[len%j];
			}
		}
		for(int i=1;i<=n;i++){
			printf("%lld ",ans[i]);
		}
		printf("\n");

    }


    return 0;
}