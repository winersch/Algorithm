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

int n, l;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> l;
    deque<pii> dq;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        while(!dq.empty() && dq.back().first > a){
            dq.pop_back();
        }
        dq.push_back({a,i});
        while(dq.front().second < i-l+1){
            dq.pop_front();
        }
        cout << dq.front().first << " ";
    }


    return 0;
}