//通天之分组背包
#include<iostream>
using namespace std;

int a[1001], b[1001], c, d[1001];
int g[1001][1001];
int dp[1001];
int main(){
    int m, n;
    cin >> m >> n;
    int k = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i] >> b[i] >> c;
        k = max(k, c);
        d[c]++;
        g[c][d[c]] = i;
    }
    //一组中最多只可以选一个,或者不选
    for (int i = 1; i <= k;i++){//组数
        for (int j = m; j >= 0;j--){//重量
            for (int s = 1; s <= d[i];s++){//组内数
                int x = g[i][s];
                if(a[x]<=j){
                    dp[j] = max(dp[j], dp[j - a[x]] + b[x]);
                }
            }
        }
    }
    cout << dp[m];
    system("pause");
    return 0;
}