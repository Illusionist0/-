//疯狂的采药
#include<iostream>
using namespace std;

long long t, m;
//完全背包问题
int main(){
    cin >> t >> m;
    long long ti, val;
    long long dp[10000005]={0};
    for (long long i = 1; i <= m;i++){
        cin >> ti >> val;
        for (int j = ti; j <= t;j++){
            dp[j] = max(dp[j - ti] + val, dp[j]);
        }
    }
    cout << dp[t];
    system("pause");
    return 0;
}