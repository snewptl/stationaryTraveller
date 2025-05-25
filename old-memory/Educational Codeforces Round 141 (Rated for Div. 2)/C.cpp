#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,a[maxn],b[maxn];
int solve(){
    int sum=0,pos=0;
    for(int i=1;i<=n&&sum+a[i]<=m;i++,pos++)sum+=a[i];
    for(int i=n;i>=1;i--){
        int temp=pos,flag=0;
        if(a[pos]>=b[i]||sum-a[pos]+b[i]<=m)flag=1;
        if(flag){
            if(temp>=i-1)return n-i+1;
        }
        else if(temp>=i)return n-i+1;
    }    
    return n+1;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
        sort(a+1,a+n+1);
        printf("%d\n",solve());
	}
	return 0;
}