#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int cnt[maxn];
vector<int>vec[maxn];
void init(){
    for(int i=1;i<=n;i++){
        for(auto j:vec[i]){
            cnt[j]=0;
        }
        vec[i].clear();
    }
}
bool solve(){
    for(int i=1;i<=n;i++){
        int flag=1;
        for(auto j:vec[i]){
            if(cnt[j]<2)flag=0;
        }
        if(flag)return true;
    }    
    return false;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            for(int j=1;j<=k;j++){
                int x;scanf("%d",&x);
                vec[i].push_back(x);
                cnt[x]++;
            }
        }
        if(solve())puts("YES");
        else puts("NO");
        init();

	}


	return 0;
}