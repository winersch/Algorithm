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

using namespace std;

int n;
bool isFriend[51][51];
bool visited[51];
int ans = 100, cnt;
vector<int> candidates;

void bfs(int a){
    memset(visited, false, sizeof(visited));
    queue<pii> q;
    q.push({a,0});
    visited[a] = true;
    int score = 0;
    while(!q.empty()){
        pii curr = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (isFriend[curr.first][i] && !visited[i]){
                q.push({i, curr.second+1});
                visited[i] = true;
                score = curr.second+1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]){
            return;
        }
    }
    if (ans > score){
        cnt = 1;
        ans = score;
        candidates.clear();
        candidates.push_back(a);
    }else if(ans == score){
        cnt++;
        candidates.push_back(a);
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    while(true){
        int a, b;
        cin >> a >> b;
        if (a == -1){
            break;
        }
        isFriend[a][b] = true;
        isFriend[b][a] = true;
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }

    std::sort(candidates.begin(), candidates.end());

    cout << ans << " " << candidates.size() << "\n";
    for (int a : candidates) {
        cout << a << " ";
    }

    return 0;
}