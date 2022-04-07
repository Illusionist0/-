//一元三次方程
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include <iomanip>
using namespace std;

int main(){
    double A,B,T,theta;
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    A=b*b-3*a*c;
    B=b*c-9*a*d;
    //C=c*c-3*b*d;
    T=(2*A*b-3*a*B)/(2*sqrt(A*A*A));
    theta=acos(T);
    double x1,x2,x3;
    x1=(-b-2*sqrt(A)*cos(theta/3))/(3*a);
    x2=(-b+sqrt(A)*(cos(theta/3)+sqrt(3)*sin(theta/3)))/(3*a);
    x3=(-b+sqrt(A)*(cos(theta/3)-sqrt(3)*sin(theta/3)))/(3*a);
    cout << fixed << setprecision(2)<<x1<<" "<<x3<<" "<<x2<<" ";
    system("pause");
    return 0;
}
