#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

#define inf 0x3f3f3f;
using namespace std;

long long ccw(pair<long long, long long>p1, pair<long long, long long>p2, pair<long long, long long>p3) {
    long long s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1;
}

bool isIntersect(pair<pair<long long,long long>,pair<long long,long long>> l1, pair<pair<long long,long long>,pair<long long,long long>> l2){

    pair<long long,long long> p1 = l1.first;
    pair<long long,long long> p2 = l1.second;
    pair<long long,long long> p3 = l2.first;
    pair<long long,long long> p4 = l2.second;

    long long p1p2 = ccw(p1,p2,p3) * ccw(p1,p2,p4);
    long long p3p4 = ccw(p3,p4,p1) * ccw(p3,p4,p2);

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

    pair<pair<long long,long long>, pair<long long,long long>> l1, l2;
    long long x1,y1,x2,y2,x3,y3,x4,y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    l1 = {{x1,y1},{x2,y2}};
    l2 = {{x3,y3},{x4,y4}};
    if (isIntersect(l1,l2)){
        cout << 1;
    }else{
        cout << 0;
    }


    return 0;
}
