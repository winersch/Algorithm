#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
#define ll long long
using namespace std;

int n;
vector<int> v[1000001];
bool visited[1000001];
int dp[1000001][2]; // 0 = early, 1 = normal;

void find(int a){
    visited[a] = true;
    dp[a][0] = 1;

    for (int i = 0; i < v[a].size(); i++) {
        int child = v[a][i];
        if (visited[child]){
            continue;
        }
        find(child);
        dp[a][1] += dp[child][0];
        dp[a][0] += min(dp[child][1], dp[child][0]);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    find(1);
    cout << min(dp[1][0], dp[1][1]);

    return 0;
}