//奶牛排队
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n ;
    int h[n],high=0,sum=0;
    h[0] = 0;
    for (int i = 1; i <= n;i++){
        cin >> h[i];
    }
    for (int i = 1; i < n;i++){
        for (int j = i+1; j <= n;j++){
            if(h[j]<=h[i])
                break;
            if(h[j]>h[high])
                high = j;
        }
        sum = max(sum, high - i + 1);
    }
    cout << sum ;
    system("pause");
    return 0;
}