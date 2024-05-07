#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define mod 10007
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int n;
int a[500001];
int b[1000001];
ll tree[500001 * 4];
ll ans;

ll find(int node, int start, int end, int left, int right) {
    if (end < left || start > right) {
        return 0;
    }
    if (left <= start && right >= end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return find(node * 2, start, mid, left, right) + find(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx) {
    if (start > idx || end < idx) {
        return;
    }
    if (start == end) {
        tree[node] = 1;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx);
    update(node * 2 + 1, mid + 1, end, idx);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[x] = i;
    }
    for (int i = 0; i < n; i++) {
        ans += find(1, 0, n - 1, b[a[i]] + 1, n - 1);
        update(1, 0, n - 1, b[a[i]]);
    }

    cout << ans;

    return 0;
}