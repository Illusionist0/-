//守望者的逃离
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int m,s,t;
int main(){
    cin >> m >> s >> t;
    int flash=0, run=0;
    vector<int> dp(t);
    for (int i = 0; i < t;i++)
    {
        run += 17;
        if(m/10>0){
            flash += 60;
            m -= 10;
        }//优先闪现
        else
            m += 4;//不够补蓝
        if(flash>run)//闪现不能用时分为等待加闪现的阶段，将这个值和跑步比较，如果大于就代替跑步，否则跑步效率高
            run = flash;
        if(run>s){//跑步(优先高效率闪现)距离超过逃生距离
            cout << "Yes" << endl
                 << i+1 << endl;
            system("pause");
            return 0;
        }
    }
    cout << "No" << endl
         << run << endl;
    system("pause");
    return 0;
}