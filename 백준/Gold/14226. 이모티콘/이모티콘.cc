#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int ans = inf, s;
bool visited[2002][2002];

struct emoji {
    int curr, cost, clip;
};

void bfs() {
    queue<emoji> q;
    q.push({1, 0, 0});
    visited[1][0] = true;

    while (!q.empty()) {
        int curr = q.front().curr;
        int cost = q.front().cost;
        int clip = q.front().clip;
        q.pop();
        if (curr == s) {
            ans = cost;
            return;
        }
        if (curr > 0 && curr < 2000) {
            if (!visited[curr][curr]) {
                visited[curr][curr] = true;
                q.push({curr, cost + 1, curr});
            }
            if (!visited[curr - 1][clip]) {
                visited[curr - 1][clip] = true;
                q.push({curr - 1, cost + 1, clip});
            }
        }

        if (clip > 0 && curr + clip < 2000) {
            if (!visited[curr + clip][clip]) {
                visited[curr + clip][clip] = true;
                q.push({curr + clip, cost + 1, clip});
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> s;
    bfs();
    cout << ans;

    return 0;
}