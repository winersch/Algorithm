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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, w, l;
vi v;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> w >> l;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; v.push_back(a);
    }

    int t = 0, weight = 0, idx = 0;
    queue<int> q;

    for (int i = 0; i < w; i++) {
        q.push(0);
    }
    while(idx < n){
        t ++;
        weight -= q.front();
        q.pop();

        if (weight + v[idx] <= l){
            q.push(v[idx]);
            weight += v[idx];
            idx++;
        }else{
            q.push(0);
        }
    }
    t += w;

    cout << t;

    return 0;
}

