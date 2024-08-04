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


int n, d;
vector<pii> shortcut[10001];
int dist[10001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c >= b-a || b > d){
            continue;
        }
        shortcut[b].push_back({a,c});
    }
    memset(dist, inf, sizeof(dist));
    dist[0] = 0;

    for (int i = 1; i <= d; i++) {
        if (shortcut[i].empty()){
            dist[i] = dist[i-1] + 1;
        }else{
            for(pii a : shortcut[i]){
                dist[i] = min(dist[i], min(dist[i-1]+1, dist[a.first] + a.second));
            }
        }
    }

    cout << dist[d];

    return 0;
}