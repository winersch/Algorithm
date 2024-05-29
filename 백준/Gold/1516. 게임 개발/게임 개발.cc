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

int n;
int cost[501];
int entry[501];
vector<int> pre[501];
int ans[501];
queue<int> q;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
        while(true){
            int a;
            cin >> a;
            if (a == -1){
                break;
            }
            pre[a-1].push_back(i);
            entry[i]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (entry[i] == 0){
            q.push(i);
            ans[i] = cost[i];
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for (int i = 0; i < pre[curr].size(); i++) {
            int next = pre[curr][i];
            entry[next]--;
            ans[next] = max(ans[next], ans[curr] + cost[next]);
            if (entry[next] == 0){
                q.push(next);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}