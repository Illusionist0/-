//回文数
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool isPalin(string s){
    if(s[0]=='0')
        return false;
    for (int i = 0; i < (int)(s.size() / 2);i++){
        if(s[i]!=s[s.size()-i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    string m;
    cin >> n >> m;
    int ans=0;
    string s1=m;
    int mod, carry=0;
    int i, j;
    while(n<=10&&!isPalin(s1)&&ans<30){
        int len = s1.size();
        string s2(len+1,'0');
        carry = 0;
        for (i = s1.size() - 1, j = 0; i >= 0; i--,j++){
            int k = s1[i] - '0' + s1[j] - '0'+carry;
            mod= k % n;
            if(mod!=k){
                carry = 1;
            }
            else{
                carry = 0;
            }
            s2[j] = mod+'0';
        }
        if(carry==1){
            s2[j] = '1';
        }
        else{
            s2.pop_back();
        }
        reverse(s2.begin(), s2.end());
        s1 = s2;
        ans++;
    }
    while(n==16&&!isPalin(s1)&&ans<30){
        int len = s1.size();
        string s2(len+1,'0');
        carry = 0;
        for (i = s1.size() - 1, j = 0; i >= 0; i--,j++){
            int x, y;
            if(s1[i]>='0'&&s1[i]<='9'){
                x = s1[i] - '0';
            }
            if(s1[i]>='A'&&s1[i]<='F'){
                x = s1[i] - 'A'+10;
            }
            if(s1[j]>='0'&&s1[j]<='9'){
                y = s1[j] - '0';
            }
            if(s1[j]>='A'&&s1[j]<='F'){
                y = s1[j] - 'A'+10;
            }
            int k = x+y+carry;
            mod= k % n;
            if(mod!=k){
                carry = 1;
            }
            else{
                carry = 0;
            }
            if(mod>=0&&mod<=9){
                s2[j] = mod+'0';
            }
            if(mod>=10&&mod<=15){
                s2[j] = mod + 'A'-10;
            }
        }
        if(carry==1){
            s2[j] = '1';
        }
        else{
            s2.pop_back();
        }
        reverse(s2.begin(), s2.end());
        s1 = s2;
        ans++;
    }
    if(isPalin(s1))
        cout << "STEP=" << ans;
    else
        cout << "Impossible!";
    system("pause");
    return 0;
}