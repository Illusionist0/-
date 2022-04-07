//最大子段和
#include<iostream>
using namespace std;

int main(){
    //freopen("P1115_2.in", "r", stdin);
    //freopen("P1115_2.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    int sum,max_sum;
    sum = 0;
    max_sum = sum;
    int minus,flag=0;//判断全负
    for (int i = 0; i < n;i++){
        cin >> a[i];
        if(a[i]<0){
            if(flag==0){
                minus = a[i];
                flag = 1;
            }
            else{
                minus = max(a[i], minus);
                flag++;
            }
        }
        //sum += a[i];
        if(sum+a[i]<0){
            sum = 0;
        }
        sum += a[i];
        max_sum = max(sum, max_sum);
    }
    if(flag==n)
        max_sum = minus;
    cout << max_sum;
    system("pause");
    return 0;
}