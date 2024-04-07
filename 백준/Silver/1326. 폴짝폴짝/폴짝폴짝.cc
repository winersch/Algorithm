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

int n;
int bridge[10001];
int visited[20001];
int a, b, ans;

void bfs() {
    queue<pair<int, int>> q;
    q.push({a, 0});
    visited[a] = 0;
    while (!q.empty()) {

        int curr = q.front().first;
        int idx = q.front().second;
        q.pop();


        for (int i = 1; curr + bridge[curr]*i <= n; i++) {
            int next = curr + bridge[curr]*i;
            if (visited[next] == -1){
                visited[next] = idx+1;
                q.push({next, idx+1});
            }
        }
        for (int i = 1; curr - bridge[curr]*i >= 1; i++) {
            int next = curr - bridge[curr]*i;
            if (visited[next] == -1){
                visited[next] = idx+1;
                q.push({next, idx+1});
            }
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> bridge[i];
    }
    cin >> a >> b;
    memset(visited, -1, sizeof(visited));
    bfs();
    cout << visited[b];

    return 0;
}