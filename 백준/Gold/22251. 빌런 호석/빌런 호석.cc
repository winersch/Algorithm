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

int n, k, p, x, ans;
vector<vector<vi>> v(10, vector<vi >(8));
vi num;

int segmentValues[10] = {
        0x7E, // 0
        0x30, // 1
        0x6D, // 2
        0x79, // 3
        0x33, // 4
        0x5B, // 5
        0x5F, // 6
        0x70, // 7
        0x7F, // 8
        0x7B  // 9
};

void dfs(int depth, int left, int a) {
    if (a > n) {
        return;
    }
    if (depth == k) {
        if (a != x && a != 0) {
            ans++;
        }
        return;
    }

    dfs(depth + 1, left, a * 10 + num[depth]);
    for (int i = 1; i < 8; i++) {
        if (left < i) {
            break;
        }
        for (int j = 0; j < v[num[depth]][i].size(); j++) {
            dfs(depth + 1, left - i, a * 10 + v[num[depth]][i][j]);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k >> p >> x;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j) {
                continue;
            }
            int diff = segmentValues[i] ^ segmentValues[j];
            int cnt = __builtin_popcount(diff);
            v[i][cnt].push_back(j);
        }
    }

    string s = to_string(x);
    num.assign(k, 0);
    for (int i = 0; i < s.size(); i++) {
        num[k - s.size() + i] = s[i] - '0';
    }

    dfs(0, p, 0);

    cout << ans;


    return 0;
}

