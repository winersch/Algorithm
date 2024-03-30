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
using namespace std;

int n;
vector<int> v[1001];
int cls[5][10];
int cnt[1001];
int ans, t;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }
            for (int k = 0; k < 5; k++) {
                if (v[j][k] == v[i][k]){
                    cnt[i]++;
                    break;
                }
            }
        }

    }

    for (int i = 0; i < n; i++) {
        if (cnt[i] > t) {
            t = cnt[i];
            ans = i;
        }
    }
    cout << ans + 1;
}