#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int n,q,l,r;
char a[maxn];
int sum[maxn];
int infa[maxn][25],ffa[maxn][25];
unordered_map<int,int>cur;
int main(){
	// freopen("D2,out","w",stdout);
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d%s",&n,&q,a);
		for(int i=0;i<=n;i++){
			for(int j=0;j<=20;j++)
			infa[i][j]=-1,ffa[i][j]=-1;
		}
		cur.clear();
		for(int i=-n-1;i<=n+1;i++){
			cur[i]=-1;
		}
		for(int i=0;i<=n;i++)sum[i]=0;
		int sgn;
		if(n%2)sgn=1;
		else sgn=-1;
		for(int i=n-1;i>=0;i--){
			int temp;
			if(a[i]=='+')temp=1;
			else temp=-1;
			sum[i]=temp*sgn+sum[i+1];
			sgn*=-1;
		}
		for(int i=0;i<n;i++){
			cur[sum[i]]=i;
			infa[i][0]=cur[sum[i]-1];
			ffa[i][0]=cur[sum[i]+1];
		}
		for(int i=1;i<=20;i++){
			for(int j=0;j<n;j++){
				if(ffa[j][i-1]!=-1)ffa[j][i]=ffa[ffa[j][i-1]][i-1];
				if(infa[j][i-1]!=-1)infa[j][i]=infa[infa[j][i-1]][i-1];
			}
		}
		while(q--){
			scanf("%d%d",&l,&r);
			int temp=sum[l-1]-sum[r];
			if(temp==0)printf("0\n");
			else if(temp%2){
				printf("1\n");
				if(temp>0){
					int now=r-1;
					for(int i=20;i>=0;i--){
						if(ffa[now][i]==-1)continue;
						if(sum[ffa[now][i]]>temp/2+1+sum[r])continue;
						now=ffa[now][i];
					}					
					printf("%d\n",now+1);
				}
				else {
					int now=r-1;
					for(int i=20;i>=0;i--){
						if(infa[now][i]==-1)continue;
						if(sum[infa[now][i]]<temp/2-1+sum[r])continue;
						now=infa[now][i];
					}
					printf("%d\n",now+1);
				}
			}
			else {
				printf("2\n");
				if(temp>0){
					int now=r-1;
					for(int i=20;i>=0;i--){
						if(ffa[now][i]==-1)continue;
						if(sum[ffa[now][i]]>temp+sum[r])continue;
						now=ffa[now][i];
					}				
					printf("%d ",now+1);
					now=r-1;	
					for(int i=20;i>=0;i--){
						if(ffa[now][i]==-1)continue;
						if(sum[ffa[now][i]]>temp/2+sum[r])continue;
						now=ffa[now][i];
					}
					printf("%d\n",now+1);
				}
				else {
					int now=r-1;
					for(int i=20;i>=0;i--){
						if(infa[now][i]==-1)continue;
						if(sum[infa[now][i]]<temp+sum[r])continue;
						now=infa[now][i];
					}
					printf("%d ",now+1);
					now=r-1;
					for(int i=20;i>=0;i--){
						if(infa[now][i]==-1)continue;
						if(sum[infa[now][i]]<temp/2+sum[r])continue;
						now=infa[now][i];
					}
					printf("%d\n",now+1);
				}
			}
		}

    }


    return 0;
}