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

int n;
vector<int> edge[3001];
bool visited[3001];
bool isCycle[3001];

bool findCycle(int curr, int parent){
    for (int a : edge[curr]) {
        if (a == parent){
            continue;
        }
        if (visited[a]){
            return isCycle[a] = true;
        }
        visited[a] = true;
        isCycle[a] = findCycle(a, curr);
    }
    return isCycle[curr];
}

int bfs(int a){
    queue<pii> q;
    q.push({a,0});
    visited[a] = true;
    while(!q.empty()){
        int curr = q.front().first;
        int cost = q.front().second;
        q.pop();
        for (int c : edge[curr]) {
            if (!visited[c]){
                if (isCycle[c]){
                    return cost+1;
                }else{
                    q.push({c, cost+1});
                    visited[c] = true;
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!isCycle[i]){
            memset(visited, false, sizeof(visited));
            visited[i] = true;
            isCycle[i] = findCycle(i,i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (isCycle[i]){
            cout << 0 << " ";
        }else{
            memset(visited, false, sizeof(visited));
            cout << bfs(i) << " ";
        }
    }

    return 0;
}