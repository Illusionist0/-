//语文成绩
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    //差分
    int n, p;
    int x, y, z;
    cin >> n >> p;
    int a[n + 1]={0}, d[n + 1];
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= p;i++){
        cin >> x >> y >> z;
        d[x] += z;
        if(y+1<=n)d[y + 1] -= z;
    }
    int min = a[0]+d[1];
    for (int i = 1; i <= n;i++){
        a[i] = d[i] + a[i - 1];
        if(a[i]<min)
            min = a[i];
    }
    cout << min;
    system("pause");
    return 0;
}