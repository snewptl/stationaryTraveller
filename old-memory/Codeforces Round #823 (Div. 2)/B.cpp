#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,t[maxn],x[maxn],pos,res;
bool check(int mid){
    int l=0,r=2e8;
    for(int i=1;i<=n;i++){
        int temp=mid-t[i];
        if(temp<0)return false;
        else l=max(l,x[i]-temp),r=min(r,x[i]+temp);
    }
    if(l<=r&&mid<=res)pos=l;
    return l<=r;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&x[i]),x[i]*=2;
        for(int i=1;i<=n;i++)scanf("%d",&t[i]),t[i]*=2;
        int l=0,r=4e8;
        res=4e8;
        pos=0;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid))res=min(mid,res),r=mid-1;
            else l=mid+1;
        }
        printf("%.1lf\n",(1.0*pos/2+eps));

	}


	return 0;
}