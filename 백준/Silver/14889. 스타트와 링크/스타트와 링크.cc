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
#define vi vector<int>

using namespace std;

int n, ans = inf;
int ablity[21][21];
bool visited[21];

void dfs(int depth, int idx){
    if (depth == n/2){
        int start = 0, link = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (visited[i] && visited[j]){
                    start += ablity[i][j] + ablity[j][i];
                }
                if (!visited[i] && !visited[j]){
                    link += ablity[i][j] + ablity[j][i];
                }
            }
        }
        ans = min(ans, abs(start - link));
        return;
    }
    for (int i = idx; i < n; i++) {
        visited[i] = true;
        dfs(depth+1, i+1);
        visited[i] = false;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ablity[i][j];
        }
    }
    dfs(0,0);
    cout << ans;



    return 0;
}