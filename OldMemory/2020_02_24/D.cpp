#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int ans = 0;
int B[20033], A[20033];
int Bn[20033], An[20033];
int main()
{
    int T;scanf("%d",&T);
    while (T--){
        scanf("%d%d%d",&a,&b,&c);
        memset(B,0x3f3f,sizeof(B));
        memset(A,0x3f3f,sizeof(A));
        for (int i = 1; i <= 20000; i++){
            for (int j = i; j <= 20000; j += i){
                if (abs(j - c) < B[i]){
                    B[i] = abs(j - c);
                    Bn[i] = j;
                }
            }
        }
        for (int i = 1; i <= 20000; i++){
            for (int j = i; j <= 20000; j += i){
                if (abs(i - a) + abs(j - b) + B[j] < A[i]){
                    A[i] = abs(i-a)+abs(j-b)+B[j];
                    An[i] = j;
                }
            }
        }
        int ans = 0x3f3f3f, id = 0;
        for (int i = 1;i<=20000;i++){
            if (A[i] < ans){
                ans = A[i];
                id = i;
            }
        }
        printf("%d\n",ans);
        printf("%d %d %d\n",id,An[id],Bn[An[id]]);
    }
    return 0;
}