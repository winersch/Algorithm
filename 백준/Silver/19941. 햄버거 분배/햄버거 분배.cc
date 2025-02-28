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
#include <list>
#include <unordered_set>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, k, ans;
string s;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] != 'P'){
            continue;
        }
        for (int j = i-k; j <= i + k; j++) {
            if (j >= 0 && j < n && s[j] == 'H'){
                s[j] = '.';
                ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}

