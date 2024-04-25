#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int rk[10];
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
        for(int i=4;i<=4;i++){
            vector<int>vec;
            int ans=0;
            for(int j=1;j<=i;j++)
                vec.push_back(j);
            do{
                for(int j=0;j<i;j++){
                    rk[vec[j]]=j+1;
                }
                int flag=1;
                for(int j=0;j<i;j++){
                    if(abs(rk[j+1]-vec[j])>1)flag=0;
                }
                if(flag){
                    ans++;
                for(auto it:vec)printf("%d ",it);
                puts("");
                }
            }while(next_permutation(vec.begin(),vec.end()));
            printf("%d %d\n",i,ans);
        }
	}


	return 0;
}