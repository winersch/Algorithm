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

int n, m, k, x;
bool visited[300001];
vi v[300001];
vi ans;

void bfs(){
    queue<pii> q;
    q.push({x,0});
    visited[x] = true;

    while(!q.empty()){
        int curr = q.front().first;
        int cost = q.front().second;
        q.pop();
        for(int a : v[curr]){
            if (!visited[a]){
                visited[a] = true;
                if (cost+1 == k){
                    ans.push_back(a);
                }else if (cost+1 < k){
                    q.push({a,cost+1});
                }
            }
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    bfs();
    if (ans.empty()){
        cout << -1;
    }else{
        std::sort(ans.begin(), ans.end());
        for(int a : ans){
            cout << a << "\n";
        }
    }

    return 0;
}