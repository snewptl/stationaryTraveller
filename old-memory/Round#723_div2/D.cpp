#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[maxn];
char ch[5]={'A','N','O','T'};
int cnt[5],len;
int vis[5],ans[5];
ll mx;
map<char,int>mp;
void dfs(int dep){
	if(dep==3){
		ll temp=0;
		for(int j=0;j<4;j++)cnt[j]=0;
		for(int i=0;i<len;i++){
			cnt[mp[s[i]]]++;	
			for(int j=0;j<4;j++){
				if(vis[j]>vis[mp[s[i]]])temp+=cnt[j];
			}
		}
		if(mx<temp){
			mx=temp;
			for(int i=0;i<4;i++)ans[i]=vis[i];
		}
		return ;
	}
	for(int i=dep;i<4;i++){
		swap(vis[dep],vis[i]);
		dfs(dep+1);
		swap(vis[dep],vis[i]);
	}
}
int main(){
    int T;scanf("%d",&T);
	for(int i=0;i<4;i++){
		vis[i]=i;mp[ch[i]]=i;
	}	
    while(T--){
        scanf("%s",s);
		len=strlen(s);mx=0;
		dfs(0);
		for(int j=0;j<4;j++)cnt[j]=0;
		for(int i=0;i<len;i++){
			cnt[mp[s[i]]]++;
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(ans[j]!=i)continue;
				for(int k=0;k<cnt[j];k++)printf("%c",ch[j]);
			}
		}
		printf("\n");
    }


    return 0;
}