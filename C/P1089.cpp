//津津的储蓄计划
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int cost[13],first,last=0,mom=0;
    for (int i = 1; i <= 12;i++)
    cin >> cost[i];
    for (int i = 1; i <= 12;i++)
    {
        first = last + 300;
        if (first < cost[i])
        {
            cout << "-" << i;
            system("pause");
            return 0;
        }
        last = first - cost[i];
        if (last >= 100)
        {
            mom+= last - last % 100;
            last = last % 100;
        }
    }
    cout << last + mom * 1.2;
    system("pause");
    return 0;
}