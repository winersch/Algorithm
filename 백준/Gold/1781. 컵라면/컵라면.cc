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

using namespace std;


int n, ans;
vector<int> v[200001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    priority_queue<int, vector<int>, less<>> pq;
    for (int i = n; i > 0; i--) {
        for(int a : v[i]){
            pq.push(a);
        }
        if (!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }


    cout << ans;

    return 0;
}