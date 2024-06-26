#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>

using namespace std;

int n;


ll ccw(pll p1, pll p2, pll p3) {
    ll s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1;
}

bool isIntersect(pair<pll,pll> l1, pair<pll,pll> l2){

    pll p1 = l1.first;
    pll p2 = l1.second;
    pll p3 = l2.first;
    pll p4 = l2.second;

    ll p1p2 = ccw(p1,p2,p3) * ccw(p1,p2,p4);
    ll p3p4 = ccw(p3,p4,p1) * ccw(p3,p4,p2);

    if (p1p2 == 0 && p3p4 == 0){
        if (p1 > p2){
            swap(p2,p1);
        }
        if(p3 > p4){
            swap(p3,p4);
        }
        return p3 <= p2 && p1 <= p4;
    }
    return p1p2 <= 0 && p3p4 <= 0;

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    pair<pll,pll> l1, l2;

    cin >> l1.first.first >> l1.first.second >> l1.second.first >> l1.second.second;
    cin >> l2.first.first >> l2.first.second >> l2.second.first >> l2.second.second;

    if (isIntersect(l1,l2)){
        cout << 1;
    }else{
        cout << 0;
    }

    return 0;
}