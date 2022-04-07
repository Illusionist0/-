//计数问题
#include<iostream>
#include<string>
using namespace std;
int count(int i,int x){
    int m, res = 0;
    while(i>=10){
        m = i % 10;
        if(x==m)
            res += 1;
        i /= 10;
    }
    if(i==x)
        res += 1;
    return res;
}
int main(){
    int n, x;
    cin >> n >> x;
    int c = 0;
    for (int i = 1; i <= n;i++){
        c+=count(i, x);
    }
    cout << c;
    system("pause");
    return 0;
}