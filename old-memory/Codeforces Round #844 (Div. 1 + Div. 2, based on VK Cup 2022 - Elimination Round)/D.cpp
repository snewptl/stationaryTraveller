#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
vector<pii>pre,nxt;
int n,a[55],ans;
map<ll,int>mp;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        ans=1;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            mp.clear();
            for(int j=i+1;j<=n;j++){
                int temp=a[j]-a[i];
                for(int k=1;k*k<=temp;k++){
                    if(temp%k==0){
                        int x=k,y=temp/k;
                        if((y-x)%2||(y+x)%2)continue;
                        int x1=(y-x)/2,x2=(y+x)/2;
                        ll ad=1ll*x1*x1-a[i];
                        if(ad<0)continue;
                        if(ad+a[j]!=1ll*x2*x2)continue;
                        mp[ad]++;
                        // printf("@@%d\n",ans);
                        ans=max(mp[ad]+1,ans);
                    }
                }
            }

        }
        printf("%d\n",ans);
	}


	return 0;
}