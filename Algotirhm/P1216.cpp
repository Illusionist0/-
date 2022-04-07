//数字三角形
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int r;
    cin >> r;
    int x;
    vector<vector<int>> triangle(r);
    for (int i = 0; i < r; i++){
        for (int j = 0; j < i + 1;j++){
            cin >> x;
            triangle[i].push_back(x);
        }
    }
    //DP
    vector<int> route;
    int m = r - 2, n = 0;
    while(m>=0){
        for (n = 0; n <= m;n++){
            triangle[m][n]+=max(triangle[m+1][n],triangle[m+1][n+1]);
        }
        m--;
    }
    cout << triangle[0][0];
    system("pause");
    return 0;
}
