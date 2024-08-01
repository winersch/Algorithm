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

using namespace std;

int n, m, ans;
string s;
int cnt[4];
int tmp[4];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> s;

    for (int i = 0; i < 4; i++) {
        cin >> cnt[i];
    }

    for (int i = 0; i < m; i++) {
        switch (s[i]) {
            case 'A':
                tmp[0]++;
                break;
            case 'C':
                tmp[1]++;
                break;
            case 'G':
                tmp[2]++;
                break;
            case 'T':
                tmp[3]++;
                break;
        }
    }

    if (tmp[0] >= cnt[0] && tmp[1] >= cnt[1] && tmp[2] >= cnt[2] && tmp[3] >= cnt[3]){
        ans++;
    }

    for (int i = m; i < n; i++) {
        switch (s[i]) {
            case 'A':
                tmp[0]++;
                break;
            case 'C':
                tmp[1]++;
                break;
            case 'G':
                tmp[2]++;
                break;
            case 'T':
                tmp[3]++;
                break;
        }
        switch (s[i - m]) {
            case 'A':
                tmp[0]--;
                break;
            case 'C':
                tmp[1]--;
                break;
            case 'G':
                tmp[2]--;
                break;
            case 'T':
                tmp[3]--;
                break;
        }
        if (tmp[0] >= cnt[0] && tmp[1] >= cnt[1] && tmp[2] >= cnt[2] && tmp[3] >= cnt[3]){
            ans++;
        }
    }

    cout << ans;

    return 0;
}