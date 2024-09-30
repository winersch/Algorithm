#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

ll num[1000001];
int n, m;

ll buildTree(ll arr[], vector<ll> &tree, int node, int start, int end){
    if (start == end){
        return tree[node] = arr[start];
    }
    int mid = (start + end)/2;

    return tree[node] = buildTree(arr, tree, node*2, start, mid) + buildTree(arr, tree, node*2+1, mid+1, end);
}

void updateTree(vector<ll> &tree, int node, int start, int end, int idx, ll diff){
    if (idx < start || idx > end){
        return;
    }
    tree[node] = tree[node] + diff;

    if (start != end){
        int mid = (start + end)/2;
        updateTree(tree, node*2, start, mid, idx, diff);
        updateTree(tree, node*2+1, mid+1, end, idx, diff);
    }


}

ll sumTree(vector<ll> &tree, int node, int start, int end, int left, int right){
    if (left > end || right < start){
        return 0;
    }
    if (left <= start && end <= right){
        return tree[node];
    }

    int mid = (start + end)/2;

    return sumTree(tree, node*2,start,mid,left,right) + sumTree(tree, node*2+1, mid+1, end, left, right);

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    int depth = (int) ceil(log2(n));
    int treeSize = (1 << (depth+1));
    vector<ll> tree(treeSize, 0);


    for (int i = 0; i < m; i++) {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1){
            updateTree(tree, 1, 0, n-1, x-1, y-num[x-1]);
            num[x-1] = y;
        }else{
            if (x > y){
                swap(x,y);
            }
            cout << sumTree(tree, 1, 0, n-1, x-1, y-1) << "\n";
        }

    }

    return 0;
}