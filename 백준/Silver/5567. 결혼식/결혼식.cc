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
bool visited[501];
vector<int> v[501];

void bfs(){
    queue<int> q;
    visited[1] = true;
    for (int i = 0; i < v[1].size(); i++) {
        int next = v[1][i];
        q.push(next);
        visited[next] = true;
        ans++;
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (int i = 0; i < v[curr].size(); i++) {
            int next = v[curr][i];
            if (!visited[next]){
                ans++;
                visited[next] = true;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs();
    cout << ans;

    return 0;
}