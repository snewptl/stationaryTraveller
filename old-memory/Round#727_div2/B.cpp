#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m;
char s[maxn];
int vis[maxn][30];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		for(int i=0;i<=m;i++){
			for(int j=0;j<26;j++)
			vis[i][j]=0;
		}
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			int len=strlen(s);
			for(int j=0;j<len;j++){
				vis[j][s[j]-'a']++;
			}
		}
		for(int i=1;i<n;i++){
			scanf("%s",s);
			int len=strlen(s);
			for(int j=0;j<len;j++){
				vis[j][s[j]-'a']--;
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<26;j++){
				if(vis[i][j])printf("%c",'a'+j);
			}
		}
		printf("\n");
		fflush(stdout);
    }


    return 0;
}