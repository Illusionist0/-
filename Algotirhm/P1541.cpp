//乌龟棋
#include<iostream>
using namespace std;
int n, m;
int dp[50][50][50][50];
int main(){
    cin >> n >> m;
    int a[n + 1], b[m + 1],c[5]={0};
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= m;i++){
        cin >> b[i];
        c[b[i]]++;
    }
    dp[0][0][0][0] = a[1];
    for (int x1 = 0; x1 <= c[1];x1++){
        for(int x2 = 0; x2 <= c[2];x2++){
            for(int x3 = 0; x3 <= c[3];x3++){
                for(int x4 = 0; x4 <= c[4];x4++){
                    int x = 1 + x1 + x2 * 2 + x3 * 3 + x4 * 4;
                    if(x1>0)
                        dp[x1][x2][x3][x4] = max(dp[x1][x2][x3][x4], dp[x1 - 1][x2][x3][x4] + a[x]);
                    if(x2>0)
                        dp[x1][x2][x3][x4] = max(dp[x1][x2][x3][x4], dp[x1][x2-1][x3][x4] + a[x]);
                    if(x3>0)
                        dp[x1][x2][x3][x4] = max(dp[x1][x2][x3][x4], dp[x1][x2][x3-1][x4] + a[x]);
                    if(x4>0)
                        dp[x1][x2][x3][x4] = max(dp[x1][x2][x3][x4], dp[x1][x2][x3][x4-1] + a[x]);
                }
            }
        }
    }
    cout << dp[c[1]][c[2]][c[3]][c[4]];
    system("pause");
    return 0;
}