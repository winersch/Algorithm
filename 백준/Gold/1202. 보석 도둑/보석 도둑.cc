#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

#define inf 0x3f3f3f;
using namespace std;

pair<int,int>jem[300001];
int backpack[300001];
int n, k;
long long ans;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        jem[i] = {a,b};
    }
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        backpack[i] = a;
    }
    sort(jem, jem+n);
    sort(backpack, backpack+k);

    int tmp = 0;
    priority_queue<int, vector<int>, less<>> pq;
    for (int i = 0; i < k; i++) {
        while (tmp < n && jem[tmp].first <= backpack[i]){
            pq.push(jem[tmp].second);
            tmp++;
        }
        if (!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}
