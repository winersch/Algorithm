#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>

using namespace std;

int n;
int graph[52][52];
//26~51;

bool bfs(int rGraph[52][52], int start, int end, int parent[]){
    bool visited[52];
    memset(visited, false, sizeof(visited));

    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for (int v = 0; v < 52; v++) {
            if (!visited[v] && rGraph[u][v] > 0){
                if (v == end){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int edmondsKarp(int start, int end){
    int u, v;

    int rGraph[52][52];
    for (u = 0; u < 52; u++) {
        for (v = 0; v < 52; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[52];
    int max_flow = 0;

    while(bfs(rGraph, start, end, parent)){
        int path_flow = inf;
        for (v = end; v != start ; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = end; v != start; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int c;
        char a, b;
        cin >> a >> b >> c;
        int u = (a >= 'a' && a <= 'z') ? a - 'a' + 26 : a - 'A';
        int v = (b >= 'a' && b <= 'z') ? b - 'a' + 26 : b - 'A';
        graph[u][v] += c;
        graph[v][u] += c;
    }
    cout << edmondsKarp(0, 25);

    return 0;
}