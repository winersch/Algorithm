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
#define mod 10007
#define ll long long
using namespace std;

int n,m;
vector<int> v[2001];
bool is_find = false;
bool visited[2001];

void dfs(int a, int depth){
    if (is_find){
        return;
    }
    if (depth == 5){
        is_find = true;
        return;
    }
    for (int i = 0; i < v[a].size(); i++) {
        if(!visited[v[a][i]]){
            visited[v[a][i]] = true;
            dfs(v[a][i], depth+1);
            visited[v[a][i]] = false;
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

    for (int i = 0; i < m; i++) {
        if (is_find){
            break;
        }
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        dfs(i,1);
    }

    if (is_find){
        cout << 1;
    }else{
        cout << 0;
    }

    return 0;
}