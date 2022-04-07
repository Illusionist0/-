//Holidays
#include<iostream>
using namespace std;
int c[101];
int main(){
    int n, m;
    cin >> n >> m;
    int a[m + 1], b[m + 1];
    for (int i = 1; i <= m;i++){
        cin >> a[i] >> b[i];
        for (int j = a[i]; j <= b[i];j++){
            c[j] += 1;
        }
    }
    for (int i = 1; i <= n;i++){
        if(c[i]!=1){
            cout << i<<" "<<c[i];
            system("pause");
            return 0;
        }
    }
    cout << "OK";
    system("pause");
    return 0;
}