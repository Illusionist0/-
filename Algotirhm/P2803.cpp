//学校选址2
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,k;
int stu[101], pos[101],len;
int sch[101],flag[101];
int sum(int j){
    int res=0;
    for (int i = 1; i <= n;i++){
        res += abs(pos[i] - pos[j]) * stu[i];
    }
}
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> stu[i];
    }
    for (int i = 2; i <= n;i++){
        cin >> len;
        pos[i] = pos[i-1] + len;
    }
    int total=0x7fffffff,f;
    for(int i=1;i<=k;i++){
        for (int j = 1; j <= n;j++){
            if(flag[j]==0){
                if(total>sum(j)){
                    total = sum(j);
                    f = j;
                }
            }
        }
        flag[f] = 1;
        sch[i] = f;
    }

    system("pause");
    return 0;
}