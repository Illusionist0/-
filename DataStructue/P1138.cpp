//第k小整数
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    //STL unique 伪去重
    int size = unique(a, a + n) - a;//不重复元素
    if(k<size){
        cout << a[k-1];
    }
    else
        cout << "NO RESULT";
    system("pause");
    return 0;
}