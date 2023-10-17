#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>


using namespace std;

int v[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] = v[i] + v[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << v[b] - v[a - 1] << "\n";
    }

    return 0;
}