#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
int a[maxn],b[maxn];
int sum[2];
int ans[maxn][2];
int tot;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d",&n);
		sum[0]=sum[1]=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++){
			sum[0]+=a[i];
			sum[1]+=b[i];
		}
		int st=2;tot=0;
		if(sum[0]!=sum[1])printf("-1\n");
		else {
			for(int i=1;i<n;i++){
				st=i+1;
				while(a[i]<b[i]){
					while(a[st]<=b[st])st++;
					a[st]--;a[i]++;
					ans[++tot][0]=st,ans[tot][1]=i;
				}
				st=i+1;
				while(a[i]>b[i]){
					while(a[st]>=b[st])st++;
					a[st]++;a[i]--;
					ans[++tot][0]=i,ans[tot][1]=st;
				}
			}
			printf("%d\n",tot);
			for(int i=1;i<=tot;i++){
				printf("%d %d\n",ans[i][0],ans[i][1]);
			}			
		}


    }


    return 0;
}
