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

int n, m, ans;
int arr[1001][1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '1'){
                arr[i][j] = 1;
                if (i != 0 && j != 0){
                    arr[i][j] = min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1])) + 1;
                }
                ans = max(ans, arr[i][j]);
            }
        }
    }

    cout << ans*ans;
    return 0;
}