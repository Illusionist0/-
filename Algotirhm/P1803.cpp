//凌乱的yyy/线段覆盖
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct race{
    int a, b;
} race;
bool cmp(race x,race y){
    return x.b <= y.b;
}
int main(){
    int n;
    cin >> n;
    race r[n];
    for (int i = 0; i < n;i++){
        cin >> r[i].a >> r[i].b;
    }
    sort(r, r+n,cmp);
    int j = 0;
    int res = 0;
    for (int i = 0; i < n;i++){//贪心策略
    //优先放右端小的线段，能放就放，原理需要结合图理解
        if(j<=r[i].a){
            j = r[i].b;
            ++res;
        }
    }
    cout << res;
    system("pause");
    return 0;
}