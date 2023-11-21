#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int visited[200001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    visited[n] = 1;
    q.push({0, n});
    if (n == k){
        cout << 0;
        return 0;
    }
    while (!q.empty()) {
        int time = q.top().first;
        int x = q.top().second;
        q.pop();

        if (x * 2 == k) {
            cout << time;
            return 0;
        }

        if (x - 1 == k || x + 1 == k) {
            cout << time + 1;
            return 0;
        }
        if (x < k && !visited[x * 2]) {
            visited[x * 2] = 1;
            q.push({time, x * 2});
        }

        if (x - 1 >= 0 && !visited[x - 1]) {
            visited[x - 1] = 1;
            q.push({time + 1, x - 1});
        }

        if (!visited[x + 1]) {
            visited[x + 1] = 1;
            q.push({time + 1, x + 1});
        }

    }


    return 0;
}