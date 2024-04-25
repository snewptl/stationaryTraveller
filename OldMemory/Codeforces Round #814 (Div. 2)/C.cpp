#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,q;
int a[maxn];
pair<pii,int> qu[maxn];
int ans[maxn];
int head,tail,cnt[maxn];
pii que[maxn*3];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&q);
        head=1,tail=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            que[++tail]={a[i],i};
            cnt[i]=0;
        }
        for(int i=1;i<=q;i++){
            int x,k;
            scanf("%d%d",&x,&k);
            qu[i]={{k,x},i};
        }
        sort(qu+1,qu+q+1);
        int rd=0;
        for(int i=1;i<=q;i++){
            while(rd<min(n,qu[i].first.first)){
                pii mx,mn;
                mx=que[head];
                mn=que[head+1];
                if(que[head].first<que[head+1].first)swap(mx,mn);
                que[++head]=mx;
                que[++tail]=mn;
                cnt[mx.second]++;
                rd++;
            }
            ans[qu[i].second]=cnt[qu[i].first.second];
            if(qu[i].first.first>n&&qu[i].first.second==que[head].second){
                ans[qu[i].second]+=qu[i].first.first-n;
            }
        }
        for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	}


	return 0;
}