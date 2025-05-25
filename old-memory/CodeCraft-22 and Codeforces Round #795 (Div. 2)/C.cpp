#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
char s[maxn];
int pre[15],lst[15];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&n,&k,s);
		int sum=0,ans=1e9;
		for(int i=0;i<n;i++){
			sum+=11*(s[i]-'0');
		}
		for(int i=0;i<2;i++)pre[i]=lst[i]=-1;
		for(int i=n-1;i>=0;i--)pre[s[i]-'0']=i;
		for(int i=0;i<n;i++)lst[s[i]-'0']=i;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				if(pre[i]==lst[j])continue;
				if(pre[i]==-1||lst[j]==-1)continue;
				int temp=pre[i]+(n-1-lst[j]);
				if(pre[i]>lst[j])temp--;
				if(temp<=k)ans=min(ans,sum-i-10*j);
			}
		}
		printf("%d\n",ans);
	}


	return 0;
}