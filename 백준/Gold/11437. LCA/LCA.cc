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


#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m;
vi node[50001];
int parent[50001];
int depth[50001];
bool visited[50001];

int lca(int a, int b){
    if (depth[a] > depth[b]){
        swap(a,b);
    }
    while(depth[a] != depth[b]){
        b = parent[b];
    }
    while(a != b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    visited[1] = true;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (int i = 0; i < node[curr].size(); i++) {
            if (!visited[node[curr][i]]){
                visited[node[curr][i]] = true;
                depth[node[curr][i]] = depth[curr] + 1;
                parent[node[curr][i]] = curr;
                q.push(node[curr][i]);
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a,b) << "\n";
    }


    return 0;
}