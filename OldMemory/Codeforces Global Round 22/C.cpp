#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        int cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]%2!=0)cnt++;
        }
        int opt=n-cnt;
        if(opt%2){
            if((cnt/2)%2==0)puts("Alice");
            else {
                if(cnt%2==0)puts("Bob");
                else puts("Alice");
            }
        }
        else {
            if(((cnt+1)/2)%2)puts("Bob");
            else puts("Alice");
        }
        

	}


	return 0;
}