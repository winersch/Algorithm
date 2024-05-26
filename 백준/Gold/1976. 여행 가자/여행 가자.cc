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
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int n, m;
int connected[201][201];
bool visited[201];
int plan[1001];

bool check(int a, int b){
    queue<int> q;
    q.push(a);
    memset(visited, false, sizeof(visited));
    visited[a] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if (connected[curr][b]){
            connected[a][b] = 1;
            connected[b][a] = 1;
            return true;
        }
        for (int i = 0; i < n; i++) {
            if (connected[curr][i] && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> connected[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> plan[i];
        plan[i]--;
    }
    if (m == 1 || n == 1){
        cout << "YES";
        return 0;
    }
    for (int i = 0; i < m-1; i++) {
        if (!check(plan[i], plan[i+1])){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}