#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn],cnt[105],cur[105];
bool check(int x){
    int sum=0,lst=x-1;
    for(int i=1;i<=n;i++){
        int temp=min(cnt[i],lst);
        cur[i]=cnt[i];
        cur[i]-=temp;
        lst-=temp;
    }
    for(int i=1;i<=x;i++){
        sum+=min(cur[i],x-i+1)-1;
        if(sum<0)return false;
    }
    return true;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)cnt[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        for(int i=n;i>=0;i--){
            if(check(i)){
                printf("%d\n",i);
                break;
            }
        }
	}


	return 0;
}