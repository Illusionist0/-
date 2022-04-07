//投资的最大收益
#include<iostream>
using namespace std;
int s, n, d, dp[1005];
//完全背包问题变式
int main(){
    cin >> s >> n >> d;
    int sum[d + 1], rate[d + 1];
    for (int i = 1; i <= d;i++){
        cin >> sum[i] >> rate[i];
    }
    //n年投资
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <=d;j++){
            for (int k = sum[j]/1000; k <= s/1000;k++){
                dp[k] = max(dp[k - sum[j]/1000] + rate[j], dp[k]);
            }
        }
        s += dp[s/1000];
    }
    cout << s;
    system("pause");
    return 0;
}