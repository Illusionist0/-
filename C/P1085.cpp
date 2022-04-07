//不高兴的津津
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int x, y, max=0, day=0;
    for (int i = 1; i <= 7;i++){
        cin >> x >> y;
        if(x+y>8){
            if(x+y>max){
                day = i;
                max = x + y;
            }
        }
    }
    cout << day;
    system("pause");
    return 0;
}