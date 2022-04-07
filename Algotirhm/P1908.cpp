//逆序对
#include<iostream>
#include<vector>

using namespace std;
//归并排序
int merge_sort(vector<int>&nums,vector<int>&tmp,int low,int high){
    if(low>=high)return 0;
    int mid = (low + high) / 2;
    int res = merge_sort(nums, tmp, low, mid)+merge_sort(nums, tmp, mid+1, high);
    //计算两个区间之间的逆序对
    int i=low,j=mid+1,k;
    for (k = low; k <= high;k++)tmp[k] = nums[k];
    for (k = low;k<=high;k++){
        if(i==mid+1)
            nums[k] = tmp[j++];
        else if(j==high+1||tmp[i]<=tmp[j])
            nums[k] = tmp[i++];
        else{
            nums[k] = tmp[j++];
            res += mid - i + 1;
        }
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin >> nums[i];
    }
    vector<int> tmp(nums.size());
    cout<<merge_sort(nums, tmp, 0, nums.size() - 1);
    system("pause");
    return 0;
}