#include <iostream>

using namespace std;
int visit[10];
int arr[10];

void dfs(int depth, int n, int m){
    if (depth == m){
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    } else{
        for (int i = 1; i <= n; i++) {
            if (visit[i]){
                continue;
            } else{
                arr[depth] = i;
                visit[i] = 1;
                dfs(depth + 1, n, m);
                visit[i] = 0;
            }

        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    dfs(0, n, m);
    return 0;
}
