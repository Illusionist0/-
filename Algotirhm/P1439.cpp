//最长公共子序列
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int n;
int main(){
    //freopen("P1439.in", "r", stdin);
    //freopen("P1439.out", "w", stdout);
    cin >> n;
    int s1[n + 1], s2[n + 1];
    int table[n+1];
    int dp[n+1];
    for (int i = 1; i <= n;i++){
        cin >> s1[i];
        table[s1[i]] = i;
    }
    for (int i = 1; i <= n;i++){
        cin >> s2[i];
        s2[i] = table[s2[i]];
    }
    //转化为LIS
    //int j = 0,longest=1;
    //set1[0]=s2[1];
    //错解，拟用O(n^2)且动态转移有误，例如，1 5 6 2 3 4在该算法下迭代结果为1 5 6，正确结果应该为1 2 3 4
    /*
    for (int i = 2; i <= n;i++){
        //set2 = set1;
        int k = 0;
        for(int set:set1){
            if(set==0)
                break;
            set2[k] = set;
            k++;
        }
        while(j>=0&&set2[j]>s2[i]){
            //set2.pop_back();
            set2[j] = 0;
            j--;
        }
        if(j>=0&&set2[j]<s2[i]){
            //set2.push_back(s2[i]);
            j++;
            set2[j] = s2[i];
        }
        if(j<0){
            //set2.push_back(s2[i]);
            j++;
            set2[j] = s2[i];
        }
        if(j+1>=longest){
            k = 0;
            for(int set:set2){
                if(set==0)
                    break;
                set1[k] = set;
                k++;
            }
            longest = j+1;
        }
    }*/
    //看过O(nlgn)的题解后重新做了一遍,仍然是LIS问题，贪心算法优化后不需要每次都从头遍历一次
    dp[1] = s2[1];
    int len = 1;
    for (int i = 2; i <= n;i++){
        if(s2[i]>dp[len]){
            dp[++len] = s2[i];//大于最长的元素直接加到尾部
        }
        else{
            //二分查找到恰好不大于的元素替换
            int l=1, r=len, mid;
            while(l<=r){
                mid = (l + r) / 2;
                if(dp[mid]<s2[i]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            dp[l] = s2[i];
        }
    }
    cout << len;
    system("pause");
    return 0;
}