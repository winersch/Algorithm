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

int n, m;
ll arr[100001];
vector<ll> tree;

ll buildTree(int node, int start, int end){
    if (start == end){
        return tree[node] = arr[start];
    }
    int mid = (start + end)/2;

    return tree[node] = buildTree(node*2, start, mid) + buildTree(node*2+1, mid+1, end);

}

void updateTree(int node, int start, int end, int idx, ll diff){
    if (idx < start || idx > end){
        return;
    }

    tree[node] += diff;

    if (start != end){
        int mid = (start + end)/2;
        updateTree(node*2, start, mid, idx, diff);
        updateTree(node*2+1, mid+1, end, idx, diff);
    }
}

ll sumTree(int node, int start, int end, int left, int right){
    if (left > end || right < start){
        return 0;
    }
    if (left <= start && end <= right){
        return tree[node];
    }
    int mid = (start + end)/2;

    return sumTree(node*2, start, mid, left, right) + sumTree(node*2+1, mid+1, end, left, right);


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int depth = (int)ceil(log2(n));
    int treesize = (1 << (depth+1));
    tree.resize(treesize);
    buildTree(1,1,n);


    for (int i = 0; i < m; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b){
            swap(a,b);
        }
        cout << sumTree(1,1,n,a,b) << "\n";
        updateTree(1,1,n,c,d - arr[c]);
        arr[c] = d;
    }

    return 0;
}