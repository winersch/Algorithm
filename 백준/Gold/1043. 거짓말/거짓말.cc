#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int people[51];
int party[51][60];
int visited[51];
queue<int> q;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int t;
    cin >> t;

    if (t == 0) {
        cout << m;
        return 0;
    }

    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        people[a] = 1;
    }


    for (int i = 0; i < m; i++) {
        cin >> party[i][1];
        for (int j = 2; j < party[i][1]+2; j++) {
            cin >> party[i][j];
            if (people[party[i][j]]) {
                party[i][0] = 1;
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (int i = 2; i < party[a][1]+2; i++) {
            people[party[a][i]] = 1;
        }
        for (int i = 0; i < m; i++) {
            if (visited[i]) {
                continue;
            }
            for (int j = 2; j < party[i][1]+2; j++) {
                if (people[party[i][j]]) {
                    q.push(i);
                    party[i][0] = 1;
                    visited[i] = 1;
                    continue;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (!party[i][0]) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}