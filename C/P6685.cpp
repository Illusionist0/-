//可持久化动态仙人掌的直径问题
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n, m, x = 1;
    cin >> n >> m;
    while(pow(x,m)<=n){
        x++;
    }
    cout << x - 1;
    system("pause");
    return 0;
}