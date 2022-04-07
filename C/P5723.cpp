//质数口袋
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool isPrime(int x){
    if(x==2||x==3)
        return true;
    if((x+1)%6==0||(x-1)%6==0){
        //一定是6k+1或者6k-1
        int s = sqrt(x);
        for (int i = 2; i <= s;i++){
            if(x%i==0)
                return false;
        }
        return true;
    }
    else
        return false;
}
int main(){
    int l;
    cin >> l;
    int sum=0,total=0;
    for (int i = 2; i < l;i++)
    {
        if (isPrime(i))
        {
            if(sum + i <= l){
                total++;
                sum += i;
                cout << i << endl;
            }
            else {
                break;
            }
        }
    }
    cout << total;
    system("pause");
    return 0;
}