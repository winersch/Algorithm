#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>
#include <list>
#include <unordered_set>
#include <sstream>
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

struct student{
    int y, m, d;
    string name;
};

bool comp(student& a, student& b){
    if (a.y == b.y){
        if (a.m == b.m){
            return a.d < b.d;
        }
        return a.m < b.m;
    }
    return a.y < b.y;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<student> v;
    for (int i = 0; i < n; i++) {
        int y, m, d;
        string name;
        cin >> name >> d >> m >> y;
        v.push_back({y,m,d,name});
    }
    std::sort(v.begin(), v.end(), comp);
    cout << v.back().name << "\n" << v.front().name;

    return 0;
}