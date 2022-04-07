//过河卒
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,horse_x,horse_y;
bool control_point[30][30];
long long dp[30][30];
int main(){
    cin >> n >> m >> horse_x >> horse_y;
    n += 2;
    m += 2;
    horse_x += 2;
    horse_y += 2;
    dp[2][1] = 1;
    control_point[horse_x][horse_y] = true;
    control_point[horse_x+2][horse_y+1] = true;
    control_point[horse_x+1][horse_y+2] = true;
    control_point[horse_x-1][horse_y+2] = true;
    control_point[horse_x-2][horse_y+1] = true;
    control_point[horse_x-2][horse_y-1] = true;
    control_point[horse_x-1][horse_y-2] = true;
    control_point[horse_x+1][horse_y-2] = true;
    control_point[horse_x+2][horse_y-1] = true;
    for (int i = 2; i <=n;i++){
        for (int j = 2; j <=m;j++){
            if(control_point[i][j])
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j-1];
        }
    }
    cout << dp[n][m];
    system("pause");
    return 0;
}