#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;

int n, m;
int input[9];
vector<int> v;

void dfs(int a, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = a; i < n; i++) {
        v[cnt] = input[i];
        dfs(i, cnt + 1);
    }


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    v.resize(m);
    sort(input, input + n);

    for (int i = 0; i < n; i++) {
        v[0] = input[i];
        dfs(i, 1);
    }
    
    return 0;
}