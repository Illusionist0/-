//混合牛奶
#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
typedef struct farmer{
    int p, a;
} farmer;
farmer f[5001];
bool cmp(farmer a,farmer b){
    return a.p < b.p;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> f[i].p >> f[i].a;
    }
    //优先买单价低的奶农
    int need = n,cost=0;
    sort(f+1, f+m+1,cmp);//排序
    for (int i = 1; i <= m; i++){
        if(f[i].a>=need){
            cost += need * f[i].p;
            need = 0;
            break;
        }
        else{
            cost += f[i].a * f[i].p;
            need -= f[i].a;
        }
    }
    cout << cost;
    system("pause");
    return 0;
}