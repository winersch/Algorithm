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

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, a, b;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> a >> b;
    deque<int> dq;
    int mx = max(a,b);

    for (int i = 1; i < a; i++) {
        dq.push_back(i);
    }
    dq.push_back(mx);
    for (int i = b-1; i > 0; i--) {
        dq.push_back(i);
    }
    if (dq.size() > n){
        cout << -1;
    }else{
        int first = dq.front();
        dq.pop_front();
        int dqSize = dq.size();
        for (int i = 0; i < n-dqSize - 1; i++) {
            dq.push_front(1);
        }
        dq.push_front(first);
        for (int a : dq) {
            cout << a << " ";
        }
    }


    return 0;
}

