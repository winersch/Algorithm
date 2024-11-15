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
int arr[100001];
vector<pii> tree;

void buildTree(int node, int start, int end){
    if (start == end){
        tree[node] = {arr[start], start};
        return;
    }
    int mid = (start + end)/2;
    buildTree(node*2, start, mid);
    buildTree(node*2+1, mid+1, end);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

pii find(int node, int start, int end, int left, int right){
    if (left > end || right < start){
        return {INT32_MAX, INT32_MAX};
    }

    if (left <= start && end <= right){
        return tree[node];
    }else{
        int mid = (start +end)/2;

        return min(find(node*2, start, mid, left, right), find(node*2+1, mid+1, end, left, right));
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int depth = (int) ceil(log2(n));
    int treesize = (1 << (depth+1));
    tree.resize(treesize);
    buildTree(1,1,n);


    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << find(1,1,n,a,b).first << "\n";

    }

    return 0;
}