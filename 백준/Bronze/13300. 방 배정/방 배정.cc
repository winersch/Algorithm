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
#include <sstream>
#include <ctime>
#include <iomanip>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vs vector<string>

using namespace std;

int n, k;
int cnt[7][2];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cnt[b][a]++;
    }

    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 2; j++) {
            ans += cnt[i][j] / k;
            if (cnt[i][j] % k != 0 && cnt[i][j] != 0){
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}