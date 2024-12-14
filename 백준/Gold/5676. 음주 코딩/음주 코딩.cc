#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, k;
vi tree, arr;


int buildTree(int node, int start, int end) {
    if (start == end) {
        int t = 0;
        if (arr[start] > 0) {
            t = 1;
        } else if (arr[start] < 0) {
            t = -1;
        }
        return tree[node] = t;
    }
    int mid = (start + end) / 2;
    return tree[node] = (buildTree(node * 2, start, mid) * buildTree(node * 2 + 1, mid + 1, end));
}

int find(int node, int start, int end, int left, int right) {
    if (end < left || start > right) {
        return 1;
    }
    if (left <= start && right >= end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return (find(node * 2, start, mid, left, right) * find(node * 2 + 1, mid + 1, end, left, right));
}

void update(int node, int start, int end, int idx, int diff) {
    if (start > idx || end < idx) {
        return;
    }
    if (start == end) {
        tree[node] = diff;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, diff);
    update(node * 2 + 1, mid + 1, end, idx, diff);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    while (cin >> n >> k) {
        tree.clear();
        arr.clear();
        int depth = (int) ceil(log2(n));
        int treeSize = (1 << (depth + 1));
        tree.resize(treeSize);
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        buildTree(1, 0, n - 1);

        for (int i = 0; i < k; i++) {
            char c;
            int a, b;
            cin >> c >> a >> b;
            if (c == 'C') {
                if (b > 0) {
                    b = 1;
                } else if (b < 0) {
                    b = -1;
                }
                update(1, 0, n - 1, a - 1, b);
            } else {
                int res = find(1, 0, n - 1, a - 1, b - 1);
                if (res > 0){
                    cout << '+';
                }else if (res < 0){
                    cout << '-';
                }else{
                    cout << 0;
                }
            }
        }
        cout << "\n";
    }


    return 0;
}