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

int arr[100001];
vector<pii> minTree;
int n, m;

void buildTree(int node, int start, int end){
    if (start == end){
        minTree[node] = {arr[start], start};
        return;
    }

    buildTree(node*2, start, (start+end)/2);
    buildTree(node*2+1, (start+end)/2 + 1,end);
    minTree[node] = min(minTree[node*2], minTree[node*2+1]);
}

pii updateTree(int node, int start, int end, int idx, int diff){
    if (idx < start || idx > end){
        return minTree[node];
    }

    if (start == end){
        return minTree[node] = {diff, idx};
    }

    int mid = (start+end)/2;

    minTree[node] = min(updateTree(node*2, start, mid, idx, diff), updateTree(node*2+1, mid+1, end, idx, diff));
    return minTree[node];
}

pii find(int node, int start, int end, int left, int right){
    if (left > end || right < start){
        return{INT32_MAX, INT32_MAX};
    }
    if (left <= start && end <= right){
        return minTree[node];
    }
    int mid = (start + end)/2;

    return min(find(node*2, start, mid, left, right), find(node*2+1, mid+1, end, left, right));

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int depth = (int) ceil(log2(n));
    int treeSize = (1 << (depth +1));
    minTree.resize(treeSize);

    buildTree(1,1,n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1){
            updateTree(1,1,n,x,y);
            arr[x] = y;
        }else{
            cout << find(1,1,n,x,y).first << "\n";
        }


    }
    return 0;
}