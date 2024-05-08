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

const int MAX = 1000001;
int n;
ll candy[MAX];
ll tree[MAX*4];

int query(int node, int start, int end, ll idx){
    if (start == end){
        return end;
    }
    int mid = (start + end)/2;
    if (tree[node*2] >= idx){
        return query(node*2, start, mid, idx);
    }else{
        return query(node*2+1, mid+1, end, idx - tree[node*2]);
    }
}

void update(int node, int start, int end, ll idx, ll val){
    if (start > idx || end < idx){
        return;
    }
    if (start == end){
        tree[node] = val;
        return;
    }
    int mid = (start + end)/2;
    update(node*2, start, mid, idx, val);
    update(node*2+1, mid+1, end, idx, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a;
        if (a == 1){
            cin >> b;
            ll ans = query(1,1,MAX, b);
            cout << ans << "\n";
            update(1,1,MAX,ans,candy[ans]-1);
            candy[ans]--;
        }else{
            cin >> b >> c;
            update(1,1,MAX,b,candy[b] + c);
            candy[b] += c;
        }
    }


    return 0;
}