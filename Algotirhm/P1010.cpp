//幂次方
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
string str(int i);
string loop(int n,string str_n);
string str(int i){
    if(i==0)return "2(0)";
    if(i==1)return "2";
    if(i==2)return "2(2)";
    return "2(" + loop(i,"") + ")";
}
string loop(int n,string str_n){
    int i=0;
    while(pow(2,i)<=n){
        i++;
    }
    str_n += str(i - 1) ;
    n-=pow(2,i-1);
    if(n>0)str_n+="+"+loop(n, "");
    return str_n;
}
int main(){
    int n;
    cin >> n; // n=2(x1)+2(x2)+...+2(xk)
    string str_n;
    cout << loop(n, "");
    system("pause");
    return 0;
}