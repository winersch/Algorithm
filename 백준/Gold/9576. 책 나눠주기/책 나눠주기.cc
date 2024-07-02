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

int n, m;
priority_queue<pii, vector<pii>, greater<>> pq;
bool matched[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> n >> m;
        memset(matched, false, sizeof(matched));

        for (int i = 0; i < m; i++) {
            int a,b;
            cin >> a >> b;
            pq.push({b,a});
        }

        while(!pq.empty()){
            int b = pq.top().first;
            int a = pq.top().second;
            pq.pop();

            for (int i = a; i <= b; i++) {
                if (!matched[i]){
                    matched[i] = true;
                    ans++;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }


    return 0;
}