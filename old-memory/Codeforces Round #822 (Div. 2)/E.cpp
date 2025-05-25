#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
vector<int>vec;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<n;i++){
        int flag=1;
        for(int j=2;j<i;j++){
            if(i%j==0)flag=0;
        }
        int vis[355];
        memset(vis,0,sizeof(vis));
        if(flag){
            int cur=i;
            for(int j=1;j<n;j++){
                vis[cur]=1;
                cur*=i,cur%=n;
                vec.push_back(cur);
            }
            int temp=1;
            for(int i=1;i<n;i++)if(!vis[i]){
                temp=0;
            }
            if(temp)break;
            vec.clear();
        }
    }
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        for(int i=0;i<n;i++){
            if(vec[i]==x){
                pos=
                for(int j=i+1;j!=i;j=(j+1)%n){
                    printf("%d");
                }
            }
        }
    }

	return 0;
}