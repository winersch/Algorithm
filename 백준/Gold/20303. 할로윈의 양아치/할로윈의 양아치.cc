#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

#define inf 0x3f3f3f;
using namespace std;

int n, m, k;
int candy[30001];
int parent[30001];
int friendsNum[30001];
int dp[3001];

int findParent(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = findParent(parent[a]);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        candy[i] = a;
        parent[i] = i;
        friendsNum[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int x = findParent(a);
        int y = findParent(b);

        if (x < y){
            parent[y] = x;
        }else{
            parent[x] = y;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (parent[i] != i){
            candy[findParent(i)] += candy[i];
            friendsNum[parent[i]] += friendsNum[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (parent[i] == i){
            for (int j = k-1; j - friendsNum[i] >= 0 ; j--) {
                dp[j] = max(dp[j], dp[j-friendsNum[i]] + candy[i]);
            }
        }
    }


    cout << dp[k-1];
    return 0;
}
