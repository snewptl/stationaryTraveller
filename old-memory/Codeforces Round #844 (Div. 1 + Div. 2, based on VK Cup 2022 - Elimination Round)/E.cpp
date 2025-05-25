#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
struct Rec{
    int u,l,d,r,idx;
};
Rec nul={0,0,0,0,0};
int n,L,R;
vector<Rec>rec,line[3];
Rec pre[maxn];

bool cmp(Rec a,Rec b){
    return a.l==b.l?a.r>b.r:a.l<b.l;
}
int vis[3][maxn],tp[maxn];
int nxt[3][maxn],frt[3][maxn];
void update(int row,int l,int r){
    for(int i=l+1;i<=min(r+1,R);i++){
        frt[row][i]=frt[row][i-1];
    }
    for(int i=r-1;i>=max(l-1,L);i--){
        nxt[row][i]=nxt[row][i+1];
    }
}
void paint(int idx){
    for(int i=pre[idx].u;i<=pre[idx].d;i++){
        for(int j=pre[idx].l;j<=pre[idx].r;j++)
            vis[i][j]=idx;
        update(i,pre[idx].l,pre[idx].r);
    }
}
void solve_rec(){
    int lst=0;
    for(auto &it:rec){
        if(it.l<=lst){
            if(it.r<=lst){
                pre[it.idx]=nul;
                continue;
            }
            else pre[it.idx].l=lst+1;
        }
        paint(it.idx);
        lst=it.r;
    }
    
    for(int i=1;i<=2;i++){
        nxt[i][n]=n+1;
        for(int j=R-1;j>=1;j--){
            nxt[i][j]=nxt[i][j+1];
            if(!vis[i][j+1])nxt[i][j]=j+1;
        }
        for(int j=2;j<=n;j++){
            frt[i][j]=frt[i][j-1];
            if(!vis[i][j-1])frt[i][j]=j-1;
        }
    }
}
void solve_line(vector<Rec>line){
    int lst=0;
    for(auto &it:line){
        if(it.l<=lst){
            if(it.r<=lst){
                pre[it.idx]=nul;
                continue;
            }
            else pre[it.idx].l=lst+1;
        }
        lst=it.r;
        int flag=1;
        while(vis[it.u][it.l]){
            it.l=nxt[it.u][it.l];
            if(it.l>it.r){
                pre[it.idx]=nul;
                flag=0;
                break;
            }
        }
        while(vis[it.u][it.r]){
            it.r=frt[it.u][it.r];
            if(it.l>it.r){
                pre[it.idx]=nul;
                flag=0;
                break;
            }
        }
        if(flag){
            int le=it.l,ri=it.r;
            int i=le;
            while(i<=ri){
                if(vis[it.u][i]){
                    int cov=vis[it.u][i];
                    pre[cov].u++;
                    while(i<=pre[cov].r){
                        vis[it.u][i]=it.idx;
                        i++;
                    }
                    if(pre[cov].u>pre[cov].d)pre[cov]=nul;
                }
                else vis[it.u][i]=it.idx,i++;
            }
            update(it.u,le,ri);
            pre[it.idx].l=le,pre[it.idx].r=ri;
        }
    }
}
void init(){
    rec.clear();
    line[1].clear();
    line[2].clear();
    for(int i=1;i<=2;i++){
        for(int j=L-1;j<=R+1;j++){
            nxt[i][j]=0;
            frt[i][j]=0;
            vis[i][j]=0;
        }
    }
    L=1e9,R=0;
}
void input(){
    scanf("%d",&n);
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        input();
        for(int i=1;i<=n;i++){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            Rec temp={a,b,c,d,i};
            L=min(L,b);
            R=max(R,d);
            pre[i]=temp;
            if(a!=c)rec.push_back({a,b,c,d,i});
            else line[a].push_back({a,b,c,d,i});
        }
        sort(rec.begin(),rec.end(),cmp);
        sort(line[1].begin(),line[1].end(),cmp);
        sort(line[2].begin(),line[2].end(),cmp);
        solve_rec();
        solve_line(line[1]);
        solve_line(line[2]);
        int ans=0;
        for(int i=1;i<=2;i++){
            for(int j=L;j<=R;j++){
                if(vis[i][j])ans++;
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++){
            printf("%d %d %d %d\n",pre[i].u,pre[i].l,pre[i].d,pre[i].r);
        }
        init();
	}


	return 0;
}