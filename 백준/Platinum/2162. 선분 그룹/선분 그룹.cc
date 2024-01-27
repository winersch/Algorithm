#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

#define inf 0x3f3f3f;
using namespace std;
int n;
vector<pair<pair<int,int>,pair<int,int>>> v;
int parent[3001];


int ccw(pair<int, int>p1, pair<int, int>p2, pair<int, int>p3) {
    int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1;
}

bool isIntersect(pair<pair<int,int>,pair<int,int>> l1, pair<pair<int,int>,pair<int,int>> l2){

    pair<int,int> p1 = l1.first;
    pair<int,int> p2 = l1.second;
    pair<int,int> p3 = l2.first;
    pair<int,int> p4 = l2.second;

    int p1p2 = ccw(p1,p2,p3) * ccw(p1,p2,p4);
    int p3p4 = ccw(p3,p4,p1) * ccw(p3,p4,p2);

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

int findParent(int a){
    if (parent[a] == a){
        return a;
    }
    return parent[a] = findParent(parent[a]);
}

void setParent(int a, int b){
    for (int i = 0; i < n; i++) {
        if (parent[i] == b){
            parent[i] = a;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({{x1,y1},{x2,y2}});
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n-1; i++) {
        int x11, y11, x12, y12;
        x11 = v[i].first.first;
        y11 = v[i].first.second;
        x12 = v[i].second.first;
        y12 = v[i].second.second;
        for (int j = i+1; j < n; j++) {
            int x21, y21, x22, y22;
            x21 = v[j].first.first;
            y21 = v[j].first.second;
            x22 = v[j].second.first;
            y22 = v[j].second.second;

            if (isIntersect({{x11,y11},{x12,y12}},{{x21,y21},{x22,y22}})){
                if(findParent(i) < findParent(j)){
                    setParent(findParent(i), findParent(j));
                }else{
                    setParent(findParent(j), findParent(i));
                }

            }
        }
    }
    int ans = 0;
    int anscnt = 0;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i){
            ans++;
            p.push_back(i);
        }
    }
    for (int i = 0; i < p.size(); i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (parent[j] == p[i]){
                tmp++;
            }
        }
        anscnt = max(anscnt, tmp);
    }

    cout << ans << "\n" << anscnt;
    return 0;
}
