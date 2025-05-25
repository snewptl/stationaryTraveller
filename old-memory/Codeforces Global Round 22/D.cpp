#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int k,n,a[maxn],b[maxn];
vector<pii>vec[2];
int in[maxn],vis[maxn];
void init(){
    vec[0].clear();
    vec[1].clear();
    for(int i=1;i<=n;i++)in[i]=0,vis[i]=0,a[i]=0;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        for(int i=1;i<=n;i++){
            if(i==1){
                if(b[i]==n+1)vec[0].push_back({1,1}),in[i]=0;
                else vec[1].push_back({1,1}),in[i]=1;
            }    
            else {
                if(b[i]==b[i-1]){
                    in[i]=in[i-1];
                    vec[in[i]].back().second++;
                }
                else {
                    in[i]=in[i-1]^1;
                    vec[in[i]].push_back({i,i});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(in[i]==0)k++;
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<vec[i].size();j++){
                if(vec[i][j].first>1){
                    int pos=vec[i][j].first;
                    if(!vis[b[pos]])a[pos-1]=b[pos],vis[b[pos]]=1;
                }
            }
        }
        int cur=1;
        for(int j=0;j<vec[0].size();j++){
            for(int i=vec[0][j].first;i<=vec[0][j].second;j++){
                if(a[i])continue;
                while(cur<=n&&vis[cur])cur++;
                a[i]=cur++;
            }
        }
        cur=n;
        for(int j=0;j<vec[1].size();j++){
            for(int i=vec[1][j].first;i<=vec[1][j].second;j++){
                if(a[i])continue;
                while(cur&&vis[cur])cur--;
                a[i]=cur--;
            }
        }        
        printf("%d\n",k);
        for(int i=1;i<=n;i++)printf("%d ",a[i]);
        puts("");
	}


	return 0;
}