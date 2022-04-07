//ABC
#include<iostream>
using namespace std;
void tsort(int &a, int &b, int &c){
    if(a>b)swap(a,b);
    if(b>c)swap(c,b);
    if(a>b)swap(a,b);
}
int main(){
    int a, b, c;
    string order;
    cin >> a >> b >> c;
    //int *pa = &a, *pb = &b, *pc = &c;
    cin >> order;
    tsort(a, b, c);
    if(order[0]=='A'){
        cout << a;
        if(order[1]=='B'){
            cout << " " << b << " " << c;
        }
        else{
            cout << " " << c << " " << b;
        }
    }
    if(order[0]=='B'){
        cout << b;
        if(order[1]=='A'){
            cout << " " << a << " " << c;
        }
        else{
            cout << " " << c << " " << a;
        }
    }
    if(order[0]=='C'){
        cout << c;
        if(order[1]=='A'){
            cout << " " << a << " " << b;
        }
        else{
            cout << " " << b << " " << a;
        }
    }
    system("pause");
    return 0;
}