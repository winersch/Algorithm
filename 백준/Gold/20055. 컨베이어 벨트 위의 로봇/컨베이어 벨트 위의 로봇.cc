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

int n, k, cnt, ans;
int dur[201];
bool robot[201];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    n *= 2;
    for (int i = 1; i <= n; i++) {
        cin >> dur[i];
    }

    while(cnt < k){
        ans++;
        int tmp = dur[n];
        for (int i = n; i > 1; i--) {
            dur[i] = dur[i-1];
            robot[i] = robot[i-1];
        }
        dur[1] = tmp;
        robot[1] = false;
        robot[n/2] = false;
        for (int i = n/2-1; i > 0; i--) {
            if (robot[i] && !robot[i+1] && dur[i+1]){
                dur[i+1]--;
                robot[i+1] = true;
                robot[i] = false;
                if (dur[i+1] == 0){
                    cnt++;
                }
            }
        }
        if (dur[1]){
            dur[1]--;
            robot[1] = true;
            if (dur[1] == 0){
                cnt++;
            }
        }
    }
    cout << ans;
    return 0;
}

