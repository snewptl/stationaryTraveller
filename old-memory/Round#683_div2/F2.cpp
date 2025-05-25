#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
const int Limit=350;

int a[maxn];

int limit;
int cnt,sum[maxn];

void add(int x,int k)
{
    if(sum[x]==limit) cnt--;
    sum[x]+=k;
    if(sum[x]==limit) cnt++;
}

int vis[maxn];
int pos[maxn<<1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],vis[a[i]]++;
    int mx=max_element(vis+1,vis+n+1)-vis;

    int ans=0;
    for(limit=1;limit<=Limit;limit++)
    {
        fill(sum+1,sum+n+1,0);cnt=0;
        for(int l=1,r=1;r<=n;r++)
        {
            add(a[r],1);
            while(sum[a[r]]>limit) add(a[l++],-1);
            if(cnt>=2) ans=max(ans,r-l+1);
        }
    }

    for(int col=1;col<=n;col++) if(vis[col]>Limit && col!=mx)
    {
        fill(pos,pos+(n<<1)+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(a[i]==col) sum[i]=1;
            else if(a[i]==mx) sum[i]=-1;
            else sum[i]=0;
            sum[i]+=sum[i-1];
        }
        int tot=n;
        pos[tot]=0;
       
        for(int i=1;i<=n;i++)
        {
            if(pos[tot+sum[i]]==-1) pos[tot+sum[i]]=i;
            else ans=max(ans,i-pos[tot+sum[i]]);
        }
    }
    cout<<ans;
    return 0;
}