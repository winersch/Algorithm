#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000007
#define ll long long
using namespace std;

ll num[1000001];
int n, m, k;

ll buildTree(ll arr[], vector<ll> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start]%mod;
    }
    int mid = (start + end) / 2;

    return tree[node] =
                   (buildTree(arr, tree, node * 2, start, mid) * buildTree(arr, tree, node * 2 + 1, mid + 1, end)) % mod;
}

void updateTree(vector<ll> &tree, int node, int start, int end, int idx, ll newValue) {
    if (idx < start || idx > end) {
        return;
    }
    if (start == end){
        tree[node] = newValue;
    }

    if (start != end) {
        int mid = (start + end) / 2;
        updateTree(tree, node * 2, start, mid, idx, newValue);
        updateTree(tree, node * 2 + 1, mid + 1, end, idx, newValue);
        tree[node] = tree[node*2] * tree[node*2+1] % mod;
    }


}

ll mulTree(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 1;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    return (mulTree(tree, node * 2, start, mid, left, right) * mulTree(tree, node * 2 + 1, mid + 1, end, left, right)) % mod;

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int depth = (int) ceil(log2(n));
    int treeSize = (1 << (depth + 1));
    vector<ll> tree(treeSize);

    buildTree(num, tree, 1, 0, n - 1);

    for (int i = 0; i < m + k; i++) {
        ll type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            updateTree(tree, 1, 0, n - 1, x - 1, y);
            num[x - 1] = y;
        } else {
            cout << mulTree(tree, 1, 0, n - 1, x - 1, y - 1) % mod << "\n";
        }
    }

}