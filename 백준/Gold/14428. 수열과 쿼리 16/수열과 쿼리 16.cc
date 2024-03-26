#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 10007
#define ll long long
using namespace std;

ll num[1000001];
vector<pair<ll, ll>> minTree;
int n, m;

void buildTree(int node, int start, int end) {
    if (start == end) {
        minTree[node] = {num[start], start};
        return;
    }
    buildTree(node * 2, start, (start + end) / 2);
    buildTree(node * 2 + 1, (start + end) / 2 + 1, end);
    minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
}

pair<ll, ll> updateTree(int node, int start, int end, ll idx, ll diff) {
    if (idx < start || idx > end) {
        return minTree[node];
    }

    if (start == end) {
        return minTree[node] = {diff, idx};
    }

    int mid = (start + end) / 2;
    minTree[node] = min(updateTree(node * 2, start, mid, idx, diff), updateTree(node * 2 + 1, mid + 1, end, idx, diff));
    return minTree[node];
}

pair<ll, ll> find(int node, int start, int end, ll left, ll right) {
    if (left > end || right < start) {
        return {INT64_MAX, INT64_MAX};
    } else if (left <= start && end <= right) {
        return minTree[node];
    } else {
        int mid = (start + end) / 2;

        return min(find(node*2,start,mid,left,right), find(node*2+1, mid+1, end, left,right));
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    int depth = (int) ceil(log2(n));
    int treeSize = (1 << (depth + 1));
    minTree.resize(treeSize);
    buildTree(1, 1, n);
    cin >> m;

    for (int i = 0; i < m; i++) {
        int type;
        ll x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            updateTree(1, 1, n, x, y);
            num[x] = y;
        } else {
            cout << find(1, 1, n, x, y).second << "\n";
        }
    }

}