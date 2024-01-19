#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int cnt;
bool teamed[100001];
bool visited[100001];
int v[100001];

void findCycle(int a) {
    visited[a] = true;

    if (!visited[v[a]]) {
        findCycle(v[a]);
    } else if (!teamed[v[a]]) {
        for (int i = v[a]; i != a; i = v[i]) {
            cnt++;
        }
        cnt++;
    }
    teamed[a] = true;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cnt = 0;
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            v[j] = a;
        }
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                findCycle(j);
            }
        }

        cout << n - cnt << "\n";
        memset(teamed, false, sizeof(teamed));
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}