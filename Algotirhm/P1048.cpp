//采药
#include<iostream>
using namespace std;

int t, m;
//01背包问题
int main(){
    cin >> t >> m;
    int ti[120], val[120];
    int dp[120][120];
    for (int i = 1; i <= m;i++){
        cin >> ti[i] >> val[i];
    }
    for (int i = 1; i <= m;i++){
        for (int j = t; j >= 0;j--){
            if(j>=ti[i])
                dp[i][j] = max(dp[i - 1][j - ti[i]] + val[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[m][t];
    system("pause");
    return 0;
}