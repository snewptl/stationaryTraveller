#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int k,n,a[maxn],b[maxn],vis[maxn];
vector<int>vec[maxn];
void init(){
    for(int i=0;i<=n+1;i++){
        vec[i].clear();
        a[i]=0;
        vis[i]=0;
    }
    k=0;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            vec[b[i]].push_back(i);
        }
        int cur;
        if(!b[1])cur=0;
        else cur=n+1;
        int flag=1,cnt=0,sgn=0;
        while(flag){
            flag=0;
            sgn^=1;
            if(sgn)k+=vec[cur].size();
            cnt+=vec[cur].size();
            for(auto it:vec[cur]){
                if(!vec[it].empty()){
                    cur=it;
                    flag=1;
                    break;
                }
            }
            if(!flag)break;
            a[cnt]=cur;
            vis[cur]=1;
        }
        if(b[1])k=n-k;
        int le=1,ri=n;
        for(int i=1;i<=n;i++){
            if(a[i])continue;
            if(b[i]>k){
                while(le<=k&&vis[le])le++;
                a[i]=le++;
            }
            if(b[i]<=k){
                while(ri>k&&vis[ri])ri--;
                a[i]=ri--;
            }            
        }
        
        printf("%d\n",k);
        for(int i=1;i<=n;i++)printf("%d ",a[i]);
        puts("");
	}


	return 0;
}