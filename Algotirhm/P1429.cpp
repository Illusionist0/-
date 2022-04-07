//平面最近点对
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include <iomanip>
using namespace std;
double dis(pair<int, int>p1,pair<int, int> p2){
    return sqrt(pow(p1.first- p2.first, 2) + pow(p1.second - p2.second, 2));
}
int main(){
    int n,x,y;
    cin >> n;//2<=n<=200000
    vector<pair<int, int>> dots;
    //TLE暴力求解
    for (int i = 0; i < n;i++){
        cin >> x >> y;
        dots.push_back(make_pair(x, y));
    }
    double min_distance=dis(dots[0],dots[1]);
    for (int i = 0; i < n;i++){
        for (int j = i+1; j < n;j++){
            min_distance = min(min_distance, dis(dots[i], dots[j]));
        }
    }
    cout << fixed << setprecision(4)<< min_distance;
    system("pause");
    return 0;
}