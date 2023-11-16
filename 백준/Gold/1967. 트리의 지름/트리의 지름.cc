#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int n;
vector <pair<int, int>> v[10001];
int max_weight;
int visited[10001];


void dfs(int start, int weight){
    visited[start] = 1;
    max_weight = max(max_weight, weight);
    for (pair<int, int> p: v[start]) {
        if (!visited[p.first]){
            dfs(p.first, weight + p.second);
        }
    }

}



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;


    for (int i = 0; i < n-1; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;

        v[a].push_back({b, weight});
        v[b].push_back({a,weight});
    }

    for (int i = 0; i < n; i++) {
        dfs(i, 0);
        memset(visited, 0, sizeof(visited));
    }

    cout << max_weight;


    return 0;
}