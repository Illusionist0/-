//铺设道路
#include<iostream>
using namespace std;
int n;
int main(){
    cin >> n;
    int d,l=0,sum=0;
    for (int i = 1; i <= n;i++){
        cin >> d;
        if (d >=l)//如果大于前者说明还需要额外填d-l段，否则在前者填土过程中该土坑已被填平
            sum += (d - l);
        l = d;
    }
    cout << sum;
    system("pause");
    return 0;
}