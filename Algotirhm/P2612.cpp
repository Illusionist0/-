//cow code
#include<iostream>
#include<string>
using namespace std;


int main(){
    string code,s0;
    cin >> code;
    long long n;
    cin >> n;
    long long len = code.length(),i=len;
    while(i<n){
        i *= 2;
    }
    while(n>len){
        if(n>i/2)n = n - i / 2 - 1;
        if(n==0)
            n = i / 2;
        i /= 2;
    }
    cout << code[n-1];
    system("pause");
    return 0;
}