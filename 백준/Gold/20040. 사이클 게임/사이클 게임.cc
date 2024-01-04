#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>


using namespace std;

int n, m;
int parent[500001];

int findParent(int a) {
    if (parent[a] == a) {
        return a;
    } else {
        return parent[a] = findParent(parent[a]);
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            int tmp = b;
            b = a;
            a = tmp;
        }
        if (findParent(a) == findParent(b)) {
            cout << i + 1;
            return 0;
        } else {
            parent[findParent(b)] = findParent(a);
        }
    }

    cout << 0;

    return 0;
}