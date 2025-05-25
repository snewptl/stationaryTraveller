#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,a[maxn],b[maxn];
vector<int>vec[maxn];
int cnt[maxn];
map<int,int>h;
int tot;
pii c[maxn];
int hsh(int x){
    if(!h.count(x))h[x]=++tot;
    return h[x];
}
void init(){
    h.clear();
    for(int i=1;i<=tot;i++){
        vec[i].clear();
        cnt[i]=0;
    }
    tot=0;
}
bool solve(){
    for(int i=1;i<=n;i++)if(a[i]<b[i])return false;
    set<pii>s;
    s.insert({1,n});
    for(int i=1;i<=tot;i++){
        int lst=0,num=cnt[i];
        for(auto j:vec[i]){
            auto it=s.upper_bound({j,n+1});
            --it;
            if(j>lst&&a[j]!=b[j]){
                --num;
                if(num<0)return false;
                if(it->second<j)return false;
                lst=it->second;
            }
            pii cur=*it;
            s.erase(it);
            pii n1={cur.first,j-1},n2={j+1,cur.second};
            if(n1.second>=n1.first)s.insert(n1);
            if(n2.second>=n2.first)s.insert(n2);
            
        }
    }
    return true;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)c[i]={b[i],i};
        sort(c+1,c+n+1,greater<pii>());
        for(int i=1;i<=n;i++){
            vec[hsh(c[i].first)].push_back(c[i].second);
        }
        for(int i=1;i<=tot;i++){
            sort(vec[i].begin(),vec[i].end());
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int x;
            scanf("%d",&x);
            cnt[hsh(x)]++;
        }
        if(!solve())puts("NO");
        else puts("YES");
	}


	return 0;
}
/*
1
13
7 9 4 5 3 3 3 6 8 10 3 2 5
5 3 1 5 3 2 2 5 8 5 1 1 5
8
1 5 3 5 4 2 3 1
*/