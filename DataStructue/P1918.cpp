//保龄球
#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int,int> a;
int main(){
    int n, q, x;
    cin >> n ;
    for (int i = 1; i <= n;i++){
        cin >> x;
        a[x] = i;
    }
    cin >> q;
    for (int i = 1; i <= q;i++){
        cin >> x;
        cout << a[x]<<endl;
    }
    system("pause");
    return 0;
}