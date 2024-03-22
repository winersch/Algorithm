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
int n, m, k;
vector<ll> minTree, maxTree;

void buildTree(int node, int start, int end) {
    if (start == end) {
        minTree[node] = maxTree[node] = num[start];
        return;
    }
    buildTree(node * 2, start, (start + end) / 2);
    buildTree(node * 2 + 1, (start + end) / 2 + 1, end);
    minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
    maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
}

pair<ll, ll> find(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return {INT64_MAX, INT64_MIN};
    } else if (left <= start && end <= right) {
        return {minTree[node], maxTree[node]};
    } else {
        pair<ll, ll> l, r;
        l = find(node * 2, start, (start + end) / 2, left, right);
        r = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
        return {min(l.first, r.first), max(l.second, r.second)};
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    int depth = (int) ceil(log2(n));
    int treeSize = (1 << (depth + 1));
    minTree.resize(treeSize);
    maxTree.resize(treeSize);

    buildTree(1, 1, n);
    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;
        pair<ll, ll> ans = find(1, 1, n, left, right);
        cout << ans.first << " " << ans.second << "\n";
    }

}