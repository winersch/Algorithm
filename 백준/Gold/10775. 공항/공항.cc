#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>

#define inf 0x3f3f3f;
using namespace std;

int n,m,ans;
vector<int> v;
int gate[100001];
int docked[100001];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i <= n; i++) {
        docked[i] = i;
    }

    bool is = true;
    for (int i = 0; i < v.size(); i++) {
        if (!is){
            break;
        }
        is = false;
        for (int j = docked[v[i]]; j > 0; j--) {
            if (gate[j] == 0){
                gate[j] = 1;
                docked[v[i]] = j;
                is = true;
                ans++;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}
