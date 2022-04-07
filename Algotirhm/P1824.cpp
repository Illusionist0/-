//进击的奶牛
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long>cow_shed;
int n,c,a;
bool check(int x){//检验函数
    int num = 0;//需要空牛棚数
    int left = cow_shed[0];
    for (int i = 1; i < n;i++){
        if(cow_shed[i]-left<x)
            num++;//不满足，空牛棚数+1
        else
            left = cow_shed[i];
        if(num>a)
            return false;//空牛棚数不足
    }
    return true;
}
int main(){
    long x;
    cin >> n >> c;
    for (int i = 0; i < n; i++){
        cin >> x;
        cow_shed.push_back(x);
    }
    sort(cow_shed.begin(), cow_shed.end());
    a = n - c;//空牛棚数
    int left = 1, right = cow_shed[n - 1] - cow_shed[0];
    //二分答案,区间左闭右开
    while(left+1<right){
        int mid = (left + right) / 2;
        if(check(mid))
            left = mid;
        else
            right = mid;
    }
    if(check(left))cout<<left;
    else cout << right;
    system("pause");
    return 0;
}