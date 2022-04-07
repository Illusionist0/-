//最大子树和
#include<iostream>
#include<vector>
using namespace std;
int dp[160001],w[160001];
vector<int> e[160001];
void dfs(int v1,int v2){//自上向下深度遍历，自下向上返回剪枝与否，v1代表下一个节点，v2代表当前结点的权值
    dp[v1] = w[v1];//初值为自身权值
    for (int i = 0; i < (int)e[v1].size();i++){
        int v = e[v1][i];
        if(v!=v2){//除本身以外的边
            dfs(v, v1);
            if(dp[v]>0){
                dp[v1] += dp[v];//不剪枝
            }
        }
    }
}
int main(){
    //剪枝
    int n,ans=-2147483647;
    cin >> n;
    //赋权
    for (int i = 1; i <= n;i++){
        cin >> w[i];
    }
    //连边
    int v1, v2;
    for (int i = 1; i <= n - 1;i++){
        cin >> v1 >> v2;
        e[v1].push_back(v2);
        e[v2].push_back(v1);
    }
    dfs(1, 0);
    //注意1不一定在范围中，一般需要比较得出最大值
    for (int i = 1; i <= n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
    system("pause");
    return 0;
}