#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m,tot;
int a[305][305],mp[305][305];
int b[maxn];
int sum[305][305];
unordered_map<int,int>rk,bg,rf;
int used[maxn][305];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		for(int i=1;i<=tot;i++){
			for(int j=1;j<=n;j++)used[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)sum[i][j]=0;
		}
		rk.clear();bg.clear();
		tot=0;rf.clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				b[(i-1)*m+j]=a[i][j];
				if(!rf[a[i][j]])rf[a[i][j]]=++tot;
			}
		}
		sort(b+1,b+n*m+1);
		int ans=0;
		for(int i=1;i<=n*m;i++)rk[b[i]]=i;
		for(int i=n*m;i>=1;i--)bg[b[i]]=i;
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--)
			sum[i][j]=sum[i][j+1]+1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int cur=a[i][j];
				int temp,cnt=1e9,lst=rk[cur],fst=bg[cur],num=rf[cur],fed;
				for(int k=1;k<=n;k++){
					if(fst>k*m)continue;
					if(lst<(k-1)*m+1)break;
					if(used[num][k]==min(lst,k*m)-max(fst-1,(k-1)*m))continue;
					int ed=min(m,lst-(k-1)*m);
					if(sum[k][ed+1]<cnt){
						cnt=sum[k][ed+1];
						temp=k;
						fed=ed;
					}
					
				}
				used[num][temp]++;
				ans+=cnt;
				for(int k=1;k<=fed;k++)sum[temp][k]--;
			}
		}
		printf("%d\n",ans);
    }


    return 0;
}