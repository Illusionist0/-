//demo
#include<iostream>
using namespace std;

int hf[40][40];
int main(){
    //freopen("P.in", "r", stdin);
    //freopen("P.out", "w", stdout);
    int n;
    cin >> n;
    hf[1][(n + 1) / 2] = 1;//1写在第一行中间
    int pi=1, pj=(n+1)/2;
    for (int k = 2; k <= n * n;k++){
        if(pi==1&&pj!=n){
            hf[n][++pj] = k;
            pi = n;
            continue;
        }
        if(pj==n&&pi!=1){
            hf[--pi][1] = k;
            pj = 1;
            continue;
        }
        if(pi==1&&pj==n){
            hf[++pi][pj] = k;
            continue;
        }
        if(pi!=1&&pj!=n){
            if(hf[pi-1][pj+1]==0){
                hf[--pi][++pj] = k;
            }
            else{
                hf[++pi][pj] = k;
            }
            continue;
        }
    }
    for (int i = 1; i <= n ;i++){
        for (int j = 1; j < n;j++){
            cout << hf[i][j] << " ";
        }
        cout << hf[i][n] << endl;
    }
    system("pause");
    return 0;
}