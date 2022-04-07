//能量项链
#include<iostream>
#include<set>
using namespace std;
int m[250],f[250][250];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> m[i];
        m[i + n] = m[i];
    }
    int e = 0;
    for(int j=2;j<=2*n;j++){
        for (int i = j-1; i > j -n&&i>=1 ;i--){
            for (int k = i; k < j;k++){
                f[i][j] = max(f[i][k] + f[k + 1][j] + m[i] * m[k+1] * m[j + 1], f[i][j]);
            }
            e=max(f[i][j], e);
        }
    }
    cout << e;
    system("pause");
    return 0;
}