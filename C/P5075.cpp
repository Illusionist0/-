//数字反转
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string f,f1,f2;
    cin >> f;
    f1 = f.substr(0, f.length() - 2);
    reverse(f1.begin(), f1.end());
    f2 = f.substr(f.length() - 1, f.length());
    cout << f2 + "." + f1;
    system("pause");
    return 0;
}