#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
char up[maxn],dn[maxn];
int vis[maxn];
int check(int p){
	return up[p]+dn[p]-'0'*2;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d%s%s",&n,up,dn);
		int ans=0,cur=0;
		for(int i=0;i<n;i++)vis[i]=0;
		for(int i=0;i<n;i++){
			int temp=up[i]+dn[i]-'0'*2;
			if(temp==2){
				if(i&&check(i-1)==0&&!vis[i-1])vis[i-1]=1,ans+=2;
				else if(i<n-1&&check(i+1)==0&&!vis[i+1])vis[i+1]=1,ans+=2;
			}		
			if(temp==1)ans+=2;
		}
		for(int i=0;i<n;i++){
			int temp=up[i]+dn[i]-'0'*2;
			if(temp!=0||vis[i])continue;
			ans+=1;
		}
		printf("%d\n",ans);
    }


    return 0;
}