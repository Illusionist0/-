//ISBN号码
#include<iostream>
#include<string>
using namespace std;

int main(){
    string code;
    unsigned int see=0;
    cin >> code;
    string num = code.substr(0, 1) + code.substr(2,3) + code.substr(6,5);
    for (int i = 0; i < 9;i++){
        see = (see + (((num[i]-'0')*(i+1)) % 11) )% 11;
    }
    if(see==(unsigned int)code[12]-'0'||(see==10&&code[12]=='X')){
        cout << "Right";
        system("pause");
        return 0;
    }
    else{
        char csee = see + '0';
        if(see==10)
            csee = 'X';
        string last="a";
        last[0] = csee;
        cout << code.substr(0, 12) + last;
    }
    system("pause");
    return 0;
}