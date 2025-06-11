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

int n, k, m;
vi node[101001];
bool visited[101001];

int bfs(){
    queue<pii> q;
    q.push({1,1});
    visited[1] = true;

    while(!q.empty()){
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (curr == n){
            return cnt;
        }

        for (auto a : node[curr]) {
            if (!visited[a]){
                visited[a] = true;
                if (a <= n){
                    q.push({a, cnt+1});
                }else{
                    q.push({a,cnt});
                }
            }
        }

    }
    return -1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        int tube = n + 1 + i;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            node[tube].push_back(a);
            node[a].push_back(tube);
        }
    }

    cout << bfs();
    return 0;
}
