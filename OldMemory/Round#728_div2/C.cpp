#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,k;
int a[205],b[205];
int link[205];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		memset(link,0,sizeof(link));
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x>y)swap(x,y);
			a[i]=x,b[i]=y;
			link[x]=y;link[y]=x;
		}
		int ans=(n-k)*(n-k-1)/2;
		int add=0;
		for(int i=1;i<=k;i++){
			int temp1=0,temp2=0;
			for(int j=a[i]+1;j<b[i];j++){
				if(link[j]){
					if(link[j]<a[i]||link[j]>b[i])add++;
				}
				else temp1++;
			}
			for(int j=b[i]+1;j<a[i]+2*n;j++){
				int t=j;
				if(t>2*n)t-=2*n;
				if(!link[t])temp2++;
			}
			ans+=min(temp1,temp2);
			// printf("%d\n",ans+add/2);
		}
		printf("%d\n",ans+add/2);
    }


    return 0;
}
/*
1
4 2
8 2
1 5
*/