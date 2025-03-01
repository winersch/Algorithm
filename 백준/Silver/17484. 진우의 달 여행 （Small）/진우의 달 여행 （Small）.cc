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

int n, m, ans = inf;
int dx[3] = {-1,0,1};
int arr[6][6];

void bfs(){
    queue<pair<pii,pii>> q; // {연료, 방향}, {좌표}
    for (int i = 0; i < n; i++) {
        q.push({{0,-1},{-1,i}});
    }

    while(!q.empty()){
        pair<pii,pii> curr = q.front();
        q.pop();
        if (curr.second.first == n-1){
            ans = min(ans, curr.first.first);
        }
        for (int i = 0; i < 3; i++) {
            if (curr.first.second == i){
                continue;
            }
            int ny = curr.second.first + 1;
            int nx = curr.second.second + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m){
                q.push({{curr.first.first + arr[ny][nx], i}, {ny,nx}});
            }
        }

    }


}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    bfs();

    cout << ans;


    return 0;
}

