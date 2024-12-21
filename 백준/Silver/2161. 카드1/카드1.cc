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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    if (n == 1){
        cout << 1;
        return 0;
    }
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    while(dq.size() > 1){
        cout << dq.front() << " ";
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }

    cout << dq.front();


    return 0;
}