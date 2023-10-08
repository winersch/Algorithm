#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

int pc[101][101];
int pcnum[101];
int n, m, cnt;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        pc[a][b] = 1;
    }

    queue<int> q;
    q.push(1);

    while (!q.empty()){
        int a = q.front();
        q.pop();
        if (pcnum[a] == 1){
            continue;
        }
        pcnum[a] = 1;
        cnt++;
        for (int i = 1; i <= n; i++) {
            if (pc[a][i] == 1 || pc[i][a] == 1){
                q.push(i);
            }
        }
    }

    cout << cnt-1;
    return 0;
}