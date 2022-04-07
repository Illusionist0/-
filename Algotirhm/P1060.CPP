//开心的金明
#include<iostream>
using namespace std;

int main(){
    //01背包问题
    int n, m;
    int v[30], w[30];
    cin >> n >> m;
    int dp[m+1][n+1];
    int i, j;
    for (i = 1; i <= m;i++){
        cin >> v[i] >> w[i];
    }
    for (j = 1; j <= m;j++){
        for (i = n; i >=0;i--){
            if(i>=v[j])
                dp[j][i] = max(dp[j-1][i],dp[j-1][i-v[j]]+v[j]*w[j] );
            else
                dp[j][i] = dp[j-1][i];
        }
    }
    cout << dp[m][n];
    system("pause");
    return 0;
}