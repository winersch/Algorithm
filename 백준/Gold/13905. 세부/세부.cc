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
vector<pair<int,pii>> v;
vector<pii> edge[100001];
int s, e;
int parent[100001];
int visited[100001];

int findParent(int a){
    if (parent[a] == a){
        return parent[a];
    }else{
        return parent[a] = findParent(parent[a]);
    }
}

void bfs(){
    memset(visited, inf, sizeof(visited));
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (int i = 0; i < edge[curr].size(); i++) {
            int next = edge[curr][i].first;
            int cost = edge[curr][i].second;
            if (visited[next] != inf){
                continue;
            }
            visited[next] = min(cost, visited[curr]);
            q.push(next);
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cin >> s >> e;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }
    std::sort(v.begin(), v.end(), greater<>());
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < v.size(); i++) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        if (b > a){
            swap(a,b);
        }
        int cost = v[i].first;
        if (findParent(a) != findParent(b)){
            parent[findParent(b)] = findParent(a);
            edge[a].push_back({b,cost});
            edge[b].push_back({a,cost});
        }
    }
    bfs();
    if (visited[e] == inf){
        cout << 0;
    }else{
        cout << visited[e];
    }

    return 0;
}