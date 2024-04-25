#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
typedef pair<int,int>pii;
int n,m,x;
int a[maxn],ans[maxn];
int sum[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		priority_queue<pii,vector<pii>,greater<pii>>q;
        scanf("%d%d%d",&n,&m,&x);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=m;i++){
			sum[i]=0;
			q.push(make_pair(0,i));
		}
			
		for(int i=1;i<=n;i++){
			pii p=q.top();q.pop();
			sum[p.second]+=a[i];
			ans[i]=p.second;
			q.push(make_pair(sum[p.second],p.second));
		}
		printf("YES\n");
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
    }


    return 0;
}