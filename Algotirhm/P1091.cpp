//合唱队形
#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    int t[n+1];
    for (int i = 1; i <= n;i++){
        cin >> t[i];
    }
    int len = 0;
    for (int i = 1; i <= n;i++){
        int left_dp[n + 1], left_len=1;
        left_dp[1] = t[i];
        for (int j = i-1; j >= 1;j--){
            //左边
            if(t[j]<left_dp[left_len]){
                left_dp[++left_len] = t[j];
            }
            else{
                //二分查找
                if(t[j]<left_dp[1]){
                    int l=2, r=left_len, mid;
                    while(l<=r){
                        mid = (l + r) / 2;
                        if(left_dp[mid]>t[j]){
                            l = mid + 1;
                        }
                        else{
                            r = mid - 1;
                        }
                    }
                    left_dp[l] = t[j];
                }
            }
        }
        int right_dp[n + 1], right_len=1;
        right_dp[1] = t[i];
        for (int j = i+1; j <= n;j++){
            //右边
            if(t[j]<right_dp[right_len]){
                right_dp[++right_len] = t[j];
            }
            else{
                //二分查找
                if(t[j]<right_dp[1]){
                    int l=2, r=right_len, mid;
                    while(l<=r){
                        mid = (l + r) / 2;
                        if(right_dp[mid]>t[j]){
                            l = mid + 1;
                        }
                        else{
                            r = mid - 1;
                        }
                    }
                    right_dp[l] = t[j];
                }
            }
        }
        len = max(len, left_len + right_len-1);
    }
    cout << n-len;
    system("pause");
    return 0;
}