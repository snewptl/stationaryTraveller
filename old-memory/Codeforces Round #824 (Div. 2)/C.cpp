#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int to[30],in[30],fa[30];
char s[maxn];
int n;
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%s",&n,s+1);
        memset(to,-1,sizeof(to));
        memset(in,-1,sizeof(in));
        for(int i=0;i<26;i++)fa[i]=i;
        for(int i=1;i<=n;i++){
            if(to[s[i]-'a']!=-1)continue;
            for(int j=0;j<26;j++){
                if(in[j]!=-1||find(s[i]-'a')==find(j))
                    continue;
                to[s[i]-'a']=j;
                in[j]=1;
                fa[find(j)]=find(s[i]-'a');
                break;
            }
        }
        int bg,ed;
        for(int i=0;i<26;i++){
            if(to[i]==-1)bg=i;
            if(in[i]==-1)ed=i;
        }
        to[bg]=ed;
        for(int i=1;i<=n;i++){
            printf("%c",to[s[i]-'a']+'a');
        }
        puts("");
	}


	return 0;
}