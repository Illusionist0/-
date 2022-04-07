//金明的预算方案
#include<iostream>
using namespace std;
int dp[32001];
int n, m;
int v[100], p[100], vx[100][2], px[100][2],q[100],z[100];
int main(){
    //freopen("P.in", "r", stdin);
    //freopen("P.out", "w", stdout);
    cin >> n >> m;
    int i, j = 1;
    for (i = 1; i <= m;i++){
        cin >> v[i] >> p[i] >> z[i];
        int c = z[i];
        if(z[i]!=0){
            vx[c][q[c]] = v[i];
            px[c][q[c]] = p[i];
            q[c]++;
        }
    }
    for (i = 1; i <= m;i++){//物品主件
        if(z[i]==0){
        for (j = n; j >= 0;j--){//重量
            if(j>=v[i]){
                //不选附件
                dp[j] = max(dp[j], dp[j - v[i]] + v[i]*p[i]);
                //选附件1
                if(q[i]>=1&&j>=v[i]+vx[i][0]){
                    dp[j] = max(dp[j], dp[j - v[i] - vx[i][0]] + v[i] * p[i] + vx[i][0] * px[i][0]);
                    //cout << j << " " << dp[j] << endl;
                }
                //选附件2
                if(q[i]>=2&&j>=v[i]+vx[i][1]){
                    dp[j] = max(dp[j], dp[j - v[i] - vx[i][1]] + v[i] * p[i] + vx[i][1] * px[i][1]);
                }
                //选附件1和选附件2
                if(q[i]>=2&&j>=v[i]+vx[i][0]+vx[i][1]){
                    dp[j] = max(dp[j], dp[j - v[i] - vx[i][0] - vx[i][1]] + v[i] * p[i] + vx[i][0] * px[i][0] + vx[i][1] * px[i][1]);
                }
            }
        }
        }
    }
    cout << dp[n];
    //system("pause");
    return 0;
}