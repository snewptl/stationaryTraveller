#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+10;
int mi[4001];
int n,k;
int a[maxn];
int ans;
int vis[maxn];
int main(){
    int T;scanf("%d",&T);
	for(int i=1;i<=4000;i++){
		mi[i]=i*i;
	}	
    while(T--){
		scanf("%d%d",&n,&k);ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=4000;j>=1;j--)
			if(a[i]%mi[j]==0){
				a[i]/=mi[j];break;
			}
		}
		int st=1;
		for(int i=1;i<=n;i++){
			if(vis[a[i]]){
				ans++;
				for(int j=st;j<=i;j++)
				vis[a[j]]=0;
				st=i;
			}
			vis[a[i]]++;
		}
		for(int i=st;i<=n;i++)vis[a[i]]=0;
		ans++;
		printf("%d\n",ans);
    }


    return 0;
}