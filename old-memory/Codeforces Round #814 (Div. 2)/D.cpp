#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,tot;
int a[maxn],le[maxn];
map<int,int>mp;
vector<int>vec[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=tot;i++)vec[i].clear();
        mp.clear();tot=0;
        for(int i=1;i<=n;i++)le[i]=-1;
        mp[0]=++tot;
        vec[tot].push_back(0);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]^=a[i-1];
            if(!mp.count(a[i]))mp[a[i]]=++tot;
            int idx=mp[a[i]];
            if(!vec[idx].empty())le[i]=vec[idx].back();
            vec[idx].push_back(i);
        }
        int lst=0,ans=n;
        for(int i=1;i<=n;i++){
            if(le[i]>=lst)ans--,lst=i;
        }
        printf("%d\n",ans);
	}


	return 0;
}