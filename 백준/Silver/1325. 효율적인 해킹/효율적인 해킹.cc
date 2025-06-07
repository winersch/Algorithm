#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <numeric>
#include <set>
#include <list>
#include <unordered_set>
#include <sstream>

#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long, long long>
#define vi vector<int>

using namespace std;

int n, m;
vi node[10001];
vi ans;
bool visited[10001];

int find(int x){
    int cnt = 1;
    memset(visited, false, sizeof(visited));
    visited[x] = true;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (auto a : node[curr]) {
            if (!visited[a]){
                visited[a] = true;
                cnt++;
                q.push(a);
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        node[b].push_back(a);
    }
    int cnt = -1;
    for (int i = 1; i <= n; i++) {
        int t = find(i);
        if (t > cnt){
            ans.clear();
            cnt = t;
            ans.push_back(i);
        }else if (t == cnt){
            ans.push_back(i);
        }

    }
    std::sort(ans.begin(), ans.end());
    for(int a : ans){
        cout << a << " ";
    }
    return 0;
}
