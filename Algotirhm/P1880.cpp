//石子合并
#include<iostream>
#include<climits>
using namespace std;
int f1[250][250], f2[250][250];
int s[250];//前缀和
int main(){
    int n;
    cin >> n;
    int m[300];
    for (int i = 1; i <= n;i++){
        cin >> m[i];
        m[i + n] = m[i];//环
    }
    for (int i = 1; i <= n+n;i++){
        s[i] = s[i - 1] + m[i];
    }
    for (int p = 1; p < n;p++){
        for (int i = 1, j = i + p; (j <2*n)&&(i<2*n); i++,j=i+p)
        {
            f2[i][j] = INT_MAX;
            for (int k = i; k < j;k++){
                f1[i][j] = max(f1[i][j], f1[i][k] + f1[k + 1][j] + s[j] - s[i - 1]);
                f2[i][j] = min(f2[i][j], f2[i][k] + f2[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    int maxans=0, minans=INT_MAX;
    for (int i = 1; i <= n;i++){
        maxans = max(maxans, f1[i][i + n - 1]);
        minans = min(minans, f2[i][i + n - 1]);
    }
    cout << minans << endl
         << maxans ;
    system("pause");
    return 0;
}