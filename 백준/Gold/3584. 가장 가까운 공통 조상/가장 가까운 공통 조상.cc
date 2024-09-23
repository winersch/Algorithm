#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

#define inf 0x3f3f3f
#define pii pair<int,int>

int n;
int parent[10001];
bool visited[10001];

int dfs(int a){
    if (visited[a]){
        return a;
    }
    visited[a] = true;
    return dfs(parent[a]);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){

        memset(parent, -1, sizeof(parent));
        memset(visited, false, sizeof(visited));

        cin >> n;
        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            parent[b] = a;
        }
        int n1, n2;
        cin >> n1 >> n2;
        dfs(n1);
        cout << dfs(n2) << "\n";

    }


    return 0;
}