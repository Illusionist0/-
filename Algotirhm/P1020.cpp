//导弹拦截
#include<iostream>
#include<vector>
using namespace std;
int main(){
    //转化为LIS问题
    //freopen("P.in", "r", stdin);
    //freopen("P.out", "w", stdout);
    int x;
    vector<int> bomb;
    while(cin>>x){
        bomb.push_back(x);
    }
    int n = bomb.size();
    //O(n^2),纯动态规划加一点暴力
    //O(nlgn),加贪心
    int f[n+1], len=0;
    f[0] = bomb[0];
    for (int i = 1; i < n;i++){
        if(bomb[i]<=f[len]){
            f[++len] = bomb[i];
        }
        else{
            //二分
            int l=0, r=len, mid;
            while(l<=r){
                mid = (l + r) / 2;
                if(bomb[i]<=f[mid]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            f[l] = bomb[i];
        }
    }
    int p[n],equip = 0;
    p[0] = bomb[0];
    for (int i = 0; i < n;i++){
        if(bomb[i]>p[equip]){
            p[++equip] = bomb[i];
        }
        else{
            //二分
            int l=0, r=equip, mid;
            while(l<=r){
                mid = (l + r) / 2;
                if(bomb[i]>p[mid]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            p[l] = bomb[i];
        }
    }
    cout << len+1 << endl;
    cout << equip + 1;
    //system("pause");
    return 0;
}