//明明的随机数
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    //桶排序，读取元素时，如果桶里已有就不读，输出元素时遍历整个桶，从小到大输出桶里有的元素
    //freopen("P.in", "r", stdin);
    //freopen("P.out", "w", stdout);
    int n;
    cin >> n;
    int rand[n];
    for (int i = 0; i < n;i++){
        cin >> rand[i];
    }
    sort(rand, rand + n);
    int res = unique(rand, rand + n) - rand;
    cout << res<<endl;
    cout << rand[0];
    for (int i = 1; i < res;i++){
        cout << " "<<rand[i];
    }
        system("pause");
    return 0;
}