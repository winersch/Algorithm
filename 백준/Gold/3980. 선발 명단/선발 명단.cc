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

int ablity[11][11];
bool selected[11];
int t, ans;

void dfs(int idx, int sum){
    if (idx == 11){
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 11; i++) {
        if (ablity[idx][i] > 0 && !selected[i]){
            selected[i] = true;
            dfs(idx+1,sum + ablity[idx][i]);
            selected[i] = false;
        }
    }


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while(t--){
        ans = 0;
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                cin >> ablity[i][j];
            }
        }

        for (int i = 0; i < 11; i++) {
            if (ablity[0][i] > 0){
                selected[i] = true;
                dfs(1,ablity[0][i]);
                selected[i] = false;
            }
        }
        cout << ans << "\n";

    }

    return 0;
}