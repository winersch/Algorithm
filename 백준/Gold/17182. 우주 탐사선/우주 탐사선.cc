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

int n, k, ans = inf;
int location[11][11];

void bfs(){
    queue<pair<int,pii>> q;
    q.push({0,{k, 1<<k}});

    while(!q.empty()){
        int cost = q.front().first;
        int curr = q.front().second.first;
        int visited = q.front().second.second;
        q.pop();
        if ((visited & (int)pow(2,n)-1) == (int)pow(2,n)-1){
            ans = min(ans, cost);
        }
        for (int i = 0; i < n; i++) {
            if (visited & 1<<i){
                continue;
            }
            q.push({cost + location[curr][i], {i, visited | 1<<i}});
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> location[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                location[i][j] = min(location[i][j], location[i][k] + location[k][j]);
            }
        }
    }
    bfs();
    cout << ans;

    return 0;
}