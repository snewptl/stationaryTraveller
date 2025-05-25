#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&k);
        if(k%2){
            puts("YES");
            for(int i=1;i<=n;i+=2){
                printf("%d %d\n",i,i+1);
            }
        }
        else {
            if(k%4==0)puts("NO");
            else {
                puts("YES");
                vector<int>vec;
                for(int i=1;i<=n;i+=2)vec.push_back(i);
                for(int i=4;i<=n;i+=4){
                    printf("%d %d\n",vec.back(),i);
                    vec.pop_back();
                }
                for(int i=2;i<=n;i+=4){
                    printf("%d %d\n",i,vec.back());
                    vec.pop_back();
                }
            }
        }
	}


	return 0;
}