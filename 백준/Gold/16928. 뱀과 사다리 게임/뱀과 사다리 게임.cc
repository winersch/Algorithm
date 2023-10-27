#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <cmath>


using namespace std;
int go[102];
int visited[102];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    queue<pair<int,int>> q;
    for (int i = 0; i < n+m; i++) {
        int a, b;
        cin >> a >> b;
        go[a] = b;
    }

    q.push({1,0});
    while (!q.empty()) {
        int a = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int nx = a+i;
            if(nx >= 100){
                cout << cnt+1;
                return 0;
            }
            while (go[nx] != 0){
                nx = go[nx];
            }
            if (!visited[nx]){
                q.push({nx,cnt+1});
                visited[nx] = 1;
            }
        }
    }


    return 0;
}