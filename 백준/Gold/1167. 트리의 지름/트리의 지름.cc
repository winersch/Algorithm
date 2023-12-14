#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int v, ans;
vector<pair<int,int>> tree[100001];
int visited[100001];
bool last = false;

int bfs(int a){
    queue<pair<int,int>> q;
    memset(visited, 0, sizeof(visited));
    visited[a] = 1;
    for (int i = 0; i < tree[a].size(); i++) {
        q.push({tree[a][i].first, tree[a][i].second});
        visited[tree[a][i].first] = 1;
    }
    int tmp = 0;
    int x;

    while (!q.empty()){
        int curr = q.front().first;
        int cost = q.front().second;
        q.pop();
        if (cost > tmp){
            tmp = cost;
            x = curr;
        }
        if (last){
            ans = max(ans, cost);
        }
        for (int i = 0; i < tree[curr].size(); i++) {

            if (!visited[tree[curr][i].first]){
                q.push({tree[curr][i].first, cost + tree[curr][i].second});
                visited[tree[curr][i].first] = 1;
            }
        }
    }
    last = true;
    return x;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> v;
    for (int i = 1; i <= v; i++) {
        vector<int> vec;
        int n, a;
        cin >> n;
        while (true){
            cin >> a;
            if (a == -1){
                break;
            }
            vec.push_back(a);
        }

        int tmp, cost;
        for (int j = 0; j < vec.size(); j++) {
            if (j%2 == 0){
                tmp = vec[j];
            } else{
                cost = vec[j];
                tree[n].push_back({tmp,cost});
            }
        }
    }

    bfs(bfs(1));
    cout << ans;
    return 0;
}