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



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        bool room[101] = {true};
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j+=i) {
                room[j] = !room[j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (room[i]){
                ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}