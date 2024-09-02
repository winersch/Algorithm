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

bool bfs(vector<vi>& graph, vi& color, int node){
    queue<int> q;
    q.push(node);
    color[node] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (int a : graph[curr]) {
            if (color[a] == -1){
                color[a] = 1 - color[curr];
                q.push(a);
            }else if (color[a] == color[curr]){
                return false;
            }
        }
    }
    return true;
}

bool check(vector<vi>& graph){
    int n = graph.size();
    vi color(n, -1);

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1){
            if(!bfs(graph, color,i)){
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        int v, e;
        cin >> v >> e;
        vector<vi> graph(v+1);

        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        if (check(graph)){
            cout << "YES\n";
        }else{
            cout <<"NO\n";
        }


    }

    return 0;
}