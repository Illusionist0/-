//快速幂取余
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long a, b, p, s=1;
    cin >> a >> b >> p;
    long x=b,y,z;
    while(x>0){
        y=1;
        z=a%p;
        while(y<=x&&x>1){
            y*=2;
            if(y>x)
                break;
            z=(z*z)%p;
        }
        s = (s*z)%p;
        if(x==1)
            x = 0;
        x=x-y/2;
    }
    cout << a << "^" << b << " mod " << p << "=" << s;
    system("pause");
    return 0;
}