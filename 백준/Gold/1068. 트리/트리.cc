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
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int n, root, ans, removed;
vector<int> v[51];

void find(int a) {

    for (int i = 0; i < v[a].size(); i++) {
        if (v[a][i] == removed){
            if (v[a].size() == 1){
                ans++;
            }
            continue;
        }
        if (v[v[a][i]].empty()) {
            ans++;
            continue;
        }
        find(v[a][i]);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == -1) {
            root = i;
        } else {
            v[a].push_back(i);
        }
    }
    cin >> removed;
    if (removed == root) {
        cout << 0;
        return 0;
    }
    find(root);

    cout << ans;

    return 0;
}