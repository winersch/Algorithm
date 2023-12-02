#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>


using namespace std;

int n, k, ans, anscnt;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool is_find = false;
pair<int, int> visited[200001];

void bfs() {

    pq.push({0, n});
    while (!pq.empty()) {
        int curr = pq.top().second;
        int cnt = pq.top().first;
        pq.pop();
        if (curr * 2 == k || curr + 1 == k || curr - 1 == k) {
            if (is_find) {
                if (cnt + 1 == ans) {
                    anscnt++;
                } else {
                    continue;
                }
            } else {
                ans = cnt + 1;
                anscnt++;
                is_find = true;
            }
        }
        if (curr * 2 <= 200001 && curr*2 <= k*2) {
            if (!visited[curr * 2].first) {
                visited[curr * 2].first = 1;
                visited[curr*2].second = cnt+1;
                pq.push({cnt + 1, curr * 2});
            } else if(visited[curr*2].second == cnt+1){
                pq.push({cnt+1, curr*2});
            }
        }
        if (curr + 1 <= 100000) {
            if (!visited[curr + 1].first){
                visited[curr+1].first = 1;
                visited[curr+1].second = cnt+1;
                pq.push({cnt+1, curr+1});
            }else if(visited[curr+1].second == cnt+1){
                pq.push({cnt+1, curr+1});
            }
        }
        if (curr - 1 >= 0) {
            if (!visited[curr - 1].first){
                visited[curr-1].first = 1;
                visited[curr-1].second = cnt+1;
                pq.push({cnt+1, curr-1});
            }else if(visited[curr-1].second == cnt+1){
                pq.push({cnt+1, curr-1});
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    if (n == k){
        cout << 0 << "\n" << 1;
        return 0;
    }
    bfs();
    cout << ans << "\n" << anscnt;
    return 0;
}